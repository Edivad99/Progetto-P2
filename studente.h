#ifndef STUDENTE_H
#define STUDENTE_H
#include "persona.h"
#include <string.h>
#include <QDate>

using std::string;

class Studente : public Persona
{
public:
    Studente(string nome, string cognome, QDate datanascita, string codicefiscale, int occupazione);

    ~Studente();//magari metterlo vituale ?

private:
    enum Occupazione{Superiori, Universita};
};

#endif // STUDENTE_H
