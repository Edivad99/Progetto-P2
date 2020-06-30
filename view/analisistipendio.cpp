#include "analisistipendio.h"

AnalisiStipendio::AnalisiStipendio(lista<QStringList*> *csvData, QWidget *parent): QWidget(parent)
{
    setWindowTitle("QBusiness - Analizza stipendio"); //titolo della nuova finestra
    mainLayout = new QHBoxLayout(this);
    listaStipendi = new QListWidget();
    listaStipendi->setSizeAdjustPolicy(QListWidget::AdjustToContents);
    setLayout(mainLayout);

    setMinimumSize(QSize(650,650));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mainLayout->setMargin(0);

    InizializzaSalario(csvData->getSize(), TabellaModel::categorie().size() + 1);
    Grafico(csvData);
    ListaStipendi();

    mainLayout->addWidget(chartView, 66);
    mainLayout->addWidget(listaStipendi, 33);
}

void AnalisiStipendio::InizializzaSalario(unsigned int size, unsigned int numeroCategorie)
{
    //matrice contenente il salario per ogni categoria di dipendente di ogni file aperto
    stipendio = new float[size*numeroCategorie];
    for(unsigned int i = 0; i < size; i++)
        for(unsigned int j = 0; j < numeroCategorie; j++)
            stipendio[(i*numeroCategorie)+j] = 0;
}


 void AnalisiStipendio::Grafico(lista<QStringList*> *csvData)
 {
     //creazione delle colonne dell'istogramma
     QList<QBarSet*> *set = new QList<QBarSet*>();
     QStringList categorie = TabellaModel::categorie();
     int numeroCategorie = categorie.size();
     for(int i = 0; i < numeroCategorie; i++)
     {
         set->push_back(new QBarSet(categorie.at(i)));
     }
     set->push_back(new QBarSet("Altro"));

     QStringList listaMesiLetti;

     //calcolo del salario
     int rowCount = 0;
     for (lista<QStringList*>::constiterator cit = csvData->begin(); cit != csvData->end(); ++cit)
     {
         QStringList* testo = *cit;
         QString mese = testo->at(0).split(";")[0];
         QString anno = testo->at(0).split(";")[1];

         QDate data =QDate::fromString(mese.append(anno),"MMMMyyyy");
         listaDataLetta.push_back(data);

         for(int i = 1;i<testo->size();++i)//file
         {
             QStringList linea=testo->at(i).split(";");//linea
             QString tipologia=linea.at(3);
             float salario=std::min(linea.at(5).toFloat(), 0.0F);

             bool trovato = false;
             for(int j = 0; j < numeroCategorie && !trovato; j++)
             {
                 if(categorie.at(j) == tipologia)
                 {
                     stipendio[rowCount*(numeroCategorie + 1) +j]+=salario;
                     trovato = true;
                 }
             }
             if(!trovato)
                 stipendio[rowCount*(numeroCategorie + 1)+numeroCategorie]+=salario;//altro
         }
         //inserimento dati delle varie categorie
         listaMesiLetti << GeneralUtil::capitalizeFirstLetter(data.toString("MMMM yyyy"));
         for(int j = 0; j < set->size(); j++)
         {
            *((*set)[j]) << stipendio[rowCount*(numeroCategorie + 1) +j];
         }
         rowCount++;
     }

     //creazione grafico
     QChart *chart = new QChart();
     QBarSeries *finalSeries = new QBarSeries();
     finalSeries->append(*set);
     chart->addSeries(finalSeries);
     chart->setTitle("Stipendi");
     chart->setAnimationOptions(QChart::SeriesAnimations);

     QBarCategoryAxis *axisX = new QBarCategoryAxis();
     axisX->append(listaMesiLetti);
     chart->addAxis(axisX, Qt::AlignBottom);
     finalSeries->attachAxis(axisX);

     QValueAxis *axisY = new QValueAxis();
     float maxStipendio = *std::max_element(stipendio, stipendio+((numeroCategorie + 1)*csvData->getSize()));
     axisY->setRange(0, maxStipendio*1.1);
     chart->addAxis(axisY, Qt::AlignLeft);
     finalSeries->attachAxis(axisY);

     chart->legend()->setVisible(true);
     chart->legend()->setAlignment(Qt::AlignBottom);

     chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
 }

 void AnalisiStipendio::ListaStipendi()
 {
     int categorie = TabellaModel::categorie().size() + 1;
     for(int i = 0; i < listaDataLetta.size(); i++)
     {
         QListWidgetItem *item = new QListWidgetItem();
         item->setSizeHint(QSize(item->sizeHint().width(), 22*(categorie+3)));
         listaStipendi->addItem(item);
         listaStipendi->setItemWidget(item, new WStipendioMensile(listaDataLetta.at(i), stipendio+(categorie*i)));
     }
 }
