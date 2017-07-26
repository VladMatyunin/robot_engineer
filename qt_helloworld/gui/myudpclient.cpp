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
}


void UDPClient::listenRobot(){
    if(!isConntected){
        isConntected = true;
        emit controller->connectedToRobot();

    }
    QByteArray baDatagram;
    do {

        baDatagram.resize(m_pudp->pendingDatagramSize());
        m_pudp->readDatagram(baDatagram.data(),baDatagram.size());

    }while(m_pudp->hasPendingDatagrams());
    QDataStream in(&baDatagram, QIODevice::ReadOnly);

    do {

        char* buffer = new char[275];
        in.readRawData(buffer,275);

        if(buffer[0]==2){
            emit controller->robot->telemetryChanged(buffer);
            return;
        }else{
            delete[] buffer;
            return;}
    }while (!in.atEnd());

}



UDPClient::~UDPClient(){
    m_pudp->close();
    delete m_pudp;
    delete robotAddress;
    delete timer;
}



void UDPClient::sendPacket(RemoteControlPacket packet){
    QByteArray baDatagram;
    QDataStream out(&baDatagram,QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_5_2);
    out.writeRawData((char*)&packet,57);
    m_pudp->writeDatagram(baDatagram,*robotAddress,ROBOT_PORT);

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
    connect(m_pudp,SIGNAL(readyRead()),this,SLOT(listenRobot()));
    connect(m_pudp,SIGNAL(connected()),this,SLOT(startTimerTask()));

    startTimerTask();
}
void UDPClient::startTimerTask(){
    connect(timer, SIGNAL(timeout()), this, SLOT(sendLivePackets()));
    timer->start(300);
}


void UDPClient::sendLivePackets(){
    RemoteControlPacket *packet = controller->packet;
    sendPacket(*packet);
}

void UDPClient::disconnectFromRobot(){
    m_pudp->disconnectFromHost();
    timer->stop();
    disconnect(m_pudp,SIGNAL(readyRead()),this,SLOT(listenRobot()));
    disconnect(m_pudp,SIGNAL(connected()),this,SLOT(startTimerTask()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(sendLivePackets()));

}
