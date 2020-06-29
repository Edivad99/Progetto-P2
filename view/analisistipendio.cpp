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

    InizializzaSalario(csvData->getSize(), TabellaModel::categorie().size());
    Grafico(csvData, TabellaModel::categorie().size()); //metodo per costruire l'istogramma

    mainLayout->addWidget(chartView, 66);
    mainLayout->addWidget(dati, 33);
}

void AnalisiStipendio::InizializzaSalario(unsigned int size, unsigned int numeroCategorie)
{
    //matrice contenente il salario per ogni categoria di dipendente di ogni file aperto
    stipendio = new float[size*numeroCategorie];
    for(unsigned int i = 0; i < size; i++)
        for(unsigned int j = 0; j < numeroCategorie; j++)
            stipendio[(i*numeroCategorie)+j] = 0;
}


 void AnalisiStipendio::Grafico(lista<QStringList*> *csvData, unsigned int numeroCategorie)
 {
     //creazione delle colonne dell'istogramma
     QList<QBarSet*> *set = new QList<QBarSet*>();
     QStringList categorie = TabellaModel::categorie();
     for(unsigned int i = 0; i < numeroCategorie; i++)
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
         for(int i = 1;i<testo->size();++i)//file
         {
             QStringList linea=testo->at(i).split(";");//linea
             QString tipologia=linea.at(3);
             float salario=linea.at(5).toFloat();

             bool trovato = false;
             for(unsigned int j = 0; j < numeroCategorie && !trovato; j++)
             {
                 if(categorie.at(j) == tipologia)
                 {
                     stipendio[rowCount*numeroCategorie+j]+=salario;
                     trovato = true;
                 }
             }
             if(!trovato)
                 stipendio[rowCount*numeroCategorie+numeroCategorie]+=salario;//altro
         }
         //inserimento dati delle varie categorie
         listaMesiLetti << GeneralUtil::capitalizeFirstLetter(data.toString("MMMM"));
         for(int j = 0; j < set->size(); j++)
         {
            *((*set)[j]) << stipendio[rowCount*numeroCategorie +j];
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
     float maxStipendio = *std::max_element(stipendio, stipendio+(numeroCategorie*csvData->getSize()));
     axisY->setRange(0, maxStipendio*1.1);
     chart->addAxis(axisY, Qt::AlignLeft);
     finalSeries->attachAxis(axisY);

     chart->legend()->setVisible(true);
     chart->legend()->setAlignment(Qt::AlignBottom);

     chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
 }

 void AnalisiStipendio::SalarioTot(lista<QStringList *> *csvData, unsigned int N)//Si occupa della lista
 {
     //calcolo del salario
     /*int rowCount = 0;
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
     }*/
 }
