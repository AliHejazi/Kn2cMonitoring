#include "robotsdata.h"
#include <QDebug>

robotsData::robotsData(QSettings *settings,QObject *parent) : QObject(parent)
{
    data = new QByteArray();
    settings->beginGroup("Robot");
    robots = QVector<robotSensors*>(settings->value("RobotsNumber").toInt());
    settings->endGroup();
    for(int i = 0 ; i < robots.size() ; i++){
        robots[i] = new robotSensors(settings);
    }
}

bool robotsData::updateData(QByteArray& newData){
    data->append(newData);
    char *ar = data->data();
    for(int i = 0 ; i < data->size() ; i++){
        if(isValid(&ar[i])){
            qDebug() << "Robot" << (ar[i+1] - 97);
            robots[ar[i+1] - 97]->update(&ar[i+2]);
            data->remove(0,i+34);
            ar = data->data();
        }
    }
    return true;
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
