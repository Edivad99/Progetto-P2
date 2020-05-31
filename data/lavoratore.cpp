#include "lavoratore.h"

Lavoratore::Lavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                       OreLavorative orePreviste, QDate dataScadenza):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    _reparto(reparto), _orePreviste(orePreviste), _contratto(dataScadenza.isNull()? Indeterminato : Determinato),
    _dataScadenza(dataScadenza), _IDAziendale(generateID(codiceFiscale))
{

}

Lavoratore::~Lavoratore()
{

}

string Lavoratore::getReparto() const
{
    return _reparto;
}

OreLavorative Lavoratore::getOrePreviste() const
{
    return _orePreviste;
}

Contratto Lavoratore::getTipologiaContratto() const
{
    return _contratto;
}

void Lavoratore::setReparto(string nuovoReparto)
{
    _reparto = nuovoReparto;
}

void Lavoratore::setOrePreviste(OreLavorative o)
{
    _orePreviste = o;
}

void Lavoratore::setContrattoIndeterminato()
{
    _contratto = Indeterminato;
    _dataScadenza = QDate(0,0,0);
}

void Lavoratore::setContrattoDeterminato(QDate dataScadenza)
{
    _contratto = Determinato;
    _dataScadenza = dataScadenza;
}

size_t Lavoratore::getID() const
{
    return _IDAziendale;
}

size_t Lavoratore::generateID(std::string cf)
{
    std::hash<std::string> hash_fn;
    size_t str_hash = hash_fn(cf);
    return str_hash;
}

QDomElement Lavoratore::XmlSerialize(QDomDocument doc) const
{
    QDomElement lavoratore = doc.createElement("Lavoratore");;
    lavoratore.appendChild(Persona::XmlSerialize(doc));
    lavoratore.setAttribute("Reparto", QString::fromStdString(_reparto));
    std::stringstream ss;
    ss << _orePreviste;
    lavoratore.setAttribute("OrePreviste", QString::fromStdString(ss.str()));
    lavoratore.setAttribute("Contratto", QString::fromStdString((_contratto == 0) ? "Determinato" : "Indeterminato"));
    lavoratore.setAttribute("DataScadenza", _dataScadenza.toString("dd/MM/yyyy"));
    lavoratore.setAttribute("IDAziendale", Lavoratore::getID());
    return lavoratore;
}

QDate Lavoratore::getDataScadenza() const
{
    return _dataScadenza;
}
