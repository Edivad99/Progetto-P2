#ifndef DIRIGENTE_H
#define DIRIGENTE_H

#include "model/lavoratore.h"

class Dirigente : public Lavoratore
{
public:
    //Dirigente a tempo determinato e indeterminato ?
    Dirigente(float baseFissa,string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
              float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QUuid IDAziendale = QUuid::createUuid());

    Dirigente(float baseFissa,string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza, QUuid IDAziendale = QUuid::createUuid());

    virtual float Stipendio() const;

    float getBaseFissa() const;

    void setBaseFissa(float value);

private:
    //nuovi attributi?
    float _baseFissa;
};

#endif // DIRIGENTE_H
