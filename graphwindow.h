#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QHBoxLayout>
#include <QWidget>
#include <QBarSet>
#include <QBarSeries>
#include <QtCharts>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChartView>
#include <QPainter>

class GraphWindow : public QWidget
{
    Q_OBJECT

public:
    GraphWindow(QStringList testo ,QWidget *parent = nullptr);
    ~GraphWindow() = default;

private:

    QHBoxLayout *mainLayout;
    QVBoxLayout *mainLayoutDati;
    QChartView *chartView;

};

#endif // GRAPHWINDOW_H
