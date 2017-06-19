#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H
#include <QByteArray>
#include <QObject>
#pragma pack(push,1)
struct RemoteControlPacket{
    u_int8_t FRAME_TYPE_ID=1;
    int16_t AXIS[16];
    u_int8_t BUTTON[16];
    double TELEMETRY;
};
//#pragma pack(pop)
class RobotController : public QObject
{
    Q_OBJECT
public:
    RobotController();
    RemoteControlPacket* turnLight();
    RemoteControlPacket* getBasicPacket();

    
};

#endif // ROBOTCONTROLLER_H
