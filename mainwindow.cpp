#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentItem = new StudyItem(this);
    QObject::connect(ui->nextKanjiButton,SIGNAL(clicked()),currentItem,SLOT(nextKanji()));
    QObject::connect(ui->previousKanjiButton,SIGNAL(clicked()),currentItem,SLOT(previousKanji()));
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

void MainWindow::updateWidgets(QString kanji, QString translation, QString onyoumi, QString kunyoumi)
{
    ui->writingPadWidget->clearImage();
    this->ui->kanjiTemplateLabel->setText(kanji);
    this->ui->translationTextLabel->setText(translation);
    this->ui->onyoumiTextLabel->setText(onyoumi);
    this->ui->kunyoumiTextLabel->setText(kunyoumi);
}
