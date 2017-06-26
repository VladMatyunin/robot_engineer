#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myudpclient.h>
#include "robot.h"
#include "robotsettings.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();




private slots:

    void on_lightToggle_clicked();

    void on_connectButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_settings_clicked();

    void on_neckSlider_sliderMoved(int position);


    void on_waist_sliderMoved(int position);

    void on_waistUpDown_sliderMoved(int position);


    void on_flipers_sliderMoved(int position);


    void on_gripper_sliderMoved(int position);


    void on_platformR_sliderMoved(int position);


    void on_platformF_sliderMoved(int position);

    void on_gripper_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    bool isLight;
    UDPClient *client;
    Robot *robot;
    RobotSettings *settings;
};

#endif // MAINWINDOW_H
