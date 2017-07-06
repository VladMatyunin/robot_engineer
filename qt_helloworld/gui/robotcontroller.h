#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include <QByteArray>
#include <QObject>
#include <QTimer>
#include "robotPackets.h"
#include "robot.h"
class UDPClient;
class RobotController : public QObject
{
    Q_OBJECT
public: Robot *robot;
public: UDPClient *client;
void startTimerTask();
void sendLivePackets();

signals:
    void connectedToRobot();

public:
    RemoteControlPacket *packet;
    QTimer *timer;
    RobotController(Robot *robot);
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

    void stopElbowNeck();
    void stopNeck();
    void stopWaist();
    void stopWaistUpDown();
    void stopPlatformD();
    void stopPlatformR();
    void stopGripper();
    void stopFlippers();

    void connectClient();


};

#endif // ROBOTCONTROLLER_H
