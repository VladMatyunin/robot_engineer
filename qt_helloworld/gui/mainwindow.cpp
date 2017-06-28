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
MainWindow::JointForm::JointForm(MainWindow *ui){
    this->window = ui;
}

void MainWindow::JointForm::validateValues(){
    this->elbow = validateValue(window->ui->elbowLineEdit->text());
    this->neck = validateValue(window->ui->neckLineEdit->text());
    this->shoulder = validateValue(window->ui->shoulderLineEdit->text());
    this->waist = validateValue(window->ui->waistLineEdit->text());
    this->platformF = validateValue(window->ui->platformForwardLineEdit->text());
    this->platformR = validateValue(window->ui->platformRLineEdit->text());

}
int MainWindow::JointForm::validateValue(QString value){
    if(value.isNull()|| value.isEmpty())
        return 0;
    return value.toInt();
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
    if (position%10!=0){
        ui->neckSlider->setValue((position/10+1)*10);
    }else
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

void MainWindow::on_platformR_sliderMoved(int position)
{
    if (position>50) robot->moveRight(position);
    else if (position<50) robot->moveLeft(position);
}


void MainWindow::on_gripper_valueChanged(int value)
{

    robot->gripper(value);
}

void MainWindow::on_flipper_valueChanged(int value)
{

    robot->flippers(value);
}

void MainWindow::on_acceptForms_clicked()
{
    form->validateValues();
    robot->moveForward(form->platformF);
    robot->moveLeft(form->platformR);
    robot->moveWaist(form->shoulder);
    robot->turnElbowAndNeck(form->elbow);
    robot->turnNeck(form->neck);
    robot->turnWaist(form->waist);
}


void MainWindow::on_platformF_sliderReleased()
{

}

void MainWindow::on_platformF_rangeChanged(int min, int max)
{
    qDebug()<<min<<max;
}

void MainWindow::on_platformF_sliderMoved(int position)
{

}

void MainWindow::on_platformF_valueChanged(int value)
{
    if(value%10==0) qDebug()<<"AWWDAS";
}
