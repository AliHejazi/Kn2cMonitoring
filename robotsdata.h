#ifndef ROBOTSDATA_H
#define ROBOTSDATA_H
#include "robotsensors.h"
#include "constants.h"
#include <QVector>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QByteArray>


class robotsData : public QObject
{
    Q_OBJECT
public:
    QByteArray* data;
    QVector<robotSensors*> robots;
    explicit robotsData(QSettings *,QObject *parent = 0);
    bool updateData(QByteArray& newData);
    bool isValid(char*);
signals:

public slots:
};

#endif // ROBOTSDATA_H
