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
    void Robot::turnWaist(){
        controller->moveJoint();
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

Robot::~Robot(){
    delete configuration;
    delete controller;
}

