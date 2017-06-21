#include "livepacketsenvoker.h"
#include "QO"
LivePacketsEnvoker::LivePacketsEnvoker():: public QObject
{

}
public slots:
    void envokeRobotController();
