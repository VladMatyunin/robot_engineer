#ifndef MYUDPCLIENT_H
#define MYUDPCLIENT_H
#include <QObject>
#include <QtNetwork/QUdpSocket>
class UDPClient : public QObject{
    Q_OBJECT

private:
    QUdpSocket *m_pudp;


public:
    UDPClient();
       void processData(bool);
};
#endif // UDPCLIENT_H
