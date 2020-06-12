#ifndef STUDENTELAVORATORE_H
#define STUDENTELAVORATORE_H

#include "studente.h"
#include "lavoratore.h"

class StudenteLavoratore : public Studente, public Lavoratore
{
public:
    StudenteLavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione,
                       string reparto, OreLavorative orePreviste, QDate dataScadenza);
    StudenteLavoratore(QDomElement studlavor);

    virtual ~StudenteLavoratore();

    virtual float Stipendio(float bonus = 0) const;

    virtual QDomElement XmlSerialize(QDomDocument doc) const;

    virtual QString type() const;
};

#endif // STUDENTELAVORATORE_H
