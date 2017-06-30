#include "robotcontroller.h"
#include <QObject>
#include <QByteArray>
#include <QStringBuilder>
#include <QString>
#include "myudpclient.h"
#include <QTimer>
#include "robotPackets.h"
#include "QDebug"
#include "robot.h"
RobotController::RobotController(Robot *r):QObject()
{
    robot = r;
    client = new UDPClient(this);
    timer = new QTimer();
    packet = getBasicPacket();
}

RobotController::~RobotController(){
    delete client;
    delete timer;
    delete packet;
    delete robot;
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
 * sets the AXIS[1] speed to @speed, this moves platform
 */
void RobotController::movePlatformDirect(int speed){
    packet->AXIS[1] = speed;
}



void RobotController::movePlatformRotate(int speed){
    packet->AXIS[0] = speed;
}

void RobotController::setFlippersUp(){
    packet->AXIS[5] = 1;

}


void RobotController::setFlippersDown(){
    packet->BUTTON[5] = 1;
}

/*
 * if open = true, then open gripper,
 * else close
 */
void RobotController::gripper(bool open){
    if(open){
        packet->BUTTON[0] = 1;
    }
    else packet->BUTTON[3] = 1;
}

void RobotController::neck(int speed){
    packet->AXIS[4] = speed;
    packet->BUTTON[10] = 1;
}
void RobotController::elbowNeck(int speed){
    packet->AXIS[4] = speed;

}

void RobotController::waist(int speed){
    packet->BUTTON[9] = 1;
    packet->AXIS[0] = speed;
}

void RobotController::waistUpDown(int speed){
    packet->BUTTON[9] = 1;
    packet->AXIS[1] = speed;
}


void RobotController::stopWaist(){
    packet->BUTTON[9] = 0;
    packet->AXIS[0] = 0;
}
void RobotController::stopWaistUpDown(){
    packet->BUTTON[9] = 0;
    packet->AXIS[1] = 0;
}
void RobotController::stopPlatformD(){
    packet->AXIS[1] = 0;
}
void RobotController::stopPlatformR(){
    packet->AXIS[0] = 0;
}

void RobotController::stopElbowNeck(){
    packet->AXIS[4] = 0;
    packet->BUTTON[10] = 0;
}

void RobotController::stopNeck(){
    packet->AXIS[4] = 0;
}

void RobotController::stopFlippers(){
    packet->BUTTON[5] = 0;
    packet->AXIS[5] = 0;
}
void RobotController::stopGripper(){
    packet->BUTTON[0] = 0;
    packet->BUTTON[3] = 0;
}
