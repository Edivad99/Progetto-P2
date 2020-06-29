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

class AnalisiStipendio : public QWidget
{
    Q_OBJECT

public:
    AnalisiStipendio(lista<QStringList*> *csvData, QWidget *parent = nullptr);
    ~AnalisiStipendio() = default;

private:

    QHBoxLayout *mainLayout;
    QListWidget *dati;
    QChartView *chartView;

    void Grafico(lista<QStringList*> *csvData);
    void SalarioTot(lista<QStringList*> *csvData, unsigned int N);
    void InizializzaSalario(unsigned int size, unsigned int N);
    float *stipendio;

};

#endif // GRAPHWINDOW_H
