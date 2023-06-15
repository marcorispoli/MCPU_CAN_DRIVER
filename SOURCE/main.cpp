#define MAIN_CPP

#include "application.h"
#include "applog.h"

#include <QFile>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    appLog(argc, argv, "C:/OEM/Gantry/Log/mcpu_candriver.log", debugWindow::debugMessageHandler);

    // Create the Window Log if necessary
    if(appLog::isWindow){
        WINDOW = new debugWindow();
        WINDOW->show();
    }

    SYSCONFIG = new sysConfig(configFile::_CFG_READONLY);
    if(!SYSCONFIG->isFormatCorrect()) {
        qDebug() << " WRONG CONFIGURATION FILE FORMAT!";
        exit(1);
    }

    SERVER = new Server(SYSCONFIG->getParam<QString>(SYS_CAN_PROCESS_PARAM,SYS_CAN_IP),SYSCONFIG->getParam<uint>(SYS_CAN_PROCESS_PARAM,SYS_CAN_PORT));
    INTERFACE = new Interface();

    bool loopback = false ;
    CAN = new canDriver();
    if(appLog::options.contains("-loopback")) loopback = true;
    CAN->driverOpen(Application::CAN_BAUDRATE, loopback);


    INTERFACE->Start();
    SERVER->Start();
    return a.exec();
}
