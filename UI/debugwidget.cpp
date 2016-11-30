#include "debugwidget.h"
#include "ui_debugwidget.h"
#include <QLabel>
#include <QDebug>
#include <Qt>
#include <QPalette>

debugWidget::debugWidget(QSettings *settings,QWidget *parent):
    QWidget(parent),
    ui(new Ui::debugWidget)
{
    ui->setupUi(this);
    qDebug() << "i am in fucking area";
    //
    settings->beginGroup("Robot");
    int sensorsNumber = settings->value("SensorsNumber").toInt();
    qDebug() << "i am in fucking area2" << sensorsNumber;
    settings->endGroup();
    //
    settings->beginGroup("SensorNames");
    LCDs = QVector<QLCDNumber*>(sensorsNumber);
    for(int i = 0 ; i < sensorsNumber ; i++){
        QString s = settings->value(QString::number(i+1)).toString();
        QLabel* label = new QLabel(s);
        qDebug() << s;
        ui->gridLayout->addWidget(label,i,0);
        label->show();
        LCDs[i] = new QLCDNumber(123);
        LCDs[i]->setPalette(QPalette(QPalette::WindowText,Qt::black));
        ui->gridLayout->addWidget(LCDs[i],i,1);
    }
    settings->endGroup();
}

void debugWidget::update(QVector<QPair<QString ,int> > Data){
    for(int i = 0 ; i < LCDs.size() ; i++){
        LCDs[i]->display(Data[i].second);
    }
}

debugWidget::~debugWidget()
{
    delete ui;
}
