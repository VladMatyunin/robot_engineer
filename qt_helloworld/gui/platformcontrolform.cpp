#include "platformcontrolform.h"

#include <QPushButton>
PlatformControlForm::PlatformControlForm()
{
    up = new QPushButton("^");
    down = new QPushButton("_");
    left = new QPushButton("<");
    right = new QPushButton(">");
    this->addWidget(up);
    this->addWidget(left);
    this->addWidget(right);
    this->addWidget(down);
}
