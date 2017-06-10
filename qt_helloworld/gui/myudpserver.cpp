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
    m_pudp->bind(2425);
    QTimer* ptimer = new QTimer(this);
    ptimer->start();
    show();
    connect(m_pudp,SIGNAL(readyRead()),SLOT(slotSendDatagram()));
    //connect(ptimer, SIGNAL(timeout()), SLOT(slotSendDatagram()));
}
void MyUdpServer::slotSendDatagram(){
    QByteArray baDatagram;
    do {
        baDatagram.resize(m_pudp->pendingDatagramSize());
        m_pudp->readDatagram(baDatagram.data(),baDatagram.size());

    }while(m_pudp->hasPendingDatagrams());
    QDataStream in(&baDatagram, QIODevice::ReadOnly);
    char* isLight;
    in >> isLight;
    append(isLight);
}
