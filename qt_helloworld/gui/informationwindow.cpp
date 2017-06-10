#include "informationwindow.h"
#include <QLabel>
InformationWindow::InformationWindow()
{
    title = new QLabel("Here will be information");
    this->addWidget(title);
}
