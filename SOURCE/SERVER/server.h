#ifndef SERVER_H
#define SERVER_H

/*!
 * \defgroup  interfaceModule Ethernet Interface Module.
 *
 * This Module implements the communication with the Clients of the Can Bus.
 *
 *
 *
 * # DEVICE DRIVER OVERVIEW
 *
 * This module implements a Server Socket TcpIp based communication,\n
 * in order to let Client applications to send data frames on the CAN network.
 *
 * The server allows the connection with multi clients at the address:
 *
 * - IP: 127.0.0.1 (local Host);
 * - PORT: 10001
 *
 * The Client that needs to send data into the CAN Network shall:
 * - Connect the server at the IP&PORT;
 * - Set the Acceptance filter mask and the filter address;
 * - Send and receive data to/from CAN bus.
 *
 *  NOTE: after connection, the Acceptance filter is closed and no data can be received.
 *
 * # PROTOCOL DESCRIPTION
 *
 *  There are two only command frames:
 *  - Acceptance Filter frame format;
 *  - Can Data frame format;
 *
 *  Every frame is in ascii format so it can be easily monitored
 *
 *  ## ACCEPTANCE FILTER FRAME FORMAT
 *
 *  The Client need to open a Point to Point  Acceptance filter: the filter
 *  is in the form of a address range: filter_address_low, filter_address_high.
 *
 *  The rule to accept a CAN frame with a given canId address is:
 *
 *
 *      Acceptance Rule: (canId >= filter_address_low ) && (canId <= filter_address_high )
 *
 *  The Acceptance Filter data format is:
 *
 *
 *       <F filter_address_low filter_address_high >
 *
 *  Where
 *  - '<' and '>' are frame delimiters
 *  - F: is the frame type identifier;
 *  - filter_mask: is the 16 bit filter mask;
 *  - filter_address: is the 16 bit filter address;
 *
 *
 *      NOTE: space characters are ignored for the frame syntax;
 *
 *  The address arguments can be:
 *  - Decimal format: example, 1356;
 *  - Hexadecimal format: example, 0x1345
 *
 *  The Acceptance filter workflow is:
 *  - Client sends <F filter_address_low filter_address_high >
 *  - Server answer replying the frame: <F filter_address_low filter_address_high >
 *
 *
 *  ## CAN DATA FRAME FORMAT
 *
 *  The Client can send data to the BUS using the Can Data Frame format:
 *
 *       <D B0 B1 .. B7>
 *
 *  Where
 *  - '<' and '>' are frame delimiters
 *  - D: is the frame type identifier;
 *  - B0 to B7: are 8 bit can data content.
 *
 *
 *      NOTE: space characters are ignored for the frame syntax;
 *      NOTE: the data lenght can be lower than 8. In this case
 *      the can frame is filled with 0;
 *      NOTE: if the data lenght should be greater than 8, the data will be truncated to 8.
 *
 *  The can data content B0 to B7 can be of the following format:
 *  - Decimal format: example, 125;
 *  - Hexadecimal format: example, 0xCC
 *
 * ## CAN DATA RECEPTION
 *
 * When a data frame is received from the CAN bus,\n
 * the application forwards the frame to all the connected Clients \n
 * whitch the frame canId matches with the acceptance rule:
 * - (canId & filter_mask) == filter_address;
 *
 *
 *
 */

#include <QObject>

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkInterface>



/**
 * @brief This is the Client socket class
 *
 * For every  Connected Client the Application creates
 * an item of this class, handling the data exchange from
 * the client and the application.
 *
 *
 * \ingroup interfaceModule
 */
class ServerItem: public QObject
{
     Q_OBJECT

public:

    explicit ServerItem(){};
    ~ServerItem(){};

signals:
    void itemDisconnected(ushort id); //!< Signal of the client disconnection event
    void sendToClient(QByteArray data);//!< Signal to send data to the TcpIp socket for data transmission to CLient

public slots:

    void disconnected(); //!< Socket disconnection event slot
    void socketError(QAbstractSocket::SocketError error);//!< Socket error event slot
    void socketRxData();//!< Socket data received event slot
    void socketTxData(QByteArray);//!< Socket data to be transmitted

public:
    QTcpSocket* socket; //!< Pointer to the socket;
    ushort id;          //!< Identifier of the socket client
    ushort rxCanId;     //!< canId di ricezione

    uint16_t txCanId;
    QByteArray txData;
    bool dataPresent;

private:
    void handleSocketFrame(QByteArray* data);//!< Ethernet frame decoding function
    ushort getItem(int* index, QByteArray* data, bool* data_ok);

};

/**
 * @brief This class handle the whole set of connected clients
 *
 * The class handle the queue of the connected class;
 *
 * The class forwards the received can frame to the Client
 * registered with the address of the Can frame sender;
 *
 * The class is responsible to erase a disconnected client socket.
 *
 * \ingroup interfaceModule
 */
class Server : public QTcpServer
{
    Q_OBJECT

public:

    explicit Server(QString ipaddress, int port);
    ~Server();

    static const long _DEFAULT_TX_TIMEOUT = 5000;    //!< Default timeout in ms for tx data
    bool Start(void);   //! Starts listening the server on the IP&Port
    bool getNextTxFrame(ushort* client_id, uint16_t* pRxCanId, uint16_t* pTxCanId,  QByteArray* pdata); //! Return the next frame to be sent
    void rxCanFrameHandle(ushort client_id, ushort canId, QByteArray* data); //!< Handles the can rx/tx data to be sent to the client
    void rxAsyncCanFrameHandle(ushort canId, QByteArray* data); //!<  Handles the Asynch data to be sent to the client

signals:

public slots:
    void disconnected(ushort id); //!< Disconnection slot coming from the internal socket    

protected:
    void incomingConnection(qintptr socketDescriptor) override; //!< Incoming connection slot


private:

    QList<ServerItem*>  socketList;    //!< List of Sockets
    QHostAddress        localip;       //!< Address of the local server
    quint16             localport;     //!< Port of the local server
    ushort              idseq;


};


#endif // SERVER_H
