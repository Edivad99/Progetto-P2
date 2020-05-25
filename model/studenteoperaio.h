#ifndef STUDENTEOPERAIO_H
#define STUDENTEOPERAIO_H

#include "model/studente.h"
#include "model/operaio.h"

class StudenteOperaio : public Studente, public Operaio
{
public:
    StudenteOperaio(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione, string reparto,
                    OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, Livello livello, QUuid IDAziendale = QUuid::createUuid());

    StudenteOperaio(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione, string reparto,
                    OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza,Livello livello, QUuid IDAziendale = QUuid::createUuid());

     virtual ~StudenteOperaio();
};

#endif // STUDENTEOPERAIO_H
