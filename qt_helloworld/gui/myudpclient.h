#ifndef MYUDPCLIENT_H
#define MYUDPCLIENT_H
#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <robotcontroller.h>
#include <QThread>
#include <QTimer>
class UDPClient : public QObject{
    Q_OBJECT
    public slots:
        void sendLivePackets();
private:
    QUdpSocket *m_pudp;
    RobotController *controller;
    QThread *thread;
    QTimer timer;


public:
    UDPClient();

    void processData(bool);
    ~UDPClient();

};
#endif // UDPCLIENT_H
