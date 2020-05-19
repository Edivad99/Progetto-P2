#include "studente.h"

Studente::Studente(string nome, string cognome, QDate datanascita, string codicefiscale, int occupazione)
    :Persona(nome, cognome, datanascita, codicefiscale)/*, Occupazione(occupazione) inizializzare enum non so come si fa :( )*/{}

Studente::~Studente()
{

};
