#include "impiegato.h"

//RICORDARE DI CAMBIARE PAGAPERORA2

Impiegato::Impiegato(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere, Telefono numeroTelefono,
                     std::string reparto, float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie,
                     OreLavorative orePermesso, float pagaPerOra2, QUuid IDAziendale): Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere,
                                                                                                  numeroTelefono, reparto, pagaPerOra, orePreviste,
                                                                                                  oreFerie, orePermesso, IDAziendale), _pagaPerOra2(pagaPerOra2)
{

}

Impiegato::Impiegato(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere, Telefono numeroTelefono,
                     std::string reparto, float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie,
                     OreLavorative orePermesso, QDate dataScadenza, float pagaPerOra2, QUuid IDAziendale): Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere,
                                                                                                                      numeroTelefono, reparto, pagaPerOra, orePreviste,
                                                                                                                      oreFerie, orePermesso, dataScadenza, IDAziendale), _pagaPerOra2(pagaPerOra2)
{

}

float Impiegato::pagaPerOra2() const
{
    return _pagaPerOra2;
}

void Impiegato::setPagaPerOra2(float pagaPerOra2)
{
    _pagaPerOra2 = pagaPerOra2;
}

float Impiegato::Stipendio() const
{
    return 0;
}
