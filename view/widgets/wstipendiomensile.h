#ifndef WSTIPENDIOMENSILE_H
#define WSTIPENDIOMENSILE_H

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QDate>
#include <util/generalutil.h>
#include <model/tabellamodel.h>

class WStipendioMensile : public QFrame
{
    Q_OBJECT
public:
    WStipendioMensile(QDate data, float *stipendio, QWidget *parent =0);
private:
    QDate _data;
    float *_stipendio;

    void initUI();
};

#endif // WSTIPENDIOMENSILE_H
