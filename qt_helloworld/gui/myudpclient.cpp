#include <QtNetwork/QUdpSocket>
#include "myudpclient.h"
UDPClient::UDPClient():QObject()
{
    m_pudp = new QUdpSocket(this);
    m_pudp->bind(2424);
}
void UDPClient::processData(bool isLight){

}
