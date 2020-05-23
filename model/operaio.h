#ifndef OPERAIO_H
#define OPERAIO_H

#include "model/lavoratore.h"

enum Livello{ Livello1, Livello2, Livello3, Livello4, Livello5 };

class Operaio : public Lavoratore
{
public:

    Operaio(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, string reparto,
               float pagaPerOra, int orePreviste, int oreFerie, int orePermesso, Livello livello, QUuid IDAziendale = QUuid::createUuid());

    Livello getLivello() const;

    void setLivello(Livello livello);

    virtual float Stipendio() const;

private:
    Livello _livello;
    static const float _salarioMensile[5];
};

#endif // OPERAIO_H
