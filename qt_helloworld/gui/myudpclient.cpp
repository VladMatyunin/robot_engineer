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

UDPClient::UDPClient():QObject()
{
    m_pudp = new QUdpSocket(this);
    m_pudp->bind(2424);
}
void UDPClient::processData(bool isLight){
    QByteArray baDatagram;
    QDataStream out(&baDatagram,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    QDateTime dt = QDateTime::currentDateTime();
    //qDebug()<<"Sent:"+dt.toString();
    out <<dt;
    m_pudp->writeDatagram(baDatagram,QHostAddress::LocalHost,2424);
}
