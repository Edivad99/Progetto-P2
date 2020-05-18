#ifndef STUDENTE_H
#define STUDENTE_H
#include "persona.h"

class Studente : public Persona
{
public:
    Studente(char nome, char cognome, /*Data datanascita,*/ char codicefiscale, int occupazione);

    ~Studente();//magari metterlo vituale ?

private:
    enum Occupazione{Superiori, Universita};
};

#endif // STUDENTE_H
