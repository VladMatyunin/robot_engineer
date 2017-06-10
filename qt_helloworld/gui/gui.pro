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
    counter.cpp \
    myudpclient.cpp \
    myudpserver.cpp \
    robotcontroller.cpp \
    jointcontrolform.cpp \
    platformcontrolform.cpp \
    informationwindow.cpp

HEADERS  += mainwindow.h \
    counter.h \
    myudpclient.h \
    myudpserver.h \
    robotcontroller.h \
    jointcontrolform.h \
    platformcontrolform.h \
    informationwindow.h

FORMS    += mainwindow.ui
