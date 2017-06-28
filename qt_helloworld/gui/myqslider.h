#ifndef MYQSLIDER_H
#define MYQSLIDER_H

#include <QObject>
#include <QSlider>
class MyQSlider : public QSlider
{
    Q_OBJECT
public:
    explicit MyQSlider(QObject *parent = 0);


signals:

public slots:
    void my_sliderMoved();

    void sliderReleased();

};

#endif // MYQSLIDER_H
