#include "operaio.h"

Operaio::Operaio(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono,
                 string reparto, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, Livello livello, QUuid IDAziendale):
                Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
                Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, IDAziendale),
                _livello(livello)
{

}

Operaio::Operaio(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono,
                 string reparto, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza,Livello livello, QUuid IDAziendale):
                Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
                Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, dataScadenza, IDAziendale),
                _livello(livello)
{

}

Operaio::~Operaio()
{

}

Livello Operaio::getLivello() const
{
    return _livello;
}

void Operaio::setLivello(Livello livello)
{
    _livello = livello;
}

float Operaio::Stipendio(float bonus) const
{
    //TODO: decidere se va bene così
    return _salarioMensile[_livello] + bonus;
}

const float Operaio::_salarioMensile[] = {1000, 1350, 1575, 1825, 2100};
