#ifndef ROBOT_H
#define ROBOT_H
#include <robotcontroller.h>
#include <robotconfiguration.h>
class Robot
{
public:
    RobotController *controller;
    ~Robot();
    Robot();
    void moveForward();
    void moveBack();
    void moveLeft();
    void moveRight();
    void turnLight();
    void turnWaist(int speed);
    void moveWaist(int speed);
    void turnNeck(int speed);
    void turnElbowAndNeck(int speed);
    void flippersUp();
    void flippersDown(int speed);
    void openGripper();
    void closeGripper();

    RobotConfiguration* getConfiguration();

private:
    RobotConfiguration *configuration;
    int getRealSpeed(int uiSpeed);
};

#endif // ROBOT_H
