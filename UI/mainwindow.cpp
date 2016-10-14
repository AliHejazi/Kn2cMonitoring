#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_datawindow.h"
#include <QFileDialog>
#include <QTextStream>

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
    robots = new robotsData(0);
    settings = new QSettings("/home/jafar/kn2cMonitoring/source/setting.ini",QSettings::IniFormat);
    serialPort = new QSerialPort();
//    settings->beginGroup("wifiSettings");
        //tanzim setting
//    settings->endGroup();
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
   data = data + serialPort->readAll();
   QByteArray copyData(data);
   QTextStream out(dataFile);
   out << copyData;
   out.flush();
   robots->updateData(data);
}
