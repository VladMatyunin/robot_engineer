#include "robot.h"
#include <robotcontroller.h>

Robot::Robot()
{
    controller = new RobotController();
    configuration = new RobotConfiguration(5000,16000,false);
}
    void Robot::moveBack(){
        controller->movePlatformDirect(false, configuration->platformForwardSpeed);
    }
    void Robot::moveForward(){
        controller->movePlatformDirect(true, configuration->platformForwardSpeed);
    }
    void Robot::moveLeft(){
        controller->movePlatformRotate(false, configuration->platformRotateSpeed);
    }
    void Robot::moveRight(){
        controller->movePlatformRotate(true, configuration->platformRotateSpeed);
    }
    void Robot::turnLight(){
        controller->turnLight();
    }

    void Robot::flippersUp(){
        controller->setFlippersUp();
    }
    void Robot::flippersDown(int speed){
        int realSpeed = 0;
        if (speed>50) realSpeed = speed*60;
        else{
            speed-=50;
            realSpeed = speed*60;
        }
        controller->setFlippersDown(speed);
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
        controller->neck(getRealSpeed(speed));
    }

    int Robot::getRealSpeed(int speed){
        int realSpeed = 0;
        if (speed>50) realSpeed = speed*320;
        else{
            speed-=50;
            realSpeed = speed*320;
        }
        return realSpeed;
    }
    void Robot::turnWaist(int speed){
        controller->waist(getRealSpeed(speed));
    }
    void Robot::moveWaist(int speed){
        controller->waistUpDown(getRealSpeed(speed));
    }


Robot::~Robot(){
    delete configuration;
    delete controller;
}

