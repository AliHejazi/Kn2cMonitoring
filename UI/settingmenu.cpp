#include "settingmenu.h"
#include <iostream>

settingMenu::settingMenu(QWidget* parent):QMenuBar(parent)
{
    std::cout << "fuck";
}

void settingMenu::mouseReleaseEvent(QMouseEvent* Event){
    if(settingwindow == nullptr){
        qDebug("i am here");

        settingwindow = new settingWindow(this);
        settingwindow->show();
    }
    else{
        settingwindow->close();
        delete settingwindow;
        settingwindow = nullptr;
    }
}
