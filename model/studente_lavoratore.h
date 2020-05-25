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

    virtual ~StudenteLavoratore();

    virtual float Stipendio(float bonus = 0) const;

    bool operator==(const StudenteLavoratore &sl) const;

    bool operator!=(const StudenteLavoratore &sl) const;
};

#endif // STUDENTELAVORATORE_H
