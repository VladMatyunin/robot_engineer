#ifndef MYUDPCLIENT_H
#define MYUDPCLIENT_H
#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <robotcontroller.h>
#include <QThread>
#include <QTimer>
#include <QDataStream>
#include <QHostAddress>
#define ROBOT_PORT 10000
class UDPClient : public QObject{
    Q_OBJECT
    public slots:
        void startTimerTask();
        void sendLivePackets();
        void listenRobot();
private:
    QUdpSocket *m_pudp;
    RobotController *controller;
    QThread *thread;
    QTimer timer;
    QHostAddress *robotAddress;
    void writeInputToFile(char *data);
    void sendPacket(RemoteControlPacket packet);



public:
    UDPClient();
    void putData(QDataStream &out, const RemoteControlPacket &packet);
    void processData(bool);
    ~UDPClient();
    void connectToRobot();
    void moveForward();
    void moveBack();
    void moveLeft();
    void moveRight();

};
#endif // UDPCLIENT_H
