#include "studente_lavoratore.h"

StudenteLavoratore::StudenteLavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, Occupazione occupazione,
                                       string reparto, OreLavorative orePreviste, QDate dataScadenza):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Studente(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, occupazione),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, dataScadenza)
{

}

StudenteLavoratore::StudenteLavoratore(QDomElement studlavor):
    Persona(studlavor.childNodes().at(0).toElement().childNodes().at(0).toElement()),//persona
    Studente(studlavor.childNodes().at(0).toElement()),//studente
    Lavoratore(studlavor.childNodes().at(1).toElement())//lavoratore
{

}

StudenteLavoratore::~StudenteLavoratore()
{

}

float StudenteLavoratore::Stipendio(float bonus) const
{
    return (getOccupazione() == Superiori ? 250 : 1500);
}

QDomElement StudenteLavoratore::XmlSerialize(QDomDocument doc) const
{
    QDomElement studlav = doc.createElement(type());
    studlav.appendChild(Studente::XmlSerialize(doc));
    studlav.appendChild(Lavoratore::XmlSerialize(doc));
    return studlav;
}

QString StudenteLavoratore::type() const
{
    return QString("Studente-Lavoratore");
}
