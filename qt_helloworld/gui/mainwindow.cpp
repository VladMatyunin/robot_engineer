#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myudpclient.h"
#include "robot.h"
#include "QDebug"
#include "robotsettings.h"
#include <QKeyEvent>
#include <robotPackets.h>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    robot = new Robot();
    client = new UDPClient(robot->controller);
    connect(robot,SIGNAL(telemetryChanged(TelemetryPacket*)),this,SLOT(setTelemetry(TelemetryPacket*)));
    qApp->installEventFilter(this);
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



void MainWindow::on_gripper_valueChanged(int value)
{
    qDebug()<<value;
    robot->gripper(value);
}

void MainWindow::on_flipper_valueChanged(int value)
{

    robot->flippers(value);
}

void MainWindow::on_acceptForms_clicked()
{
    form->validateValues();
    //robot->moveForward(form->platformF);
    //robot->moveLeft(form->platformR);
    robot->moveWaist(form->shoulder);
    robot->turnElbowAndNeck(form->elbow);
    robot->turnNeck(form->neck);
    robot->turnWaist(form->waist);
}




void MainWindow::on_platformF_valueChanged(int value)
{
    if (value%10==0)
        robot->moveD(value);
}

void MainWindow::on_settings_clicked()
{

}

void MainWindow::on_platformR_valueChanged(int value)
{
    if (value%10==0)
        robot->moveR(value);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    if (event->type()==QEvent::KeyPress) {
            QKeyEvent* key = static_cast<QKeyEvent*>(event);
            if ( (key->key()==Qt::Key_Space)) {
                on_stopAll_clicked();
            } else {
                return QObject::eventFilter(obj, event);
            }
            return true;
        } else {
            return QObject::eventFilter(obj, event);
        }
        return false;
}

void MainWindow::on_stopAll_clicked()
{
    robot->stopAll();
    setSlidersToStart();
}
void MainWindow::setSlidersToStart(){
    ui->waistUpDown->setValue(50);
    ui->waistLeftRight->setValue(50);
    ui->elbowSlider->setValue(50);
    ui->neckSlider->setValue(50);
    ui->gripper->setValue(0);
    ui->flipper->setValue(0);
    ui->platformF->setValue(50);
    ui->platformR->setValue(50);
}

void MainWindow::on_waistLeftRight_valueChanged(int value)
{
    if (value%10==0){
        robot->turnWaist(value);
    }
}

void MainWindow::on_elbowSlider_valueChanged(int value)
{
    if (value%10==0){
        robot->turnElbowAndNeck(value);
    }
}

void MainWindow::on_neckSlider_valueChanged(int value)
{
    if (value%10==0){
        robot->turnNeck(value);
    }
}

void MainWindow::on_waistUpDown_valueChanged(int value)
{
    if(value%10==0){
        robot->moveWaist(value);
    }
}
void MainWindow::setTelemetry(TelemetryPacket *packet){
    qDebug()<<"GEET";
}
