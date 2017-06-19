#include "robotcontroller.h"
#include <QObject>
#include <QByteArray>
#include <QStringBuilder>
#include <QString>
struct RemoteControlPacket{
    unsigned int FRAME_TYPE_ID;
    int* AXIS = new int[16];
    unsigned int* BUTTON = new unsigned int[16];
    double TELEMETRY;
    RemoteControlPacket(){
        FRAME_TYPE_ID = 1;
        setZeros(AXIS,16);
        setZeros(BUTTON, 16);

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
    void setZeros(int* array, int size){
        for(int i = 0; i < size; i++){
            array[i] = 0;
        }
    }
    void setZeros(unsigned int* array, int size){
        for(int i = 0; i < size; i++){
            array[i] = 0;
        }
    }

    static RemoteControlPacket getLivePacket(){
        return RemoteControlPacket();
    }

    QByteArray toByteArray(){
        QByteArray byteArray;
        return byteArray.append(FRAME_TYPE_ID)
                //.append(AXIS)
                //.append(BUTTON)
                .append(TELEMETRY);
    }
    char* convertArray(int* array, int size){
        QString b;

        char *charArray = new char[size];
        for(int i = 0; i < size; i++){
        b.append(QString::number(array[i]));
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
RemoteControlPacket RobotController::getBasicPacket(){

    return RemoteControlPacket::getLivePacket();
}
