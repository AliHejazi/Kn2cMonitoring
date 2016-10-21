#include "robotsdata.h"
#include <QDebug>

robotsData::robotsData(QSettings *settings,QByteArray *data,int firstDataSize,QObject *parent) : QObject(parent)
{
    this->ar = data->data();
    size = firstDataSize;
    settings->beginGroup("Robot");
    currentIndex = 0;
    robots = QVector<robotSensors*>(settings->value("RobotsNumber").toInt());
    settings->endGroup();
    for(int i = 0 ; i < robots.size() ; i++){
        robots[i] = new robotSensors(settings);
    }
}

bool robotsData::updateData(int newDataSize){
    size += newDataSize;
    for(; currentIndex < (size - 38) ; currentIndex++){
        if(isValid(&ar[currentIndex])){
            //check this idea
            //currentIndex += 34
            qDebug()<< (ar[currentIndex+1] - 97);
            robots[ar[currentIndex+1] - 97]->update(&ar[currentIndex+2]);
            currentIndex++;
            return true;
        }
    }
    return false;
}

bool robotsData::isValid(char* c){
    if(c[0] != 'z')
        return false;
    if(c[34] != 'z')
        return false;
    if(c[68] != 'z')
        return false;
    if(!((c[1] >= 97)&&(c[35] >= 97)&&(c[69] >= 97)))
        return false;
    if(c[1] + 1 != c[35])
        return false;
    if(c[35] + 1 != c[69])
        return false;
    return true;
}
