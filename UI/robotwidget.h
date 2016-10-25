#ifndef ROBOTWIDGET_H
#define ROBOTWIDGET_H
#include <QWidget>
#include <QVector>
#include <QPair>
#include <QSettings>
#include "robotsensors.h"
#include <limits.h>
#include <QTime>

namespace Ui {
class RobotWidget;
}

class RobotWidget : public QWidget
{
    Q_OBJECT

public:
    QTime *time;
    int RobotId;
    explicit RobotWidget(int,QSettings*,QWidget *parent = 0);
    ~RobotWidget();    
public slots:
    void update(QVector<QPair<QString ,int > >);
private:
    Ui::RobotWidget *ui;
};

#endif // ROBOTWIDGET_H
