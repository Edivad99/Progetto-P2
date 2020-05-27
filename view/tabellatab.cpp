#include "tabellatab.h"

TabellaTab::TabellaTab(QWidget *parent): QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    layoutOpzioni = new QVBoxLayout();
    aggiungi = new QGroupBox("Aggiungi");
    modifica = new QGroupBox("Modifica");
    rimuovi = new QGroupBox("Rimuovi");

    //Imposto il "peso" per ogni grouBox
    QSizePolicy aggiungiPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    aggiungiPolicy.setHorizontalStretch(3);
    aggiungi->setSizePolicy(aggiungiPolicy);

    QSizePolicy altrePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    altrePolicy.setHorizontalStretch(1);
    modifica->setSizePolicy(altrePolicy);
    rimuovi->setSizePolicy(altrePolicy);


    //Imposto le dimensioni della tabella
    table = new QTableWidget(5,6);
    /*QSizePolicy tablePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    tablePolicy.setHorizontalStretch(1);
    table->setSizePolicy(tablePolicy);*/
    aggiungiTestoEsempio();

    //Imposto le dimensioni della parte dei controlli

    Aggiungi();
    Modifica();
    Rimuovi();

    //Aggiunta layout
    mainLayout->addWidget(table, 66);

    layoutOpzioni->addWidget(aggiungi);
    layoutOpzioni->addWidget(modifica);
    layoutOpzioni->addWidget(rimuovi);


    mainLayout->addLayout(layoutOpzioni, 33);

    mainLayout->setMargin(0);
    setLayout(mainLayout);
}

