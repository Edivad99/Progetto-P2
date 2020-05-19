#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using std::string;
class Persona
{
public:
    Persona(string nome, string cognome, /*Data datanascita,*/ string codicefiscale);

    ~Persona();

    string getNome() const;

    string getCognome() const;

    string getCodiceFiscale() const;

private:
    string Nome;
    string Cognome; //#inclue <string> non lo vede, boh
    //Data DataNascita; non ho trovato la classe standard per la data
    string CodiceFiscale;
};

#endif // PERSONA_H
