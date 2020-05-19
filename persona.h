#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <QDate>

using std::string;
class Persona
{
public:
    Persona(string nome, string cognome, QDate datanascita, string codicefiscale);

    ~Persona();

    string getNome() const;

    string getCognome() const;

    string getCodiceFiscale() const;

private:
    string Nome;
    string Cognome;
    QDate DataNascita;
    string CodiceFiscale;
};

#endif // PERSONA_H
