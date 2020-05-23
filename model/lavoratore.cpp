#include "lavoratore.h"

Lavoratore::Lavoratore(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere, Telefono numeroTelefono, std::string reparto,
                       float pagaPerOra, float orePreviste, float oreFerie, float orePermesso, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono), _reparto(reparto), _pagaPerOra(pagaPerOra), _orePreviste(orePreviste), _oreFerie(oreFerie),
    _orePermesso(orePermesso), _IDAziendale(IDAziendale)
{

}

std::string Lavoratore::getReparto() const
{
    return _reparto;
}

float Lavoratore::getOrePreviste() const
{
    return _orePreviste;
}

float Lavoratore::getOreFerie() const
{
    return _oreFerie;
}

float Lavoratore::getOrePermesso() const
{
    return _orePermesso;
}

float Lavoratore::getPagaPerOra() const
{
    return _pagaPerOra;
}

QUuid Lavoratore::getID() const
{
    return _IDAziendale;
}

float Lavoratore::Stipendio() const
{
    return 0;
}
