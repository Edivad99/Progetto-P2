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

QDomElement Persona::XmlSerialize(QDomDocument doc) const
{
    QDomElement persona = doc.createElement("Persona");
    persona.setAttribute("Nome", QString::fromStdString(_nome));
    persona.setAttribute("Cognome", QString::fromStdString(_cognome));
    persona.setAttribute("DataNascita", _dataNascita.toString("dd/MM/yyyy"));
    persona.setAttribute("CodiceFiscale", QString::fromStdString(_codiceFiscale));
    persona.setAttribute("Genere", QString::fromStdString((_genere == 0) ? "M" : "F"));
    std::stringstream text;
    text << _numeroTelefono;
    persona.setAttribute("Telefono", QString::fromStdString(text.str()));

    return persona;
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

QDate Persona::getDataNascita() const
{
    return _dataNascita;
}
