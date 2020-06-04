#include "graphwindow.h"

GraphWindow::GraphWindow(QStringList testo, QWidget *parent): QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    mainLayoutDati = new QVBoxLayout();
    setLayout(mainLayout);

    setMinimumSize(QSize(650,650));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //TODO: Da rimuovere e mettere nel file css appena possibile
    mainLayout->setMargin(0);

    float salarioTot[]={0,0,0,0,0};
    QDate data =QDate::fromString(testo.at(0),"MMMM;yyyy");
    for(int i=1;i<testo.size();++i)
    {
        QStringList linea=testo.at(i).split(";");
        QString tipologia=linea.at(3);
        float salario=linea.at(5).toFloat();
        if(tipologia=="Operaio")
        {
            salarioTot[0]+=salario;
        }
        else if(tipologia=="Impiegato")
        {
            salarioTot[1]+=salario;
        }
        else if(tipologia=="Rappresentante")
        {
            salarioTot[2]+=salario;
        }
        else if(tipologia=="StudenteLavoratore")
        {
            salarioTot[3]+=salario;
        }
        else
        {
            salarioTot[4]+=salario;//altro
        }
    }



    QBarSet *set0 = new QBarSet("Operaio");
    QBarSet *set1 = new QBarSet("Impiegato");
    QBarSet *set2 = new QBarSet("Rappresentante");
    QBarSet *set3 = new QBarSet("StudenteLavoratore");
    QBarSet *set4 = new QBarSet("Altro");

    *set0 << salarioTot[0];*set0<< salarioTot[0]+20000;
    *set1 << salarioTot[1]<< salarioTot[1];
    *set2 << salarioTot[2]<< salarioTot[2];
    *set3 << salarioTot[3]<< salarioTot[3];
    *set4 << salarioTot[4]<< salarioTot[4];
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Stipendi");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    categories << data.toString("MMMM")<<"Luglio";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,*std::max_element(salarioTot, salarioTot+5)*1.1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    mainLayout->addWidget(chartView,66);

    mainLayoutDati->addWidget(new QLabel("Operaio: "+QString::number(salarioTot[0])));
    mainLayoutDati->addWidget(new QLabel("Impiegato: "+QString::number(salarioTot[1])));
    mainLayoutDati->addWidget(new QLabel("Rappresentante: "+QString::number(salarioTot[2])));
    mainLayoutDati->addWidget(new QLabel("StudenteLavoratore: "+QString::number(salarioTot[3])));
    mainLayoutDati->addWidget(new QLabel("Altro: "+QString::number(salarioTot[4])));

    mainLayout->addLayout(mainLayoutDati,33);


}
