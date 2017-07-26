#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "robot.h"
#include <QEvent>
#include <vector>
#include <QTableWidget>
#include <QProgressDialog>
#include "settingsdialog.h"
#include "robotpositioncontroller.h"
/*
 * structure needed to work with input windows
 */
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
    /*
     * overrided method to handle hot keys
     */
    bool eventFilter(QObject* obj, QEvent* event);

    //needed to set sliders to start while pressing PANIC button(space)
    void setSlidersToStart();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



    /*
 * slots to work with ui(sliders, buttons and inputs)
 *
 */
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

    void on_acceptButton_clicked();

public slots:
    //slot to control telemetry from client(robot) and show it
    void setTelemetry(char *data);
    //slot called when client connected to show button(disconnected)
    void connectedToRobotUI();

private:
    //sets all input windows to zero
    void setInputToZero();

    /* converts speed form sliders(from 0 to 100) to robot speed(from -32000 to 32000)
     * uses robotConfiguration to convert MAX_SPEED from configuration
     */
    int getRealSpeed(int speed, int maxSpeed);

    //validates value from input window
    int validateValue(QString value);

    JointForm *form;

    //collects all windows and call validateValue() method
    void validateValues();

    //progress dialog to show, when connecting to robot
    QProgressDialog *dialog;
    Ui::MainWindow *ui;
    bool isLight;

    //main class to work with robot, see description in headers
    Robot *robot;
    RobotPositionController *posController;
    //settings dialog to configure robot speed
    SettingsDialog *settings;

    int currentGripper = 0;
    int currentFlippers = 0;

    //enables and disables all robot control items(sliders, inputs etc)
    //needed to work with slot connectedToRobotUI() method
    void setEnabledAllControls(bool);

};



#endif // MAINWINDOW_H
