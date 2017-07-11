#ifndef PACKETSENDER_H
#define PACKETSENDER_H

#define ROBOT_PORT 10000
#include <QThread>
#include <QUdpSocket>
#include <robotcontroller.h>
#include <QTimer>
class PacketSender :QObject
{
    Q_OBJECT
private:
    RobotController *controller;
    QUdpSocket *m_pudp;
    QHostAddress *address;

public:
    PacketSender(QUdpSocket *,RobotController*, QHostAddress *);
public slots:
    void sendPackets();
};

#endif // PACKETSENDER_H
