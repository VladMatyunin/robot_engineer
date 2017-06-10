#include "robotcontroller.h"
#include <QObject>
#include <QByteArray>
struct RemoteControlPacket{
    unsigned int FRAME_TYPE_ID;
    int* AXIS = new int[16];
    unsigned int* BUTTON = new unsigned int[16];
    double TELEMETRY;
    RemoteControlPacket(){
        FRAME_TYPE_ID = 1;
        memset(AXIS,0,sizeof(AXIS));
        memset(BUTTON,0,sizeof(BUTTON));
        TELEMETRY = 0.0;
    }
//char* convertArray(int* array,int size);
//char* convertArrayUnsigned(unsigned int* array, int size);
public:
    static RemoteControlPacket turnLight(){
        RemoteControlPacket packet;
        packet.BUTTON[1] = 1;
        return packet;
    }
    static RemoteControlPacket getLivePacket(){
        return RemoteControlPacket();
    }

    QByteArray toByteArray(){
        QByteArray byteArray;
        return byteArray.append(FRAME_TYPE_ID)
                .append(convertArray(AXIS,16))
                .append(convertArrayUnsigned(BUTTON,16))
                .append(TELEMETRY);
    }
    char* convertArray(int* array, int size){
        char *charArray = new char[size];
        for(int i = 0; i < size; i++){
            charArray[i] = array[i];
        }
        return charArray;
    }
    char* convertArrayUnsigned(unsigned int* array, int size){
        char *charArray = new char[size];
        for(int i = 0; i < size; i++){
            charArray[i] = array[i];
        }
        return charArray;
    }
};

RobotController::RobotController():QObject()
{
    
}

QByteArray RobotController::turnLight(){

    return RemoteControlPacket::turnLight().toByteArray();
}
QByteArray RobotController::getBasicPacket(){

    return RemoteControlPacket::getLivePacket().toByteArray();
}
