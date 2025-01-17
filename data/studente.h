#ifndef STUDENTE_H
#define STUDENTE_H

#include "persona.h"

using std::string;

enum Occupazione{Superiori, Universita};

class Studente : virtual public Persona
{
public:
    Studente(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione);

    Studente(QDomElement stud);

    virtual ~Studente();

    virtual QDomElement XmlSerialize(QDomDocument doc) const;

    Occupazione getOccupazione() const;

private:
    Occupazione _occupazione;
};

#endif // STUDENTE_H
