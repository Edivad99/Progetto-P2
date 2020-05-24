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
    Lavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               float pagaPerOra, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QUuid IDAziendale = QUuid::createUuid());

    string getReparto() const;

    float getPagaPerOra() const;

    OreLavorative getOrePreviste() const;

    OreLavorative getOreFerie() const;

    OreLavorative getOrePermesso() const;

    void setReparto(string nuovoReparto);

    void setPagaPerOra(float nuovaPagaPerOra);

    void setOrePreviste(OreLavorative o);

    void setOreFerie(OreLavorative o);

    void setOrePermesso(OreLavorative o);

    QUuid getID() const;

    //Se impostato su false restituisce i primi 8 caratteri, che è abbastanza per distinguere i lavoratori
    string getStringID(bool complete = false) const;

    virtual float Stipendio() const;

protected:
    string _reparto;
    float _pagaPerOra;
    OreLavorative _orePreviste;//Le ore previste da contratto
    OreLavorative _oreFerie;//Le ore di ferie da contratto
    OreLavorative _orePermesso;//Le ore di permesso da contratto
    const QUuid _IDAziendale;//Identificativo aziendale, usato per riconoscre il lavoratore
};

#endif // LAVORATORE_H
