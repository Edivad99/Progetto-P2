#include "telefono.h"


Telefono::Telefono(string numeroTelefono, string prefisso): _numeroTelefono((isNumber(numeroTelefono) ? numeroTelefono : "0")),
    _prefisso((isNumber(prefisso) ? prefisso : "0"))
{

}

bool Telefono::isNumber(string numero)
{
    string::const_iterator it = numero.begin();
    while (it != numero.end() && std::isdigit(*it)) ++it;
    return !numero.empty() && it == numero.end();
}

string Telefono::getNumeroTelefono() const
{
    return _numeroTelefono;
}

string Telefono::getPrefisso() const
{
    return _prefisso;
}

std::ostream &operator<<(std::ostream& os, Telefono telefono)
{
    if(telefono.getNumeroTelefono() == "0")
        os << "Sconosciuto";
    else
    {
        if(telefono.getPrefisso() != "0")
            os << telefono.getPrefisso() << " ";
        os << telefono.getNumeroTelefono();
    }
    return  os;
}
