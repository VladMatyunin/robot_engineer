#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "robot.h"
#include "robotsettings.h"
#include <QEvent>
#include <vector>
#include <QTableWidget>
#include <QProgressDialog>
struct JointForm{
    int platformF;
    int platformR;
    int shoulder;
    int elbow;
    int neck;
    int waist;

};
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    bool eventFilter(QObject* obj, QEvent* event);
    void setSlidersToStart();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();




private slots:

    void on_lightToggle_clicked();

    void on_connectButton_clicked();

    void on_settings_clicked();

    void on_gripper_valueChanged(int value);

    void on_flipper_valueChanged(int value);

    void on_acceptForms_clicked();


    void on_platformF_valueChanged(int value);

    void on_platformR_valueChanged(int value);

    void on_stopAll_clicked();

    void on_waistLeftRight_valueChanged(int value);

    void on_elbowSlider_valueChanged(int value);

    void on_neckSlider_valueChanged(int value);

    void on_waistUpDown_valueChanged(int value);
   public slots:
    void setTelemetry(TelemetryPacket &packet);
    void connectedToRobotUI();

private:
    int validateValue(QString value);
    JointForm form;
    void validateValues();
    QProgressDialog *dialog;
    Ui::MainWindow *ui;
    bool isLight;
    Robot *robot;
    RobotSettings *settings;
    int currentGripper = 0;
    int currentFlippers = 0;
    std::vector<std::vector<QTableWidgetItem> > telemetryViewItems;
    
    void setEnabledAllControls(bool);

};



#endif // MAINWINDOW_H
