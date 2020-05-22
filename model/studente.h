#ifndef STUDENTE_H
#define STUDENTE_H
#include "model/persona.h"
#include <string.h>
#include <QDate>

using std::string;

enum Occupazione{Superiori, Universita};

class Studente : public Persona
{
public:
    Studente(string nome, string cognome, QDate dataNascita, string codiceFiscale, Telefono numeroTelefono, enum Occupazione occupazione);

    ~Studente();//magari metterlo vituale ?

private:
    Occupazione Occupazione;
};

#endif // STUDENTE_H
