#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H
#include <QByteArray>
#include <QObject>
struct RemoteControlPacket;
class RobotController : public QObject
{
    Q_OBJECT
public:
    RobotController();
    QByteArray turnLight();
    RemoteControlPacket getBasicPacket();
    
};

#endif // ROBOTCONTROLLER_H
