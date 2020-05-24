#ifndef ORELAVORATIVE_H
#define ORELAVORATIVE_H

#include <ostream>

class OreLavorative
{
public:
    OreLavorative(int ore = 0, int minuti = 0);

    int getOre() const;

    int getMinuti() const;

    void aggiungiOre(int ore);

    void aggiungiMinuti(int minuti);

    OreLavorative operator+(OreLavorative o);
    OreLavorative operator-(OreLavorative o);
    bool operator==(OreLavorative o);
    bool operator!=(OreLavorative o);
    bool operator<(OreLavorative o);
    bool operator<=(OreLavorative o);
    bool operator>(OreLavorative o);
    bool operator>=(OreLavorative o);

private:
    int _sec;
};

std::ostream& operator<<(std::ostream& os, const OreLavorative& o);
#endif // ORELAVORATIVE_H
