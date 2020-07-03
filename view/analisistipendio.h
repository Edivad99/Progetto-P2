#ifndef ANALISISTIPENDIO_H
#define ANALISISTIPENDIO_H

#include <QHBoxLayout>
#include <QWidget>
#include <QBarSet>
#include <QBarSeries>
#include <QtCharts>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChartView>
#include <QPainter>
#include <util/generalutil.h>
#include <util/lista.h>
#include <view/widgets/wstipendiomensile.h>
#include <model/tabellamodel.h>

class AnalisiStipendio : public QWidget
{
    Q_OBJECT

public:
    AnalisiStipendio(lista<QStringList*> *csvData, QWidget *parent = nullptr);
    ~AnalisiStipendio() = default;

private:

    QHBoxLayout *mainLayout;
    QListWidget *listaStipendi;
    QChartView *chartView;

    void InizializzaSalario(unsigned int size, unsigned int numeroCategorie);
    void Grafico(lista<QStringList*> *csvData);
    void ListaStipendi();

    float *stipendio;
    QStringList listaMesiLetti;

};

#endif // GRAPHWINDOW_H
