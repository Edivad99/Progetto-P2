#ifndef LAVORATORE_H
#define LAVORATORE_H
#include "persona.h"

class Lavoratore : public Persona
{
public:
    Lavoratore(char nome, char cognome, /*Data datanascita,*/ char codicefiscale, char reparto, float pagaperora, float orelavoro, float orelavorare, float oreferie, float orepermesso);

    virtual ~Lavoratore();

    char getReparto() const;

    float getOreLavoro() const;

    float getOreLavorare() const;

    float getOreFerie() const;

    float getOrePermesso() const;

    float getPagaPerOra() const;

    virtual float Stipendio(float PagaPerOra) const;
    virtual float Stipendio(int mese) const;
/*pensavo:
 * 1.1 parametro(PagaPerOra) = stipendio annuale
 * 2.2 parametri(magari un mese) e PagaPerOra = stipendio di quel mese
 * qua è ancora vago perchè non so come calcolare lo stipendio, facciamo che è in base a OreLavorare? oppure in altro modo? e se poi mettiamo straordinari?
*/

private:
    char Reparto;
    float PagaPerOra;
    float OreLavoro;//ore trasformate in base dieci
    float OreLavorare;//come sopra
    float OreFerie;//come sopra
    float OrePermesso;//come sopra
};

#endif // LAVORATORE_H
