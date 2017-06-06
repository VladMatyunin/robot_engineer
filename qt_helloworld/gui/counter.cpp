#include "counter.h"
#include "QDebug"
Counter::Counter() :QObject(),m_nValue(0){
    client = new UDPClient;
}
void Counter::slotInc(){
    emit counterChanged(++m_nValue);
    if (m_nValue == 5){
        emit goodbye();
    }

}
void Counter::changeLight(){
    isLight=!isLight;
    qDebug()<<isLight;
    client->processData(isLight);
}
