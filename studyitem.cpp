#include "studyitem.h"

StudyItem::StudyItem(QObject *parent) :
    QObject(parent)
{
    QObject::connect(this,SIGNAL(itemUpdated(QString,QString,QString,QString)),this->parent(),SLOT(updateWidgets(QString,QString,QString,QString)));
    id = 1;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("studyitems.sqlite");
    if ( db.open() == true )
    {
      this->getStudyItemFromDatabase();
      emit itemUpdated(kanji,translation,onyoumi,kunyoumi);
    }
}

void StudyItem::nextKanji()
{
    id++;
    this->getStudyItemFromDatabase();
    emit itemUpdated(kanji,translation,onyoumi,kunyoumi);
}
void StudyItem::previousKanji()
{
    id--;
    this->getStudyItemFromDatabase();
    emit itemUpdated(kanji,translation,onyoumi,kunyoumi);
}


void StudyItem::getStudyItemFromDatabase()
{
    QSqlQuery query;
    query.prepare("SELECT id, kanji,translation,onyoumi,kunyoumi FROM studyitems where id = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.next()) {
        kanji = query.value(1).toString();
        translation = query.value(2).toString();
        onyoumi = query.value(3).toString();
        kunyoumi = query.value(4).toString();
    }
    else
    {
        id = 0;
        this->nextKanji();
    }
}
