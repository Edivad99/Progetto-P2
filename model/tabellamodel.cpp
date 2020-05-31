#include "tabellamodel.h"

TabellaModel::TabellaModel()
{
    lavoratori = new lista<Lavoratore*>();
}

void TabellaModel::readFromFile(QDomDocument doc)
{
    QDomElement root = doc.firstChildElement();
    for (int i=0;i<root.childNodes().size();++i)
    {
        if(root.childNodes().at(i).nodeName()=="Operaio")
        {
            QDomElement oper=root.childNodes().at(i).toElement();
            lavoratori->insertBack(new Operaio(oper));
        }
        else if(root.childNodes().at(i).nodeName()=="Impiegato")
        {
            QDomElement impie=root.childNodes().at(i).toElement();
            lavoratori->insertBack(new Impiegato(impie));
        }
        else if(root.childNodes().at(i).nodeName()=="Rappresentante")
        {
            QDomElement rappr=root.childNodes().at(i).toElement();
            lavoratori->insertBack(new Rappresentante(rappr));
        }
        else if(root.childNodes().at(i).nodeName()=="StudenteLavoratore")
        {
            QDomElement studlav=root.childNodes().at(i).toElement();
            lavoratori->insertBack(new StudenteLavoratore(studlav));
        }
    }
}

QDomDocument TabellaModel::saveFile()
{
    QDomDocument doc("Dipendenti");
    QDomElement root = doc.createElement("Dipendenti");

    for (lista<Lavoratore*>::constiterator cit = lavoratori->begin(); cit != lavoratori->end(); ++cit)
    {
        root.appendChild((*cit)->XmlSerialize(doc));
    }
    doc.appendChild(root);
    return doc;
}

void TabellaModel::aggiungiLavoratore(Lavoratore *nuovoLavoratore)
{
    lavoratori->insertBack(nuovoLavoratore);
}

lista<Lavoratore*>* TabellaModel::getLavoratori() const
{
    return lavoratori;
}
