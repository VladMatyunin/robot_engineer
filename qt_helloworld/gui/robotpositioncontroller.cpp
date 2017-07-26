#include "robotpositioncontroller.h"
#include <QObject>
#include <QByteArray>
#include <QStringBuilder>
#include <QString>
#include "myudpclient.h"
#include "robotPackets.h"
#include "QDebug"
#include "robot.h"
RobotPositionController::RobotPositionController(Robot *r):QObject()
{
    robot = r;

}

RobotPositionController::~RobotPositionController(){
    delete positionInfo;
}

void RobotPositionController::handleTelemetry(char *data){
    positionInfo = (TelemetryPacket*) data;
    delete data;
}


void RobotPositionController::rotateWaist(int angle){
    int c = executePositionValue(angle);
//    while (positionInfo->M_DATA[5].POSITION<executePositionValue(angle)) {
//        robot->turnWaist(robot->configuration->waistSpeed);
//    }
//    robot->stopAll();
}

int RobotPositionController::executePositionValue(int angle){
    return ((60000*angle)/360);
}
