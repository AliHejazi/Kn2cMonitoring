#include "robotwidget.h"
#include "ui_robotwidget.h"

RobotWidget::RobotWidget(int robotId,QSettings* settings,QWidget *parent):
    QWidget(parent),
    ui(new Ui::RobotWidget)
{
    ui->setupUi(this);
    time = new QTime();
    time->start();
    RobotId = robotId;
    //setting names of widgets
    ui->currentMotor0Widget->addGraph();
    ui->currentMotor0Widget->graph(0)->setName("Motor 1 Current");
    ui->currentMotor0Widget->xAxis->setLabel("time(microSecond)");
    ui->currentMotor0Widget->yAxis->setLabel("I(mA)");
    ui->currentMotor0Widget->xAxis->setRange(0,30);
    ui->currentMotor0Widget->yAxis->setRange(INT32_MIN,INT32_MAX);
    //
    ui->currentMotor1Widget->addGraph();
    ui->currentMotor1Widget->graph(0)->setName("Motor 2 Current");
    ui->currentMotor1Widget->xAxis->setLabel("time(microSecond)");
    ui->currentMotor1Widget->yAxis->setLabel("I(mA)");
    ui->currentMotor1Widget->xAxis->setRange(0,30);
    ui->currentMotor1Widget->yAxis->setRange(INT32_MIN,INT32_MAX);
    //
    ui->currentMotor2Widget->addGraph();
    ui->currentMotor2Widget->graph(0)->setName("Motor 3 Current");
    ui->currentMotor2Widget->xAxis->setLabel("time(microSecond)");
    ui->currentMotor2Widget->yAxis->setLabel("I(mA)");
    ui->currentMotor2Widget->xAxis->setRange(0,30);
    ui->currentMotor2Widget->yAxis->setRange(INT32_MIN,INT32_MAX);
    //
    ui->currentMotor3Widget->addGraph();
    ui->currentMotor3Widget->graph(0)->setName("Motor 4 Current");
    ui->currentMotor3Widget->xAxis->setLabel("time(microSecond)");
    ui->currentMotor3Widget->yAxis->setLabel("I(mA)");
    ui->currentMotor3Widget->xAxis->setRange(0,30);
    ui->currentMotor3Widget->yAxis->setRange(INT32_MIN,INT32_MAX);
    //
    ui->batteryWidget->addGraph();
    ui->batteryWidget->graph(0)->setName("Battery Voltage");
    ui->batteryWidget->xAxis->setLabel("time(microSecond)");
    ui->batteryWidget->yAxis->setLabel("V(mV)");
    ui->batteryWidget->xAxis->setRange(0,30);
    ui->batteryWidget->yAxis->setRange(INT32_MIN,INT32_MAX);
    //
    ui->capacitorWidget->addGraph();
    ui->capacitorWidget->graph(0)->setName("Capacitor Voltage");
    ui->capacitorWidget->xAxis->setLabel("time(microSecond)");
    ui->capacitorWidget->yAxis->setLabel("V(mV)");
    ui->capacitorWidget->xAxis->setRange(0,30);
    ui->capacitorWidget->yAxis->setRange(INT32_MIN,INT32_MAX);
    //setting Maximum of currents
    ui->currentMotor0Dial->setMaximum(INT32_MAX);
    ui->currentMotor1Dial->setMaximum(INT32_MAX);
    ui->currentMotor2Dial->setMaximum(INT32_MAX);
    ui->currentMotor3Dial->setMaximum(INT32_MAX);
    //setting Minimum of currents
    ui->currentMotor0Dial->setMinimum(INT32_MIN);
    ui->currentMotor1Dial->setMinimum(INT32_MIN);
    ui->currentMotor2Dial->setMinimum(INT32_MIN);
    ui->currentMotor3Dial->setMinimum(INT32_MIN);
    /////////////////////
    ui->batteryProgressBar->setMaximum(INT32_MAX);
    ui->batteryProgressBar->setMinimum(INT32_MIN);
    ui->capacitorProgressBar->setMaximum(INT32_MAX);
    ui->capacitorProgressBar->setMinimum(INT32_MIN);
}

RobotWidget::~RobotWidget()
{
    delete ui;
}

void RobotWidget::update(QVector<QPair<QString, int> > data){
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
    if(data[1].second == 0){
        ui->freeWheelWirelessToolButton->setStyleSheet("background-color: rgb(255, 0, 4);");
    }
    if(data[1].second == 1){
        ui->freeWheelWirelessToolButton->setStyleSheet("background-color: rgb(94, 211, 16);");
    }
    //
    if(data[2].second == 0){
        ui->freeWheelMotorToolButton->setStyleSheet("background-color: rgb(255, 0, 4);");
    }
    if(data[2].second == 1){
        ui->freeWheelMotorToolButton->setStyleSheet("background-color: rgb(94, 211, 16);");
    }
    //
    if(data[3].second == 0){
        ui->freeWheelBatteryToolButton->setStyleSheet("background-color: rgb(255, 0, 4);");
    }
    if(data[3].second == 1){
        ui->freeWheelBatteryToolButton->setStyleSheet("background-color: rgb(94, 211, 16);");
    }
    //
    ui->capacitorProgressBar->setValue(data[4].second);
    ui->capacitorWidget->graph(0)->addData(currentTime,((double)data[4].second));
    ui->capacitorWidget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->capacitorWidget->xAxis->setRange(currentTime-25,currentTime+5);
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
    //
    //fuck u reza
//    if(data[10]){
//        ui->microTemperatureGraphicsView->setStyleSheet("border-image: url(:/new/prefix1/Images/GoodCircuit.jpg);");
//    }
//    else if(data[10]){
//        ui->microTemperatureGraphicsView->setStyleSheet("border-image: url(:/new/prefix1/Images/Circuit_OverHeating.png);");
//    }
    //again fuck u reza
    //
    ui->currentMotor0Widget->graph(0)->addData(currentTime,((double)data[11].second));
    ui->currentMotor0Widget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->currentMotor0Widget->xAxis->setRange(currentTime-25,currentTime+5);
    ui->currentMotor0Widget->replot();
    //
    ui->currentMotor1Widget->graph(0)->addData(currentTime,((double)data[12].second));
    ui->currentMotor1Widget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->currentMotor1Widget->xAxis->setRange(currentTime-25,currentTime+5);
    ui->currentMotor1Widget->replot();
    //
    ui->currentMotor2Widget->graph(0)->addData(currentTime,((double)data[13].second));
    ui->currentMotor2Widget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->currentMotor2Widget->xAxis->setRange(currentTime-25,currentTime+5);
    ui->currentMotor2Widget->replot();
    //
    ui->currentMotor3Widget->graph(0)->addData(currentTime,((double)data[14].second));
    ui->currentMotor3Widget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->currentMotor3Widget->xAxis->setRange(currentTime-25,currentTime+5);
    ui->currentMotor3Widget->replot();
    //
    ui->batteryWidget->graph(0)->addData(currentTime,((double)data[15].second));
    ui->batteryWidget->graph(0)->removeData(currentTime-30.008,currentTime-30);
    ui->batteryWidget->xAxis->setRange(currentTime-25,currentTime+5);
    ui->batteryWidget->replot();
}
