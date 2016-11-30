#ifndef ROBOTWIDGET_H
#define ROBOTWIDGET_H
#include <QWidget>
#include <QVector>
#include <QPair>
#include <QSettings>
#include "robotsensors.h"
#include <limits.h>
#include <QTime>
#include <QTabWidget>

namespace Ui {
class RobotWidget;
}

//struct Range;

class RobotWidget : public QWidget
{
    Q_OBJECT

public:
//    static QVector<Range> ranges;
    int MaxTimePlot;
    QTime *time;
    QTabWidget* tabWidget;
    int state;
    int RobotId;
    explicit RobotWidget(QTabWidget* tabwidget,int,QSettings*,QWidget *parent = 0);
    ~RobotWidget();    
    void updateTabIcon(QVector<QPair<QString, int> > data);
public slots:
    void update(QVector<QPair<QString ,int > >);
//    void updateRangs();
private:
    Ui::RobotWidget *ui;
};

#endif // ROBOTWIDGET_H
