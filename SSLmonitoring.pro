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
    UI/settingwindow.cpp \
    UI/datawindow.cpp \
    UI/tabwidget.cpp \
    constants.cpp \
    robotsdata.cpp \
    robotsensors.cpp

HEADERS  += \
    UI/mainwindow.h \
    UI/wifi.h \
    UI/settingwindow.h \
    UI/datawindow.h \
    UI/tabwidget.h \
    constants.h \
    robotsdata.h \
    robotsensors.h

FORMS    += \
    UI/mainwindow.ui \
    UI/settingwindow.ui \
    UI/datawindow.ui \
    UI/tabwidget.ui

DISTFILES += \
    setting.ini

RESOURCES += \
    Resources/image.qrc

