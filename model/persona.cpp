#include "persona.h"

Persona::Persona(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono)
    :_nome(nome), _cognome(cognome), _dataNascita(dataNascita), _codiceFiscale(codiceFiscale), _genere(genere), _numeroTelefono(numeroTelefono)
{

};

Persona::~Persona()//quello di base per ora, magari poi lo tolgo se non verrà usato
{

}

Genere Persona::getGenere() const
{
    return _genere;
}

Telefono Persona::getNumeroTelefono() const
{
    return _numeroTelefono;
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
