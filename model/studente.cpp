#include "studente.h"

Studente::Studente(string nome, string cognome, QDate datanascita, string codicefiscale, enum Occupazione occupazione)
    :Persona(nome, cognome, datanascita, codicefiscale), Occupazione(occupazione)
{

}

Studente::~Studente()
{

};
