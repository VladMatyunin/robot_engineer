#ifndef PACKETRECEIVER_H
#define PACKETRECEIVER_H
#define ROBOT_PORT 10000
#include <QThread>
#include <QUdpSocket>
#include <robotcontroller.h>
class PacketReceiver :QObject
{
    Q_OBJECT
public:
    PacketReceiver(QUdpSocket *,RobotController*, QHostAddress *);
public slots:
    void receive();
private:
    RobotController *controller;
    QUdpSocket *m_pudp;
    QHostAddress *address;
};

#endif // PACKETRECEIVER_H
