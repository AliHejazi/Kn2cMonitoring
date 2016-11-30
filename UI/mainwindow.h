#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSerialPort>
#include <QFile>
#include <QSettings>
#include <QVector>
#include <QTextStream>
#include "settingwindow.h"
#include "datawindow.h"
#include "robotsdata.h"
#include "robotwidget.h"
#include "debugwidget.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QFile* dataFile;
    char* fuckinpointer;
    settingWindow* settingWin;
    QSerialPort* serialPort;
    dataWindow* dataWin;
    QSettings* settings;
    robotsData* robots;
    QVector<RobotWidget *> robotTabs;
    QVector<debugWidget *> debugTabs;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSerialPort *getSerialPort() const;
    void setSerialPort(QSerialPort *value);
    void loadSerialPort();
    void seriaPortDebug();
    static void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

public slots:
    void manipulateData();

private slots:
    void on_actionWifi_Settings_triggered();
    void on_actionData_triggered();
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_connectButton_clicked();

    void on_actionDebug_data_triggered();

    void on_actionMonitoring_data_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
