#include "myqslider.h"
#include <QSlider>
#include <QDebug>
MyQSlider::MyQSlider(QObject *parent)
{
    //connect(this, SIGNAL(sliderReleased()),this, SLOT(my_sliderMoved()));
}

void MyQSlider::my_sliderMoved(){
    int position = value();
    if (position%10!=0){
        if (position%10>5)
        setValue((position/10+1)*10);
        else setValue((position/10)*10);

    }
}
void MyQSlider::sliderReleased(){
    int i = 0;
    i++;
    i = i*7;
}
