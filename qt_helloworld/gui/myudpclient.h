#ifndef MYUDPCLIENT_H
#define MYUDPCLIENT_H
#include <QObject>
#include <QtNetwork/QUdpSocket>
class UDPClient : public QObject{
    Q_OBJECT

private:
    QUdpSocket *m_pudp;
public slots:
       void processData(bool);
public:
    UDPClient();

};
#endif // UDPCLIENT_H
