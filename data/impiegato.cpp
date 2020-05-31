#include "impiegato.h"

Impiegato::Impiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                     OreLavorative orePreviste, QDate dataScadenza, float pagaPerOra):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, dataScadenza),
    _pagaPerOra(pagaPerOra)
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

QDomElement Impiegato::XmlSerialize(QDomDocument doc) const
{
    QDomElement impiegato = doc.createElement("Impiegato");;
    impiegato.appendChild(Lavoratore::XmlSerialize(doc));
    impiegato.setAttribute("PagaOra", _pagaPerOra);
    return impiegato;
}
