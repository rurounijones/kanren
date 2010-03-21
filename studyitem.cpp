#include "studyitem.h"

StudyItem::StudyItem(QObject *parent) :
    QObject(parent)
{
    QObject::connect(this,SIGNAL(itemUpdated(QString,QString)),this->parent(),SLOT(updateWidgets(QString,QString)));
    id = 1;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("studyitems.sqlite");
    if ( db.open() == true )
    {
      this->getStudyItemFromDatabase();
      emit itemUpdated(kanji,translation);
    }
}

void StudyItem::nextKanji()
{
    id++;
    this->getStudyItemFromDatabase();
    emit itemUpdated(kanji,translation);
}

void StudyItem::getStudyItemFromDatabase()
{
    QSqlQuery query;
    query.prepare("SELECT kanji,translation,onyoumi,kunyoumi FROM studyitems where id = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.next()) {
        kanji = query.value(0).toString();
        translation = query.value(1).toString();
        onyoumi = query.value(2).toString();
        kunyoumi = query.value(3).toString();
    }
    else
    {
        id = 0;
        this->nextKanji();
    }
}
