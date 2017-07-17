#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "robotconfiguration.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0, RobotConfiguration *c=NULL);
    ~SettingsDialog();

private slots:
    void on_platformForward_Slider_valueChanged(int value);

    void on_platformRotate_Slider_valueChanged(int value);

    void on_Neck_Slider_valueChanged(int value);

    void on_Elbow_Slider_valueChanged(int value);

    void on_Waist_Slider_valueChanged(int value);

    void on_Shoulder_Slider_valueChanged(int value);

    void on_buttonBox_accepted();

private:
    RobotConfiguration *conf;
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
