#ifndef INFORMATIONWINDOW_H
#define INFORMATIONWINDOW_H
#include <QVBoxLayout>
#include <QLabel>
class InformationWindow : public QVBoxLayout
{
private:
    QLabel *title;
public:
    InformationWindow();
};

#endif // INFORMATIONWINDOW_H
