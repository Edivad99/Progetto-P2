#ifndef LAVORATORE_H
#define LAVORATORE_H
#include "model/persona.h"
#include "util/orelavorative.h"
#include <string>
#include <QDate>

using std::string;

enum Contratto{Determinato, Indeterminato};

class Lavoratore : virtual public Persona
{
public:
    //Se la data è invalida allora significa che il lavoro è indeterminato, deve essere l'utente che lo inserisce
    Lavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               OreLavorative orePreviste, QDate dataScadenza);

    virtual ~Lavoratore();

    string getReparto() const;

    OreLavorative getOrePreviste() const;

    Contratto getTipologiaContratto() const;

    void setReparto(string nuovoReparto);

    void setOrePreviste(OreLavorative o);

    void setContrattoIndeterminato();

    void setContrattoDeterminato(QDate dataScadenza);

    size_t getID() const;

    //Possibilità di aggiungere un bonus da sommare al calcolo dello stipendio
    virtual float Stipendio(float bonus = 0) const = 0;

private:
    string _reparto;
    OreLavorative _orePreviste;//Le ore previste da contratto

    //Parte relativa alla tipologia di contratto
    Contratto _contratto;
    QDate _dataScadenza;

    const size_t _IDAziendale;//Identificativo aziendale, usato per riconoscre il lavoratore

    static size_t generateID(string cf);
};

#endif // LAVORATORE_H
