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
    packet = getBasicPacket();
}

RobotController::~RobotController(){
    delete client;
    delete timer;
    delete packet;
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
void RobotController::movePlatformDirect(int speed){
    packet->AXIS[1] = speed;
}


/*
 * if direction is true - move right, else move left
 */
void RobotController::movePlatformRotate(int speed){
    packet->AXIS[0] = speed;
}

void RobotController::setFlippersUp(){
    packet->BUTTON[5] = 1;
}


void RobotController::setFlippersDown(){
    packet->AXIS[5] = 1;
}

void RobotController::gripper(bool open){
    if(open){
        packet->BUTTON[0] = 1;
    }
    else packet->BUTTON[3] = 1;
}

void RobotController::neck(int speed){
    packet->AXIS[4] = speed;
}
void RobotController::elbowNeck(int speed){
    packet->AXIS[4] = speed;
    packet->BUTTON[10] = 1;
}

void RobotController::waist(int speed){
    packet->BUTTON[9] = 1;
    packet->AXIS[0] = speed;
}

void RobotController::waistUpDown(int speed){
    packet->BUTTON[9] = 1;
    packet->AXIS[1] = speed;
}
void RobotController::stopFlippers(){
    packet->BUTTON[5] = 0;
    packet->AXIS[5] = 0;
}
void RobotController::stopGripper(){
    packet->BUTTON[0] = 0;
    packet->BUTTON[3] = 0;
}
