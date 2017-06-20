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
#include "QFile"
UDPClient::UDPClient():QObject()
{
    m_pudp = new QUdpSocket(this);
    controller = new RobotController;
    m_pudp->bind(2424);
    robotAddress = new QHostAddress("192.168.1.11");
    connect(m_pudp,SIGNAL(connected()),this,SLOT(startTimerTask()));
    connect(m_pudp,SIGNAL(readyRead()),this,SLOT(listenRobot()));
}


void UDPClient::listenRobot(){
    QByteArray baDatagram;
    RobotController controller;
    do {
        baDatagram.resize(m_pudp->pendingDatagramSize());
        m_pudp->readDatagram(baDatagram.data(),baDatagram.size());

    }while(m_pudp->hasPendingDatagrams());
    QDataStream in(&baDatagram, QIODevice::ReadOnly);
    qDebug()<<"Got info from robot";
    writeInputToFile(&in);
}



void UDPClient::processData(bool isLight){
    QByteArray baDatagram;
    QDataStream out(&baDatagram,QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_5_2);
    RemoteControlPacket *packet = controller->turnLight();

    qDebug()<<sizeof(*packet);
    putData(out,*packet);
    m_pudp->writeDatagram(baDatagram,*robotAddress,ROBOT_PORT);
}
UDPClient::~UDPClient(){
    m_pudp->close();
    delete m_pudp;
    delete controller;
    delete robotAddress;
}



void UDPClient::startTimerTask(){
    connect(&timer, SIGNAL(timeout()), this, SLOT(sendLivePackets()));
    timer.start(1000);
}



void UDPClient::sendLivePackets(){
        QByteArray baDatagram;

        QDataStream out(&baDatagram,QIODevice::ReadWrite);
        out.setVersion(QDataStream::Qt_5_2);
        RemoteControlPacket *packet = controller->getBasicPacket();
        putData(out,*packet);
        m_pudp->writeDatagram(baDatagram,*robotAddress,ROBOT_PORT);

}


void UDPClient::putData(QDataStream &out, const RemoteControlPacket &packet){
    out.writeRawData((char*)&packet,57);

//    out.writeRawData((char*)packet.AXIS, 16*sizeof(char));
//    out.writeRawData((char*)packet.BUTTON,16*sizeof(char));
//    out << packet.TELEMETRY;
    }



void UDPClient::writeInputToFile(QDataStream *out){
    QString filename="/home/vlad/Desktop/Robotics/qt_helloworld/robot_logs/logs.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        //stream << *((char*)packet)<< endl;
    }
}
