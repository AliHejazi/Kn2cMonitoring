#include "datawindow.h"
#include "ui_datawindow.h"
#include <QCloseEvent>
#include <QThread>
#include <QString>

dataWindow::dataWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::dataWindow)
{
    ui->setupUi(this);
}

dataWindow::~dataWindow()
{
    delete ui;
}

void dataWindow::PrintData(QByteArray *data){
    s.append(data->data());
    ui->DatatextBrowser->setText(s);
}

