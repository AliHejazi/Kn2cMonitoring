#include "robotsdata.h"
#include <QDebug>

robotsData::robotsData(QSettings *settings,QByteArray &data,QObject *parent) : QObject(parent)
{
    this->ar = data.data();
    settings->beginGroup("Robot");
    robots = QVector<robotSensors*>(settings->value("SensorsNumber").toInt());
    settings->endGroup();
    for(int i = 0 ; i < robots.size() ; i++){
        robots[i] = new robotSensors(settings);
    }
}

bool robotsData::updateData(int size){
//    char *ar = data.data();
    for(int i = 0; i < size ; i++){
//        if(isValid(&ar[i])){
//            //check shavad
//            robots[ar[i+1] - 97]->update(data->left(32).data());
//            QByteArray refreshedData = data->right(data->size()-34);
//            delete data;
//            data = &refreshedData;
//            return true;
//        }
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
