#include "rappresentante.h"


Rappresentante::Rappresentante(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale,
                               Genere genere, Telefono numeroTelefono, std::string reparto, float pagaPerOra, OreLavorative orePreviste,
                               OreLavorative oreFerie, OreLavorative orePermesso, float venditeEffettuate, float pagaPerOra3,
                               QUuid IDAziendale): Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere,
                                                 numeroTelefono, reparto, pagaPerOra, orePreviste,
                                                 oreFerie, orePermesso, IDAziendale), _pagaPerOra3(pagaPerOra3), _venditeEffettuate(venditeEffettuate)
{

}

Rappresentante::Rappresentante(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale,
                               Genere genere, Telefono numeroTelefono, std::string reparto, float pagaPerOra, OreLavorative orePreviste,
                               OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza,
                               float venditeEffettuate, float pagaPerOra3, QUuid IDAziendale): Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere,
                                                                          numeroTelefono, reparto, pagaPerOra, orePreviste,
                                                                          oreFerie, orePermesso, dataScadenza, IDAziendale), _pagaPerOra3(pagaPerOra3), _venditeEffettuate(venditeEffettuate)
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

// PAGAPERORA3
float Rappresentante::pagaPerOra3() const
{
    return _pagaPerOra3;
}

void Rappresentante::setPagaPerOra3(float pagaPerOra3)
{
    _pagaPerOra3 = pagaPerOra3;
}
