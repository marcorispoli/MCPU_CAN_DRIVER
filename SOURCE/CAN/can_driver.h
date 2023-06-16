#ifndef VSCAN_CAN_DRIVER_H
#define VSCAN_CAN_DRIVER_H

/*!
 * \defgroup  candriverModule CAN Driver Module.
 *
 * This Module implements the transmission and reception activity
 * with the CAN bus.
 *
 * # DEVICE DRIVER OVERVIEW
 *
 * This Module is based on the vs_can_api.dll library interface \n
 * that allows to handle the VSCAN/USB-CAN Plus device converter.
 *
 * In order to properly connect the Converter, the Module device driver shall be installed in Windows OS
 * and the setup procedures shall be completed.
 * See the [VSCAN Manual](https://www.vscom.de/download/multiio/others/info/VSCAN_Manual.pdf) for details.
 *
 * The module basically sends can frame coming from Processes inside the PC to the CAN BUS,
 * and route the CAN BUS frames to the Process sender.
 * There are two subject in the communication:
 * - The Process connected to the TCP/IP server socket;
 * - The remote device connected through the CAN bus;
 *
 * Every process connected is registered with only one reception address: this address rapresent the Point to Point address;
 *
 * The module, every 1ms polls the connected process in order to send a P2P frame:
 * - when a P2P frame is sent, no more frame will be sent until a frame matching the P2P address of the sender is received.
 * - if the answer is not received in 5ms, an error frame is sent back to the sender;
 *
 * When a P2P exchange completes, the next P2P frame will be fetched from another connected process different from the previous one,
 * to guarantee that all the connected process can have the same priority.
 *
 * In case a received frame with an address not matching the expected address should be received,
 * it will be forwarded as an ASYNC frame to all the connected processes wich the lower 7 bit of the P2P address
 * should match the lower 7 bit of the received address.
 * The lower 7 bit should corrispond to a unique Device ID in the Network.
 *
 *
 * The Process can only send point to point frames and receive point to point answer or an asynch frame.
 * The Remote device shall answer to a point to point frame
 * The module basically provides two communication types:
 * - Point to point data exchange: The sender Process can only send Point to Point frames and receive a point to point answer or an Asynch frame;
 * - Asynch data frame: ;
 *
 *
 *
 * The module every millisecond polls the CAN BUS reception for incoming frame
 * and sends a frame coming from the
 *
 * The Device Gets data coming from the Ethernet Server interface then forwards them to the CAN network and viceversa.
 *
 *  NOTE: the can data format is always STANDARD 11bit address.
 *  The byte in the frame are always 8. The bytes not used are set to 0.
 *
 * The Driver can be opened in normal mode or loopback mode:
 * - When in loopback mode, the data driver receives also the data sent.
 *
 *
 * # INTERFACE FUNCTIONS
 *
 * The Driver implements the following functions:
 * - canDriver::driverOpen(): opens the connection with the system device driver;
 * - canDriver::driverClose(): close the connection with the system device driver;
 * - canDriver::sendOnCanSlot(): slot function that sends the data on the CAN bus
 * - canDriver::receivedCanFrame(): signal function emitted when a valid frame is received from the CAN bus;
 *
 *
 *
 */
#include <QTimer>
#include <QTimerEvent>

typedef void VOID;
typedef char CHAR;
typedef unsigned long DWORD;
typedef unsigned char UCHAR;
typedef unsigned short USHORT;
typedef unsigned long ULONG;
#include "vs_can_api.h"

/**
 * @brief This is the class implementing the Can Driver Interface
 *
 * \ingroup candriverModule
 */
class canDriver: public QObject
{
   Q_OBJECT
   public:

   canDriver();
   ~canDriver(){driverClose();};

    static const unsigned char VSCAN_NUM_MESSAGES = 10; //!< Max number of quesued can frames


   /// This enumeration defines the Can Bauderate
   typedef enum{
        _CAN_1000K = 0,
        _CAN_800K,
        _CAN_500K,
        _CAN_250K,
        _CAN_125K,
        _CAN_100K,
        _CAN_50K,
        _CAN_20K
    }_CanBR;

    void driverClose(void); //!< Close the communication wioth the System Driver
    bool driverOpen(_CanBR BR, bool loopback); //!< Open the communication with the System Driver

    inline bool isDeviceOpen(void){return deviceOpen;}
    inline uint8_t getApiMaj(void){return version.Major;}
    inline uint8_t getApiMin(void){return version.Minor;}
    inline uint8_t getApiSub(void){return version.SubMinor;}
    inline uint32_t getHWSn(void){return hwparam.SerialNr;}
    inline uint8_t getHWrev(void){return hwparam.HwVersion;}
    inline uint8_t getHWsrev(void){return hwparam.SwVersion;}


signals:
    void receivedCanFrame(ushort id, QByteArray data); //!< Signal emitted when a CAN frame is received
    void transmittedCanFrame(ushort id, QByteArray data); //!< Signal emitted when a CAN frame is transmitted

public slots:


private slots:
    void canTimerEvent(void);   //!< Timer scheduled to read the queue of the received messages

private:
    bool deviceOpen;
    VSCAN_API_VERSION   version;    //!< System Driver Api Version
    VSCAN_HWPARAM       hwparam;    //!< System Driver Hardware Version
    VSCAN_HANDLE        handle;     //!< Handle of the driver
    VSCAN_MSG           rxmsgs[VSCAN_NUM_MESSAGES]; //!< Array of the received Can Frames
    DWORD               rxmsg; //!< Number of received frames from CAN

    ushort rxCanId; //!< canId of the pending can message
    QByteArray rxCanData; //!< Data of the can frame

    QTimer canTimer;
    bool   rxEvent;
    uint8_t rxClientId;

    void printErrors(void);
    void canSendFrame(void); //!< Sends on the CAN bus
    QByteArray txData;
    uint16_t txCanId;


};

#endif // VSCAN_CAN_DRIVER_H
