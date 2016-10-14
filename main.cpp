#include "UI/mainwindow.h"
#include <QApplication>
#include <QSerialPortInfo>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    (new MainWindow)->show();
    return a.exec();
}
