#ifndef ROBOTDATA_H
#define ROBOTDATA_H

#include <QObject>

class robotData : public QObject
{
    Q_OBJECT
private:
    QChar startKey;
    qint8 IDkey;
    int sensor1;
    int sensor2;
    int sensor3;
    int sensor4;
    int sensor5;
    int sensor6;
    int sensor7;
    int sensor8;
    int sensor9;
    int sensor10;
    int sensor11;

public:
    explicit robotData(QObject *parent = 0);



};

#endif // ROBOTDATA_H
