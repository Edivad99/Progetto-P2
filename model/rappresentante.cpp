#include "rappresentante.h"

Rappresentante::Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                               OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float pagaPerOra, float venditeEffettuate, QUuid IDAziendale)
    :Impiegato(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, pagaPerOra, IDAziendale), _venditeEffettuate(venditeEffettuate)
{

}

Rappresentante::Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                               OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float venditeEffettuate, float pagaPerOra, QDate dataScadenza, QUuid IDAziendale)
    :Impiegato(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, pagaPerOra, dataScadenza, IDAziendale), _venditeEffettuate(venditeEffettuate)
{

}

float Rappresentante::Stipendio() const
{
    return 0;
}

float Rappresentante::venditeEffettuate() const
{
    return _venditeEffettuate;
}

void Rappresentante::setVenditeEffettuate(float venditeEffettuate)
{
    _venditeEffettuate = venditeEffettuate;
}
