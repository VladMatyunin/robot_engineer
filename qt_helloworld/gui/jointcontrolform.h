#ifndef JOINTCONTROLFORM_H
#define JOINTCONTROLFORM_H
#include <QObject>
#include <QSlider>
#include <QVBoxLayout>
class JointControlForm : public QVBoxLayout
{
public:
    JointControlForm();
    ~JointControlForm();


private:
    QSlider *joint1;
    QSlider *joint2;
    QSlider *joint3;
};

#endif // JOINTCONTROLFORM_H
