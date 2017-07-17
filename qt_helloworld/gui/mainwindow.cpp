#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "robot.h"
#include "QDebug"
#include <QKeyEvent>
#include <QStandardItem>
#include <robotPackets.h>
#include <robotcontroller.h>
#include <QProgressDialog>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new JointForm;
    robot = new Robot();
    settings = new SettingsDialog(this,robot->configuration);
    connect(robot,SIGNAL(telemetryChanged(TelemetryPacket&)),this,SLOT(setTelemetry(TelemetryPacket&)));
    qApp->installEventFilter(this);
    dialog = new QProgressDialog("Connecting to robot...", "Cancel", 0, 0);
    dialog->setWindowModality(Qt::WindowModal);
    QTableWidget *widget = ui->telemetryView;
    for(int i = 0; i < 10; ++i){
        widget->setItem(i,0,new QTableWidgetItem());
        widget->setItem(i,1,new QTableWidgetItem());
    }
    QStringList *list  = new QStringList();
    RobotController *c = robot->controller;
    connect(robot->controller,SIGNAL(connectedToRobot()),this,SLOT(connectedToRobotUI()));
    *list<<"grippersR"           //1
        <<"shoulder"             //2
       <<"neck"                 //3
      <<"elbow"                //4
     <<"grippersF"            //5
    <<"waist"                //6
    <<"platformRight"        //7
    <<"platformLeft"         //8
    <<"flippers"             //9
    <<"Light";               //10
    widget->setVerticalHeaderLabels(*list);

}



void MainWindow::validateValues(){
    form->elbow = validateValue(ui->elbowLineEdit->text());
    form->neck = validateValue(ui->neckLineEdit->text());
    form->shoulder = validateValue(ui->shoulderLineEdit->text());
    form->waist = validateValue(ui->waistLineEdit->text());
    form->platformF = validateValue(ui->platformForwardLineEdit->text());
    form->platformR = validateValue(ui->platformRLineEdit->text());

}
int MainWindow::validateValue(QString value){
    if(value.isNull()|| value.isEmpty())
        return 0;
    return value.toInt();
}





MainWindow::~MainWindow()
{
    delete dialog, form;
    delete ui;
    delete robot, settings;
}

void MainWindow::on_lightToggle_clicked()
{
    isLight = !isLight;
    robot->turnLight();
}

void MainWindow::on_connectButton_clicked()
{
    if (!robot->isConnected){
        robot->connectToEngineer();

        dialog->exec();
    }
    else{
        robot->isConnected=false;
        setEnabledAllControls(false);
        robot->controller->disconnectClient();
        ui->connectButton->setText("Connect");
    }
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
    validateValues();
    if(form->platformF>0){
        robot->moveD(form->platformF);
        if(form->platformR>0)
            robot->moveR(form->platformR);
    }
    else{
        if(form->platformR>0)
            robot->moveR(form->platformR);
        else{
            robot->moveWaist(form->shoulder);
            if (form->waist>0)
                robot->turnWaist(form->waist);
        }
    }


    if(form->elbow>0)
        robot->turnElbowAndNeck(form->elbow);
    else
        robot->turnNeck(form->neck);
}




void MainWindow::on_platformF_valueChanged(int value)
{
    if (value%10==0)
        if (value==50)
            robot->controller->stopPlatformD();
        else
            robot->moveD(getRealSpeed(value, robot->configuration->platformForwardSpeed));
}

void MainWindow::on_settings_clicked()
{
    settings->show();


}

void MainWindow::on_platformR_valueChanged(int value)
{
    if (value%10==0)
        if (value==50)
            robot->controller->stopPlatformR();
        else
            robot->moveR(getRealSpeed(value, robot->configuration->platformRotateSpeed));
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Space)) {
            qDebug()<<"STTTOOOOP";
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
    setInputToZero();
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
void MainWindow::setInputToZero(){
    ui->elbowLineEdit->setText("0");
    ui->neckLineEdit->setText("0");
    ui->shoulderLineEdit->setText("0");
    ui->waistLineEdit->setText("0");
    ui->platformForwardLineEdit->setText("0");
    ui->platformRLineEdit->setText("0");
}

void MainWindow::on_waistLeftRight_valueChanged(int value)
{
    if (value%10==0){
        if (value==50)
            robot->controller->stopWaist();
        else
            robot->turnWaist(getRealSpeed( value, robot->configuration->waistSpeed));
    }
}

void MainWindow::on_elbowSlider_valueChanged(int value)
{
    if (value%10==0){
        if (value==50)
            robot->controller->stopElbowNeck();
        else
            robot->turnElbowAndNeck(getRealSpeed( value,robot->configuration->elbowSpeed));
    }
}

void MainWindow::on_neckSlider_valueChanged(int value)
{
    if (value%10==0){
        if (value==50)
            robot->controller->stopNeck();
        else
            robot->turnNeck(getRealSpeed( value, robot->configuration->neckSpeed));
    }
}

void MainWindow::on_waistUpDown_valueChanged(int value)
{
    if(value%10==0){
        if (value==50)
            robot->controller->stopWaistUpDown();
        else
            robot->moveWaist(getRealSpeed(value,robot->configuration->shouldersSpeed));
    }
}
void MainWindow::setTelemetry(TelemetryPacket &packet){

    QTableWidget *widget = ui->telemetryView;
    for(int i = 0; i < 10; ++i){
        QTableWidgetItem *itemSpeed = widget->item(i,0);
        QTableWidgetItem *itemPosition = widget->item(i,1);
        int robotSpeed = packet.M_DATA[i].SPEED;
        int robotPosition = packet.M_DATA[i].POSITION;
        itemSpeed->setText(QString::number(robotSpeed));
        itemPosition->setText(QString::number(robotPosition));
        ui->telemetryView->item(i,0)->setText(QString::number(packet.M_DATA[i].SPEED));
        ui->telemetryView->item(i,1)->setText(QString::number(packet.M_DATA[i].POSITION));
    }
    delete &packet;
}
void MainWindow::connectedToRobotUI(){
    ui->connectButton->setText("Disconnect");
    robot->isConnected = true;
    setEnabledAllControls(true);
    dialog->hide();
    qDebug()<<"CONNECTED";
}
void MainWindow::setEnabledAllControls(bool v){
    ui->waistUpDown->setEnabled(v);
    ui->elbowSlider->setEnabled(v);
    ui->waistLeftRight->setEnabled(v);
    ui->gripper->setEnabled(v);
    ui->flipper->setEnabled(v);
    ui->neckSlider->setEnabled(v);
    ui->platformF->setEnabled(v);
    ui->platformR->setEnabled(v);

    ui->elbowLineEdit->setEnabled(v);
    ui->neckLineEdit->setEnabled(v);
    ui->shoulderLineEdit->setEnabled(v);
    ui->waistLineEdit->setEnabled(v);
    ui->platformForwardLineEdit->setEnabled(v);
    ui->platformRLineEdit->setEnabled(v);
}


int MainWindow::getRealSpeed(int speed, int maxSpeed){
    int realSpeed = 0;
    realSpeed = (speed-50)*(maxSpeed/50);
    qDebug()<<realSpeed;
    return realSpeed;
}
