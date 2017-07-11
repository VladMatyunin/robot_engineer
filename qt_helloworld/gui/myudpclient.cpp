#include <QtNetwork/QUdpSocket>
#include "myudpclient.h"
#include "QTimer"
#include "QDateTime"
#include "QtNetwork/QUdpSocket"
#include "QTextEdit"
#include "QHostAddress"
#include "QDataStream"
#include "QByteArray"
#include "QDebug"
#include "QThread"
#include "QTimer"
#include "QFile"
#include "robotcontroller.h"
#include "QUdpSocket"
UDPClient::UDPClient(RobotController *controller):QObject()
{
    m_pudp = new QUdpSocket(this);
    robotAddress = new QHostAddress("10.42.0.1");
    this->controller = controller;
    timer = new QTimer();
    QThread *threadSender = new QThread();
    QThread *threadReceiver = new QThread();
    receiver->moveToThread(threadReceiver);
    sender->moveToThread(threadSender);
    receiver = new PacketReceiver(m_pudp,this->controller,robotAddress);
    sender = new PacketSender(m_pudp,this->controller,robotAddress);

}






UDPClient::~UDPClient(){
    m_pudp->close();
    delete m_pudp;
    delete robotAddress;
    delete timer;
    delete sender,receiver;
}


void UDPClient::connectToRobot(){
    m_pudp->bind(*robotAddress,ROBOT_PORT);
    connect(m_pudp,SIGNAL(readyRead()),receiver,SLOT(receive());
    connect(m_pudp,SIGNAL(connected()),this,SLOT(startTimerTask()));

    startTimerTask();
}
void UDPClient::startTimerTask(){
    connect(timer, SIGNAL(timeout()), sender, SLOT(sendPackets());
    timer->start(300);
}

void UDPClient::disconnectFromRobot(){
    m_pudp->disconnectFromHost();
    timer->stop();
    disconnect(m_pudp,SIGNAL(readyRead()),receiver,SLOT(receive());
    disconnect(m_pudp,SIGNAL(connected()),this,SLOT(startTimerTask()));
    disconnect(timer, SIGNAL(timeout()), sender, SLOT(sendPackets());


}
