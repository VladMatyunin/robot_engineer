#include "myslot.h"

class MySlot: public QObject{
    Q_OBJECT

public :MySlot();
public slots:
    void slot(){
        qDebug() << sender()->objectName();
    }
}
