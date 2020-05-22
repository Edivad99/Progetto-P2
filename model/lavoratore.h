#ifndef LAVORATORE_H
#define LAVORATORE_H
#include "model/persona.h"
#include <string>
#include <QDate>

using std::string;

class Lavoratore : public Persona
{
public:
    //TODO: Forse dovremmo usare QTime per gestire le varie ore di lavoro?
    //uuid per id dei lavoratori costante
    //enum sesso
    //rendi costante i campi
    Lavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Telefono numeroTelefono, string reparto,
               float pagaPerOra, float orePreviste, float oreFerie, float orePermesso);

    string getReparto() const;

    float getOrePreviste() const;

    float getOreFerie() const;

    float getOrePermesso() const;

    float getPagaPerOra() const;

    virtual float Stipendio() const;

protected:
    string _reparto;
    float _pagaPerOra;
    float _orePreviste;//come sopra
    float _oreFerie;//come sopra
    float _orePermesso;//come sopra
};

#endif // LAVORATORE_H
