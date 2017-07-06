#ifndef MYUDPCLIENT_H
#define MYUDPCLIENT_H
#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QThread>
#include <QTimer>
#include <QDataStream>
#include <QHostAddress>
#include "robotPackets.h"
#define ROBOT_PORT 10000
class RobotController;
class UDPClient : public QObject{
    Q_OBJECT
    public slots:
        void startTimerTask();
        void sendLivePackets();
        void listenRobot();
private:
        bool isConntected = false;
    QUdpSocket *m_pudp;
    QHostAddress *robotAddress;
    void writeInputToFile(char *data);
    RobotController *controller;
    QTimer *timer;


public:
    UDPClient(RobotController *controller);
    //UDPClient();
    void putData(QDataStream &out, const RemoteControlPacket &packet);
    void processData(bool);
    void sendPacket(RemoteControlPacket packet);
    ~UDPClient();
    void connectToRobot();


};
#endif // UDPCLIENT_H
