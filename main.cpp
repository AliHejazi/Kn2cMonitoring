#include "UI/mainwindow.h"
#include <QApplication>
#include <QSerialPortInfo>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
