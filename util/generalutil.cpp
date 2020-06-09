#include "generalutil.h"


QString GeneralUtil::capitalizeFirstLetter(QString string)
{
    QString result = QString(string[0].toUpper());
    result.append(QString::fromStdString(string.toStdString().substr(1, string.length()-1)));
    return result;
}

QDate GeneralUtil::strToItaDate(QString date)
{
    return QDate::fromString(date,"dd/MM/yyyy");
}

QString GeneralUtil::dateToItaStr(QDate date)
{
    return date.toString("dd/MM/yyyy");
}
