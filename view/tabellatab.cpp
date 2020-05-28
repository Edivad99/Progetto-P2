#include "tabellatab.h"

TabellaTab::TabellaTab(TabellaModel *model, QWidget *parent): QWidget(parent), _model(model)
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

    //Visualizzo di default l'operaio
    VisualizzaOperaio();
    connect(tipologia, SIGNAL(currentIndexChanged(int)), this, SLOT(tipologiaIndexChanged(int)));
    connect(btnAggiungi, SIGNAL(clicked()), this, SLOT(btnAggiungiClicked()));
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

    //Azioni
    btnAggiungi = new QPushButton();

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
    Qlivello = new QWidget();
    QVBoxLayout *livelloLayout = new QVBoxLayout(Qlivello);
    livelloLayout->setSpacing(0);
    livelloLayout->addWidget(new QLabel("Livello"));
    livello->setRange(1, 5);
    livelloLayout->addWidget(livello);
    layoutAggiungi->addWidget(Qlivello, 1, 1);

    //PAGA PER ORA
    Qpaga = new QWidget();
    QVBoxLayout *pagaLayout = new QVBoxLayout(Qpaga);
    pagaLayout->setSpacing(0);
    pagaLayout->addWidget(new QLabel("Paga per ora"));
    pagaPerOra->setRange(0, 10000);
    pagaLayout->addWidget(pagaPerOra);
    layoutAggiungi->addWidget(Qpaga, 2, 1);

    //VENDITE EFFETTUATE
    Qvendite = new QWidget();
    QVBoxLayout *venditeLayout = new QVBoxLayout(Qvendite);
    venditeLayout->setSpacing(0);
    venditeLayout->addWidget(new QLabel("Vendite effettuate"));
    venditeEffettuate->setRange(0, 1000);
    venditeLayout->addWidget(venditeEffettuate);
    layoutAggiungi->addWidget(Qvendite, 3, 1);

    //OCCUPAZIONE
    Qoccupazione = new QWidget();
    QVBoxLayout *occupazioneLayout = new QVBoxLayout(Qoccupazione);
    occupazioneLayout->setSpacing(0);
    occupazioneLayout->addWidget(new QLabel("Occupazione"));
    QStringList occupazioneItems;
    occupazioneItems.push_back("Superiori");
    occupazioneItems.push_back("Università");
    occupazione->addItems(occupazioneItems);
    occupazioneLayout->addWidget(occupazione);
    layoutAggiungi->addWidget(Qoccupazione, 4, 1);

    //BOTTONE AGGIUNGI
    btnAggiungi->setText("Aggiungi");
    layoutAggiungi->addWidget(btnAggiungi, 5, 1);


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

void TabellaTab::VisualizzaOperaio()
{
    //Livello
    Qlivello->setVisible(true);
    //Paga per ora
    Qpaga->setVisible(false);
    //Vendite effettuate
    Qvendite->setVisible(false);
    //Occupazione
    Qoccupazione->setVisible(false);
}

void TabellaTab::VisualizzaImpiegato()
{
    //Livello
    Qlivello->setVisible(false);
    //Paga per ora
    Qpaga->setVisible(true);
    //Vendite effettuate
    Qvendite->setVisible(false);
    //Occupazione
    Qoccupazione->setVisible(false);
}

void TabellaTab::VisualizzaRappresentante()
{
    //Livello
    Qlivello->setVisible(false);
    //Paga per ora
    Qpaga->setVisible(true);
    //Vendite effettuate
    Qvendite->setVisible(true);
    //Occupazione
    Qoccupazione->setVisible(false);
}

void TabellaTab::VisualizzaStudente()
{
    //Livello
    Qlivello->setVisible(false);
    //Paga per ora
    Qpaga->setVisible(false);
    //Vendite effettuate
    Qvendite->setVisible(false);
    //Occupazione
    Qoccupazione->setVisible(true);
}

bool TabellaTab::convalidaInput(string tipologia, string nome, string cognome, string cf, string telefono, string reparto)
{
    //TODO:Forse da aggiungere controlli sulle date
    bool accettabile = true;
    if(tipologia.empty()) accettabile = false;
    else if(accettabile && nome.empty()) accettabile = false;
    else if(accettabile && cognome.empty()) accettabile = false;
    else if(accettabile && cf.empty() && cf.length() != 16) accettabile = false;
    else if(accettabile && telefono.empty()) accettabile = false;
    else if(accettabile && reparto.empty()) accettabile = false;
    return accettabile;
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

void TabellaTab::tipologiaIndexChanged(int index)
{
    if(index==0)
        VisualizzaOperaio();
    else if (index == 1)
        VisualizzaImpiegato();
    else if (index == 2)
        VisualizzaRappresentante();
    else if (index == 3)
        VisualizzaStudente();
}

void TabellaTab::btnAggiungiClicked()
{
    //Generali
    string Tipologia = tipologia->currentText().toStdString();
    string Nome = nome->text().toStdString();
    string Cognome = cognome->text().toStdString();
    QDate DataNascita = dataNascita->date();
    Genere GenereEnum = (genere->currentText().toStdString() == "M" ? Genere::M : Genere::F);
    string CF = cf->text().toStdString();
    string NumeroTelefono = numeroTelefono->text().trimmed().toStdString();
    string Reparto = reparto->text().toStdString();
    int OreDiLavoro = oreDiLavoro->value();
    bool Determinato = determinato->isChecked();
    QDate ScadenzaContratto = scadenzaContratto->date();
    if(!Determinato)
        ScadenzaContratto = QDate(0,0,0);

    //Operaio
    int Livello = livello->value();
    //Impiegato
    float PagaPerOra = pagaPerOra->value();
    //+Rappresentante
    int VenditeEffettuate = venditeEffettuate->value();
    //Studente
    Occupazione OccupazioneEnum = (occupazione->currentText().toStdString() == "Superiori" ? Occupazione::Superiori : Occupazione::Universita);

    if(!convalidaInput(Tipologia, Nome, Cognome, CF, NumeroTelefono, Reparto))
    {
        QMessageBox *message = new QMessageBox(QMessageBox::Information, "Errore dati inseriti", "I dati inseriti non sono corretti o sono mancanti!", QMessageBox::Ok);
        message->show();
    }
    else
    {
        Lavoratore *nuovo = nullptr;
        if(Tipologia == "Operaio")
        {
            nuovo = new Operaio(Nome, Cognome, DataNascita, CF, GenereEnum, Telefono(NumeroTelefono), Reparto, OreLavorative(OreDiLavoro), ScadenzaContratto, static_cast<enum Livello>(Livello-1));
        }
        else if (Tipologia == "Impiegato")
        {
            nuovo = new Impiegato(Nome, Cognome, DataNascita, CF, GenereEnum, Telefono(NumeroTelefono), Reparto, OreLavorative(OreDiLavoro), ScadenzaContratto, PagaPerOra);
        }
        else if (Tipologia == "Rappresentante")
        {
            nuovo = new Rappresentante(Nome, Cognome, DataNascita, CF, GenereEnum, Telefono(NumeroTelefono), Reparto, OreLavorative(OreDiLavoro), ScadenzaContratto, PagaPerOra, VenditeEffettuate);
        }
        else if (Tipologia == "Studente")
        {
            nuovo = new StudenteLavoratore(Nome, Cognome, DataNascita, CF, GenereEnum, Telefono(NumeroTelefono), OccupazioneEnum, Reparto, OreLavorative(OreDiLavoro), ScadenzaContratto);
        }
        if(nuovo != nullptr)
            _model->aggiungiLavoratore(nuovo);
    }
}
