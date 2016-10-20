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
    //set availble ports
    for(int i = 0 ; i < QSerialPortInfo::availablePorts().size() ; i++){
        ui->availablePortsComboBox->insertItem(i,QSerialPortInfo::availablePorts()[i].portName());
    }
    //initialize availabe settings for serialPort
    if(QSerialPortInfo::availablePorts().size() != 0){
        ui->baudRateComboBox->insertItem(0,"1200");
        ui->baudRateComboBox->insertItem(1,"2400");
        ui->baudRateComboBox->insertItem(2,"4800");
        ui->baudRateComboBox->insertItem(3,"9600");
        ui->baudRateComboBox->insertItem(4,"19200");
        ui->baudRateComboBox->insertItem(5,"38400");
        ui->baudRateComboBox->insertItem(6,"57600");
        ui->baudRateComboBox->insertItem(7,"115200");
        ui->baudRateComboBox->insertItem(8,"UnknownBaud");
        ///////////
        ui->dataBitsComboBox->insertItem(0,"5");
        ui->dataBitsComboBox->insertItem(1,"6");
        ui->dataBitsComboBox->insertItem(2,"7");
        ui->dataBitsComboBox->insertItem(3,"8");
        ui->dataBitsComboBox->insertItem(4,"UnknownDataBits");
        //////////
        ui->flowControlComboBox->insertItem(0,"NoFlowControl");
        ui->flowControlComboBox->insertItem(1,"HardwareControl");
        ui->flowControlComboBox->insertItem(2,"SoftwareControl");
        ui->flowControlComboBox->insertItem(3,"UnknownFlowControl");
        ///////////////
        ui->parityComboBox->insertItem(0,"NoParity");
        ui->parityComboBox->insertItem(1,"EvenParity");
        ui->parityComboBox->insertItem(2,"OddParity");
        ui->parityComboBox->insertItem(3,"SpaceParity");
        ui->parityComboBox->insertItem(4,"MarkParity");
        ui->parityComboBox->insertItem(5,"UnknownParity");
    }
    loadUISettings();
}

settingWindow::~settingWindow()
{
    delete ui;
}


void settingWindow::on_OKButton_clicked()
{
    saveSerialPortSettings();
    seriaPortDebug();
    mainWindow->setEnabled(true);
    this->close();
}

void settingWindow::closeEvent(QCloseEvent* event){
    mainWindow->setEnabled(true);
    event->accept();
}


void settingWindow::on_cancelButton_clicked()
{
    mainWindow->setEnabled(true);
    this->close();
}

void settingWindow::on_saveAsDeafultPushButton_clicked()
{
    saveDefaultSettings();
    saveSerialPortSettings();
    seriaPortDebug();
    mainWindow->setEnabled(true);
    this->close();
}

void settingWindow::saveSerialPortSettings(){
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
    case 8:
        serialPort->setBaudRate(QSerialPort::UnknownBaud);
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
}

void settingWindow::saveDefaultSettings(){
    setting->beginGroup("wifiSettings");
    //save port name
    setting->setValue("PortName",ui->availablePortsComboBox->currentText());
    //save baudrate setting
    switch(ui->baudRateComboBox->currentIndex()){
    case 0:
        setting->setValue("BaudRate","1200");
        break;
    case 1:
        setting->setValue("BaudRate","2400");
        break;
    case 2:
        setting->setValue("BaudRate","4800");
        break;
    case 3:
        setting->setValue("BaudRate","9600");
        break;
    case 4:
        setting->setValue("BaudRate","19200");
        break;
    case 5:
        setting->setValue("BaudRate","38400");
        break;
    case 6:
        setting->setValue("BaudRate","57600");
        break;
    case 7:
        setting->setValue("BaudRate","115200");
        break;
    case 8:
        setting->setValue("BaudRate","-1");
        break;
    }
    //save dataBit setting
    switch(ui->dataBitsComboBox->currentIndex()){
    case 0:
        setting->setValue("DataBits","5");
        break;
    case 1:
        setting->setValue("DataBits","6");
        break;
    case 2:
        setting->setValue("DataBits","7");
        break;
    case 3:
        setting->setValue("DataBits","8");
        break;
    case 4:
        setting->setValue("DataBits","-1");
        break;
    }
    //save flowControl setting
    switch(ui->flowControlComboBox->currentIndex()){
    case 0:
        setting->setValue("FlowControl","NoFlowControl");
        break;
    case 1:
        setting->setValue("FlowControl","HardwareControl");
        break;
    case 2:
        setting->setValue("FlowControl","SoftwareControl");
        break;
    case 3:
        setting->setValue("FlowControl","UnknownFlowControl");
        break;
    }
    //save parity setting
    switch(ui->parityComboBox->currentIndex()){
    case 0:
        setting->setValue("Parity","NoParity");
        break;
    case 1:
        setting->setValue("Parity","EvenParity");
        break;
    case 2:
        setting->setValue("Parity","OddParity");
        break;
    case 3:
        setting->setValue("Parity","SpaceParity");
        break;
    case 4:
        setting->setValue("Parity","MarkParity");
        break;
    case 5:
        setting->setValue("Parity","UnknownParity");
        break;
    }
    setting->endGroup();
}


void settingWindow::loadUISettings(){
    setting->beginGroup("wifiSettings");
    //load baudraty for ui
    if(setting->value("BaudRate").toInt() != -1)
        ui->baudRateComboBox->setCurrentText(setting->value("BaudRate").toString());
    else
        ui->baudRateComboBox->setCurrentText("UnknownBaud");
    //load databits for ui
    if(setting->value("DataBits").toInt() != -1)
        ui->dataBitsComboBox->setCurrentText(setting->value("DataBits").toString());
    else
        ui->dataBitsComboBox->setCurrentText("UnknownDataBits");
    //load flowcontrol for ui
    if(setting->value("FlowControl").toString().compare("NoFlowControl") == 0)
        ui->flowControlComboBox->setCurrentText("NoFlowControl");
    if(setting->value("FlowControl").toString().compare("HardwareControl") == 0)
        ui->flowControlComboBox->setCurrentText("HardwareControl");
    if(setting->value("FlowControl").toString().compare("SoftwareControl") == 0)
        ui->flowControlComboBox->setCurrentText("SoftwareControl");
    if(setting->value("FlowControl").toString().compare("UnknownFlowControl") == 0)
        ui->flowControlComboBox->setCurrentText("UnknownFlowControl");
    //load Parity for ui
    if(setting->value("Parity").toString().compare("NoParity") == 0)
        ui->parityComboBox->setCurrentText("NoParity");
    if(setting->value("Parity").toString().compare("EvenParity") == 0)
        ui->parityComboBox->setCurrentText("EvenParity");
    if(setting->value("Parity").toString().compare("OddParity") == 0)
        ui->parityComboBox->setCurrentText("OddParity");
    if(setting->value("Parity").toString().compare("SpaceParity") == 0)
        ui->parityComboBox->setCurrentText("SpaceParity");
    if(setting->value("Parity").toString().compare("MarkParity") == 0)
        ui->parityComboBox->setCurrentText("MarkParity");
    if(setting->value("Parity").toString().compare("UnknownParity") == 0)
        ui->parityComboBox->setCurrentText("UnknownParity");
    setting->endGroup();
}

void settingWindow::seriaPortDebug(){
    qDebug("Wifi Settings");
    qDebug() << "portName" << serialPort->portName();
    qDebug() << "BaudRate = " << serialPort->baudRate();
    qDebug() << serialPort->dataBits();
    qDebug() << serialPort->parity();
    qDebug() << serialPort->flowControl();
}
