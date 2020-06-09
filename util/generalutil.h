#ifndef GENERALUTIL_H
#define GENERALUTIL_H

#include <QDate>
#include <QString>

class GeneralUtil
{
public:
    static QString capitalizeFirstLetter(QString string);
    static QDate strToItaDate(QString date);
    static QString dateToItaStr(QDate date);
};

#endif // GENERALUTIL_H
