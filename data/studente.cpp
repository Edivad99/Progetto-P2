#include "studente.h"

Studente::Studente(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione)
    :Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono), _occupazione(occupazione)
{

}

Studente::Studente(QDomElement stud):Persona(stud.childNodes().at(0).toElement()),
    _occupazione(Occupazione(stud.attribute("Occupazione").toStdString()=="Superiori" ? 0:1))
{

}

Studente::~Studente()
{

}

QDomElement Studente::XmlSerialize(QDomDocument doc) const
{
    QDomElement studente = doc.createElement("Studente");;
    studente.appendChild(Persona::XmlSerialize(doc));
    studente.setAttribute("Occupazione", QString::fromStdString((_occupazione == 0) ? "Superiori" : "Universita'"));
    return studente;
}

Occupazione Studente::getOccupazione() const
{
    return _occupazione;
};
