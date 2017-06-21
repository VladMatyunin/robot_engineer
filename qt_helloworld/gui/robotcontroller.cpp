#include "robotcontroller.h"
#include <QObject>
#include <QByteArray>
#include <QStringBuilder>
#include <QString>
#include "myudpclient.h"
#include <QTimer>
#include "robotPackets.h"
#include "QDebug"
RobotController::RobotController():QObject()
{
    client = new UDPClient(this);
    timer = new QTimer();
}

RobotController::~RobotController(){
    delete client;
    delete timer;
}

void RobotController::turnLight(){
    RemoteControlPacket *packet = getBasicPacket();
    packet->BUTTON[1] = 1;

    client->sendPacket(*packet);
}
RemoteControlPacket* RobotController::getBasicPacket(){

    RemoteControlPacket *packet = new RemoteControlPacket();
    packet->AXIS[16] = {0};
    packet->BUTTON[16] = {0};
    packet->TELEMETRY = 0.0;
    return packet;
}


/*
 * if direction is true - move forward, else move back
 */
void RobotController::movePlatformDirect(bool direction, int speed){
    RemoteControlPacket *packet = getBasicPacket();
    if (direction)
        packet->AXIS[1] = -speed;
    else
        packet->AXIS[1] = speed;
    client->sendPacket(*packet);
}


/*
 * if direction is true - move right, else move left
 */
void RobotController::movePlatformRotate(bool direction, int speed){
    RemoteControlPacket *packet = getBasicPacket();
    if (direction)
        packet->AXIS[0] = speed;
    else
        packet->AXIS[0] = -speed;
    client->sendPacket(*packet);
}

void RobotController::moveJoint(){
    RemoteControlPacket *packet = getBasicPacket();
    //packet->BUTTON[10] = 1;
    packet->AXIS[4] = -5000;
    client->sendPacket(*packet);
}

void RobotController::setFlippersUp(){
    RemoteControlPacket *packet = getBasicPacket();
    packet->BUTTON[5] = 1;
    client->sendPacket(*packet);
}


void RobotController::setFlippersDown(int realSpeed){
    RemoteControlPacket *packet = getBasicPacket();
    packet->AXIS[5] = 1;
    qDebug()<<realSpeed;
    client->sendPacket(*packet);
}

void RobotController::gripper(bool open){
    RemoteControlPacket *packet = getBasicPacket();
    if(open){
        packet->BUTTON[0] = 1;
    }
    else packet->BUTTON[3] = 1;
    client->sendPacket(*packet);
}


