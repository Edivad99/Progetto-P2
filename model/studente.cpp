#include "studente.h"

Studente::Studente(string nome, string cognome, QDate dataNascita, string codiceFiscale, Telefono numeroTelefono, enum Occupazione occupazione)
    :Persona(nome, cognome, dataNascita, codiceFiscale, numeroTelefono), Occupazione(occupazione)
{

}

Studente::~Studente()
{

};
