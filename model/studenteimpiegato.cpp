#include "studenteimpiegato.h"


StudenteImpiegato::StudenteImpiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono,
                                     Occupazione occupazione, string reparto, OreLavorative orePreviste, OreLavorative oreFerie,
                                     OreLavorative orePermesso, float pagaPerOra, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, IDAziendale),
    Studente(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, occupazione),
    Impiegato(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, pagaPerOra, IDAziendale)
{

}

StudenteImpiegato::StudenteImpiegato(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono,
                                     Occupazione occupazione, string reparto, OreLavorative orePreviste, OreLavorative oreFerie,
                                     OreLavorative orePermesso, float pagaPerOra, QDate dataScadenza, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, dataScadenza, IDAziendale),
    Studente(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, occupazione),
    Impiegato(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, pagaPerOra, dataScadenza, IDAziendale)
{

}

StudenteImpiegato::~StudenteImpiegato()
{

}
