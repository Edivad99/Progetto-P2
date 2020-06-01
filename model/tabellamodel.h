#ifndef TABELLAMODEL_H
#define TABELLAMODEL_H

#include <data/lavoratore.h>
#include <data/impiegato.h>
#include <data/studente_lavoratore.h>
#include <data/operaio.h>
#include <data/rappresentante.h>
#include <util/lista.h>
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

    bool deviSalvare();
    void salvato();

private:
    lista<Lavoratore*> lavoratori;
    bool _deviSalvare;
};

#endif // TABELLAMODEL_H
