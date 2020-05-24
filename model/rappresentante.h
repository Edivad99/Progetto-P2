#ifndef RAPPRESENTANTE_H
#define RAPPRESENTANTE_H

#include "model/lavoratore.h"

class Rappresentante:  public Lavoratore
{

public:// PER IL MOMENTO PAGAPERORA su impiegato è pagaPerOra2 perchè dobbiamo toglierlo da lavoratore
    Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float venditeEffettuate, float pagaPerOra3, QUuid IDAziendale = QUuid::createUuid());

    Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza, float venditeEffettuate, float pagaPerOra3, QUuid IDAziendale = QUuid::createUuid());

    virtual float Stipendio() const;

    float venditeEffettuate() const;

    void setVenditeEffettuate(float venditeEffettuate);
    //STESSA COSA DI IMPIEGATO qui però pagaPerOra3
    float pagaPerOra3() const;

    void setPagaPerOra3(float pagaPerOra3);

private:

    float _pagaPerOra3;

    float _venditeEffettuate;
};

#endif // RAPPRESENTANTE_H
