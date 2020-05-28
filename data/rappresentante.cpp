#include "rappresentante.h"

Rappresentante::Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                               OreLavorative orePreviste, QDate dataScadenza, float pagaPerOra, int venditeEffettuate):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Impiegato(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, dataScadenza, pagaPerOra),
    _venditeEffettuate(venditeEffettuate)
{

}


float Rappresentante::Stipendio(float bonus) const
{
    return Impiegato::Stipendio(bonus) + (_venditeEffettuate * guadagnoPerMerce);
}

int Rappresentante::venditeEffettuate() const
{
    return _venditeEffettuate;
}

void Rappresentante::setVenditeEffettuate(int venditeEffettuate)
{
    _venditeEffettuate = venditeEffettuate;
}

const float Rappresentante::guadagnoPerMerce = 25;
