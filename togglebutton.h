#ifndef TOGGLEBUTTON_H
#define TOGGLEBUTTON_H

#include <QPushButton>

class ToggleButton : public QPushButton
{
  Q_OBJECT
public:

    explicit ToggleButton(QWidget *parent = 0);

signals:
    void clicked(bool);

public slots:
    void onClick();

private:
    bool status;

};

#endif // TOGGLEBUTTON_H
