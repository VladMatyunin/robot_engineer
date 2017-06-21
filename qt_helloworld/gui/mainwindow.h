#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myudpclient.h>
#include "robot.h"
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
    void on_moveForward_pressed();

    void on_moveLeft_pressed();

    void on_moveRight_pressed();

    void on_moveBack_pressed();

    void on_lightToggle_clicked();

    void on_connectButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_rangeChanged(int min, int max);

    void on_flippersUp_clicked();

    void on_flipers_down_rangeChanged(int min, int max);

    void on_flipers_down_sliderMoved(int position);

    void on_openGripper_clicked();

    void on_closeGripper_clicked();

    void on_test_clicked();

private:
    Ui::MainWindow *ui;
    bool isLight;
    UDPClient *client;
    Robot *robot;
};

#endif // MAINWINDOW_H
