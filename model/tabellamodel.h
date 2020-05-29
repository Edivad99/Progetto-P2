#ifndef TABELLAMODEL_H
#define TABELLAMODEL_H

#include <QFile>
#include <data/lavoratore.h>
#include <util/lista.h>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

class TabellaModel
{
public:
    //Costruttore dove va passato l'oggetto XML
    TabellaModel();

    void readFromFile(QFile *file);
    QDomDocument safeFile();

    void aggiungiLavoratore(Lavoratore *nuovoLavoratore);
    lista<Lavoratore*> getLavoratori() const;
private:
    lista<Lavoratore*> lavoratori;
};

#endif // TABELLAMODEL_H
