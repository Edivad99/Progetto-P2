#ifndef STUDENTE_H
#define STUDENTE_H
#include "persona.h"
#include <string.h>

using std::string;

class Studente : public Persona
{
public:
    Studente(string nome, string cognome, /*Data datanascita,*/ string codicefiscale, int occupazione);

    ~Studente();//magari metterlo vituale ?

private:
    enum Occupazione{Superiori, Universita};
};

#endif // STUDENTE_H
