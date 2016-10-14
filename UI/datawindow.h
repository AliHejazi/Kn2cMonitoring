#ifndef DATAWINDOW_H
#define DATAWINDOW_H
#include <QSerialPort>
#include <QMainWindow>

namespace Ui {
class dataWindow;
}

class dataWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit dataWindow(QWidget *parent = 0,QSerialPort* serialPort = 0);
    ~dataWindow();
    Ui::dataWindow *ui;
    QSerialPort* serialPort;
    void closeEvent(QCloseEvent *event);
public slots:
    void PrintData();
};

#endif // DATAWINDOW_H
