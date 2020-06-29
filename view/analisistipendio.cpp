#include "analisistipendio.h"

AnalisiStipendio::AnalisiStipendio(lista<QStringList*> *csvData, QWidget *parent): QWidget(parent)
{
    setWindowTitle("QBusiness - Analizza stipendio"); //titolo della nuova finestra
    mainLayout = new QHBoxLayout(this);
    dati = new QListWidget();
    dati->setSizeAdjustPolicy(QListWidget::AdjustToContents);
    setLayout(mainLayout);

    setMinimumSize(QSize(650,650));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mainLayout->setMargin(0);


    Grafico(csvData); //metodo per costruire l'istogramma

    mainLayout->addWidget(chartView, 66);
    mainLayout->addWidget(dati, 33);
}

void AnalisiStipendio::InizializzaSalario(unsigned int size, unsigned int N)
{
    //matrice contenente il salario per ogni categoria di dipendente di ogni file aperto
    stipendio = new float[size*N];
    for(unsigned int i = 0; i < size; i++)
        for(unsigned int j = 0; j < N; j++)
            stipendio[(i*N)+j] = 0;
}


 void AnalisiStipendio::Grafico(lista<QStringList*> *csvData)
 {
     //creazione legenda
     QBarSet *set0 = new QBarSet("Operaio");
     QBarSet *set1 = new QBarSet("Impiegato");
     QBarSet *set2 = new QBarSet("Rappresentante");
     QBarSet *set3 = new QBarSet("StudenteLavoratore");
     QBarSet *set4 = new QBarSet("Altro");
     QStringList categories;


     //creazione delle colonne dell'istogramma
     QBarSeries *series = new QBarSeries();
     series->append(set0);
     series->append(set1);
     series->append(set2);
     series->append(set3);
     series->append(set4);

     //creazione grafico
     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Stipendi");
     chart->setAnimationOptions(QChart::SeriesAnimations);

     QBarCategoryAxis *axisX = new QBarCategoryAxis();
     axisX->append(categories);
     chart->addAxis(axisX, Qt::AlignBottom);
     series->attachAxis(axisX);

     QValueAxis *axisY = new QValueAxis();
     float maxStipendio = *std::max_element(&salarioTot[0][0], &salarioTot[0][0]+5*csvData->getSize());
     axisY->setRange(0, maxStipendio*1.1);
     chart->addAxis(axisY, Qt::AlignLeft);
     series->attachAxis(axisY);

     chart->legend()->setVisible(true);
     chart->legend()->setAlignment(Qt::AlignBottom);

     chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
 }

 void AnalisiStipendio::SalarioTot(lista<QStringList *> *csvData, unsigned int N)
 {
     //calcolo del salario
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
                 stipendio[rowCount*N+0]+=salario;
             }
             else if(tipologia=="Impiegato")
             {
                 stipendio[rowCount*N+1]+=salario;
             }
             else if(tipologia=="Rappresentante")
             {
                 stipendio[rowCount*N+2]+=salario;
             }
             else if(tipologia=="StudenteLavoratore")
             {
                 stipendio[rowCount*N+3]+=salario;
             }
             else
             {
                 stipendio[rowCount*N+4]+=salario;//altro
             }
         }

         QListWidgetItem *item = new QListWidgetItem();
         item->setSizeHint(QSize(item->sizeHint().width(), 180));
         dati->addItem(item);
         dati->setItemWidget(item, new WStipendioMensile(data, stipendio[rowCount*N]));
         //inserimento dati delle varie categorie
         categories << GeneralUtil::capitalizeFirstLetter(data.toString("MMMM"));
         *set0 << salarioTot[rowCount][0];
         *set1 << salarioTot[rowCount][1];
         *set2 << salarioTot[rowCount][2];
         *set3 << salarioTot[rowCount][3];
         *set4 << salarioTot[rowCount][4];
         rowCount++;
     }
 }
