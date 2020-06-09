#include "analisistipendio.h"

AnalisiStipendio::AnalisiStipendio(lista<QStringList*> *csvData, QWidget *parent): QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    mainLayoutDati = new QVBoxLayout();
    setLayout(mainLayout);

    setMinimumSize(QSize(650,650));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mainLayout->setMargin(0);

    float salarioTot[csvData->getSize()][5];
    for(unsigned int i = 0; i < csvData->getSize(); i++)
        for(int j = 0; j < 5; j++)
            salarioTot[i][j] = 0;

    QBarSet *set0 = new QBarSet("Operaio");
    QBarSet *set1 = new QBarSet("Impiegato");
    QBarSet *set2 = new QBarSet("Rappresentante");
    QBarSet *set3 = new QBarSet("StudenteLavoratore");
    QBarSet *set4 = new QBarSet("Altro");
    QStringList categories;

    int rowCount = 0;
    for (lista<QStringList*>::constiterator cit = csvData->begin(); cit != csvData->end(); ++cit)
    {
        QStringList* testo = *cit;
        QString mese = testo->at(0).split(";")[0];
        QString anno = testo->at(0).split(";")[1];


        QDate data =QDate::fromString(mese.append(anno),"MMMMyyyy");
        for(int i=1;i<testo->size();++i)//file
        {
            QStringList linea=testo->at(i).split(";");//linea
            QString tipologia=linea.at(3);
            float salario=linea.at(5).toFloat();
            if(tipologia=="Operaio")
            {
                salarioTot[rowCount][0]+=salario;
            }
            else if(tipologia=="Impiegato")
            {
                salarioTot[rowCount][1]+=salario;
            }
            else if(tipologia=="Rappresentante")
            {
                salarioTot[rowCount][2]+=salario;
            }
            else if(tipologia=="StudenteLavoratore")
            {
                salarioTot[rowCount][3]+=salario;
            }
            else
            {
                salarioTot[rowCount][4]+=salario;//altro
            }
        }

        categories << GeneralUtil::capitalizeFirstLetter(data.toString("MMMM"));
        *set0 << salarioTot[rowCount][0];
        *set1 << salarioTot[rowCount][1];
        *set2 << salarioTot[rowCount][2];
        *set3 << salarioTot[rowCount][3];
        *set4 << salarioTot[rowCount][4];
        rowCount++;
    }


    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Stipendi");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setMin(0);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    mainLayout->addWidget(chartView);

/*
    mainLayout->addWidget(chartView,66);

    mainLayoutDati->addWidget(new QLabel("Operaio: "+QString::number(salarioTot[0])));
    mainLayoutDati->addWidget(new QLabel("Impiegato: "+QString::number(salarioTot[1])));
    mainLayoutDati->addWidget(new QLabel("Rappresentante: "+QString::number(salarioTot[2])));
    mainLayoutDati->addWidget(new QLabel("StudenteLavoratore: "+QString::number(salarioTot[3])));
    mainLayoutDati->addWidget(new QLabel("Altro: "+QString::number(salarioTot[4])));

    mainLayout->addLayout(mainLayoutDati,33);
*/

}