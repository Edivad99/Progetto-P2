#include "impiegato.h"

Impiegato::Impiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                     OreLavorative orePreviste, QDate dataScadenza, float pagaPerOra):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, dataScadenza),
    _pagaPerOra(pagaPerOra)
{

}

Impiegato::Impiegato(QDomElement impie):
    Persona(impie.childNodes().at(0).toElement().childNodes().at(0).toElement()),
    Lavoratore(impie.childNodes().at(0).toElement()),
    _pagaPerOra(impie.attribute("PagaOra").toFloat())
{

}

float Impiegato::Stipendio(float bonus) const
{
    float pagaOra = _pagaPerOra * getOrePreviste().getOre();
    float pagaMinuti = _pagaPerOra/60 * getOrePreviste().getMinuti();
    return pagaOra + pagaMinuti + bonus;
}

float Impiegato::getPagaPerOra() const
{
    return _pagaPerOra;
}

void Impiegato::setPagaPerOra(float pagaPerOra)
{
    _pagaPerOra = pagaPerOra;
}

QString Impiegato::type() const
{
    return QString("Impiegato");
}

QDomElement Impiegato::XmlSerialize(QDomDocument doc) const
{
    QDomElement impiegato = doc.createElement(type());
    impiegato.appendChild(Lavoratore::XmlSerialize(doc));
    impiegato.setAttribute("PagaOra", _pagaPerOra);
    return impiegato;
}
