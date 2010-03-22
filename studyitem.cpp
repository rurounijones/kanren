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
