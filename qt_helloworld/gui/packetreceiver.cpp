#include "packetreceiver.h"

PacketReceiver::PacketReceiver(QUdpSocket *s, RobotController *c, QHostAddress *adr)
{
    this->controller = c;
    this->m_pudp = s;
    this->address = adr;
}
PacketReceiver::receive(){
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

            TelemetryPacket *telPacket = new TelemetryPacket();
            telPacket = (TelemetryPacket*)(buffer);
            emit controller->robot->telemetryChanged(*telPacket);
            return;
        }else{
        delete[] buffer;
            return;}
    }while (!in.atEnd());

 //   qDebug()<<"Got info from robot";
}
