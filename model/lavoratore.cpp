#include "lavoratore.h"

Lavoratore::Lavoratore(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Telefono numeroTelefono, std::string reparto,
                       float pagaPerOra, float orePreviste, float oreFerie, float orePermesso):
    Persona(nome, cognome, dataNascita, codiceFiscale, numeroTelefono), _reparto(reparto), _pagaPerOra(pagaPerOra), _orePreviste(orePreviste), _oreFerie(oreFerie),
    _orePermesso(orePermesso)
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

float Lavoratore::Stipendio() const
{
    return 0;
}
