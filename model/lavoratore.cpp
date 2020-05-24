#include "lavoratore.h"

Lavoratore::Lavoratore(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere, Telefono numeroTelefono, std::string reparto,
                       float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono), _reparto(reparto), _pagaPerOra(pagaPerOra), _orePreviste(orePreviste), _oreFerie(oreFerie),
    _orePermesso(orePermesso), _contratto(dataScadenza.isNull()? Indeterminato : Determinato), _dataScadenza(dataScadenza), _IDAziendale(IDAziendale)
{

}

Lavoratore::Lavoratore(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere, Telefono numeroTelefono, std::string reparto,
                       float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QUuid IDAziendale)
    : Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, pagaPerOra, orePreviste, oreFerie, orePermesso, QDate(0,0,0), IDAziendale)
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

Contratto Lavoratore::getTipologiaContratto() const
{
    return _contratto;
}

void Lavoratore::setReparto(string nuovoReparto)
{
    _reparto = nuovoReparto;
}

void Lavoratore::setPagaPerOra(float nuovaPagaPerOra)
{
    _pagaPerOra = nuovaPagaPerOra;
}

void Lavoratore::setOrePreviste(OreLavorative o)
{
    _orePreviste = o;
}

void Lavoratore::setOreFerie(OreLavorative o)
{
    _oreFerie = o;
}

void Lavoratore::setOrePermesso(OreLavorative o)
{
    _orePermesso = o;
}

void Lavoratore::setContrattoIndeterminato()
{
    _contratto = Indeterminato;
    _dataScadenza = QDate(0,0,0);
}

void Lavoratore::setContrattoDeterminato(QDate dataScadenza)
{
    _contratto = Determinato;
    _dataScadenza = dataScadenza;
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