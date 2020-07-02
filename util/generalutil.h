#ifndef GENERALUTIL_H
#define GENERALUTIL_H

#include <QDate>
#include <QString>

class GeneralUtil
{
public:
    static QString capitalizeFirstLetter(const QString& string);
    static QDate strToItaDate(const QString& date);
    static QString dateToItaStr(const QDate& date);
};

#endif // GENERALUTIL_H
