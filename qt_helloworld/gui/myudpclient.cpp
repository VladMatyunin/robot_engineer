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
    timer.start(5000);
}
void UDPClient::processData(bool isLight){
    QByteArray baDatagram;
    QDataStream out(&baDatagram,QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_5_2);
    RemoteControlPacket *packet = controller->turnLight();

    qDebug()<<sizeof(*packet);
    putData(out,*packet);
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
        RemoteControlPacket *packet = controller->getBasicPacket();
        putData(out,*packet);
        m_pudp->writeDatagram(baDatagram,QHostAddress::LocalHost,2425);

}
void UDPClient::putData(QDataStream &out, const RemoteControlPacket &packet){
    out.writeRawData((char*)&packet,57);

//    out.writeRawData((char*)packet.AXIS, 16*sizeof(char));
//    out.writeRawData((char*)packet.BUTTON,16*sizeof(char));
//    out << packet.TELEMETRY;
    }
