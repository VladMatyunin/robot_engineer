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
    void turnWaist();
    void flippersUp();
    void flippersDown(int speed);
    void openGripper();
    void closeGripper();
private:
    RobotConfiguration *configuration;
};

#endif // ROBOT_H
