#ifndef TELEFONO_H
#define TELEFONO_H

#include <string>
#include <ostream>

using std::string;

class Telefono
{
public:
    Telefono(string numeroTelefono, string prefisso = "39");

    static bool isNumber(string numero);

    string getNumeroTelefono() const;
    string getPrefisso() const;

private:
    string _numeroTelefono;
    string _prefisso;
};

std::ostream &operator<<(std::ostream& os, Telefono telefono);

#endif // TELEFONO_H
