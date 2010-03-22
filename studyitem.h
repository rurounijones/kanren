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

#ifndef STUDYITEM_H
#define STUDYITEM_H

#include <QObject>
#include <QtSql>

class StudyItem : public QObject
{
Q_OBJECT
public:
    explicit StudyItem(QObject *parent = 0);
signals:
    void itemUpdated(QString kanji,QString translation, QString onyoumi, QString kunyoumi);
public slots:
    void nextKanji();
    void previousKanji();

private:
    QSqlDatabase db;
    int id;
    QString kanji;
    QString translation;
    QString onyoumi;
    QString kunyoumi;
    void getStudyItemFromDatabase();
};

#endif // STUDYITEM_H
