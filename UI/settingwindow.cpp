#include "settingwindow.h"
#include "ui_settingwindow.h"
#include "mainwindow.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include "main.cpp"

settingWindow::settingWindow(QMainWindow* mainWindow, QSettings* setting, QSerialPort* serialPort):
    QMainWindow(),
    mainWindow(mainWindow),
    ui(new Ui::settingWindow),
    serialPort(serialPort),
    setting(setting)
{
    ui->setupUi(this);
    for(int i = 0 ; i < QSerialPortInfo::availablePorts().size() ; i++){
        ui->availablePortsComboBox->insertItem(i,QSerialPortInfo::availablePorts()[i].portName());
    }
    if(QSerialPortInfo::availablePorts().size() != 0){
        ui->baudRateComboBox->insertItem(0,"1200");
        ui->baudRateComboBox->insertItem(1,"4800");
        ui->baudRateComboBox->insertItem(2,"9600");
        ui->baudRateComboBox->insertItem(3,"19200");
        ui->baudRateComboBox->insertItem(4,"38400");
        ui->baudRateComboBox->insertItem(5,"57600");
        ui->baudRateComboBox->insertItem(6,"115200");
        ui->baudRateComboBox->insertItem(7,"UnknownBaud");
        ui->dataBitsComboBox->insertItem(0,"5");
        ui->dataBitsComboBox->insertItem(1,"6");
        ui->dataBitsComboBox->insertItem(2,"7");
        ui->dataBitsComboBox->insertItem(3,"8");
        ui->dataBitsComboBox->insertItem(4,"UnknownDataBits");
        ui->flowControlComboBox->insertItem(0,"NoFlowControl");
        ui->flowControlComboBox->insertItem(1,"HardwareControl");
        ui->flowControlComboBox->insertItem(2,"SoftwareControl");
        ui->flowControlComboBox->insertItem(3,"UnknownFlowControl");
        ui->parityComboBox->insertItem(0,"NoParity");
        ui->parityComboBox->insertItem(1,"EvenParity");
        ui->parityComboBox->insertItem(2,"OddParity");
        ui->parityComboBox->insertItem(3,"SpaceParity");
        ui->parityComboBox->insertItem(4,"MarkParity");
        ui->parityComboBox->insertItem(5,"UnknownParity");
    }
    setting->beginGroup("wifiSettings");

    if(setting->value("BaudRate").toInt() != -1)
        ui->baudRateComboBox->setCurrentText(setting->value("BaudRate").toString());
    else
        ui->baudRateComboBox->setCurrentText("UnknownBaud");


    if(setting->value("DataBits").toInt() != -1)
        ui->dataBitsComboBox->setCurrentText(setting->value("DataBits").toString());
    else
        ui->dataBitsComboBox->setCurrentText("UnknownDataBits");


    if(setting->value("FlowControl").toString().compare("NoFlowControl"))
        ui->flowControlComboBox->setCurrentText("NoFlowControl");
    if(setting->value("FlowControl").toString().compare("HardwareControl"))
        ui->flowControlComboBox->setCurrentText("HardwareControl");
    if(setting->value("FlowControl").toString().compare("SoftwareControl"))
        ui->flowControlComboBox->setCurrentText("SoftwareControl");
    if(setting->value("FlowControl").toString().compare("UnknownFlowControl"))
        ui->flowControlComboBox->setCurrentText("UnknownFlowControl");


    switch(setting->value("Parity").toInt()){
    case 0:
        ui->parityComboBox->setCurrentIndex(0);
        break;
    case 2:
        ui->parityComboBox->setCurrentIndex(1);
        break;
    case 3:
        ui->parityComboBox->setCurrentIndex(2);
        break;
    case 4:
        ui->parityComboBox->setCurrentIndex(3);
        break;
    case 5:
        ui->parityComboBox->setCurrentIndex(4);
        break;
    case -1:
        ui->parityComboBox->setCurrentIndex(5);
        break;
    }
    setting->endGroup();
}

settingWindow::~settingWindow()
{
    delete ui;
}

void settingWindow::on_pushButton_clicked()
{
    serialPort->setPortName(ui->availablePortsComboBox->currentText());
    switch(ui->baudRateComboBox->currentIndex()){
    case 0:
        serialPort->setBaudRate(QSerialPort::Baud1200);
        break;
    case 1:
        serialPort->setBaudRate(QSerialPort::Baud2400);
        break;
    case 2:
        serialPort->setBaudRate(QSerialPort::Baud4800);
        break;
    case 3:
        serialPort->setBaudRate(QSerialPort::Baud9600);
        break;
    case 4:
        serialPort->setBaudRate(QSerialPort::Baud19200);
        break;
    case 5:
        serialPort->setBaudRate(QSerialPort::Baud38400);
        break;
    case 6:
        serialPort->setBaudRate(QSerialPort::Baud57600);
        break;
    case 7:
        serialPort->setBaudRate(QSerialPort::Baud115200);
        break;
    }
    switch(ui->dataBitsComboBox->currentIndex()){
    case 0:
        serialPort->setDataBits(QSerialPort::Data5);
        break;
    case 1:
        serialPort->setDataBits(QSerialPort::Data6);
        break;
    case 2:
        serialPort->setDataBits(QSerialPort::Data7);
        break;
    case 3:
        serialPort->setDataBits(QSerialPort::Data8);
        break;
    case 4:
        serialPort->setDataBits(QSerialPort::UnknownDataBits);
        break;
    }

    switch(ui->flowControlComboBox->currentIndex()){
    case 0:
        serialPort->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
        break;
    case 1:
        serialPort->setFlowControl(QSerialPort::FlowControl::HardwareControl);
        break;
    case 2:
        serialPort->setFlowControl(QSerialPort::FlowControl::SoftwareControl);
        break;
    case 3:
        serialPort->setFlowControl(QSerialPort::FlowControl::UnknownFlowControl);
        break;
    }
    switch(ui->parityComboBox->currentIndex()){
    case 0:
        serialPort->setParity(QSerialPort::NoParity);
        break;
    case 1:
        serialPort->setParity(QSerialPort::EvenParity);
        break;
    case 2:
        serialPort->setParity(QSerialPort::OddParity);
        break;
    case 3:
        serialPort->setParity(QSerialPort::SpaceParity);
        break;
    case 4:
        serialPort->setParity(QSerialPort::MarkParity);
        break;
    case 5:
        serialPort->setParity(QSerialPort::UnknownParity);
        break;
    }
    serialPort->open(QIODevice::ReadOnly);
    mainWindow->setEnabled(true);
    this->close();
//    delete this;
}

