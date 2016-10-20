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
    void loadUISettings();
    void saveSerialPortSettings();
    void saveDefaultSettings();
    void seriaPortDebug();

private slots:

    void on_saveAsDeafultPushButton_clicked();

    void on_cancelButton_clicked();

    void on_OKButton_clicked();

private:

    Ui::settingWindow *ui;
};

#endif // SETTINGWINDOW_H
