#include "robot.h"
#include <robotcontroller.h>
#include <QDebug>
Robot::Robot()
{
    controller = new RobotController();
    configuration = new RobotConfiguration(5000,16000,false);
}
    void Robot::moveBack(int speed){
        controller->movePlatformDirect(getRealSpeed(speed));
    }
    void Robot::moveForward(int speed){
        controller->movePlatformDirect(getRealSpeed(speed));
    }
    void Robot::moveLeft(int speed){
        controller->movePlatformRotate(getRealSpeed(speed));
    }
    void Robot::moveRight(int speed){
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
        controller->elbowNeck(getRealSpeed(speed));
    }
    void Robot::turnNeck(int speed){
        qDebug()<<"SEEEND";
        controller->neck(getRealSpeed(speed));
    }

    int Robot::getRealSpeed(int speed){
        int realSpeed = 0;
        realSpeed = (speed-50)*150;
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
        case -1: controller->gripper(false);
        default: controller->stopGripper();
            break;
        }
    }


Robot::~Robot(){
    delete configuration;
    delete controller;
}

