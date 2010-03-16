#include "kanjilabel.h"

KanjiLabel::KanjiLabel(QWidget *parent)
{
    this->setParent(parent);
}

void KanjiLabel::toggleVisibility()
{
    this->setVisible(!this->isVisible());
}
