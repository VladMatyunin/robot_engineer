#include "packetsender.h"

PacketSender::PacketSender(QUdpSocket *s, RobotController *c, QHostAddress *adr)
{
    this->m_pudp = s;
    this->controller = c;
    this->address = adr;
}
PacketSender::sendPackets(){
        RemoteControlPacket *packet = controller->packet;
        QByteArray baDatagram;
        QDataStream out(&baDatagram,QIODevice::ReadWrite);
        out.setVersion(QDataStream::Qt_5_2);
        out.writeRawData((char*)&packet,57);
        m_pudp->writeDatagram(baDatagram, *address, ROBOT_PORT);
}

