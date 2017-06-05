#include "mysignal.h"

class MySignal: public QObject {
    Q_OBJECT
public:
    void sendSignal(){
        emit sendString("Information");
    }
signals:
    void sendString(const QString&);
}
