#ifndef DATAWINDOW_H
#define DATAWINDOW_H
#include <QSerialPort>
#include <QMainWindow>
#include <QByteArray>

namespace Ui {
class dataWindow;
}

class dataWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString s;
    explicit dataWindow(QWidget *parent = 0);
    ~dataWindow();
    Ui::dataWindow *ui;

public slots:
    void PrintData(QByteArray *data);

};

#endif // DATAWINDOW_H
