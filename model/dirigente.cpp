#include "dirigente.h"

Dirigente::Dirigente(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere,
                     Telefono numeroTelefono, std::string reparto, float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, float baseFissa,
                     QUuid IDAziendale):
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, pagaPerOra, orePreviste, oreFerie, orePermesso, IDAziendale),
    _baseFissa(baseFissa)
{

}

Dirigente::Dirigente(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere,
                     Telefono numeroTelefono, std::string reparto, float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso,
                     QDate dataScadenza, float baseFissa, QUuid IDAziendale):
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, pagaPerOra, orePreviste, oreFerie, orePermesso, dataScadenza, IDAziendale),
    _baseFissa(baseFissa)
{

}

float Dirigente::Stipendio() const
{
    return 0;
}

float Dirigente::getBaseFissa() const
{
    return _baseFissa;
}

void Dirigente::setBaseFissa(float value)
{
    _baseFissa = value;
}
