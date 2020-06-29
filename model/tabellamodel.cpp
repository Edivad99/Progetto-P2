#include "tabellamodel.h"

TabellaModel::TabellaModel(): lavoratori(), _deviSalvare(false)
{
}

void TabellaModel::readFromFile(QDomDocument doc)
{
    eliminaLavoratori();
    QDomElement root = doc.firstChildElement();
    if(root.nodeName()!= "Dipendenti")
        throw new std::invalid_argument("La root non ha nome \"Dipendenti\"");
    for (int i=0;i<root.childNodes().size();++i)
    {
        if(root.childNodes().at(i).nodeName()=="Operaio")
        {
            QDomElement oper=root.childNodes().at(i).toElement();
            aggiungiLavoratore(new Operaio(oper));
        }
        else if(root.childNodes().at(i).nodeName()=="Impiegato")
        {
            QDomElement impie=root.childNodes().at(i).toElement();
            aggiungiLavoratore(new Impiegato(impie));
        }
        else if(root.childNodes().at(i).nodeName()=="Rappresentante")
        {
            QDomElement rappr=root.childNodes().at(i).toElement();
            aggiungiLavoratore(new Rappresentante(rappr));
        }
        else if(root.childNodes().at(i).nodeName()=="Studente-Lavoratore")
        {
            QDomElement studlav=root.childNodes().at(i).toElement();
            aggiungiLavoratore(new StudenteLavoratore(studlav));
        }
        else
        {
            throw new std::runtime_error("Impossibile processare il contenuto");
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

void TabellaModel::aggiungiLavoratore(Lavoratore *nuovoLavoratore)
{
    for (lista<Lavoratore*>::constiterator cit = lavoratori.begin(); cit != lavoratori.end(); ++cit)
    {
        if((*cit)->getCodiceFiscale() == nuovoLavoratore->getCodiceFiscale())
            throw new std::invalid_argument("Un lavoratore con questo codice fiscale è già stato inserito");
    }
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
    QString result=GeneralUtil::capitalizeFirstLetter(QDate::currentDate().toString("MMMM;yyyy")).append("\n");
    for (lista<Lavoratore*>::constiterator cit = lavoratori.begin(); cit != lavoratori.end(); ++cit)
    {
        result += (*cit)->generateCSVRow(bonus);
    }
    return result;
}

bool TabellaModel::deviSalvare() const
{
    return _deviSalvare;
}

void TabellaModel::salvato()
{
    _deviSalvare = false;
}

void TabellaModel::eliminaLavoratori()
{
    lavoratori.clear();
}

QStringList TabellaModel::categorie()
{
    QStringList tipologieItems;
    tipologieItems.push_back("Operaio");
    tipologieItems.push_back("Impiegato");
    tipologieItems.push_back("Rappresentante");
    tipologieItems.push_back("Studente-Lavoratore");
    return tipologieItems;
}
