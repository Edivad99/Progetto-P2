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
#include <QDateEdit>
#include <sstream>
#include <QRadioButton>
#include <QSpinBox>

class TabellaTab : public QWidget
{
    Q_OBJECT
public:
    TabellaTab(QWidget *parent = 0);
private:
    QHBoxLayout *mainLayout;
    QTableWidget* table;

    QVBoxLayout *layoutOpzioni;
    QGroupBox *aggiungi, *modifica, *rimuovi;

    QGridLayout *layoutAggiungi, *layoutModifica, *layoutRimuovi;

    //Input
    QComboBox *tipologia, *genere, *occupazione;
    QLineEdit *nome, *cognome, *cf, *reparto, *numeroTelefono;
    QDateEdit *dataNascita, *scadenzaContratto;
    QRadioButton *determinato, *indeterminato;
    QSpinBox *oreDiLavoro, *livello, *venditeEffettuate;
    QDoubleSpinBox *pagaPerOra;

    //QWidget per mostrare/nascondere alcuni campi
    QWidget *Qlivello, *Qpaga, *Qvendite, *Qoccupazione;

    void Aggiungi();
    void Modifica();
    void Rimuovi();

    void VisualizzaOperaio();
    void VisualizzaImpiegato();
    void VisualizzaRappresentante();
    void VisualizzaStudente();

    //Test
    void aggiungiTestoEsempio();

private slots:
    void tipologiaIndexChanged(int);

};

#endif // TABELLATAB_H
