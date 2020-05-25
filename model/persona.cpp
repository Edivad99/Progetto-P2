#include "persona.h"

Persona::Persona(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono)
    :_nome(nome), _cognome(cognome), _dataNascita(dataNascita), _codiceFiscale(codiceFiscale), _genere(genere), _numeroTelefono(numeroTelefono)
{

};

Persona::~Persona()
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

bool Persona::operator==(const Persona &p) const
{
    return _nome == p._nome &&
            _cognome == p._cognome &&
            _dataNascita == p._dataNascita &&
            _codiceFiscale == p._codiceFiscale &&
            _genere == p._genere &&
            _numeroTelefono == p._numeroTelefono;
}

bool Persona::operator!=(const Persona &p) const
{
    return !operator==(p);
}
