#ifndef ROBOTPOSITIONCONTROLLER_H
#define ROBOTPOSITIONCONTROLLER_H
#include <QByteArray>
#include <QObject>
#include <QTimer>
#include "robotPackets.h"
#include "robot.h"

class RobotPositionController : public QObject
{
    Q_OBJECT

int executePositionValue(int angle);
public: Robot *robot;


public:
    TelemetryPacket *positionInfo;
    void rotateWaist(int angle);

    RobotPositionController(Robot *robot);
    ~RobotPositionController();
public slots:
    void handleTelemetry(char *data);


};

#endif // ROBOTPOSITIONCONTROLLER_H
