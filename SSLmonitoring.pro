#-------------------------------------------------
#
# Project created by QtCreator 2016-09-21T13:16:04
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SSLmonitoring
TEMPLATE = app


SOURCES += main.cpp\
    UI/mainwindow.cpp \
    UI/wifi.cpp \
    serial.cpp \
    UI/settingmenu.cpp \
    UI/settingwindow.cpp

HEADERS  += \
    UI/mainwindow.h \
    UI/wifi.h \
    serial.h \
    UI/settingmenu.h \
    UI/settingwindow.h

FORMS    += \
    UI/mainwindow.ui \
    UI/settingwindow.ui

RESOURCES += \
    images.qrc

DISTFILES +=
