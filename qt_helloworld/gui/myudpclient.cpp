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
#include "robotcontroller.h"
#include "QThread"
#include "QTimer"
UDPClient::UDPClient():QObject()
{
    m_pudp = new QUdpSocket(this);
    controller = new RobotController;
    m_pudp->bind(2424);
    connect(&timer, SIGNAL(timeout()), this, SLOT(sendLivePackets()));
    timer.start(1000);
}
void UDPClient::processData(bool isLight){
    QByteArray baDatagram;
    QDataStream out(&baDatagram,QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_5_2);
    QByteArray array = controller->turnLight();
    out<<array.data();
    m_pudp->writeDatagram(baDatagram,QHostAddress::LocalHost,2425);
}
UDPClient::~UDPClient(){
    m_pudp->close();
    delete m_pudp;
    delete controller;
}

void UDPClient::sendLivePackets(){
        QByteArray baDatagram;
        QDataStream out(&baDatagram,QIODevice::ReadWrite);
        out.setVersion(QDataStream::Qt_5_2);
//        QByteArray array = controller->getBasicPacket();
        out<<controller->getBasicPacket();
//        qDebug()<<array.data();
        m_pudp->writeDatagram(baDatagram,QHostAddress::LocalHost,2425);

}
