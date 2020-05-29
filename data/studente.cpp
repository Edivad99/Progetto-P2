#include "studente.h"

Studente::Studente(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, enum Occupazione occupazione)
    :Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono), _occupazione(occupazione)
{

}

Studente::~Studente()
{

}

QDomDocument Studente::XmlSerialize(QDomDocument doc)
{
    QDomElement root = doc.createElement("Studente");
    doc.appendChild(root);
    root.appendChild(Persona::XmlSerialize(doc));

    /*QDomElement occup = doc.createElement("Occupazione");
    QString g=(_occupazione == 0) ? "Superiori" : "Universita'";
    root.appendChild(occup);
    occup.appendChild(doc.createTextNode(g));*/

    return doc;
}

Occupazione Studente::getOccupazione() const
{
    return _occupazione;
};
