#include "persona.h"

Persona::Persona(string nome, string cognome, QDate dataNascita, string codiceFiscale, Telefono numeroTelefono)
    :_nome(nome), _cognome(cognome), _dataNascita(dataNascita), _codiceFiscale(codiceFiscale), _numeroTelefono(numeroTelefono)
{

};

Persona::~Persona()//quello di base per ora, magari poi lo tolgo se non verrà usato
{

}

string Persona::getNome() const
{
    return _nome;
}

string Persona::getCognome() const
{
    return _cognome;
}

string Persona::getCodiceFiscale() const
{
    return _codiceFiscale;
}

void Persona::setNumeroTelefono(Telefono numeroTelefono)
{
    _numeroTelefono = numeroTelefono;
}
