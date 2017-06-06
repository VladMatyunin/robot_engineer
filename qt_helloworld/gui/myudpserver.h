#ifndef MYUDPSERVER_H
#define MYUDPSERVER_H
#include <QTextEdit>
#include <QtNetwork/QUdpSocket>
class MyUdpServer : public QTextEdit
{
    Q_OBJECT
private:
    QUdpSocket* m_pudp;
public:
    MyUdpServer(QWidget *pwgt=0);

private slots:
void slotSendDatagram();
};
#endif // MYUDPSERVER_H
