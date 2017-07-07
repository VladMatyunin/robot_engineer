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
        controller->movePlatformDirect(-speed);
    }

    void Robot::moveR(int speed){
        controller->movePlatformRotate(speed);
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
        controller->elbowNeck(-speed);
    }
    void Robot::turnNeck(int speed){
        controller->neck(-speed);
    }


    void Robot::turnWaist(int speed){
        controller->waist(speed);
    }
    void Robot::moveWaist(int speed){
        controller->waistUpDown(speed);
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

    delete controller;
delete configuration;
}
void Robot::connectToEngineer(){
    controller->connectClient();
}


