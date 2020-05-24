#include "studenteoperaio.h"

StudenteOperaio::StudenteOperaio(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere,
                                 Telefono numeroTelefono, Studente::Occupazione occupazione, std::string reparto, OreLavorative orePreviste, OreLavorative oreFerie,
                                 OreLavorative orePermesso, Livello livello, QUuid IDAziendale):
    Persona(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono), Occupazione(occupazione),
    Lavoratore(nome, cognome, dataNascita, codiceFiscale, genere, numeroTelefono, reparto, orePreviste, oreFerie, orePermesso, IDAziendale), livello(livello)
{

}
//non so cosa mettere nella lista di inizializzazione, inteoria non vanno tolti tutti quelli di persona e vanno costruiti qui una volta ma non ricordo
StudenteOperaio::StudenteOperaio(std::string nome, std::string cognome, QDate dataNascita, std::string codiceFiscale, Genere genere,
                                 Telefono numeroTelefono, Studente::Occupazione occupazione, std::string reparto, OreLavorative orePreviste, OreLavorative oreFerie,
                                 OreLavorative orePermesso, QDate dataScadenza, Livello livello, QUuid IDAziendale):
    Persona(occupazione),
    Operaio(reparto, orePreviste, oreFerie, orePermesso, dataScadenza, livello, IDAziendale)
{

}
