#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <QDate>
#include "util/telefono.h"

using std::string;

enum Genere{M, F};

class Persona
{
public:

    Persona(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono);

    virtual ~Persona();

    string getNome() const;

    string getCognome() const;

    string getCodiceFiscale() const;

    Genere getGenere() const;

    Telefono getNumeroTelefono() const;

    void setNumeroTelefono(Telefono numeroTelefono);

    bool operator==(const Persona &p) const;

    bool operator!=(const Persona &p) const;

private:
    const string _nome;
    const string _cognome;
    const QDate _dataNascita;
    const string _codiceFiscale;
    const Genere _genere;
    Telefono _numeroTelefono;
};

#endif // PERSONA_H
