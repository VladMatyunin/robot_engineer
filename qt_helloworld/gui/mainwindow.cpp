#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myudpclient.h"
#include "robot.h"
#include "QDebug"
#include "robotsettings.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    robot = new Robot();
    client = new UDPClient(robot->controller);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete client;
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
    robot->turnElbowAndNeck(position);

}

void MainWindow::on_settings_clicked()
{
    settings = new RobotSettings();
    settings->show();
}

void MainWindow::on_neckSlider_sliderMoved(int position)
{
    robot->turnNeck(position);


}



void MainWindow::on_waist_sliderMoved(int position)
{
    robot->turnWaist(position);
}


void MainWindow::on_waistUpDown_sliderMoved(int position)
{
    robot->moveWaist(position);
}



void MainWindow::on_flipers_sliderMoved(int position)
{
    if (position<40) robot->flippers(-1);
    else if (position>60) robot->flippers(1);
    else if (position<60 && position>40) robot->flippers(0);
}

void MainWindow::on_gripper_sliderMoved(int position)
{
    if (position<40){
        ui->gripper->setValue(0);}
    else if (position>60) { ui->gripper->setValue(100);}
    else if (position<60 && position>40) { ui->gripper->setValue(50);}
}

void MainWindow::on_platformR_sliderMoved(int position)
{
    if (position>50) robot->moveRight(position);
    else if (position<50) robot->moveLeft(position);
}

void MainWindow::on_platformF_sliderMoved(int position)
{

    if (position>50) robot->moveForward(position);
    else if (position<50) robot->moveBack(position);
}


void MainWindow::on_gripper_valueChanged(int position)
{
    if (position<40){ robot->gripper(-1);
        ui->gripper->setValue(0);}
    else if (position>60) {robot->gripper(1); ui->gripper->setValue(100);}
    else if (position<60 && position>40) {robot->gripper(0); ui->gripper->setValue(50);}
}
