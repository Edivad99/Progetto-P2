#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <QDate>
#include "util/telefono.h"

using std::string;
class Persona
{
public:
    Persona(string nome, string cognome, QDate dataNascita, string codiceFiscale, Telefono numeroTelefono);

    ~Persona();

    string getNome() const;

    string getCognome() const;

    string getCodiceFiscale() const;

    void setNumeroTelefono(Telefono numeroTelefono);

private:
    const string _nome;
    const string _cognome;
    const QDate _dataNascita;
    const string _codiceFiscale;
    Telefono _numeroTelefono;
};

#endif // PERSONA_H
