#ifndef ROBOTSENSORS_H
#define ROBOTSENSORS_H
#include <QVector>
#include <QPair>
#include <QString>
#include <QStringList>
#include <QObject>
#include <QSettings>

class robotSensors : public QObject
{
    Q_OBJECT
public:
    static int sensorNumber;
    QVector <QPair<QString,int>> sensors;
    QVector <QPair<int,int>> byteIndex;
    explicit robotSensors(QSettings* settings,QObject *parent = 0);
    void setSensorsNames(QVector<QString> &values);
    QVector<QString> getSensorsNames();
    int operator[](int index);
    bool update(char *c);
signals:

public slots:
};

#endif // ROBOTSENSORS_H
