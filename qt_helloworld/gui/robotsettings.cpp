#include "robotsettings.h"
#include "ui_robotsettings.h"
#include "robotconfiguration.h"
//RobotSettings::RobotSettings(QWidget *parent, RobotConfiguration *conf) :
//    QTabWidget(parent),
//    ui(new Ui::RobotSettings)
//{
//    this->conf = conf;

//    ui->setupUi(this);
//    ui->fwrd_platf_input->setText(conf->platformForwardSpeed);
//    ui->rt_platf_input->setText(conf->platformRotateSpeed);
//    ui->platform_forward_settings->setValue(conf->platformForwardSpeed);
//    ui->platform_settings_rotate->setValue(conf->platformRotateSpeed);
//}
RobotSettings::RobotSettings(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::RobotSettings)
{
    this->conf = conf;

    ui->setupUi(this);
}

RobotSettings::~RobotSettings()
{
    delete ui;
}
