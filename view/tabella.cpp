#include "tabella.h"

Tabella::Tabella(TabellaModel *model, QWidget *parent): QWidget(parent), _model(model)
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
    table = new QTableWidget();
    updateTabella();

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

void Tabella::Aggiungi()
{
    layoutAggiungi = new QGridLayout();

    //Input
    tipologia = new QComboBox();
    genere = new QComboBox();
    occupazione = new QComboBox();
    nome = new QLineEdit();
    cognome = new QLineEdit();
    reparto = new QLineEdit();
    numeroTelefono = new WTelefono();
    cf = new QLineEdit();
    dataNascita = new QDateEdit();
    contratto = new WContratto();
    oreDiLavoro = new WCSpinBox(QString("Ore di lavoro previste"), 0, 200, 160);
    livello = new WCSpinBox(QString("Livello"), 1, 5, 1);
    pagaPerOra = new WPagaPerOra();
    venditeEffettuate = new WCSpinBox(QString("Vendite effettuate"), 0, 10000, 0);

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
    tipologieItems.push_back("Studente-Lavoratore");
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
    layoutAggiungi->addWidget(numeroTelefono, 6, 0);

    //REPARTO
    reparto->setPlaceholderText("Reparto");
    layoutAggiungi->addWidget(reparto, 7, 0);

    //ORE LAVORATIVE
    layoutAggiungi->addWidget(oreDiLavoro, 8, 0);

    //TIPOLOGIA DI CONTRATTO
    layoutAggiungi->addWidget(contratto, 0, 1);

    //LIVELLO
    layoutAggiungi->addWidget(livello, 1, 1);

    //PAGA PER ORA
    layoutAggiungi->addWidget(pagaPerOra, 2, 1);

    //VENDITE EFFETTUATE
    layoutAggiungi->addWidget(venditeEffettuate, 3, 1);

    //OCCUPAZIONE
    Qoccupazione = new QWidget();
    QVBoxLayout *occupazioneLayout = new QVBoxLayout(Qoccupazione);
    occupazioneLayout->setMargin(0);
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

void Tabella::Modifica()
{
    layoutModifica = new QGridLayout();

    QLabel* example = new QLabel("Modifica");
    layoutModifica->addWidget(example);

    modifica->setLayout(layoutModifica);
}

void Tabella::Rimuovi()
{
    layoutRimuovi = new QGridLayout();

    QLabel* example = new QLabel("Rimuovi");
    layoutRimuovi->addWidget(example);

    rimuovi->setLayout(layoutRimuovi);
}

void Tabella::VisualizzaOperaio()
{
    //Livello
    livello->setVisible(true);
    //Paga per ora
    pagaPerOra->setVisible(false);
    //Vendite effettuate
    venditeEffettuate->setVisible(false);
    //Occupazione
    Qoccupazione->setVisible(false);
}

void Tabella::VisualizzaImpiegato()
{
    //Livello
    livello->setVisible(false);
    //Paga per ora
    pagaPerOra->setVisible(true);
    //Vendite effettuate
    venditeEffettuate->setVisible(false);
    //Occupazione
    Qoccupazione->setVisible(false);
}

void Tabella::VisualizzaRappresentante()
{
    //Livello
    livello->setVisible(false);
    //Paga per ora
    pagaPerOra->setVisible(true);
    //Vendite effettuate
    venditeEffettuate->setVisible(true);
    //Occupazione
    Qoccupazione->setVisible(false);
}

void Tabella::VisualizzaStudente()
{
    //Livello
    livello->setVisible(false);
    //Paga per ora
    pagaPerOra->setVisible(false);
    //Vendite effettuate
    venditeEffettuate->setVisible(false);
    //Occupazione
    Qoccupazione->setVisible(true);
}

bool Tabella::convalidaInput(string nome, string cognome, string cf, string reparto) const
{
    //TODO:Forse da aggiungere controlli sulle date
    bool accettabile = true;
    if(accettabile && nome.empty()) accettabile = false;
    else if(accettabile && cognome.empty()) accettabile = false;
    else if(accettabile && (cf.empty() || cf.length() != 16)) accettabile = false;
    else if(accettabile && reparto.empty()) accettabile = false;
    return accettabile;
}

void Tabella::setText(QString text, int row, int column)
{
    QTableWidgetItem *pCell = table->item(row, column);
    if(!pCell)
    {
        pCell = new QTableWidgetItem();
        pCell->setFlags(pCell->flags() ^ Qt::ItemIsEditable);
        table->setItem(row, column, pCell);
    }
    pCell->setText(text);
}

void Tabella::updateTabella()
{
    QStringList intestazioneColonna;
    intestazioneColonna.push_back("ID");
    intestazioneColonna.push_back("Tipologia");
    intestazioneColonna.push_back("Nome");
    intestazioneColonna.push_back("Cognome");
    intestazioneColonna.push_back("Data di nascita");
    intestazioneColonna.push_back("CF");
    intestazioneColonna.push_back("Genere");
    intestazioneColonna.push_back("Telefono");
    intestazioneColonna.push_back("Occupazione");
    intestazioneColonna.push_back("Reparto");
    intestazioneColonna.push_back("Ore di lavoro");
    intestazioneColonna.push_back("Contratto");//DETERMINATO INDETERMINATO
    intestazioneColonna.push_back("Data scadenza");
    intestazioneColonna.push_back("Livello");
    intestazioneColonna.push_back("Paga per ora");
    intestazioneColonna.push_back("Vendite effettuate");

    lista<Lavoratore*>supp = _model->getLavoratori();
    table->setRowCount(supp.getSize());
    table->setColumnCount(intestazioneColonna.size());
    table->setHorizontalHeaderLabels(intestazioneColonna);

    int rowCount = 0;
    for(lista<Lavoratore*>::constiterator cit = supp.begin(); cit != supp.end(); cit++)
    {
        QString nome = QString::fromStdString((*cit)->getNome());
        QString cognome = QString::fromStdString((*cit)->getCognome());
        QString dataNascita = QString((*cit)->getDataNascita().toString("dd/MM/yyyy"));
        QString cf = QString::fromStdString((*cit)->getCodiceFiscale());
        QString genere = QString(QString::fromStdString(((*cit)->getGenere() == 0) ? "M" : "F"));

        std::stringstream textNumeroTelefono;
        textNumeroTelefono << (*cit)->getNumeroTelefono();
        QString numeroTelefono = QString::fromStdString(textNumeroTelefono.str());//Telefono
        QString reparto = QString::fromStdString((*cit)->getReparto());//Reparto

        std::stringstream textOrePreviste;
        textOrePreviste << (*cit)->getOrePreviste();
        QString orePreviste = QString::fromStdString(textOrePreviste.str());//Ore di lavoro
        QString contratto = QString::fromStdString(((*cit)->getTipologiaContratto() == 0 ? "Determinato" : "Indeterminato"));//Contratto
        QString dataScadenza = QString((*cit)->getDataScadenza().toString("dd/MM/yyyy"));//Data scadenza

        setText(QString::fromStdString(std::to_string((*cit)->getID())), rowCount, 0);//ID
        setText(nome, rowCount, 2);//Nome
        setText(cognome, rowCount, 3);//Cognome
        setText(dataNascita, rowCount, 4);//DataNascita
        setText(cf, rowCount, 5);//CF
        setText(genere, rowCount, 6);//Genere
        setText(numeroTelefono, rowCount, 7);//Telefono
        setText(reparto, rowCount, 9);//Reparto
        setText(orePreviste, rowCount, 10);//Ore di lavoro
        setText(contratto, rowCount, 11);//Contratto
        setText(dataScadenza, rowCount, 12);//Data scadenza

        Operaio* operaio =dynamic_cast<Operaio*>(*cit);
        Impiegato* impiegato =dynamic_cast<Impiegato*>(*cit);
        Rappresentante* rappresentante =dynamic_cast<Rappresentante*>(*cit);
        StudenteLavoratore* studlav =dynamic_cast<StudenteLavoratore*>(*cit);

        QString tipologia = "";
        if(operaio)
        {
            tipologia = QString("Operaio");
            string livello = std::to_string(operaio->getLivello() + 1);
            setText(QString::fromStdString(livello), rowCount, 13);//Livello
        }
        else if(impiegato)
        {
            tipologia = QString("Impiegato");
            string pagaPerOra = std::to_string(impiegato->getPagaPerOra());
            setText(QString::fromStdString(pagaPerOra), rowCount, 14);//Paga per ora

            if (rappresentante)
            {
                tipologia = QString("Rappresentante");
                string venditeEffettuate = std::to_string(rappresentante->getVenditeEffettuate());
                setText(QString::fromStdString(venditeEffettuate), rowCount, 15);//Vendite effettuate
            }
        }
        else if(studlav)
        {
            tipologia = QString("StudenteLavoratore");
            string occupazione = studlav->getOccupazione() == 0 ? "Superiori" : "Universita'";
            setText(QString::fromStdString(occupazione), rowCount, 8);//Occupazione
        }

        setText(tipologia, rowCount, 1);//Tipologia
        rowCount++;
    }
}

void Tabella::tipologiaIndexChanged(int index)
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

void Tabella::btnAggiungiClicked()
{
    //Generali
    int Tipologia = tipologia->currentIndex();
    string Nome = nome->text().toStdString();
    string Cognome = cognome->text().toStdString();
    QDate DataNascita = dataNascita->date();
    Genere GenereEnum = (genere->currentText().toStdString() == "M" ? Genere::M : Genere::F);
    string CF = cf->text().toStdString(); for (auto & c: CF) c = toupper(c);
    Telefono NumeroTelefono = numeroTelefono->getNumeroTelefono();
    string Reparto = reparto->text().toStdString();
    int OreDiLavoro = oreDiLavoro->getValue();
    bool Determinato = contratto->isDeterminato();
    QDate ScadenzaContratto = contratto->getDataScadenza();
    if(!Determinato)
        ScadenzaContratto = QDate(0,0,0);

    //Operaio
    int Livello = livello->getValue();
    //Impiegato
    float PagaPerOra = pagaPerOra->getPaga();
    //+Rappresentante
    int VenditeEffettuate = venditeEffettuate->getValue();
    //Studente
    Occupazione OccupazioneEnum = (occupazione->currentText().toStdString() == "Superiori" ? Occupazione::Superiori : Occupazione::Universita);

    if(!convalidaInput(Nome, Cognome, CF, Reparto))
    {
        QMessageBox *message = new QMessageBox(QMessageBox::Information, "Errore dati inseriti", "I dati inseriti non sono corretti o sono mancanti!", QMessageBox::Ok);
        message->show();
    }
    else
    {
        Lavoratore *nuovo = nullptr;
        if(Tipologia == 0)
        {
            nuovo = new Operaio(Nome, Cognome, DataNascita, CF, GenereEnum, NumeroTelefono, Reparto, OreLavorative(OreDiLavoro), ScadenzaContratto, static_cast<enum Livello>(Livello-1));
        }
        else if (Tipologia == 1)
        {
            nuovo = new Impiegato(Nome, Cognome, DataNascita, CF, GenereEnum, NumeroTelefono, Reparto, OreLavorative(OreDiLavoro), ScadenzaContratto, PagaPerOra);
        }
        else if (Tipologia == 2)
        {
            nuovo = new Rappresentante(Nome, Cognome, DataNascita, CF, GenereEnum, NumeroTelefono, Reparto, OreLavorative(OreDiLavoro), ScadenzaContratto, PagaPerOra, VenditeEffettuate);
        }
        else if (Tipologia == 3)
        {
            nuovo = new StudenteLavoratore(Nome, Cognome, DataNascita, CF, GenereEnum, NumeroTelefono, OccupazioneEnum, Reparto, OreLavorative(OreDiLavoro), ScadenzaContratto);
        }
        if(nuovo != nullptr)
        {
            _model->aggiungiLavoratore(nuovo);
            updateTabella();
        }
    }
}
