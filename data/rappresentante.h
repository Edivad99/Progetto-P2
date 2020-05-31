#ifndef RAPPRESENTANTE_H
#define RAPPRESENTANTE_H

#include "impiegato.h"

class Rappresentante: public Impiegato
{

public:

    Rappresentante(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
                OreLavorative orePreviste, QDate dataScadenza, float pagaPerOra, int venditeEffettuate);

    virtual float Stipendio(float bonus) const;

    virtual QDomElement XmlSerialize(QDomDocument doc) const;

    int getVenditeEffettuate() const;

    void setVenditeEffettuate(int venditeEffettuate);

    static const float guadagnoPerMerce;

private:

    int _venditeEffettuate;
};

#endif // RAPPRESENTANTE_H
