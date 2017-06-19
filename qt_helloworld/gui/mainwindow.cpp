#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myudpclient.h"
using namespace std
;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new UDPClient();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete client;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    isLight=!isLight;
    qDebug()<<isLight;
    client->processData(isLight);
}
