#-------------------------------------------------
#
# Project created by QtCreator 2017-06-05T12:58:31
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myudpclient.cpp \
    robotcontroller.cpp \
    robot.cpp \
    robotconfiguration.cpp \
    robotsettings.cpp

HEADERS  += mainwindow.h \
    myudpclient.h\
    robotcontroller.h \
    robot.h \
    robotconfiguration.h \
    robotsettings.h \
    robotPackets.h

FORMS    += mainwindow.ui \
    robotsettings.ui
