#include "lavoratore.h"

Lavoratore::Lavoratore(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere, Telefono numeroTelefono, std::string reparto,
                       float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono), _reparto(reparto), _pagaPerOra(pagaPerOra), _orePreviste(orePreviste), _oreFerie(oreFerie),
    _orePermesso(orePermesso), _IDAziendale(IDAziendale)
{

}

std::string Lavoratore::getReparto() const
{
    return _reparto;
}

OreLavorative Lavoratore::getOrePreviste() const
{
    return _orePreviste;
}

OreLavorative Lavoratore::getOreFerie() const
{
    return _oreFerie;
}

OreLavorative Lavoratore::getOrePermesso() const
{
    return _orePermesso;
}

string Lavoratore::getStringID(bool complete) const
{
    if(complete)
        return _IDAziendale.toString().toStdString();//{fec984fc-82b4-44e1-90cd-3366f44d4ac6}
    else
        return _IDAziendale.toString().toStdString().substr(1,8);//fec984fc
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
