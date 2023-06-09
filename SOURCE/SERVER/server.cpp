#include "application.h"
#include <QStringConverter>



/**
 * This function create the server structure.
 *
 * @param ipaddress: server IP address
 * @param port: server port
 */
Server::Server(QString ipaddress, int port):QTcpServer()
{
    socketList.clear();
    localip = QHostAddress(ipaddress);
    localport = port;
    idseq=0;

}

/**
 * Distructor of the Server structure.
 *
 * When the server is destroyed, the client queue needs to be destroyed as well.
 *
 */
Server::~Server()
{
    if(socketList.size()){
        for(int i = 0; i<socketList.size(); i++ ){
            if(socketList[i]->socket != nullptr) {
                socketList[i]->socket->close();
                socketList[i]->socket->deleteLater();
            }
        }
    }
}

/**
 * @brief This function activates the server listening.
 *
 * @return
 */
bool Server::Start(void)
{
    qDebug() << "VSCAN DRIVER INTERFACE ADDRESS: IP=" << localip.toString() << ", PORT=" << localport ;
    if (!this->listen(localip,localport)) return false;
    return true;

}

/**
 * This callback is called from the Socket library \n
 * whenever an incoming connection is requested by a remote CLient.
 *
 * When the connection is accepted, the CLient is added to
 * the server queue of the connected clients.
 *
 *
 * @param socketDescriptor
 */
void Server::incomingConnection(qintptr socketDescriptor)
{

    ServerItem* item = new ServerItem();

    item->socket = new QTcpSocket(this); // Create a new socket
    if(!item->socket->setSocketDescriptor(socketDescriptor))
    {
        delete item->socket;
        delete item;
        return;
    }

    item->socket->setSocketOption(QAbstractSocket::LowDelayOption,1);
    socketList.append(item);


    // Interface signal connection
    connect(item->socket,SIGNAL(readyRead()), item, SLOT(socketRxData()),Qt::UniqueConnection);
    connect(item->socket,SIGNAL(disconnected()),item, SLOT(disconnected()),Qt::UniqueConnection);
    connect(item,SIGNAL(sendToClient(QByteArray)),item, SLOT(socketTxData(QByteArray)),Qt::QueuedConnection);

    connect(item,SIGNAL(itemDisconnected(ushort )),this, SLOT(disconnected(ushort )),Qt::UniqueConnection);
    connect(item->socket,SIGNAL(errorOccurred(QAbstractSocket::SocketError)),item,SLOT(socketError(QAbstractSocket::SocketError)),Qt::UniqueConnection);

    item->id = this->idseq++;
    item->rxCanId = 0;
    item->dataPresent = false;
    return;
 }

/**
 * Socket disconnected callback
 */
void ServerItem::disconnected(void){
    emit itemDisconnected(this->id);
}

/**
 * Socket error callback
 *
 * @param error: the error code
 */
void ServerItem::socketError(QAbstractSocket::SocketError error)
{
    emit itemDisconnected(this->id);
    return;
}

/**
 * This function is called whenever a Client disconnects.
 *
 * The function deletes the client socket structure \n
 * removing the client from the active Client connection queue.
 *
 * @param id: the client identifier
 */
void Server::disconnected(ushort id)
{

    for(int i =0; i < socketList.size(); i++ ){
        if(socketList[i]->id == id){

            disconnect(socketList[i]);
            socketList[i]->socket->deleteLater();
            delete socketList[i];
            socketList.remove(i);
            return;
        }
    }

}



ushort ServerItem::getItem(int* index, QByteArray* data, bool* data_ok){
    *data_ok = false;
    bool is_hex = false;
    QString val;

    for(; *index< data->size(); (*index)++) if(data->at(*index) != ' ') break; // Removes the spaces

    for(; *index< data->size(); (*index)++){
        if(data->at(*index) == ' '){
            if(!val.size()) return 0;
            *data_ok = true;
            if(is_hex) return val.toUShort(data_ok, 16);
            else return val.toUShort();
        }
        if((data->at(*index) == 'x') |(data->at(*index) == 'X')) is_hex = true;
        val.append(data->at(*index));
    }

    // Non è terminato con uno spazio: errore
    return 0;
}

/**
 * This function decodes a single frame received from the Client.
 *
 * In case of successfully Registering frame identification,\n
 * the CLient is registered to a canId target device;
 *
 * In case of successfully Can Data frame identification,\n
 * the data are sent to the target device;
 *
 *
 * @param data: the pointer to the protocol frame to be decoded.
 */
