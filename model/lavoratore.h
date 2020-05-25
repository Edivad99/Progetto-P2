#ifndef LAVORATORE_H
#define LAVORATORE_H
#include "model/persona.h"
#include "util/orelavorative.h"
#include <string>
#include <QDate>
#include <QUuid>

using std::string;

enum Contratto{Determinato, Indeterminato};

class Lavoratore : virtual public Persona
{
public:
    //Se la data è invalida allora significa che il lavoro è indeterminato, deve essere l'utente che lo inserisce
    Lavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza, QUuid IDAziendale = QUuid::createUuid());

    virtual ~Lavoratore();

    string getReparto() const;

    OreLavorative getOrePreviste() const;

    OreLavorative getOreFerie() const;

    OreLavorative getOrePermesso() const;

    Contratto getTipologiaContratto() const;

    void setReparto(string nuovoReparto);

    void setOrePreviste(OreLavorative o);

    void setOreFerie(OreLavorative o);

    void setOrePermesso(OreLavorative o);

    void setContrattoIndeterminato();

    void setContrattoDeterminato(QDate dataScadenza);

    QUuid getID() const;

    //Se impostato su false restituisce i primi 8 caratteri, che è abbastanza per distinguere i lavoratori
    string getStringID(bool complete = false) const;

    //Possibilità di aggiungere un bonus da sommare al calcolo dello stipendio
    virtual float Stipendio(float bonus = 0) const = 0;

    bool operator==(const Lavoratore &p) const;

    bool operator!=(const Lavoratore &p) const;

private:
    string _reparto;
    OreLavorative _orePreviste;//Le ore previste da contratto
    OreLavorative _oreFerie;//Le ore di ferie da contratto
    OreLavorative _orePermesso;//Le ore di permesso da contratto

    //Parte relativa alla tipologia di contratto
    Contratto _contratto;
    QDate _dataScadenza;

    const QUuid _IDAziendale;//Identificativo aziendale, usato per riconoscre il lavoratore
};

#endif // LAVORATORE_H
