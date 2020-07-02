#ifndef TELEFONO_H
#define TELEFONO_H

#include <string>
#include <ostream>

using std::string;

class Telefono
{
public:
    Telefono(string numeroTelefono, string prefisso = "39");
    static Telefono Sconosciuto();

    static bool isNumber(const string& numero);

    string getNumeroTelefono() const;
    string getPrefisso() const;

    bool operator==(const Telefono& t) const;
    bool operator!=(const Telefono& t) const;

private:
    string _numeroTelefono;
    string _prefisso;
};

std::ostream& operator<<(std::ostream& os, const Telefono& telefono);

#endif // TELEFONO_H
