#include "rappresentante.h"

Rappresentante::Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                               OreLavorative orePreviste, QDate dataScadenza, float pagaPerOra, int venditeEffettuate):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Impiegato(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, dataScadenza, pagaPerOra),
    _venditeEffettuate(venditeEffettuate)
{

}

Rappresentante::Rappresentante(QDomElement rappr):
    Persona(rappr.childNodes().at(0).toElement().childNodes().at(0).toElement().childNodes().at(0).toElement()),
    Impiegato(rappr.childNodes().at(0).toElement()),
    _venditeEffettuate(rappr.attribute("Vendite").toInt())
{

}


float Rappresentante::Stipendio(float bonus) const
{
    return Impiegato::Stipendio(bonus) + (_venditeEffettuate * guadagnoPerMerce);
}

int Rappresentante::getVenditeEffettuate() const
{
    return _venditeEffettuate;
}

void Rappresentante::setVenditeEffettuate(int venditeEffettuate)
{
    _venditeEffettuate = venditeEffettuate;
}

QString Rappresentante::type() const
{
    return QString("Rappresentante");
}

QDomElement Rappresentante::XmlSerialize(QDomDocument doc) const
{
    QDomElement rappre = doc.createElement(type());;
    rappre.appendChild(Impiegato::XmlSerialize(doc));
    rappre.setAttribute("Vendite", _venditeEffettuate);
    return rappre;
}

const float Rappresentante::guadagnoPerMerce = 25;
