#include "tabellamodel.h"

TabellaModel::TabellaModel(): lavoratori(), _deviSalvare(false)
{
}

void TabellaModel::readFromFile(QDomDocument doc)
{
    lavoratori.clear();
    QDomElement root = doc.firstChildElement();
    for (int i=0;i<root.childNodes().size();++i)
    {
        if(root.childNodes().at(i).nodeName()=="Operaio")
        {
            QDomElement oper=root.childNodes().at(i).toElement();
            lavoratori.insertBack(new Operaio(oper));
        }
        else if(root.childNodes().at(i).nodeName()=="Impiegato")
        {
            QDomElement impie=root.childNodes().at(i).toElement();
            lavoratori.insertBack(new Impiegato(impie));
        }
        else if(root.childNodes().at(i).nodeName()=="Rappresentante")
        {
            QDomElement rappr=root.childNodes().at(i).toElement();
            lavoratori.insertBack(new Rappresentante(rappr));
        }
        else if(root.childNodes().at(i).nodeName()=="StudenteLavoratore")
        {
            QDomElement studlav=root.childNodes().at(i).toElement();
            lavoratori.insertBack(new StudenteLavoratore(studlav));
        }
    }
    _deviSalvare = false;
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

//Per i metodi che bosigna creare, ricordasi di mettere _deviSalvare a TRUE

void TabellaModel::aggiungiLavoratore(Lavoratore *nuovoLavoratore)
{
    lavoratori.insertBack(nuovoLavoratore);
    _deviSalvare = true;
}

lista<Lavoratore*> TabellaModel::getLavoratori() const
{
    return lavoratori;
}

Lavoratore *TabellaModel::getLavoratoreByID(std::string ID)
{
    for (lista<Lavoratore*>::constiterator cit = lavoratori.begin(); cit != lavoratori.end(); ++cit)
    {
        if(std::to_string((*cit)->getID()) == ID)
        {
            _deviSalvare = true;
            return *cit;
        }
    }
    return nullptr;
}

void TabellaModel::rimuoviPerID(std::string ID)
{
    for (lista<Lavoratore*>::constiterator cit = lavoratori.begin(); cit != lavoratori.end(); ++cit)
    {
        if(std::to_string((*cit)->getID()) == ID)
        {
            lavoratori.erase(cit);
            _deviSalvare = true;
            return;
        }
    }
}

QString TabellaModel::generaStipendio(float bonus) const
{
    bonus = std::max(bonus, 0.0F);
    QString result;
    for (lista<Lavoratore*>::constiterator cit = lavoratori.begin(); cit != lavoratori.end(); ++cit)
    {
        QString id=QString::number((*cit)->getID());
        QString nome=QString::fromStdString((*cit)->getNome());
        QString cognome=QString::fromStdString((*cit)->getCognome());

        //getTipologia
        Operaio* operaio =dynamic_cast<Operaio*>((*cit));
        Impiegato* impiegato =dynamic_cast<Impiegato*>((*cit));
        Rappresentante* rappresentante =dynamic_cast<Rappresentante*>((*cit));
        StudenteLavoratore* studlav =dynamic_cast<StudenteLavoratore*>((*cit));
        QString tipologia = "";
        if(operaio)
            tipologia = QString("Operaio");
        else if(impiegato)
        {
            tipologia = QString("Impiegato");
            if (rappresentante)
                tipologia = QString("Rappresentante");
        }
        else if(studlav)
            tipologia = QString("StudenteLavoratore");


        QString codfisc=QString::fromStdString((*cit)->getCodiceFiscale());
        QString salario=QString::number((*cit)->Stipendio(bonus));
        result += id+";"+nome+";"+cognome+";"+tipologia+";"+codfisc+";"+salario+"\n";
    }
    return result;
}

bool TabellaModel::deviSalvare()
{
    return _deviSalvare;
}

void TabellaModel::salvato()
{
    _deviSalvare = false;
}
