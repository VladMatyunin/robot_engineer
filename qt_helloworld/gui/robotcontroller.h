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
    RemoteControlPacket *packet;
    QTimer *timer;
    RobotController();
    ~RobotController();
    void turnLight();

    RemoteControlPacket * getBasicPacket();
    void movePlatformDirect(int speed);
    void movePlatformRotate(int speed);
    void setFlippersUp();
    void setFlippersDown();
    void gripper(bool open);
    void elbowNeck(int speed);
    void neck(int speed);
    void waist(int speed);
    void waistUpDown(int speed);
    void stopGripper();
    void stopFlippers();
};

#endif // ROBOTCONTROLLER_H
