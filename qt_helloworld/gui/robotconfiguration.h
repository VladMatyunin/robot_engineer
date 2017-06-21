#ifndef ROBOTCONFIGURATION_H
#define ROBOTCONFIGURATION_H

class RobotConfiguration
{
public:
    RobotConfiguration();
    RobotConfiguration(int platformForwardSpeed=5000, int platformRotateSpeed = 5000, bool light = false);
    int platformForwardSpeed;
    int platformRotateSpeed;
    bool lightValue;
    int shouldersSpeed;
};

#endif // ROBOTCONFIGURATION_H