void settingWindow::closeEvent(QCloseEvent* event){
    mainWindow->setEnabled(true);
    event->accept();
    delete this;
}

void settingWindow::on_pushButton_2_clicked()
{
    mainWindow->setEnabled(true);
    this->close();
    delete this;
}

void settingWindow::on_saveAsDeafultPushButton_clicked()
{
    setting->beginGroup(QString("wifiSettings"));
    serialPort->setPortName(ui->availablePortsComboBox->currentText());
    switch(ui->baudRateComboBox->currentIndex()){
    case 0:
        serialPort->setBaudRate(QSerialPort::Baud1200);
        setting->setValue("BaudRate",QSerialPort::Baud1200);
        break;
    case 1:
        serialPort->setBaudRate(QSerialPort::Baud2400);
        setting->setValue("BaudRate",QSerialPort::Baud2400);
        break;
    case 2:
        serialPort->setBaudRate(QSerialPort::Baud4800);
        setting->setValue("BaudRate",QSerialPort::Baud4800);
        break;
    case 3:
        serialPort->setBaudRate(QSerialPort::Baud9600);
        setting->setValue("BaudRate",QSerialPort::Baud9600);
        break;
    case 4:
        serialPort->setBaudRate(QSerialPort::Baud19200);
        setting->setValue("BaudRate",QSerialPort::Baud19200);
        break;
    case 5:
        serialPort->setBaudRate(QSerialPort::Baud38400);
        setting->setValue("BaudRate",QSerialPort::Baud38400);
        break;
    case 6:
        serialPort->setBaudRate(QSerialPort::Baud57600);
        setting->setValue("BaudRate",QSerialPort::Baud57600);
        break;
    case 7:
        serialPort->setBaudRate(QSerialPort::Baud115200);
        setting->setValue("BaudRate",QSerialPort::Baud115200);
        break;
    }
    switch(ui->dataBitsComboBox->currentIndex()){
    case 0:
        serialPort->setDataBits(QSerialPort::Data5);
        setting->setValue("DataBits",QSerialPort::Data5);
        break;
    case 1:
        serialPort->setDataBits(QSerialPort::Data6);
        setting->setValue("DataBits",QSerialPort::Data6);
        break;
    case 2:
        serialPort->setDataBits(QSerialPort::Data7);
        setting->setValue("DataBits",QSerialPort::Data7);
        break;
    case 3:
        serialPort->setDataBits(QSerialPort::Data8);
        setting->setValue("DataBits",QSerialPort::Data8);
        break;
    case 4:
        serialPort->setDataBits(QSerialPort::UnknownDataBits);
        setting->setValue("DataBits",QSerialPort::UnknownDataBits);
        break;
    }

    switch(ui->flowControlComboBox->currentIndex()){
    case 0:
        serialPort->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
        setting->setValue("FlowControl","NoFlowControl");
        break;
    case 1:
        serialPort->setFlowControl(QSerialPort::FlowControl::HardwareControl);
        setting->setValue("FlowControl","HardwareControl");
        break;
    case 2:
        serialPort->setFlowControl(QSerialPort::FlowControl::SoftwareControl);
        setting->setValue("FlowControl","SoftwareControl");
        break;
    case 3:
        serialPort->setFlowControl(QSerialPort::FlowControl::UnknownFlowControl);
        setting->setValue("FlowControl","UnknownFlowControl");
        break;
    }
    switch(ui->parityComboBox->currentIndex()){
    case 0:
        serialPort->setParity(QSerialPort::NoParity);
        setting->setValue("Parity",QSerialPort::NoParity);
        break;
    case 1:
        serialPort->setParity(QSerialPort::EvenParity);
        setting->setValue("Parity",QSerialPort::EvenParity);
        break;
    case 2:
        serialPort->setParity(QSerialPort::OddParity);
        setting->setValue("Parity",QSerialPort::OddParity);
        break;
    case 3:
        serialPort->setParity(QSerialPort::SpaceParity);
        setting->setValue("Parity",QSerialPort::SpaceParity);
        break;
    case 4:
        serialPort->setParity(QSerialPort::MarkParity);
        setting->setValue("Parity",QSerialPort::MarkParity);
        break;
    case 5:
        serialPort->setParity(QSerialPort::UnknownParity);
        setting->setValue("Parity",QSerialPort::UnknownParity);
        break;
    }
    serialPort->open(QIODevice::ReadOnly);
    setting->endGroup();
    mainWindow->setEnabled(true);
    this->close();
//    delete this;
}
