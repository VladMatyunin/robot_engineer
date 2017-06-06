#ifndef COUNTER_H
#define COUNTER_H
#include <QObject>

class Counter : public QObject{
    Q_OBJECT
private: int m_nValue;
private : bool isLight;
public: Counter();
public slots:
    void slotInc();
    void changeLight();
signals:
    void goodbye();
    void counterChanged(int);
};

#endif // COUNTER_H
