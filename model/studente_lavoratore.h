#ifndef STUDENTELAVORATORE_H
#define STUDENTELAVORATORE_H

#include "studente.h"
#include "lavoratore.h"

class StudenteLavoratore : public Studente, Lavoratore
{
public:
    //Lo studente lavoratore forse dovrebbe avere sempre la data di scadenza
    StudenteLavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione,
                       string reparto, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza, QUuid IDAziendale = QUuid::createUuid());

    StudenteLavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione,
                       string reparto, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QUuid IDAziendale = QUuid::createUuid());
};

#endif // STUDENTELAVORATORE_H
