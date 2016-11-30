#include "robotwidget.h"
#include "ui_robotwidget.h"
#include <Qt>

//struct Range;

RobotWidget::RobotWidget(QTabWidget* tabwidget,int robotId,QSettings* settings,QWidget *parent):
    QWidget(parent),
    ui(new Ui::RobotWidget)
{
    ui->setupUi(this);
    RobotId = robotId;
    this->tabWidget = tabwidget;
    //setting names of widgets
    ui->currentMotor0Widget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    ui->currentMotor0Widget->setInteraction(QCP::iRangeDrag, true);
    ui->currentMotor0Widget->setInteraction(QCP::iRangeZoom, true);
    ui->currentMotor0Widget->addGraph();
    ui->currentMotor0Widget->graph(0)->setName("Motor 1 Current");
    ui->currentMotor0Widget->xAxis->setLabel("time(microSecond)");
    ui->currentMotor0Widget->yAxis->setLabel("I(mA)");
    ui->currentMotor0Widget->xAxis->setRange(0,30);
    ui->currentMotor0Widget->yAxis->setRange(-10000,10000);
    //
    ui->currentMotor1Widget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    ui->currentMotor1Widget->setInteraction(QCP::iRangeDrag, true);
    ui->currentMotor1Widget->setInteraction(QCP::iRangeZoom, true);
    ui->currentMotor1Widget->addGraph();
    ui->currentMotor1Widget->graph(0)->setName("Motor 2 Current");
    ui->currentMotor1Widget->xAxis->setLabel("time(microSecond)");
    ui->currentMotor1Widget->yAxis->setLabel("I(mA)");
    ui->currentMotor1Widget->xAxis->setRange(0,30);
    ui->currentMotor1Widget->yAxis->setRange(-10000,10000);
    //
    ui->currentMotor2Widget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    ui->currentMotor2Widget->setInteraction(QCP::iRangeDrag, true);
    ui->currentMotor2Widget->setInteraction(QCP::iRangeZoom, true);
    ui->currentMotor2Widget->addGraph();
    ui->currentMotor2Widget->graph(0)->setName("Motor 3 Current");
    ui->currentMotor2Widget->xAxis->setLabel("time(microSecond)");
    ui->currentMotor2Widget->yAxis->setLabel("I(mA)");
    ui->currentMotor2Widget->xAxis->setRange(0,30);
    ui->currentMotor2Widget->yAxis->setRange(-10000,10000);
    //
    ui->currentMotor3Widget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    ui->currentMotor3Widget->setInteraction(QCP::iRangeDrag, true);
    ui->currentMotor3Widget->setInteraction(QCP::iRangeZoom, true);
    ui->currentMotor3Widget->addGraph();
    ui->currentMotor3Widget->graph(0)->setName("Motor 4 Current");
    ui->currentMotor3Widget->xAxis->setLabel("time(microSecond)");
    ui->currentMotor3Widget->yAxis->setLabel("I(mA)");
    ui->currentMotor3Widget->xAxis->setRange(0,30);
    ui->currentMotor3Widget->yAxis->setRange(-10000,10000);
    //
    ui->batteryWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    ui->batteryWidget->setInteraction(QCP::iRangeDrag, true);
    ui->batteryWidget->setInteraction(QCP::iRangeZoom, true);
    ui->batteryWidget->addGraph();
    ui->batteryWidget->graph(0)->setName("Battery Voltage");
    ui->batteryWidget->xAxis->setLabel("time(microSecond)");
    ui->batteryWidget->yAxis->setLabel("V(mV)");
    ui->batteryWidget->xAxis->setRange(0,30);
    ui->batteryWidget->yAxis->setRange(0,12600);
    //
    ui->capacitorWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    ui->capacitorWidget->setInteraction(QCP::iRangeDrag, true);
    ui->capacitorWidget->setInteraction(QCP::iRangeZoom, true);
    ui->capacitorWidget->addGraph();
    ui->capacitorWidget->graph(0)->setName("Capacitor Voltage");
    ui->capacitorWidget->xAxis->setLabel("time(microSecond)");
    ui->capacitorWidget->yAxis->setLabel("V(mV)");
    ui->capacitorWidget->xAxis->setRange(0,30);
    ui->capacitorWidget->yAxis->setRange(0,7000);
    //setting Maximum of currents
    ui->currentMotor0Dial->setMaximum(10000);
    ui->currentMotor1Dial->setMaximum(10000);
    ui->currentMotor2Dial->setMaximum(10000);
    ui->currentMotor3Dial->setMaximum(10000);
    //setting Minimum of currents
    ui->currentMotor0Dial->setMinimum(-10000);
    ui->currentMotor1Dial->setMinimum(-10000);
    ui->currentMotor2Dial->setMinimum(-10000);
    ui->currentMotor3Dial->setMinimum(-10000);
    /////////////////////
    ui->batteryProgressBar->setMaximum(12600);
    ui->batteryProgressBar->setMinimum(0);
    ui->capacitorProgressBar->setMaximum(7000);
    ui->capacitorProgressBar->setMinimum(0);
    /////////////////////
    time = new QTime();
    time->start();
}

