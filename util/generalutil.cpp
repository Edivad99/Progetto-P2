#include "generalutil.h"


QString GeneralUtil::capitalizeFirstLetter(QString string)
{
    QString result = QString(string[0].toUpper());
    result.append(QString::fromStdString(string.toStdString().substr(1, string.length()-1)));
    return result;
}
