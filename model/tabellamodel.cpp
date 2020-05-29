#include "tabellamodel.h"

TabellaModel::TabellaModel()
{
    //Imposto il file a nullo
    currentFile = nullptr;
}

void TabellaModel::readFromFile(QFile *file)
{
    //Mi salvo il puntatore all'oggetto  file nel caso l'utente decida di fare solo salva
    currentFile = file;
}

QDomDocument TabellaModel::saveFile()
{
    QDomDocument doc("Dipendenti");
    QDomElement root = doc.createElement("Dipendenti");

    for (lista<Lavoratore*>::constiterator cit = lavoratori.begin(); cit != lavoratori.end(); ++cit)
    {
        root.appendChild((*cit)->XmlSerialize(doc));
    }
    doc.appendChild(root);
    return doc;
}

void TabellaModel::aggiungiLavoratore(Lavoratore *nuovoLavoratore)
{
    lavoratori.insertBack(nuovoLavoratore);
}

lista<Lavoratore*> TabellaModel::getLavoratori() const
{
    return lavoratori;
}
