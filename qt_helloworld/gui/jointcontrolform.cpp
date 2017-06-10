#include "jointcontrolform.h"
#include <QVBoxLayout>
#include <QSlider>
JointControlForm::JointControlForm()
{
    joint1 = new QSlider();
    joint2 = new QSlider();
    joint3 = new QSlider();
    this->addWidget(joint1);
    this->addWidget(joint2);
    this->addWidget(joint3);

}
JointControlForm::~JointControlForm(){
    delete joint1,joint2,joint3;
}
