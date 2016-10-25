#ifndef ROBOTSENSORS_H
#define ROBOTSENSORS_H
#include <QVector>
#include <QPair>
#include <QString>
#include <QStringList>
#include <QObject>
#include <QSettings>
#include <QByteArray>
#include "UI/robotwidget.h"

class robotSensors : public QObject
{
    Q_OBJECT
public:
    static int sensorNumber;
    QVector <QPair<QString,int>> sensors;
    QVector <QPair<int,int>> byteIndex;
    void invertByIndex(char* s);
    explicit robotSensors(QSettings* settings,QObject *parent = 0);
    void setSensorsNames(QVector<QString> &values);
    QVector<QString> getSensorsNames();
    int operator[](int index);
    void update(char *c);
signals:
    void valueChanged(QVector<QPair<QString ,int > > value);
};

#endif // ROBOTSENSORS_H
