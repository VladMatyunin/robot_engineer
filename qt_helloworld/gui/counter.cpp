#include "counter.h"
#include "QDebug"
Counter::Counter() :QObject(),m_nValue(0){}
void Counter::slotInc(){
    emit counterChanged(++m_nValue);
    if (m_nValue == 5){
        emit goodbye();
    }
}
void Counter::changeLight(){
    isLight=!isLight;
    qDebug()<<isLight;
}
