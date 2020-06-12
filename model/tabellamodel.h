#ifndef TABELLAMODEL_H
#define TABELLAMODEL_H

#include <data/lavoratore.h>
#include <data/impiegato.h>
#include <data/studente_lavoratore.h>
#include <data/operaio.h>
#include <data/rappresentante.h>
#include <util/lista.h>
#include <util/generalutil.h>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

class TabellaModel
{
public:
    TabellaModel();

    void readFromFile(QDomDocument doc);
    QDomDocument saveFile();

    void aggiungiLavoratore(Lavoratore *nuovoLavoratore);
    lista<Lavoratore*> getLavoratori() const;

    Lavoratore* getLavoratoreByID(string ID);
    void rimuoviPerID(string ID);

    QString generaStipendio(float bonus) const;

    bool deviSalvare() const;
    void salvato();

    void eliminaLavoratori();

private:
    lista<Lavoratore*> lavoratori;
    bool _deviSalvare;
};

#endif // TABELLAMODEL_H
