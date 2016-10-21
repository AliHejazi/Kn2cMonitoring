#ifndef ROBOTSDATA_H
#define ROBOTSDATA_H
#include "robotsensors.h"
#include "constants.h"
#include <QVector>
#include <QObject>
#include <QtCore>
#include <QtGui>


class robotsData : public QObject
{
    Q_OBJECT
public:
    char *ar;
    int size;
    int currentIndex;
    QVector<robotSensors*> robots;
    explicit robotsData(QSettings *, QByteArray *data,int firstDataSize, QObject *parent = 0);
    bool updateData(int size);
    bool isValid(char*);
signals:

public slots:
};

#endif // ROBOTSDATA_H
