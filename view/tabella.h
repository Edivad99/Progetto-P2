#ifndef TABELLATAB_H
#define TABELLATAB_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QGroupBox>
#include <QComboBox>
#include <QLineEdit>
#include <QMessageBox>
#include <sstream>
#include <QPushButton>
#include <model/tabellamodel.h>
#include <view/widgets/wcontratto.h>
#include <view/widgets/wcspinbox.h>
#include <view/widgets/worelavoro.h>
#include <view/widgets/wpagaperora.h>
#include <view/widgets/wtelefono.h>
#include "data/lavoratore.h"
#include "data/operaio.h"
#include "data/impiegato.h"
#include "data/rappresentante.h"
#include "data/studente_lavoratore.h"
#include <QCheckBox>
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
    QVBoxLayout *mainLayout, *layoutOpzioni, *layoutRimuovi;
    QHBoxLayout *tableLayout, *bottomBar;
    QTableWidget* table;

    QGroupBox *aggiungi, *modifica, *rimuovi;

    QGridLayout *layoutAggiungi, *layoutModifica;

    //Input
    QComboBox *tipologia, *genere, *occupazione, *rimuoviID;
    QLineEdit *nome, *cognome, *cf, *reparto, *editReparto;
    QDateEdit *dataNascita;

    //Custom Input
    WContratto *contratto, *editContratto;
    WTelefono *numeroTelefono, *editNumeroTelefono;
    WCSpinBox *livello, *venditeEffettuate, *editLivello, *editVenditeEffettuate;
    WPagaPerOra *pagaPerOra, *editPagaPerOra;
    WOreLavoro *oreDiLavoro, *editOreDiLavoro;

    //Azioni
    QPushButton *btnAggiungi, *btnModifica, *btnRimuovi;

    //QWidget per mostrare/nascondere alcuni campi
    QWidget *Qoccupazione;
    QLabel *editNome, *editID, *numeroDipendenti;
    QCheckBox *operaioCB, *impiegatoCB, *studlavCB;

    void Aggiungi();
    void Modifica();
    void Rimuovi();
    void BottomBar();

    void VisualizzaOperaio();
    void VisualizzaImpiegato();
    void VisualizzaRappresentante();
    void VisualizzaStudente();

    void tabellaChanged();

    //Controllo sull'input
    bool convalidaInput(const string& nome, const string& cognome, const string& cf, const string& reparto) const;

    void setText(QString text, int row, int column);
    void resetModifica();
private slots:
    void tipologiaIndexChanged(int);
    void btnAggiungiClicked();
    void btnModificaClicked();
    void btnRimuoviClicked();
    void cellaClicked(int, int);
    void checkboxChanged(int);

};

#endif // TABELLATAB_H
