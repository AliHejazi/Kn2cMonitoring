#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class settingWindow;
}

class settingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit settingWindow(QWidget *parent = 0);
    ~settingWindow();

private:
    Ui::settingWindow *ui;
};

#endif // SETTINGWINDOW_H
