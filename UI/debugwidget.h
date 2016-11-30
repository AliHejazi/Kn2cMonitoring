#ifndef DEBUGWIDGET_H
#define DEBUGWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QSettings>
#include <QVector>
#include <QLCDNumber>
#include <QPair>

namespace Ui {
class debugWidget;
}

class debugWidget : public QWidget
{
    Q_OBJECT

public:
    QVector<QLCDNumber*> LCDs;
    int robotId;
    explicit debugWidget(QSettings *settings,QWidget *parent = 0);
    ~debugWidget();

public slots:
    void update(QVector<QPair<QString ,int> >);


private:
    Ui::debugWidget *ui;
};

#endif // DEBUGWIDGET_H