void TabellaTab::Aggiungi()
{
    layoutAggiungi = new QGridLayout();

    //Input
    tipologia = new QComboBox();
    genere = new QComboBox();
    occupazione = new QComboBox();
    nome = new QLineEdit();
    cognome = new QLineEdit();
    reparto = new QLineEdit();
    numeroTelefono = new QLineEdit();
    cf = new QLineEdit();
    dataNascita = new QDateEdit();
    scadenzaContratto = new QDateEdit();
    oreDiLavoro = new QSpinBox();
    livello = new QSpinBox();
    pagaPerOra = new QDoubleSpinBox();
    venditeEffettuate = new QSpinBox();
    determinato = new QRadioButton();
    indeterminato = new QRadioButton();

    //HorizontalPolicy Fixed
    //Bisogna decidere se tenere questa parte
    /*QSizePolicy general(QSizePolicy::Fixed, QSizePolicy::Fixed);
    tipologia->setSizePolicy(general);
    genere->setSizePolicy(general);
    occupazione->setSizePolicy(general);
    nome->setSizePolicy(general);
    cognome->setSizePolicy(general);
    reparto->setSizePolicy(general);
    numeroTelefono->setSizePolicy(general);
    cf->setSizePolicy(general);
    dataNascita->setSizePolicy(general);
    scadenzaContratto->setSizePolicy(general);
    oreDiLavoro->setSizePolicy(general);
    livello->setSizePolicy(general);
    pagaPerOra->setSizePolicy(general);
    venditeEffettuate->setSizePolicy(general);
    determinato->setSizePolicy(general);
    indeterminato->setSizePolicy(general);*/



    //TIPOLOGIA
    //Questa parte bisogna spostarla sul modello
    QVBoxLayout *tipologiaLayout = new QVBoxLayout();
    tipologiaLayout->setSpacing(0);
    tipologiaLayout->addWidget(new QLabel("Tipologia"));

    QStringList tipologieItems;
    tipologieItems.push_back("Operaio");
    tipologieItems.push_back("Impiegato");
    tipologieItems.push_back("Rappresentante");
    tipologieItems.push_back("Studente");
    tipologia->addItems(tipologieItems);
    tipologiaLayout->addWidget(tipologia);
    layoutAggiungi->addLayout(tipologiaLayout, 0, 0);

    //NOME
    nome->setPlaceholderText("Nome");
    layoutAggiungi->addWidget(nome, 1, 0);

    //COGNOME
    cognome->setPlaceholderText("Cognome");
    layoutAggiungi->addWidget(cognome, 2, 0);

    //DATA DI NASCITA
    QVBoxLayout *dataNascitaLayout = new QVBoxLayout();
    dataNascitaLayout->setSpacing(0);
    dataNascitaLayout->addWidget(new QLabel("Data di Nascita"));
    dataNascitaLayout->addWidget(dataNascita);
    layoutAggiungi->addLayout(dataNascitaLayout, 3, 0);

    //GENERE
    QVBoxLayout *genereLayout = new QVBoxLayout();
    genereLayout->setSpacing(0);
    genereLayout->addWidget(new QLabel("Genere"));

    QStringList genereItems;
    genereItems.push_back("M");
    genereItems.push_back("F");
    genere->addItems(genereItems);
    genereLayout->addWidget(genere);
    layoutAggiungi->addLayout(genereLayout, 4,0);

    //CODICE FISCALE
    cf->setPlaceholderText("CodiceFiscale");
    layoutAggiungi->addWidget(cf, 5, 0);

    //NUMERO DI TELEFONO
    numeroTelefono->setPlaceholderText("Numero di Telefono");
    layoutAggiungi->addWidget(numeroTelefono, 6, 0);

    //REPARTO
    reparto->setPlaceholderText("Reparto");
    layoutAggiungi->addWidget(reparto, 7, 0);

    //ORE LAVORATIVE
    QVBoxLayout *oreLayout = new QVBoxLayout();
    oreLayout->addWidget(new QLabel("Ore di lavoro previste"));
    oreDiLavoro->setRange(0, 200); //Per convenzione non si può lavorare più di 200 ore
    oreDiLavoro->setValue(160);
    oreLayout->addWidget(oreDiLavoro);
    layoutAggiungi->addLayout(oreLayout, 8, 0);

    //TIPOLOGIA DI CONTRATTO
    QVBoxLayout *contrattoLayout = new QVBoxLayout();
    contrattoLayout->setSpacing(0);
    contrattoLayout->addWidget(new QLabel("Tipologia di Contratto"));

    indeterminato->setText("Indeterminato");
    indeterminato->setChecked(true);
    contrattoLayout->addWidget(indeterminato);

    QHBoxLayout *determinatoLayout = new QHBoxLayout();
    determinato->setText("Determinato");
    determinatoLayout->addWidget(determinato);
    determinatoLayout->addWidget(scadenzaContratto);

    contrattoLayout->addLayout(determinatoLayout);
    layoutAggiungi->addLayout(contrattoLayout, 0, 1);

    //LIVELLO
    QVBoxLayout *livelloLayout = new QVBoxLayout();
    livelloLayout->setSpacing(0);
    livelloLayout->addWidget(new QLabel("Livello"));
    livello->setRange(1, 5);
    livelloLayout->addWidget(livello);
    layoutAggiungi->addLayout(livelloLayout, 1, 1);

    //PAGA PER ORA
    QVBoxLayout *pagaLayout = new QVBoxLayout();
    pagaLayout->setSpacing(0);
    pagaLayout->addWidget(new QLabel("Paga per ora"));
    pagaPerOra->setRange(0, 10000);
    pagaLayout->addWidget(pagaPerOra);
    layoutAggiungi->addLayout(pagaLayout, 2, 1);

    //VENDITE EFFETTUATE
    QVBoxLayout *venditeLayout = new QVBoxLayout();
    venditeLayout->setSpacing(0);
    venditeLayout->addWidget(new QLabel("Vendite effettuate"));
    venditeEffettuate->setRange(0, 1000);
    venditeLayout->addWidget(venditeEffettuate);
    layoutAggiungi->addLayout(venditeLayout, 3, 1);

    //OCCUPAZIONE
    QVBoxLayout * occupazioneLayout = new QVBoxLayout();
    occupazioneLayout->setSpacing(0);
    occupazioneLayout->addWidget(new QLabel("Occupazione"));
    QStringList occupazioneItems;
    occupazioneItems.push_back("Superiori");
    occupazioneItems.push_back("Università");
    occupazione->addItems(occupazioneItems);
    occupazioneLayout->addWidget(occupazione);
    layoutAggiungi->addLayout(occupazioneLayout, 4, 1);


    aggiungi->setLayout(layoutAggiungi);
}

void TabellaTab::Modifica()
{
    layoutModifica = new QGridLayout();

    QLabel* example = new QLabel("Modifica");
    layoutModifica->addWidget(example);

    modifica->setLayout(layoutModifica);
}

void TabellaTab::Rimuovi()
{
    layoutRimuovi = new QGridLayout();

    QLabel* example = new QLabel("Rimuovi");
    layoutRimuovi->addWidget(example);

    rimuovi->setLayout(layoutRimuovi);
}



void TabellaTab::aggiungiTestoEsempio()
{
    for(int i=0; i<table->rowCount(); i++)
    {
        for(int j=0; j<table->columnCount(); j++)
        {
            QTableWidgetItem *pCell = table->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                table->setItem(i, j, pCell);
            }
            std::stringstream text;
            text << "(" << i << "," << j << ")";
            pCell->setText(QString::fromStdString(text.str()));
        }
    }
}
