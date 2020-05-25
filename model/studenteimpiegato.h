#ifndef STUDENTEIMPIEGATO_H
#define STUDENTEIMPIEGATO_H

#include "model/studente.h"
#include "model/impiegato.h"

class StudenteImpiegato : public Studente, public Impiegato
{
public:
    StudenteImpiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione, string reparto,
                    OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float pagaPerOra, QUuid IDAziendale = QUuid::createUuid());

    StudenteImpiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione, string reparto,
                    OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float pagaPerOra, QDate dataScadenza, QUuid IDAziendale = QUuid::createUuid());

     virtual ~StudenteImpiegato();
};

#endif // STUDENTEIMPIEGATO_H
