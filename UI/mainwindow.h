#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSerialPort>
#include <QFile>
#include <QSettings>
#include "settingwindow.h"
#include "datawindow.h"
#include "robotsdata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    settingWindow* settingWin;
    QSerialPort* serialPort;
    dataWindow* dataWin;
    QFile* dataFile;
    QSettings* settings;
    robotsData* robots;
    QByteArray* data;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSerialPort *getSerialPort() const;
    void setSerialPort(QSerialPort *value);
    void loadSerialPort();
    void seriaPortDebug();

public slots:
    void manipulateData();

private slots:
    void on_actionWifi_Settings_triggered();
    void on_actionData_triggered();
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_connectButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
