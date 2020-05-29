#ifndef OPERAIO_H
#define OPERAIO_H

#include "lavoratore.h"

enum Livello{ Livello1, Livello2, Livello3, Livello4, Livello5 };

class Operaio : public Lavoratore
{
public:

    Operaio(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               OreLavorative orePreviste, QDate dataScadenza, Livello livello);

    Livello getLivello() const;

    void setLivello(Livello livello);

    virtual float Stipendio(float bonus) const;

    virtual QDomElement XmlSerialize(QDomDocument doc);

private:
    Livello _livello;
    static const float _salarioMensile[5];
};

#endif // OPERAIO_H
