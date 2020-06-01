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
    //creo un elemento studente lavoratore <StudenteLavoratore>
    QDomElement studlav = doc.createElement("StudenteLavoratore");
    //appendo <Persona>, come nella chiusura a diamante, l'elemento Persona viene creato da StudenteLavoratore
    //studlav.appendChild(Persona::XmlSerialize(doc));
    //creo elemento <Studente> e sottraggo la parte di persona
    QDomElement stud =Studente::XmlSerialize(doc);
    //stud.removeChild(stud.childNodes().at(0).toElement());
    studlav.appendChild(stud);
    //creo elemento <Lavoratore> e sottraggo la parte di persona
    QDomElement lavor =Lavoratore::XmlSerialize(doc);
    //lavor.removeChild(lavor.childNodes().at(0).toElement());
    studlav.appendChild(lavor);
    return studlav;
}
