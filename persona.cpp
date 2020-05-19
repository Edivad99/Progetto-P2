#include "persona.h"

Persona::Persona(string nome, string cognome, QDate datanascita, string codicefiscale)
    :Nome(nome), Cognome(cognome), DataNascita(datanascita), CodiceFiscale(codicefiscale)
{

};

Persona::~Persona()//quello di base per ora, magari poi lo tolgo se non verrà usato
{

}

string Persona::getNome() const
{
    return Nome;
}

string Persona::getCognome() const
{
    return Cognome;
}

string Persona::getCodiceFiscale() const
{
    return CodiceFiscale;
}