RobotWidget::~RobotWidget()
{
    delete ui;
}

void RobotWidget::update(QVector<QPair<QString, int> > data){
    double Scale;
    //rang bi tafavot background-color: rgb(241, 239, 236);
    double currentTime = time->elapsed() / 1000;
    qDebug()<< "time" << currentTime;
    ui->CycleTimeusLCDNumber->display(data[0].second);
    if((data[0].second > 4000) || (data[0].second < 3000)){
        ui->CycleTimeusLCDNumber->setStyleSheet("background-color: rgb(255, 0, 4);");
    }
    else{
        ui->CycleTimeusLCDNumber->setStyleSheet("background-color: rgb(94, 211, 16);");
    }
    //
    if(data[1].second == 1){
        ui->freeWheelWirelessToolButton->setStyleSheet("background-color: rgb(255, 0, 4);");
    }
    if(data[1].second == 0){
        ui->freeWheelWirelessToolButton->setStyleSheet("background-color: rgb(94, 211, 16);");
    }
    //
    if(data[2].second == 1){
        ui->freeWheelMotorToolButton->setStyleSheet("background-color: rgb(255, 0, 4);");
    }
    if(data[2].second == 0){
        ui->freeWheelMotorToolButton->setStyleSheet("background-color: rgb(94, 211, 16);");
    }
    //
    if(data[3].second == 1){
        ui->freeWheelBatteryToolButton->setStyleSheet("background-color: rgb(255, 0, 4);");
    }
    if(data[3].second == 0){
        ui->freeWheelBatteryToolButton->setStyleSheet("background-color: rgb(94, 211, 16);");
    }
    //
    ui->capacitorProgressBar->setValue(data[4].second);
    Scale = ui->capacitorWidget->xAxis->range().size();
    ui->capacitorWidget->graph(0)->addData(currentTime,((double)data[4].second));
    ui->capacitorWidget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->capacitorWidget->xAxis->setRange(currentTime-((Scale/6)*5),currentTime+(Scale/6));
    ui->capacitorWidget->replot();
    //
    ui->dataSenderPacketLCDNumber->display(data[5].second);
    if(data[5].second < 65){
        ui->dataSenderPacketLCDNumber->setStyleSheet("background-color: rgb(255, 0, 4);");
    }
    else{
        ui->dataSenderPacketLCDNumber->setStyleSheet("background-color: rgb(94, 211, 16);");
    }
    //
    ui->dataReceivedPacketLCDNumber->display(data[6].second);
    if(data[6].second > data[5].second){
        ui->dataReceivedPacketLCDNumber->setStyleSheet("background-color: rgb(255, 0, 4);");
    }
    else{
        ui->dataReceivedPacketLCDNumber->setStyleSheet("background-color: rgb(94, 211, 16);");
    }
    /////////////////////////
    if(data[7].second < 50){
        ui->wifiGraphicsView->setStyleSheet("border-image: url(:/new/prefix1/Images/veryLowSignal.png);");
    }
    else if(data[7].second < 60){
        ui->wifiGraphicsView->setStyleSheet("border-image: url(:/new/prefix1/Images/lowSignal.png);");
    }
    else if(data[7].second < 68){
        ui->wifiGraphicsView->setStyleSheet("border-image: url(:/new/prefix1/Images/mediumSignal.png);");
    }
    else if(data[7].second >= 68){
        ui->wifiGraphicsView->setStyleSheet("border-image: url(:/new/prefix1/Images/highSignal.png);");
    }
    ////////////////////////
    if(data[8].second == 0){
        ui->LastKickOrderToolButton->setText("No Command");
    }
    else if(data[8].second){
        ui->LastKickOrderToolButton->setText("With sensor");
    }
    else if(data[8].second){
        ui->LastKickOrderToolButton->setText("Without sensor");
    }
    ////////////////////////
    ui->wirelessResetCounter->display(data[9].second);
    ////////////////////////
    Scale = ui->currentMotor0Widget->xAxis->range().size();
    ui->currentMotor0Widget->graph(0)->addData(currentTime,((double)data[11].second));
    ui->currentMotor0Widget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->currentMotor0Widget->xAxis->setRange(currentTime-((Scale/6)*5),currentTime+(Scale/6));
    ui->currentMotor0Widget->replot();
    //
    Scale = ui->currentMotor1Widget->xAxis->range().size();
    ui->currentMotor1Widget->graph(0)->addData(currentTime,((double)data[12].second));
    ui->currentMotor1Widget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->currentMotor1Widget->xAxis->setRange(currentTime-((Scale/6)*5),currentTime+(Scale/6));
    ui->currentMotor1Widget->replot();
    //
    Scale = ui->currentMotor2Widget->xAxis->range().size();
    ui->currentMotor2Widget->graph(0)->addData(currentTime,((double)data[13].second));
    ui->currentMotor2Widget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->currentMotor2Widget->xAxis->setRange(currentTime-((Scale/6)*5),currentTime+(Scale/6));
    ui->currentMotor2Widget->replot();
    //
    Scale = ui->currentMotor3Widget->xAxis->range().size();
    ui->currentMotor3Widget->graph(0)->addData(currentTime,((double)data[14].second));
    ui->currentMotor3Widget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->currentMotor3Widget->xAxis->setRange(currentTime-((Scale/6)*5),currentTime+(Scale/6));
    ui->currentMotor3Widget->replot();
    //
    Scale = ui->batteryWidget->xAxis->range().size();
    ui->batteryProgressBar->setValue(data[15].second);
    ui->batteryWidget->graph(0)->addData(currentTime,((double)data[15].second));
    ui->batteryWidget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->batteryWidget->xAxis->setRange(currentTime-((Scale/6)*5),currentTime+(Scale/6));
    ui->batteryWidget->replot();
    /////////////////////////
    updateTabIcon(data);
}

void RobotWidget::updateTabIcon(QVector<QPair<QString, int> > data){
    int count = 0;
    if(data[15].second < 6300){
        tabWidget->setTabIcon(RobotId,QIcon(":/new/prefix1/Images/batterylow.png"));
        count++;
    }
    if(((data[0].second > 4000) || (data[0].second < 3000))){
        count++;
        tabWidget->setTabIcon(RobotId,QIcon(":/new/prefix1/Images/process.gif"));
    }
    if((data[1].second == 1) || (data[2].second == 1) || (data[3].second == 1))
        tabWidget->setTabIcon(RobotId,QIcon(":/new/prefix1/Images/RedSquare.jpg"));
    if(count == 0)
        tabWidget->setTabIcon(RobotId,QIcon());
    int count2 = 0;
    for(int i = 0 ; i < data.size() ; i++)
        if(data[i].second == 0)
            count2++;
    if(count2 == data.size())
        tabWidget->setTabIcon(RobotId,QIcon(":/new/prefix1/Images/off2.png"));
}
