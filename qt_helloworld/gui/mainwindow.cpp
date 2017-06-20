#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myudpclient.h"
using namespace std
;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new UDPClient();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete client;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    isLight=!isLight;
    qDebug()<<isLight;
    client->processData(isLight);
}

void MainWindow::on_pushButton_5_clicked()
{
    client->connectToRobot();
}



void MainWindow::on_moveForward_pressed()
{
    client->moveForward();
}

void MainWindow::on_moveLeft_pressed()
{
    client->moveLeft();
}

void MainWindow::on_moveRight_pressed()
{
    client->moveRight();
}

void MainWindow::on_moveBack_pressed()
{
    client->moveBack();
}
