#include "lavoratore.h"

Lavoratore::Lavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                       OreLavorative orePreviste, QDate dataScadenza):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    _reparto(reparto), _orePreviste(orePreviste), _contratto(dataScadenza.isNull()? Indeterminato : Determinato),
    _dataScadenza(dataScadenza), _IDAziendale(generateID(codiceFiscale))
{

}

Lavoratore::Lavoratore(QDomElement lavorat):
    Persona(lavorat.childNodes().at(0).toElement()),
    _reparto(lavorat.attribute("Reparto").toStdString()), _orePreviste(lavorat.attribute("OrePreviste").split(":")[0].toInt(),lavorat.attribute("OrePreviste").split(":")[1].toInt()),
    _contratto(GeneralUtil::strToItaDate(lavorat.attribute("DataScadenza")).isNull()? Indeterminato : Determinato),
    _dataScadenza(GeneralUtil::strToItaDate(lavorat.attribute("DataScadenza"))), _IDAziendale(generateID(lavorat.childNodes().at(0).toElement().attribute("CodiceFiscale").toStdString()))
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
    lavoratore.setAttribute("DataScadenza", GeneralUtil::dateToItaStr(_dataScadenza));
    lavoratore.setAttribute("IDAziendale", QString::fromStdString(std::to_string(Lavoratore::getID())));
    return lavoratore;
}

QDate Lavoratore::getDataScadenza() const
{
    return _dataScadenza;
}

QString Lavoratore::generateCSVRow(float bonus) const
{
    QString id = QString::fromStdString(std::to_string(_IDAziendale));
    QString nome = QString::fromStdString(getNome());
    QString cognome = QString::fromStdString(getCognome());
    QString codfisc=QString::fromStdString(getCodiceFiscale());
    QString salario=QString::number(Stipendio(bonus));

    return id+";"+nome+";"+cognome+";"+type()+";"+codfisc+";"+salario+"\n";
}
