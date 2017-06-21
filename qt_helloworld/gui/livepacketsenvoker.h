#ifndef LIVEPACKETSENVOKER_H
#define LIVEPACKETSENVOKER_H
#include <QObject>
#include "robotcontroller.h"
class LivePacketsEnvoker:public QObject
{

public slots:
    void envokeLivePackets();
public:
    LivePacketsEnvoker();
};

#endif // LIVEPACKETSENVOKER_H
