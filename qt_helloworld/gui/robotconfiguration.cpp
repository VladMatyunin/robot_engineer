#include "robotconfiguration.h"

RobotConfiguration::RobotConfiguration()
{
}
RobotConfiguration::RobotConfiguration(int platformForwardSpeed, int platformRotateSpeed, bool light){
    this->platformForwardSpeed = platformForwardSpeed;
    this->platformRotateSpeed = platformRotateSpeed;
    this->lightValue = light;
}
