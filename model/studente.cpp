#include "studente.h"

Studente::Studente(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione)
    :Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono), _occupazione(occupazione)
{

}

Studente::~Studente()
{

}

Occupazione Studente::getOccupazione() const
{
    return _occupazione;
};
