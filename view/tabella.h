﻿#ifndef TABELLATAB_H
#define TABELLATAB_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QGroupBox>
#include <QComboBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QMessageBox>
#include <sstream>
#include <QRadioButton>
#include <QSpinBox>
#include <QPushButton>
#include <model/tabellamodel.h>
#include "data/lavoratore.h"
#include "data/operaio.h"
#include "data/impiegato.h"
#include "data/rappresentante.h"
#include "data/studente_lavoratore.h"
#include <iostream>

using std::string;

class Tabella : public QWidget
{
    Q_OBJECT
public:
    Tabella(TabellaModel *model, QWidget *parent = 0);

    void updateTabella();

private:
    //Modello
    TabellaModel *_model;

    //GUI
    QHBoxLayout *mainLayout;
    QTableWidget* table;

    QVBoxLayout *layoutOpzioni;
    QGroupBox *aggiungi, *modifica, *rimuovi;

    QGridLayout *layoutAggiungi, *layoutModifica, *layoutRimuovi;

    //Input
    QComboBox *tipologia, *genere, *occupazione;
    QLineEdit *nome, *cognome, *cf, *reparto, *numeroTelefono, *prefisso;
    QDateEdit *dataNascita, *scadenzaContratto;
    QRadioButton *determinato, *indeterminato;
    QSpinBox *oreDiLavoro, *livello, *venditeEffettuate;
    QDoubleSpinBox *pagaPerOra;

    //Azioni
    QPushButton *btnAggiungi, *btnModifica, *btnRimuovi;

    //QWidget per mostrare/nascondere alcuni campi
    QWidget *Qlivello, *Qpaga, *Qvendite, *Qoccupazione;

    void Aggiungi();
    void Modifica();
    void Rimuovi();

    void VisualizzaOperaio();
    void VisualizzaImpiegato();
    void VisualizzaRappresentante();
    void VisualizzaStudente();

    //Controllo sull'input
    bool convalidaInput(string nome, string cognome, string cf, string telefono, string prefisso, string reparto) const;

    //Test
    void setText(QString text, int row, int column);

private slots:
    void tipologiaIndexChanged(int);
    void btnAggiungiClicked();

};

#endif // TABELLATAB_H