#include "orelavorative.h"


OreLavorative::OreLavorative(int ore, int minuti)
{
    if(ore < 0 || minuti < 0)
        _sec = 0;
    else
        _sec = ore * 3600 + minuti * 60;
}

int OreLavorative::getOre() const
{
    return _sec / 3600;
}

int OreLavorative::getMinuti() const
{
    return (_sec / 60) % 60;
}

void OreLavorative::aggiungiOre(int ore)
{
    int supp = _sec + (ore * 3600);
    _sec = std::max(supp, 0);
}

void OreLavorative::aggiungiMinuti(int minuti)
{
    int supp = _sec + (minuti * 60);
    _sec = std::max(supp, 0);
}

OreLavorative OreLavorative::operator+(OreLavorative o)
{
    OreLavorative result;
    result._sec = _sec + o._sec;
    return result;
}

OreLavorative OreLavorative::operator-(OreLavorative o)
{
    OreLavorative result;
    result._sec = std::max(_sec - o._sec, 0);
    return result;
}

bool OreLavorative::operator==(OreLavorative o)
{
    return _sec == o._sec;
}

bool OreLavorative::operator!=(OreLavorative o)
{
    return _sec != o._sec;
}

bool OreLavorative::operator<(OreLavorative o)
{
    return _sec < o._sec;
}

bool OreLavorative::operator<=(OreLavorative o)
{
    return _sec <= o._sec;
}

bool OreLavorative::operator>(OreLavorative o)
{
    return _sec > o._sec;
}

bool OreLavorative::operator>=(OreLavorative o)
{
    return _sec >= o._sec;
}

std::ostream& operator<<(std::ostream& os, const OreLavorative& o)
{
    os << o.getOre() << ":" << o.getMinuti();
    return os;
}
