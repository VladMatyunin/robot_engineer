#ifndef ROBOTSETTINGS_H
#define ROBOTSETTINGS_H

#include <QTabWidget>

namespace Ui {
class RobotSettings;
}

class RobotSettings : public QTabWidget
{
    Q_OBJECT

public:
    explicit RobotSettings(QWidget *parent = 0);
    ~RobotSettings();

private:
    Ui::RobotSettings *ui;
};

#endif // ROBOTSETTINGS_H
