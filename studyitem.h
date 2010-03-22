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
