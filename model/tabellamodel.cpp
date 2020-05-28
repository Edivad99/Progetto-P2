#include "tabellamodel.h"

TabellaModel::TabellaModel()
{

}

void TabellaModel::aggiungiLavoratore(Lavoratore *nuovoLavoratore)
{
    lavoratori.insertBack(nuovoLavoratore);
}

lista<Lavoratore*> TabellaModel::getLavoratori() const
{
    return lavoratori;
}
