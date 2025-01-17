#include "operaio.h"

Operaio::Operaio(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono,
                 string reparto, OreLavorative orePreviste, QDate dataScadenza, Livello livello):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, dataScadenza),
    _livello(livello)
{

}

Operaio::Operaio(QDomElement operaio):
    Persona(operaio.childNodes().at(0).toElement().childNodes().at(0).toElement()),
    Lavoratore(operaio.childNodes().at(0).toElement()),
    _livello(Livello(operaio.attribute("Livello").toInt()-1))
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
    return _salarioMensile[_livello] + bonus;
}

QDomElement Operaio::XmlSerialize(QDomDocument doc) const
{
    QDomElement operaio = doc.createElement(type());
    operaio.appendChild(Lavoratore::XmlSerialize(doc));
    operaio.setAttribute("Livello", _livello + 1);
    return operaio;
}

QString Operaio::type() const
{
    return QString("Operaio");
}

const float Operaio::_salarioMensile[] = {1000, 1350, 1575, 1825, 2100};
