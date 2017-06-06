#include "myudpserver.h"
#include "QTimer"
#include "QDateTime"
#include "QtNetwork/QUdpSocket"
#include "QTextEdit"
#include "QHostAddress"
#include "QDataStream"
#include "QByteArray"
#include "QDataStream"


MyUdpServer::MyUdpServer(QWidget *pwgt): QTextEdit(pwgt)
{
    setWindowTitle("UDP_Server");
    m_pudp = new QUdpSocket(this);
    QTimer* ptimer = new QTimer(this);
    ptimer->start();
    show();
    //connect(ptimer, SIGNAL(timeout()), SLOT(slotSendDatagram()));
}
void MyUdpServer::slotSendDatagram(){
    QByteArray baDatagram;
    do {
        baDatagram.resize(m_pudp->pendingDatagramSize());
        m_pudp->readDatagram(baDatagram.data(),baDatagram.size());

    }while(m_pudp->hasPendingDatagrams());
    QDateTime dateTime;
    QDataStream in(&baDatagram, QIODevice::ReadOnly);
    in >> dateTime;
    append("Received:"+dateTime.toString());
}
