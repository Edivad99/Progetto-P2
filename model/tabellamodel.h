#ifndef TABELLAMODEL_H
#define TABELLAMODEL_H

#include <data/lavoratore.h>
#include <util/lista.h>

class TabellaModel
{
public:
    //Costruttore dove va passato l'oggetto XML
    TabellaModel();

    void aggiungiLavoratore(Lavoratore *nuovoLavoratore);
    lista<Lavoratore*> getLavoratori() const;
private:
    lista<Lavoratore*> lavoratori;
};

#endif // TABELLAMODEL_H
