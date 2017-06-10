#ifndef PLATFORMCONTROLFORM_H
#define PLATFORMCONTROLFORM_H
#include <QPushButton>
#include <QVBoxLayout>
class PlatformControlForm : public QVBoxLayout
{

public:
    PlatformControlForm();
private:
    QPushButton *up;
    QPushButton *down;
    QPushButton *left;
    QPushButton *right;
};

#endif // PLATFORMCONTROLFORM_H
