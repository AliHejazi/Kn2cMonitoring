#include "robotsensors.h"

int robotSensors::sensorNumber;

robotSensors::robotSensors(QSettings* settings,QObject *parent) : QObject(parent)
{
    //initialize from Qsetting
    settings->beginGroup("Robot");
    sensors = QVector<QPair<QString,int> >(settings->value("SensorsNumber").toInt());
    byteIndex = QVector<QPair<int,int> >(settings->value("SensorsNumber").toInt());
    settings->endGroup();
    settings->beginGroup("SensorNames");
    for(int i = 0 ; i < sensors.size() ; i++){
        sensors[i] = QPair<QString,int>(settings->value(QString::number(i+1)).toString(),0);
    }
    settings->endGroup();

    for(int i = 0 ; i < byteIndex.size() ; i++){
        settings->beginGroup("SensorsStartBit");
        int startBit = settings->value(QString::number(i+1)).toInt() - 1;
        settings->endGroup();
        settings->beginGroup("SensorsStopBit");
        int stopBit = settings->value(QString::number(i+1)).toInt() - 1;
        settings->endGroup();
        byteIndex[i] = QPair<int,int>(startBit,stopBit);
    }
}

bool robotSensors::update(char *c){

}

int robotSensors::operator [](int index){
    return sensors[index].second;
}
