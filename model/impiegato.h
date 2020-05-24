#ifndef IMPIEGATO_H
#define IMPIEGATO_H

#include "model/lavoratore.h"

class Impiegato :  public Lavoratore
{
public:// PER IL MOMENTO PAGAPERORA su impiegato è pagaPerOra2 perchè dobbiamo toglierlo da lavoratore
    Impiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float pagaPerOra2, QUuid IDAziendale = QUuid::createUuid());

    Impiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza, float pagaPerOra2, QUuid IDAziendale = QUuid::createUuid());

    virtual float Stipendio() const;

    float pagaPerOra2() const;

    void setPagaPerOra2(float pagaPerOra2);

private:
    float _pagaPerOra2;
};

#endif // IMPIEGATO_H
