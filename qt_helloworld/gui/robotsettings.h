#ifndef ROBOTSETTINGS_H
#define ROBOTSETTINGS_H

#include <QTabWidget>
#include "robotconfiguration.h"
namespace Ui {
class RobotSettings;
}

class RobotSettings : public QTabWidget
{
    Q_OBJECT

public:
    explicit RobotSettings(QWidget *parent = 0);
    //explicit RobotSettings(QWidget *parent = 0, RobotConfiguration *conf);
    ~RobotSettings();

private:
    RobotConfiguration *conf;
    Ui::RobotSettings *ui;
};

#endif // ROBOTSETTINGS_H
