#ifndef RAPPRESENTANTE_H
#define RAPPRESENTANTE_H

#include "model/impiegato.h"

class Rappresentante:  public Impiegato
{

public:
    Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float pagaPerOra, float venditeEffettuate, QUuid IDAziendale = QUuid::createUuid());

    Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float venditeEffettuate, float pagaPerOra, QDate dataScadenza, QUuid IDAziendale = QUuid::createUuid());

    virtual float Stipendio(float bonus) const;

    float venditeEffettuate() const;

    void setVenditeEffettuate(float venditeEffettuate);

    static const float guadagnoPerMerce;

private:

    float _venditeEffettuate;
};

#endif // RAPPRESENTANTE_H
