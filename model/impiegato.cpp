#include "impiegato.h"

Impiegato::Impiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                     OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float pagaPerOra, QUuid IDAziendale):
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, IDAziendale), _pagaPerOra(pagaPerOra)
{

}

Impiegato::Impiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                     OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float pagaPerOra, QDate dataScadenza, QUuid IDAziendale):
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, dataScadenza, IDAziendale),
    _pagaPerOra(pagaPerOra)
{

}

float Impiegato::getPagaPerOra() const
{
    return _pagaPerOra;
}

void Impiegato::setPagaPerOra(float pagaPerOra)
{
    _pagaPerOra = pagaPerOra;
}

float Impiegato::Stipendio() const
{
    return 0;
}
