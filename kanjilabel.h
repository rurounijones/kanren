#ifndef KANJILABEL_H
#define KANJILABEL_H

#include <QLabel>

class KanjiLabel : public QLabel
{
    Q_OBJECT
public:
    KanjiLabel(QWidget *parent = 0);

public slots:
    void toggleVisibility();
};

#endif // KANJILABEL_H
