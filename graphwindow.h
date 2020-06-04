#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QHBoxLayout>
#include <QWidget>
#include <QBarSet>
#include <QBarSeries>
#include <QChart>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChartView>
#include <QPainter>

class GraphWindow : public QWidget
{
    Q_OBJECT

public:
    GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow() = default;

private:

    QHBoxLayout *mainLayout;
};

#endif // GRAPHWINDOW_H
