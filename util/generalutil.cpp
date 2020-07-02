#include "generalutil.h"


QString GeneralUtil::capitalizeFirstLetter(const QString& string)
{
    if(string.size()!=0)
    {
        QString result = QString(string[0].toUpper());
        if(string.size()>1)
            result.append(QString::fromStdString(string.toStdString().substr(1, string.length()-1)));
        return result;
    }
    else
    {
        return string;
    }
}

QDate GeneralUtil::strToItaDate(const QString& date)
{
    return QDate::fromString(date,"dd/MM/yyyy");
}

QString GeneralUtil::dateToItaStr(const QDate& date)
{
    return date.toString("dd/MM/yyyy");
}
