#ifndef STUDENTE_H
#define STUDENTE_H
#include "model/persona.h"
#include <string.h>
#include <QDate>

using std::string;

enum Occupazione{Superiori, Universita};
//ho messo public, non ricordo se va o no, ma così non mi da errori
class Studente : virtual public Persona
{
public:
    Studente(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione);

    virtual ~Studente();

private:
    Occupazione Occupazione;
};

#endif // STUDENTE_H
