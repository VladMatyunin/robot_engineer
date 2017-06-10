#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H
#include <QByteArray>
#include <QObject>
class RobotController : public QObject
{
    Q_OBJECT
public:
    RobotController();
    QByteArray turnLight();
    QByteArray getBasicPacket();
    
};

#endif // ROBOTCONTROLLER_H
