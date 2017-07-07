#ifndef ROBOT_H
#define ROBOT_H
#include <robotconfiguration.h>
#include <QObject>
class RobotController;
struct TelemetryPacket;
class Robot: public QObject
{
    Q_OBJECT
public:
    RobotController *controller;
    ~Robot();
    Robot();
    /*
     * moves robot platform directly(back or forward)
     * if speed is greater that zero, robot moves back, else
     * moves forward
     */
    void moveD(int speed);
    void moveR(int speed);
    void turnLight();
    void turnWaist(int speed);
    void moveWaist(int speed);
    void turnNeck(int speed);
    void turnElbowAndNeck(int speed);
    void flippers(int direction);
    void openGripper();
    void closeGripper();
    void gripper(int direction);

    void stopGripper();
    void stopFlippers();
    void stopAll();

    void connectToEngineer();



    RobotConfiguration* getConfiguration();
signals:
    void telemetryChanged(TelemetryPacket &packet);

public:
    bool isConnected = false;
    RobotConfiguration *configuration;
    int getRealSpeed(int uiSpeed);
};

#endif // ROBOT_H
