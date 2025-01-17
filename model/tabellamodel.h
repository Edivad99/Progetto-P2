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

    void readFromFile(const QDomDocument& doc);
    QDomDocument saveFile();

    void aggiungiLavoratore(Lavoratore *nuovoLavoratore);
    lista<Lavoratore*> getLavoratori() const;

    Lavoratore* getLavoratoreByID(const string& ID);
    void rimuoviPerID(const string& ID);

    QString generaStipendio(float bonus) const;

    bool deviSalvare() const;
    void salvato();

    void eliminaLavoratori();

    static QStringList categorie();

private:
    lista<Lavoratore*> lavoratori;
    bool _deviSalvare;
};

#endif // TABELLAMODEL_H
