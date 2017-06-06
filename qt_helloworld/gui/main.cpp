#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include "counter.h"
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QCheckBox>
#include <myudpserver.h>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel lbl("0");
    QPushButton cmd("ADD");
    Counter counter;
    QWidget mainWindow;
    QWidget serverWindow;
    MyUdpServer server;
    server.show();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *lowLayout = new QHBoxLayout;
    QCheckBox lightChange("Light");
    QPushButton buttonB("B");
    QPushButton buttonC("C");

    lowLayout->addWidget(&lightChange);
    lowLayout->addWidget(&buttonB);
    lowLayout->addWidget(&buttonC);
    mainLayout->addWidget(&lbl);
    //    mainLayout->addStretch(0.2);
        mainLayout->addWidget(&cmd);
        lowLayout->setMargin(50);

    mainLayout->addLayout(lowLayout);


    mainWindow.setLayout(mainLayout);
    mainWindow.show();
    mainWindow.move(100,100);
    mainWindow.resize(200,150);
    QObject::connect(&lightChange,SIGNAL(toggled(bool)),&counter,SLOT(changeLight()));
    QObject::connect(&cmd,SIGNAL(clicked()),&counter, SLOT(slotInc()));
    QObject::connect(&counter,SIGNAL(counterChanged(int)),&lbl,SLOT(setNum(int)));
    QObject::connect(&counter,SIGNAL(goodbye()),&app,SLOT(quit()));
    return app.exec();
}
