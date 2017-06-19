#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QCheckBox>
#include <myudpserver.h>
#include <mainwindow.h>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyUdpServer server;
    server.show();
    MainWindow window(new QWidget);
    window.show();
    return app.exec();
}
