#ifndef SETTINGMENU_H
#define SETTINGMENU_H
#include <QMenuBar>
#include <QWidget>
#include "settingwindow.h"

class settingMenu : public QMenuBar
{
public:
    explicit settingMenu(QWidget* parent);
    void mouseReleaseEvent(QMouseEvent* Event);
private:
    settingWindow* settingwindow;
};

#endif // SETTINGMENU_H
