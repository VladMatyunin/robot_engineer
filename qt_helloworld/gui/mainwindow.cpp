#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myudpclient.h"
#include "robot.h"
#include "QDebug"
using namespace std
;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new UDPClient();
    robot = new Robot();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete client;
}


void MainWindow::on_moveForward_pressed()
{
    robot->moveForward();
}

void MainWindow::on_moveLeft_pressed()
{
    robot->moveLeft();
}

void MainWindow::on_moveRight_pressed()
{
    robot->moveRight();
}

void MainWindow::on_moveBack_pressed()
{
    robot->moveBack();
}

void MainWindow::on_lightToggle_clicked()
{
    isLight = !isLight;
    robot->turnLight();
}

void MainWindow::on_connectButton_clicked()
{
    client->connectToRobot();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    qDebug()<<"moved";
    robot->turnWaist();
}

void MainWindow::on_horizontalSlider_2_rangeChanged(int min, int max)
{
    robot->turnWaist();
}

void MainWindow::on_flippersUp_clicked()
{
    robot->flippersUp();
}

void MainWindow::on_flipers_down_rangeChanged(int min, int max)
{
    qDebug()<<min<<max;
}

void MainWindow::on_flipers_down_sliderMoved(int position)
{
    //qDebug()<<position;
    robot->flippersDown(position);
}

void MainWindow::on_openGripper_clicked()
{
    robot->openGripper();
}

void MainWindow::on_closeGripper_clicked()
{
    robot->closeGripper();
}

void MainWindow::on_test_clicked()
{
    robot->turnWaist();
}
