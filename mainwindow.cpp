/*

    This file is part of Kanren, Copyright 2010 Jeffrey Jones

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

*/

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
