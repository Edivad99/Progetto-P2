#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <QDate>
#include <QString>
#include "util/telefono.h"
#include "util/generalutil.h"
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <sstream>

using std::string;

enum Genere{M, F};

class Persona
{
public:

    Persona(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono);

    Persona(QDomElement pers);

    virtual ~Persona();

    string getNome() const;

    string getCognome() const;

    string getCodiceFiscale() const;

    Genere getGenere() const;

    Telefono getNumeroTelefono() const;

    virtual QDomElement XmlSerialize(QDomDocument doc) const;

    void setNumeroTelefono(const Telefono& numeroTelefono);

    bool operator==(const Persona &p) const;

    bool operator!=(const Persona &p) const;

    QDate getDataNascita() const;

private:
    const string _nome;
    const string _cognome;
    const QDate _dataNascita;
    const string _codiceFiscale;
    const Genere _genere;
    Telefono _numeroTelefono;
};

#endif // PERSONA_H
