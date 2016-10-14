#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H
#include <QSettings>
#include <QMainWindow>
#include <QCloseEvent>
#include <QSerialPort>

namespace Ui {
class settingWindow;
}

class settingWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSettings* setting;
    QSerialPort* serialPort;
    QMainWindow* mainWindow;
    explicit settingWindow(QMainWindow* mianWindow,QSettings* setting,QSerialPort* serialPort);
    ~settingWindow();
    void closeEvent(QCloseEvent* event);
    void printWifiSettins();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_saveAsDeafultPushButton_clicked();

private:

    Ui::settingWindow *ui;
};

#endif // SETTINGWINDOW_H
