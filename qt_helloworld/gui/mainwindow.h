#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myudpclient.h>
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
    void on_checkBox_toggled(bool checked);

    void on_pushButton_5_clicked();

    void on_moveForward_pressed();

    void on_moveLeft_pressed();

    void on_moveRight_pressed();

    void on_moveBack_pressed();

private:
    Ui::MainWindow *ui;
    bool isLight;
    UDPClient *client;
};

#endif // MAINWINDOW_H
