#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentItem = new StudyItem(this);
    QObject::connect(ui->nextKanjibutton,SIGNAL(clicked()),currentItem,SLOT(nextKanji()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::updateWidgets(QString kanji, QString translation)
{
    ui->writingPadWidget->clearImage();
    this->ui->kanjiTemplateLabel->setText(kanji);
    this->ui->translationLabel->setText(translation);
}
