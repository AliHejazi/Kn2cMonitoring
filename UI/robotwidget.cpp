#include "robotwidget.h"
#include "ui_robotwidget.h"

RobotWidget::RobotWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RobotWidget)
{
    ui->setupUi(this);
}

RobotWidget::~RobotWidget()
{
    delete ui;
}
