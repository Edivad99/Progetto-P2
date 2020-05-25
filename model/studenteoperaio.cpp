#include "studenteoperaio.h"

StudenteOperaio::StudenteOperaio(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere,Telefono numeroTelefono,
                                 enum Occupazione occupazione, string reparto, OreLavorative orePreviste, OreLavorative oreFerie,
                                 OreLavorative orePermesso, Livello livello, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, IDAziendale),
    Studente(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, occupazione),
    Operaio(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, livello, IDAziendale)

{

}

StudenteOperaio::StudenteOperaio(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono,
                                 enum Occupazione occupazione, string reparto, OreLavorative orePreviste, OreLavorative oreFerie,
                                 OreLavorative orePermesso, QDate dataScadenza, Livello livello, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, dataScadenza, IDAziendale),
    Studente(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, occupazione),
    Operaio(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, dataScadenza, livello, IDAziendale)
{

}

StudenteOperaio::~StudenteOperaio()
{

}
