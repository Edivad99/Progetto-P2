#ifndef WSTIPENDIOMENSILE_H
#define WSTIPENDIOMENSILE_H

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <util/generalutil.h>
#include <model/tabellamodel.h>

class WStipendioMensile : public QFrame
{
    Q_OBJECT
public:
    WStipendioMensile(QString data, float *stipendio, QWidget *parent =0);
private:
    QString _data;
    float *_stipendio;

    void initUI();
};

#endif // WSTIPENDIOMENSILE_H
