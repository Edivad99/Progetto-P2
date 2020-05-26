#include "rappresentante.h"

Rappresentante::Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                               OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float pagaPerOra, float venditeEffettuate, QDate dataScadenza):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Impiegato(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, pagaPerOra, dataScadenza),
    _venditeEffettuate(venditeEffettuate)
{

}


float Rappresentante::Stipendio(float bonus) const
{
    return Impiegato::Stipendio(bonus) + (_venditeEffettuate * guadagnoPerMerce);
}

float Rappresentante::venditeEffettuate() const
{
    return _venditeEffettuate;
}

void Rappresentante::setVenditeEffettuate(float venditeEffettuate)
{
    _venditeEffettuate = venditeEffettuate;
}

const float Rappresentante::guadagnoPerMerce = 25;
