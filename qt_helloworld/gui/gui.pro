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
    myudpserver.cpp \
    robotcontroller.cpp

HEADERS  += mainwindow.h \
    myudpclient.h \
    myudpserver.h \
    robotcontroller.h

FORMS    += mainwindow.ui
