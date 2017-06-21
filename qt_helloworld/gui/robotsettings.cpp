#include "robotsettings.h"
#include "ui_robotsettings.h"

RobotSettings::RobotSettings(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::RobotSettings)
{
    ui->setupUi(this);
}

RobotSettings::~RobotSettings()
{
    delete ui;
}
