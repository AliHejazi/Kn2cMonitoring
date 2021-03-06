#include "robotsensors.h"
#include <QDebug>

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
    equallityToPast = 0;
}

void robotSensors::update(char *c){
    invertByIndex(c);
    int pastData;
    int numOfEquallDataToPast = 0;
    for(int i = 0 ; i < sensors.size() ; i++){
        if((byteIndex[i].second - byteIndex[i].first) == 0){
            pastData = sensors[i].second;
            sensors[i].second = (int)c[byteIndex[i].first];
            if(pastData == sensors[i].second)
                numOfEquallDataToPast++;
        }
        if((byteIndex[i].second - byteIndex[i].first) == 1){
            pastData = sensors[i].second;
            short int *b = reinterpret_cast<short int*>(&c[byteIndex[i].first]);
            short int d = *b;
            sensors[i].second = d;
            if(pastData == sensors[i].second)
                numOfEquallDataToPast++;
        }
        qDebug()<< sensors[i].first << " = " << sensors[i].second;
    }
    if(numOfEquallDataToPast == sensors.size())
        equallityToPast++;
    else
        equallityToPast = 0;
    if(equallityToPast < 2)
        emit valueChanged(sensors);
}

int robotSensors::operator [](int index){
    return sensors[index].second;
}

void robotSensors::invertByIndex(char* s){
    for(int i = 0 ; i < byteIndex.size() ; i++){
        char hold = s[byteIndex[i].first];
        s[byteIndex[i].first] = s[byteIndex[i].second];
        s[byteIndex[i].second] = hold;
    }
}
