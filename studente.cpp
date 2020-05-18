#include "studente.h"

Studente::Studente(char nome, char cognome, /*Data datanascita,*/ char codicefiscale, int occupazione)
    :Persona(nome, cognome, /*datanascita,*/ codicefiscale)/*, Occupazione(occupazione) inizializzare enum non so come si fa :( )*/{}

Studente::~Studente()
{

};
