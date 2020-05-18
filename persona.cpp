#include "persona.h"

Persona::Persona(char nome, char cognome, /*Data datanascita,*/ char codicefiscale)
    :Nome(nome), Cognome(cognome), /*DataNascita(datanascita),*/ CodiceFiscale(codicefiscale){};
//è giusta la dichiarazione e lista di inizializzazione?

Persona::~Persona()//quello di base per ora, magari poi lo tolgo se non verrà usato
{

}

char Persona::getNome() const
{
    return Nome;
}

char Persona::getCognome() const
{
    return Cognome;
}

char Persona::getCodiceFiscale() const
{
    return CodiceFiscale;
}
