#include "robot.h"
#include <robotcontroller.h>
#include <QDebug>
#include <robotPackets.h>
#include <QObject>
Robot::Robot():QObject()
{
    controller = new RobotController(this);
    configuration = new RobotConfiguration(5000,16000,false);
}

    void Robot::moveD(int speed){
        //minus because forward is <(lt)0, back is >(gt)0
        controller->movePlatformDirect(-getRealSpeed(speed));
    }

    void Robot::moveR(int speed){
        controller->movePlatformRotate(getRealSpeed(speed));
    }
    void Robot::turnLight(){
        controller->turnLight();
    }

    void Robot::flippers(int direction){
        switch (direction){
        case 1: controller->setFlippersUp(); break;
        case -1: controller->setFlippersDown(); break;
        default: controller->stopFlippers(); break;
        }
    }

    void Robot::openGripper(){
        controller->gripper(true);
    }

    void Robot::closeGripper(){
        controller->gripper(false);
    }
    RobotConfiguration* Robot::getConfiguration(){
        return configuration;
    }
    void Robot::turnElbowAndNeck(int speed){
        controller->elbowNeck(-getRealSpeed(speed));
    }
    void Robot::turnNeck(int speed){
        controller->neck(-getRealSpeed(speed));
    }

    int Robot::getRealSpeed(int speed){
        int realSpeed = 0;
        realSpeed = (speed-50)*200;
        qDebug()<<realSpeed;
        return realSpeed;
    }
    void Robot::turnWaist(int speed){
        controller->waist(getRealSpeed(speed));
    }
    void Robot::moveWaist(int speed){
        controller->waistUpDown(getRealSpeed(speed));
    }

    void Robot::gripper(int direction){
        switch (direction) {
        case 1: controller->gripper(true);

            break;
        case -1: controller->gripper(false); break;
        default: controller->stopGripper();
            break;
        }
    }

void Robot::stopAll(){
    controller->stopElbowNeck();
    controller->stopNeck();
    controller->stopWaist();
    controller->stopWaistUpDown();
    controller->stopPlatformD();
    controller->stopPlatformR();
    controller->stopFlippers();
    controller->stopGripper();
}

Robot::~Robot(){
    delete configuration;
    delete controller;
}


