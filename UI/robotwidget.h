#ifndef ROBOTWIDGET_H
#define ROBOTWIDGET_H

#include <QWidget>

namespace Ui {
class RobotWidget;
}

class RobotWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RobotWidget(QWidget *parent = 0);
    ~RobotWidget();

private:
    Ui::RobotWidget *ui;
};

#endif // ROBOTWIDGET_H
