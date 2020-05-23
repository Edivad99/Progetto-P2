#ifndef LAVORATORE_H
#define LAVORATORE_H
#include "model/persona.h"
#include <string>
#include <QDate>
#include <QUuid>

using std::string;

class Lavoratore : public Persona
{
public:
    //TODO: Forse dovremmo usare QTime per gestire le varie ore di lavoro?
    //TODO: Impostare se è a tempo determinato o no
    //TODO: Permettere di cambiare la paga e le ore
    Lavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               float pagaPerOra, float orePreviste, float oreFerie, float orePermesso, QUuid IDAziendale = QUuid::createUuid());

    string getReparto() const;

    float getOrePreviste() const;

    float getOreFerie() const;

    float getOrePermesso() const;

    float getPagaPerOra() const;

    QUuid getID() const;

    virtual float Stipendio() const;

protected:
    string _reparto;
    float _pagaPerOra;
    float _orePreviste;//come sopra
    float _oreFerie;//come sopra
    float _orePermesso;//come sopra
    const QUuid _IDAziendale;
};

#endif // LAVORATORE_H
