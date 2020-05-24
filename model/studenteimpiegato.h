#ifndef STUDENTEIMPIEGATO_H
#define STUDENTEIMPIEGATO_H

#include "model/studente.h"

#include "model/operaio.h"

class StudenteImpiegato : public Studente, public Operaio
{
public:
    StudenteImpiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione, string reparto,
                    OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, Livello livello, QUuid IDAziendale = QUuid::createUuid());

    StudenteImpiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione, string reparto,
                    OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza,Livello livello, QUuid IDAziendale = QUuid::createUuid());

     virtual ~StudenteImpiegato();
};

#endif // STUDENTEIMPIEGATO_H
