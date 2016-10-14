#include "datawindow.h"
#include "ui_datawindow.h"
#include <QCloseEvent>
#include <QThread>

dataWindow::dataWindow(QWidget *parent ,QSerialPort* serialPort):
    QMainWindow(parent),
    ui(new Ui::dataWindow),
    serialPort(serialPort)
{
    ui->setupUi(this);
}

dataWindow::~dataWindow()
{
    delete ui;
}

void dataWindow::PrintData(){
    QThread::currentThread()->msleep(300);
//    ui->DatatextBrowser->setText(serialPort->rea);
    ui->DatatextBrowser->setText(QString::fromStdString(serialPort->readAll().toStdString()));
}

void dataWindow::closeEvent(QCloseEvent *event)
{
    disconnect(serialPort,SIGNAL(readyRead()),this,SLOT(PrintData()));
    event->accept();
    delete this;
}
