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
    void moveForward(int speed);
    void moveBack(int speed);
    void moveLeft(int speed);
    void moveRight(int speed);
    void turnLight();
    void turnWaist(int speed);
    void moveWaist(int speed);
    void turnNeck(int speed);
    void turnElbowAndNeck(int speed);
    void flippers(int direction);
    void openGripper();
    void closeGripper();
    void gripper(int direction);
    RobotConfiguration* getConfiguration();

private:
    RobotConfiguration *configuration;
    int getRealSpeed(int uiSpeed);
};

#endif // ROBOT_H
