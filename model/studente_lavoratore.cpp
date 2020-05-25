#include "studente_lavoratore.h"

StudenteLavoratore::StudenteLavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, Occupazione occupazione,
                                       string reparto, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QDate dataScadenza, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono),
    Studente(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, occupazione),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, dataScadenza, IDAziendale)
{

}

StudenteLavoratore::StudenteLavoratore(string nome, string cognome, QDate dataNascita, string codiceFiscale, Genere genere, Telefono numeroTelefono, Occupazione occupazione,
                                       string reparto, OreLavorative orePreviste, OreLavorative oreFerie, OreLavorative orePermesso, QUuid IDAziendale):
    StudenteLavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, occupazione, reparto, orePreviste, oreFerie, orePermesso, QDate(0,0,0), IDAziendale)
{

}
