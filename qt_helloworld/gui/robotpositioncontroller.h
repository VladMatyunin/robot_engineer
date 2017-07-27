#ifndef ROBOTPOSITIONCONTROLLER_H
#define ROBOTPOSITIONCONTROLLER_H
#include <QByteArray>
#include <QObject>
#include <QTimer>
#include "robotPackets.h"
#include "robot.h"
#define ANGLE_DELTA 182
class RobotPositionController : public QObject
{
    Q_OBJECT

int executePositionValue(int angle);
public: Robot *robot;


public:
    TelemetryPacket *positionInfo;

    void startTimerTask(int angle);
    RobotPositionController(Robot *robot);
    ~RobotPositionController();
public slots:
    void handleTelemetry(char *data);
    void rotateWaist();
    void rotateElbow();
private:
    int angle;
    int startTelemetry;
    QTimer *timer;
    bool deltaApproximateEquality(int first_telemtry, int current_telemetry, int angle_delta);

};

#endif // ROBOTPOSITIONCONTROLLER_H
