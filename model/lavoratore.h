#ifndef LAVORATORE_H
#define LAVORATORE_H
#include "model/persona.h"
#include "util/orelavorative.h"
#include <string>
#include <QDate>
#include <QUuid>

using std::string;

class Lavoratore : public Persona
{
public:
    //TODO: Impostare se è a tempo determinato o no
    //TODO: Permettere di cambiare la paga e le ore
    Lavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QUuid IDAziendale = QUuid::createUuid());

    string getReparto() const;

    float getPagaPerOra() const;

    OreLavorative getOrePreviste() const;

    OreLavorative getOreFerie() const;

    OreLavorative getOrePermesso() const;

    QUuid getID() const;

    //Se impostato su false restituisce i primi 8 caratteri, che è abbastanza per distinguere i lavoratori
    string getStringID(bool complete = false) const;

    virtual float Stipendio() const;

protected:
    string _reparto;
    float _pagaPerOra;
    OreLavorative _orePreviste;//come sopra
    OreLavorative _oreFerie;//come sopra
    OreLavorative _orePermesso;//come sopra
    const QUuid _IDAziendale;
};

#endif // LAVORATORE_H
