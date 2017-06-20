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
    robotAddress = new QHostAddress("10.42.0.1");

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
}



void UDPClient::processData(bool isLight){

    RemoteControlPacket *packet = controller->turnLight();
    sendPacket(*packet);
    delete packet;
}
UDPClient::~UDPClient(){
    m_pudp->close();
    delete m_pudp;
    delete controller;
    delete robotAddress;
}

void UDPClient::moveForward(){
    RemoteControlPacket *packet = controller->moveForwardPacket();
    sendPacket(*packet);
    delete packet;
}

void UDPClient::moveBack(){
    RemoteControlPacket *packet = controller->moveBackPacket();
    sendPacket(*packet);
    delete packet;
}

void UDPClient::moveLeft(){
    RemoteControlPacket *packet = controller->moveLeftPacket();
    sendPacket(*packet);
    delete packet;
}
void UDPClient::moveRight(){
    RemoteControlPacket *packet = controller->moveRightPacket();
    sendPacket(*packet);
    delete packet;
}


void UDPClient::startTimerTask(){
    connect(&timer, SIGNAL(timeout()), this, SLOT(sendLivePackets()));
    timer.start(500);
}



void UDPClient::sendLivePackets(){
        RemoteControlPacket *packet = controller->getBasicPacket();
        sendPacket(*packet);

}
void UDPClient::sendPacket(RemoteControlPacket packet){
    QByteArray baDatagram;
    QDataStream out(&baDatagram,QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_5_2);
    putData(out,packet);
    m_pudp->writeDatagram(baDatagram,*robotAddress,ROBOT_PORT);

}



void UDPClient::putData(QDataStream &out, const RemoteControlPacket &packet){
    out.writeRawData((char*)&packet,57);
}



void UDPClient::writeInputToFile(char *data){
    QString filename="/home/vladm/Desktop/robot_engineer/qt_helloworld/robot_logs/logs.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );

        stream << atoi(data)<< endl;
        stream.flush();

    }
}

void UDPClient::connectToRobot(){
    m_pudp->bind(*robotAddress,ROBOT_PORT);
    connect(m_pudp,SIGNAL(connected()),this,SLOT(startTimerTask()));
    connect(m_pudp,SIGNAL(readyRead()),this,SLOT(listenRobot()));
}
