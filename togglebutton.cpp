#include "togglebutton.h"

ToggleButton::ToggleButton(QWidget *parent)
    : QPushButton(parent)
{
    status = true;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT( onClick()));

}

void ToggleButton::onClick()
{
   status = !status;
   emit clicked (status);
}

