#ifndef COUNTER_H
#define COUNTER_H
#include <QObject>
#include <myudpclient.h>
class Counter : public QObject{
    Q_OBJECT
private: int m_nValue;
 bool isLight;
UDPClient* client;
public: Counter();
public slots:
    void slotInc();
    void changeLight();
signals:
    void goodbye();
    void counterChanged(int);
};

#endif // COUNTER_H
