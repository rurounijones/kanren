#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scribblearea.h"
#include "kanjilabel.h"
#include "studyitem.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateWidgets(QString kanji, QString translation);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    StudyItem *currentItem;
};

#endif // MAINWINDOW_H
