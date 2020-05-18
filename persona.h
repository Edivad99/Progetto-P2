#ifndef PERSONA_H
#define PERSONA_H
class Persona
{
public:
    Persona(char nome, char cognome, /*Data datanascita,*/ char codicefiscale);

    ~Persona();

    char getNome() const;

    char getCognome() const;

    char getCodiceFiscale() const;

private:
    char Nome;
    char Cognome; //#inclue <string> non lo vede, boh
    //Data DataNascita; non ho trovato la classe standard per la data
    char CodiceFiscale;
};

#endif // PERSONA_H
