#-------------------------------------------------
#
# Project created by QtCreator 2016-09-21T13:16:04
#
#-------------------------------------------------

QT       += core gui serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SSLmonitoring
TEMPLATE = app


SOURCES += main.cpp\
    UI/mainwindow.cpp \
    UI/settingwindow.cpp \
    UI/datawindow.cpp \
    robotsdata.cpp \
    robotsensors.cpp \
    UI/robotwidget.cpp \
    qcustomplot.cpp \
    UI/debugwidget.cpp

HEADERS  += \
    UI/mainwindow.h \
    UI/settingwindow.h \
    UI/datawindow.h \
    constants.h \
    robotsdata.h \
    robotsensors.h \
    UI/robotwidget.h \
    qcustomplot.h \
    UI/debugwidget.h

FORMS    += \
    UI/mainwindow.ui \
    UI/settingwindow.ui \
    UI/datawindow.ui \
    UI/robotwidget.ui \
    UI/debugwidget.ui

DISTFILES += \
    setting.ini

RESOURCES += \
    Resources/image.qrc

