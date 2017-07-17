#ifndef ROBOTCONFIGURATION_H
#define ROBOTCONFIGURATION_H

class RobotConfiguration
{

public:
    RobotConfiguration();
    ~RobotConfiguration();
    RobotConfiguration(int platformForwardSpeed=5000, int platformRotateSpeed = 5000, int shouldersSpeed=12000,
                       int neckSpeed=12000,int elbowSpeed=12000, int waistSpeed=12000, bool light = false);
    int platformForwardSpeed;
    int platformRotateSpeed;
    bool lightValue;
    int shouldersSpeed;
    int neckSpeed;
    int elbowSpeed;
    int waistSpeed;
};

#endif // ROBOTCONFIGURATION_H
