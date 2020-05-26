#include "studente_lavoratore.h"

StudenteLavoratore::StudenteLavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, Occupazione occupazione,
                                       string reparto, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Studente(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, occupazione),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, dataScadenza)
{

}

StudenteLavoratore::~StudenteLavoratore()
{

}

float StudenteLavoratore::Stipendio(float bonus) const
{
    return (getOccupazione() == Superiori ? 250 : 1500);
}
