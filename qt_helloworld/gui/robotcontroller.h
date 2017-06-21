#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include <QByteArray>
#include <QObject>
#include <QTimer>
#include "robotPackets.h"
class UDPClient;
class RobotController : public QObject
{
    Q_OBJECT

UDPClient *client;
void startTimerTask();
void sendLivePackets();
public:

    QTimer *timer;
    RobotController();
    ~RobotController();
    void turnLight();

    RemoteControlPacket * getBasicPacket();
    void movePlatformDirect(bool, int speed);
    void movePlatformRotate(bool, int speed);
    void moveJoint();
    void setFlippersUp();
    void setFlippersDown(int realSpeed);
    void gripper(bool open);
};

#endif // ROBOTCONTROLLER_H
