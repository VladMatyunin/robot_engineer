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
    class JointForm;
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

    void on_platformR_sliderMoved(int position);

    void on_gripper_valueChanged(int value);

    void on_flipper_valueChanged(int value);

    void on_acceptForms_clicked();

    void on_platformF_sliderReleased();

    void on_platformF_rangeChanged(int min, int max);

    void on_platformF_sliderMoved(int position);

    void on_platformF_valueChanged(int value);

private:

    Ui::MainWindow *ui;
    bool isLight;
    UDPClient *client;
    Robot *robot;
    RobotSettings *settings;
    JointForm *form;
    int currentGripper = 0;
    int currentFlippers = 0;
    class JointForm{
    public:
            int neck = 0;
            int elbow = 0;
            int waist = 0;
            int shoulder = 0;
            int platformR = 0;
            int platformF = 0;
            MainWindow *window;

        public:
            void validateValues();

            JointForm(MainWindow *window);
            ~JointForm();
        private:
            int validateValue(QString value);
        };
};


#endif // MAINWINDOW_H
