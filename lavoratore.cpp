#include "lavoratore.h"

Lavoratore::Lavoratore(char nome, char cognome, /*Data datanascita,*/ char codicefiscale, char reparto, float pagaperora, float orelavoro, float orelavorare, float oreferie, float orepermesso)
    : Persona(nome,cognome, /*datanascita,*/ codicefiscale), Reparto(reparto),
      PagaPerOra(pagaperora), OreLavoro(orelavoro), OreLavorare(orelavorare), OreFerie(oreferie), OrePermesso(orepermesso) {};

char Lavoratore::getReparto() const
{
    return Reparto;
}

float Lavoratore::getOreLavoro() const
{
    return OreLavoro;
}

float Lavoratore::getOreLavorare() const
{
    return OreLavorare;
}

float Lavoratore::getOreFerie() const
{
    return OreFerie;
}

float Lavoratore::getOrePermesso() const
{
    return OrePermesso;
}

float Lavoratore::getPagaPerOra() const
{
    return PagaPerOra;
}

float Lavoratore::Stipendio(float PagaPerOra) const
{
    //fai return del stipendio annuale (se possibile calcolalo preciso, se non possibile
    //perche lavoratore lavora da meno di un anno in azzienda, calcola stipendio atteso(magari usando come valore per i mesi mancanti un valore medio))
}

float Lavoratore::Stipendio(int mese) const
{
    //da vedere come implementare perche mancano i collegamente con una classe Data e una lista delle ore lavorate durante quel preciso mese
}
