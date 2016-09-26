#include "settingwindow.h"
#include "ui_settingwindow.h"
#include "mainwindow.h"
#include <QSerialPortInfo>
#include <QSerialPort>

settingWindow::settingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::settingWindow)
{
    ui->setupUi(this);
    for(int i = 0 ; i < QSerialPortInfo::availablePorts().size() ; i++){
        ui->availablePortsComboBox->insertItem(i,QSerialPortInfo::availablePorts()[i].portName());
    }
    if(QSerialPortInfo::availablePorts().size() != 0){
        ui->baudRateComboBox->insertItem(0,"Baud1200");
        ui->baudRateComboBox->insertItem(1,"Baud4800");
        ui->baudRateComboBox->insertItem(2,"Baud9600");
        ui->baudRateComboBox->insertItem(3,"Baud19200");
        ui->baudRateComboBox->insertItem(4,"Baud38400");
        ui->baudRateComboBox->insertItem(5,"Baud57600");
        ui->baudRateComboBox->insertItem(6,"Baud115200");
        ui->baudRateComboBox->insertItem(7,"UnknownBaud");
        ui->dataBitsComboBox->insertItem(0,"5 bits");
        ui->dataBitsComboBox->insertItem(1,"6 bits");
        ui->dataBitsComboBox->insertItem(2,"7 bits");
        ui->dataBitsComboBox->insertItem(3,"8 bits");
        ui->dataBitsComboBox->insertItem(4,"UnknownDataBits");
    }
}

settingWindow::~settingWindow()
{
    delete ui;
}
