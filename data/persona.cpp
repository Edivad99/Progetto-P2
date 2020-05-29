#include "persona.h"

Persona::Persona(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono)
    :_nome(nome), _cognome(cognome), _dataNascita(dataNascita), _codiceFiscale(codiceFiscale), _genere(genere), _numeroTelefono(numeroTelefono)
{

};

Persona::~Persona()
{

}

Genere Persona::getGenere() const
{
    return _genere;
}

Telefono Persona::getNumeroTelefono() const
{
    return _numeroTelefono;
}

QDomDocument Persona::XmlSerialize(QDomDocument doc)
{
    QDomElement root = doc.createElement("Persona");
    doc.appendChild(root);

    QDomElement nome = doc.createElement("Nome");
    root.appendChild(nome);
    nome.appendChild(doc.createTextNode(QString::fromStdString(_nome)));

    QDomElement cognome = doc.createElement("Cognome");
    root.appendChild(cognome);
    cognome.appendChild(doc.createTextNode(QString::fromStdString(_cognome)));


    QDomElement datanascita = doc.createElement("DataNascita");
    root.appendChild(datanascita);
    datanascita.appendChild(doc.createTextNode(_dataNascita.toString("dd/MM/yyyy")));


    QDomElement codicefisc = doc.createElement("CodiceFiscale");
    root.appendChild(codicefisc);
    codicefisc.appendChild(doc.createTextNode(QString::fromStdString(_codiceFiscale)));

    QDomElement genere = doc.createElement("Genere");
    QString g=(_genere == 0) ? "M" : "F";
    root.appendChild(genere);
    QDomText generee=doc.createTextNode(g);
    genere.appendChild(generee);

    QDomElement telefono = doc.createElement("Telefono");
    root.appendChild(telefono);
    std::stringstream text;
    text << _numeroTelefono;
    QDomText telefonoo=doc.createTextNode(QString::fromStdString(text.str()));
    telefono.appendChild(telefonoo);

    return doc;
}

string Persona::getNome() const
{
    return _nome;
}

string Persona::getCognome() const
{
    return _cognome;
}

string Persona::getCodiceFiscale() const
{
    return _codiceFiscale;
}

void Persona::setNumeroTelefono(Telefono numeroTelefono)
{
    _numeroTelefono = numeroTelefono;
}

bool Persona::operator==(const Persona &p) const
{
    return _nome == p._nome &&
            _cognome == p._cognome &&
            _dataNascita == p._dataNascita &&
            _codiceFiscale == p._codiceFiscale &&
            _genere == p._genere &&
            _numeroTelefono == p._numeroTelefono;
}

bool Persona::operator!=(const Persona &p) const
{
    return !operator==(p);
}

QDate Persona::getDataNascita() const
{
    return _dataNascita;
}
