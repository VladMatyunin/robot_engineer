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

    packet->BUTTON[1] = 1;
}
RemoteControlPacket* RobotController::getBasicPacket(){

    RemoteControlPacket *packet = new RemoteControlPacket();
    packet->AXIS[16] = {0};
    packet->BUTTON[16] = {0};
    packet->TELEMETRY = 0.0;
    return packet;
}
RemoteControlPacket *RobotController::moveForwardPacket(){
    RemoteControlPacket *packet = getBasicPacket();
    packet->AXIS[1] = -5000;
}


RemoteControlPacket *RobotController::moveBackPacket(){
    RemoteControlPacket *packet = getBasicPacket();
    packet->AXIS[1] = 5000;
}
RemoteControlPacket *RobotController::moveLeftPacket(){
    RemoteControlPacket *packet = getBasicPacket();
    packet->AXIS[0] = 16000;
}

RemoteControlPacket *RobotController::moveRightPacket(){
    RemoteControlPacket *packet = getBasicPacket();
    packet->AXIS[0] = -16000;
}
