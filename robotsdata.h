#ifndef ROBOTSDATA_H
#define ROBOTSDATA_H
#include "robotdata.h"
#include <QObject>

class robotsData : public QObject
{
    Q_OBJECT
public:
    QList<robotData> robots;
    explicit robotsData(QObject *parent = 0);
    bool updateData(QByteArray &data);
signals:

public slots:
};

#endif // ROBOTSDATA_H
