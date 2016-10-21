#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_datawindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QThread>
#include <QProgressDialog>
#include <QErrorMessage>
#include <QThread>
//hour
#define MAX_EXECUTION_TIME 3

QSerialPort *MainWindow::getSerialPort() const
{
    return serialPort;
}

void MainWindow::setSerialPort(QSerialPort *value)
{
    serialPort = value;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->robotTabsWidgets->
    settings = new QSettings(QApplication::applicationDirPath() + "/../source/setting.ini",QSettings::IniFormat);
    serialPort = new QSerialPort();
    loadSerialPort();
    seriaPortDebug();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionWifi_Settings_triggered()
{
    settingWin = new settingWindow(this,settings,serialPort);
    settingWin->show();
    this->setDisabled(true);
}


void MainWindow::on_actionData_triggered()
{
    dataWin = new dataWindow(this,serialPort);
    dataWin->show();
    connect(serialPort,SIGNAL(readyRead()),dataWin,SLOT(PrintData()));
}

void MainWindow::on_actionNew_triggered()
{
    this->setDisabled(true);
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()){
        dataFile = new QFile(fileName);
        dataFile->open(QFile::ReadWrite);
    }
    this->setEnabled(true);
}

void MainWindow::on_actionOpen_triggered()
{
    this->setDisabled(true);
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()){
        dataFile = new QFile(fileName);
        dataFile->open(QFile::ReadWrite);
    }
    this->setEnabled(true);
}

void MainWindow::on_actionSave_triggered()
{
    //delete this function
}

void MainWindow::manipulateData(){

    QByteArray newData = serialPort->readAll();
    data->push_back(newData);
    robots->updateData(newData.size());
}


///dont change
void MainWindow::loadSerialPort(){
    settings->beginGroup("wifiSettings");
    //load name for serialPort
    serialPort->setPortName(settings->value("PortName").toString());
    //load baudrate for serialPort
    serialPort->setBaudRate(settings->value("BaudRate").toInt());
    //load databits for serialPort
    switch(settings->value("DataBits").toInt()){
    case 5:
        serialPort->setDataBits(QSerialPort::DataBits::Data5);
        break;
    case 6:
        serialPort->setDataBits(QSerialPort::DataBits::Data6);
        break;
    case 7:
        serialPort->setDataBits(QSerialPort::DataBits::Data7);
        break;
    case 8:
        serialPort->setDataBits(QSerialPort::DataBits::Data8);
        break;
    case -1:
        serialPort->setDataBits(QSerialPort::DataBits::UnknownDataBits);
        break;
    }
    //load flowcontrol for serialPort
    if(settings->value("FlowControl").toString().compare("NoFlowControl") == 0)
        serialPort->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    if(settings->value("FlowControl").toString().compare("HardwareControl") == 0)
        serialPort->setFlowControl(QSerialPort::FlowControl::HardwareControl);
    if(settings->value("FlowControl").toString().compare("SoftwareControl") == 0)
        serialPort->setFlowControl(QSerialPort::FlowControl::SoftwareControl);
    if(settings->value("FlowControl").toString().compare("UnknownFlowControl") == 0)
        serialPort->setFlowControl(QSerialPort::FlowControl::UnknownFlowControl);
    //load Parity for serialPort
    if(settings->value("Parity").toString().compare("NoParity") == 0)
        serialPort->setParity(QSerialPort::Parity::NoParity);
    if(settings->value("Parity").toString().compare("EvenParity") == 0)
        serialPort->setParity(QSerialPort::Parity::EvenParity);
    if(settings->value("Parity").toString().compare("OddParity") == 0)
        serialPort->setParity(QSerialPort::Parity::OddParity);
    if(settings->value("Parity").toString().compare("SpaceParity") == 0)
        serialPort->setParity(QSerialPort::Parity::SpaceParity);
    if(settings->value("Parity").toString().compare("MarkParity") == 0)
        serialPort->setParity(QSerialPort::Parity::MarkParity);
    if(settings->value("Parity").toString().compare("UnknownParity") == 0)
        serialPort->setParity(QSerialPort::Parity::UnknownParity);
    settings->endGroup();
}

void MainWindow::seriaPortDebug(){
    qDebug("Wifi Settings");
    qDebug() << "portName" << serialPort->portName();
    qDebug() << "BaudRate = " << serialPort->baudRate();
    qDebug() << serialPort->dataBits();
    qDebug() << serialPort->parity();
    qDebug() << serialPort->flowControl();
}
///dont change

void MainWindow::on_connectButton_clicked()
{
    try{
        if(!(serialPort->open(QIODevice::ReadOnly)))
            throw true;
    }
    catch(bool exception){
        if(exception){
            (new QErrorMessage())->showMessage("Can not connect to serial Port!check wifi settings again.");
            return;
        }
    }
//    QByteArray firstData("FUCK U");
//    try{
//        firstData = serialPort->readAll();
//        if(firstData.isEmpty())
//            throw true;
//    }
//    catch(bool exception){
//        if(exception){
//            (new QErrorMessage())->showMessage("No data received!Check your board again.");
//            return;
//        }
//    }
    //51840000*MAX_EXECUTION_TIME
    //2147483647
    data = new QByteArray(NULL,2147483647);
    robots = new robotsData(settings,data,1);    
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(manipulateData()));
}
