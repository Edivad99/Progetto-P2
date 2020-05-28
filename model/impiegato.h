#ifndef IMPIEGATO_H
#define IMPIEGATO_H

#include "model/lavoratore.h"

class Impiegato : public Lavoratore
{
public:

    Impiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               OreLavorative orePreviste, float pagaPerOra, QDate dataScadenza);

    virtual float Stipendio(float bonus) const;

    float getPagaPerOra() const;

    void setPagaPerOra(float pagaPerOra);

private:
    float _pagaPerOra;
};

#endif // IMPIEGATO_H