void ServerItem::handleSocketFrame(QByteArray* data){

    QByteArray frame;
    bool is_register;
    bool is_valid;
    int i;
    bool data_ok;


    is_valid = false;
    for(i=0; i< data->size(); i++){
        if(data->at(i)== ' ') continue;
        if(data->at(i)== 'F') {
            is_register = true;
            is_valid = true;
            i++;
            break;
        }

        if(data->at(i)== 'D') {
            is_register = false;
            is_valid = true;
            i++;
            break;
        }
    }
    if(!is_valid) return;

    if(is_register){// Can Registering Frame: set the reception mask and address


        rxCanId = getItem(&i, data, &data_ok);
        if(!data_ok){
            rxCanId = 0;
            qDebug() << "CLIENT REGISTRATION TO A DEVICE FAILED: WRONG DEVICE FORMAT";
            return;
        }

        frame.append("<");
        frame.append(*data);
        frame.append(">");
        emit sendToClient(frame);

        qDebug() << QString("CLIENT REGISTERED FOR RECEPTION TO ADDR=0x%1").arg(rxCanId,1,16);
        return;

    }else{

        // A data is waiting to be sent
        if(dataPresent) return;

        frame.clear();
        ushort canid = getItem(&i, data, &data_ok);
        if(!data_ok) return;

        ushort val;
        for(; (i< data->size()) && (frame.size() <= 8) ; i++){
            val = getItem(&i, data, &data_ok);
            if(data_ok) frame.append((unsigned char) val);
            else break;
        }

        // If a valid set of data has been identified they will be sent to the driver        
        if(frame.size()){
            txCanId = canid;
            txData = frame;
            dataPresent = true;
            //emit sendToCan(canid,frame);
        }
    }

}

/**
 * This callback is called whenever a data stream is received
 * from a connected Client.
 *
 * Because a stream can contain multilple formatted frames,
 * this function unpack each frame sndind the content to the \n
 * ServerItem::handleSocketFrame() to decode a single data content.
 *
 */
void ServerItem::socketRxData()
{
    QByteArray frame;    

    if(socket->bytesAvailable()==0) return;
    QByteArray data = socket->readAll();



    // Identifies all the possible frames in the received stream
    for(int i=0; i<data.size(); i++){
        if(data.at(i) == '<') {
            frame.clear();
        }else if(data.at(i) == '>'){
            if(frame.size() > 4) {
                frame.append(' ');
                handleSocketFrame(&frame);
                frame.clear();
            }
        }else{
            frame.append(data.at(i));
        }
    }


}

/**
 * This function writes the socket data frame to ethernet
 *
 * @param data: the frame data content
 */
void ServerItem::socketTxData(QByteArray data)
{
    this->socket->write(data);
    this->socket->waitForBytesWritten(100);
    return;

}


/**
 * @brief This function receives the data coming from the CAN network.
 *
 * The Data packet received from the CAN network is forwarded to \n
 * the connected Slaves that has been registered with the canId identifier \n
 * or with the broadcast address (0).
 *
 * The Data is put in the socket packet as for the protocol:\n
 * <D> (uchar) b0 .. (uchar) b7
 *
 *
 * @param canId: this is the canId of the can message
 * @param data: this is the data content of the frame
 */
void Server::rxCanFrameHandle(ushort client_id, ushort canId, QByteArray* data){
    QByteArray frame;
    frame.append("<D ");
    frame.append(QString("%1 ").arg(canId).toLatin1());

    for(int i=0; i< 8;i++){
        if(i >= data->size()) frame.append("0 ");
        else frame.append(QString("%1 ").arg((uchar) data->at(i)).toLatin1());
    }
    frame += " > \n\r";

    // Sends to all the client matching the Receprion Acceptance filter
    for(int i =0; i< socketList.size(); i++){
        if(socketList[i]->id == client_id){
            socketList[i]->socket->write(frame);
            socketList[i]->socket->waitForBytesWritten(100);
        }
    }

}

/**
 * @brief This function receives the data coming from the CAN network.
 *
 * The Data packet received from the CAN network is forwarded to \n
 * the connected Slaves that has been registered with the canId identifier \n
 * or with the broadcast address (0).
 *
 * The Data is put in the socket packet as for the protocol:\n
 * <D> (uchar) b0 .. (uchar) b7
 *
 *
 * @param canId: this is the canId of the can message
 * @param data: this is the data content of the frame
 */
void Server::rxAsyncCanFrameHandle(ushort canId, QByteArray* data){
    QByteArray frame;
    frame.append("<A ");
    frame.append(QString("%1 ").arg(canId).toLatin1());

    for(int i=0; i< 8;i++){
        if(i >= data->size()) frame.append("0 ");
        else frame.append(QString("%1 ").arg((uchar) data->at(i)).toLatin1());
    }
    frame += " > \n\r";

    // Sends to all the client with the deviceId matching the canId &0x3F
    for(int i =0; i< socketList.size(); i++){
        if((canId & 0x3F) == (socketList[i]->rxCanId & 0x3F)){
            socketList[i]->socket->write(frame);
            socketList[i]->socket->waitForBytesWritten(100);
        }
    }

}

bool Server::getNextTxFrame(ushort* client_id, uint16_t* pRxCanId, uint16_t* pTxCanId,  QByteArray* pdata){
    static uint8_t idx =0;


    for(int i =0; i< socketList.size(); i++){
        if(idx >= socketList.size()) idx = 0;

        if(socketList[idx]->dataPresent){
            *pTxCanId = (socketList[idx]->txCanId);
            *pRxCanId = (socketList[idx]->rxCanId);
            *pdata =  (socketList[idx]->txData);
            *client_id = socketList[idx]->id;
            socketList[idx]->dataPresent = false;
            idx++;
            return true;
        }
        idx++;
    }

    return false;
}

