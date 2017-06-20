#include "robotcontroller.h"
#include <QObject>
#include <QByteArray>
#include <QStringBuilder>
#include <QString>


RobotController::RobotController():QObject()
{
    
}

RemoteControlPacket* RobotController::turnLight(){
    RemoteControlPacket *packet = getBasicPacket();
    packet->BUTTON[0] = 51;
    packet->BUTTON[1] = 52;
}
RemoteControlPacket* RobotController::getBasicPacket(){

    RemoteControlPacket *packet = new RemoteControlPacket();
    packet->AXIS[16] = {0};
    packet->BUTTON[16] = {0};
    packet->TELEMETRY = 0.0;
    return packet;
}
