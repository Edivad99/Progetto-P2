#include "studente_lavoratore.h"

StudenteLavoratore::StudenteLavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, Occupazione occupazione,
                                       string reparto, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Studente(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, occupazione),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, dataScadenza, IDAziendale)
{

}

StudenteLavoratore::~StudenteLavoratore()
{

}

float StudenteLavoratore::Stipendio(float bonus) const
{
    return (getOccupazione() == Superiori ? 250 : 1500);
}

bool StudenteLavoratore::operator==(const StudenteLavoratore &sl) const
{
    return Persona::operator==(sl) && Lavoratore::operator==(sl);
}

bool StudenteLavoratore::operator!=(const StudenteLavoratore &sl) const
{
    return !operator==(sl);
}
