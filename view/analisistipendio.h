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

class AnalisiStipendio : public QWidget
{
    Q_OBJECT

public:
    AnalisiStipendio(lista<QStringList*> *csvData, QWidget *parent = nullptr);
    ~AnalisiStipendio() = default;

private:

    QHBoxLayout *mainLayout;
    QVBoxLayout *mainLayoutDati;
    QChartView *chartView;

};

#endif // GRAPHWINDOW_H
