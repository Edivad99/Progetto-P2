#ifndef LAVORATORE_H
#define LAVORATORE_H

#include "persona.h"
#include "util/orelavorative.h"

using std::string;

enum Contratto{Determinato, Indeterminato};

class Lavoratore : virtual public Persona
{
public:
    //Se la data è invalida allora significa che il lavoro è indeterminato, deve essere l'utente che lo inserisce
    Lavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               OreLavorative orePreviste, QDate dataScadenza);

    Lavoratore(QDomElement lavorat);

    string getReparto() const;

    OreLavorative getOrePreviste() const;

    Contratto getTipologiaContratto() const;

    void setReparto(const string& nuovoReparto);

    void setOrePreviste(const OreLavorative& o);

    void setContrattoIndeterminato();

    void setContrattoDeterminato(const QDate& dataScadenza);

    size_t getID() const;

    //Possibilità di aggiungere un bonus da sommare al calcolo dello stipendio
    virtual float Stipendio(float bonus = 0) const = 0;

    virtual QDomElement XmlSerialize(QDomDocument doc) const;

    QDate getDataScadenza() const;

    QString generateCSVRow(float bonus) const;

    virtual QString type() const = 0;

private:
    string _reparto;
    OreLavorative _orePreviste;//Le ore previste da contratto

    //Parte relativa alla tipologia di contratto
    Contratto _contratto;
    QDate _dataScadenza;

    const size_t _IDAziendale;//Identificativo aziendale, usato per riconoscre il lavoratore

    static size_t generateID(const string& cf);
};

#endif // LAVORATORE_H
