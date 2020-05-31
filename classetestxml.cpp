#include "classetestxml.h"

void ClasseTestXML::TestXML()
{
    /*Letture da csv*/

   /*QFile file("..\\Progetto-P2\\dipendenti.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return 1;
    }

    QStringList wordlist;
    lista<Lavoratore*> dipendenti;
    while (!file.atEnd())
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            wordlist=line.split(";");
            QString a=wordlist.first();
            wordlist.pop_front();

            string nome = wordlist[0].toUtf8().constData();
            string cognome = wordlist[1].toUtf8().constData();
            QDate dataNascita = QDate::fromString(wordlist[2],"dd/MM/yyyy");
            string cf = wordlist[3].toUtf8().constData();
            Genere genere = Genere(wordlist[4].toInt());
            //Bisogna fare dei controlli sul telefono per il prefisso
            Telefono telefono(wordlist[5].toUtf8().constData());
            string reparto = wordlist[7].toUtf8().constData();
            OreLavorative oreLavorative(wordlist[8].split(":")[0].toInt(),wordlist[8].split(":")[1].toInt());
            QDate dataScadenza = QDate::fromString(wordlist[9],"dd/MM/yyyy");

            if(a=="Operaio")
                dipendenti.insertBack(new Operaio(nome, cognome, dataNascita, cf, genere, telefono, reparto, oreLavorative, dataScadenza, Livello(wordlist[10].toInt())));
            else if(a=="Impiegato")
                dipendenti.insertBack(new Impiegato(nome, cognome, dataNascita ,cf, genere, telefono, reparto, oreLavorative, dataScadenza, wordlist[11].toFloat()));
            else if(a=="Rappresentante")
                dipendenti.insertBack(new Rappresentante(nome, cognome, dataNascita ,cf, genere, telefono, reparto, oreLavorative, dataScadenza, wordlist[11].toFloat(), wordlist[12].toFloat()));
            else if(a=="StudenteLavoratore")
                dipendenti.insertBack(new StudenteLavoratore(nome, cognome, dataNascita, cf, genere, telefono, Occupazione(wordlist[6].toInt()), reparto, oreLavorative, dataScadenza));
            wordlist.clear();
        }
    }
    std::cout << dipendenti.front()->getNome() <<" "<< dipendenti.front()->getDataNascita().toString("dd/MM/yyyy").toStdString()<< std::endl;*/


    //SCRITTURA XML
    /*Persona p("Matteoo","Vignagaa",QDate(1998,07,26),"VGNMTT23389025",Genere(0),Telefono("3926146576"));
    Studente s("Matteoo","Vignagaa",QDate(1998,07,26),"VGNMTT23389025",Genere(0),Telefono("3926146576"),Occupazione::Universita);
    Impiegato im("Matteoo","Vignagaa",QDate(1998,07,26),"VGNMTT23389025",Genere(0),Telefono("3926146576"),"Montaggio",OreLavorative(120),QDate(2020,11,21),10.50);
    Operaio op("Matteoo","Vignagaa",QDate(1998,07,26),"VGNMTT23389025",Genere(0),Telefono("3926146576"),"Montaggio",OreLavorative(120),QDate(2020,11,21),Livello::Livello5);
    Rappresentante ra("Matteoo","Vignagaa",QDate(1998,07,26),"VGNMTT23389025",Genere(0),Telefono("3926146576"),"Montaggio",OreLavorative(120),QDate(2020,11,21),8.00,15);
    StudenteLavoratore sl("Matteoo","Vignagaa",QDate(1998,07,26),"VGNMTT23389025",Genere(0),Telefono("3926146576"), Occupazione::Universita,"Montaggio",50,QDate(2020,12,25));

    QDomDocument doc("Dipendenti");
    QDomElement root = doc.createElement("Dipendenti");;
    root.appendChild(p.XmlSerialize(doc));
    root.appendChild(s.XmlSerialize(doc));
    root.appendChild(im.XmlSerialize(doc));
    root.appendChild(op.XmlSerialize(doc));
    root.appendChild(ra.XmlSerialize(doc));
    root.appendChild(sl.XmlSerialize(doc));
    doc.appendChild(root);

    QFile file2("C:\\Users\\Matteo\\Desktop\\doc.xml");
    if(!file2.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << file2.errorString();
    }
    else
    {
        QTextStream stream(&file2);
        stream<<doc.toString();
        file2.close();
    }*/

    //LETTURA XML

    QDomDocument documentoletto("Docum");
    QFile filelett("C:\\Users\\Matteo\\Desktop\\doc2.xml");
    if(!filelett.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Errore nell'apertura del file";
        return;
    }
    else
    {
        if(!documentoletto.setContent(&filelett))
        {
            qDebug() <<  "Errore nel caricare il documento";
            return;
        }
        filelett.close();
    }
    lista<Lavoratore*> dipendenti2;
    //prendi l'elemento root

    QDomElement root = documentoletto.firstChildElement();
    for (int i=0;i<root.childNodes().size();++i) {
        if(root.childNodes().at(i).nodeName()=="Operaio")
        {
            QDomElement oper=root.childNodes().at(i).toElement();
            /*QDomElement lavor=oper.childNodes().at(0).toElement();
            QDomElement pers=lavor.childNodes().at(0).toElement();
            string nome=pers.attribute("Nome").toStdString();
            string cognome=pers.attribute("Cognome").toStdString();
            QDate datanasc=QDate::fromString(pers.attribute("DataNascita"),"dd/MM/yyyy");
            string codfisc=pers.attribute("CodiceFiscale").toStdString();
            Genere gener=Genere(pers.attribute("Genere").toInt());
            Telefono numtelef(pers.attribute("Telefono").split(" ")[1].toStdString(),pers.attribute("Telefono").split(" ")[0].toStdString());
            string repart=lavor.attribute("Reparto").toStdString();
            OreLavorative orelav(lavor.attribute("OrePreviste").split(":")[0].toInt(),lavor.attribute("OrePreviste").split(":")[1].toInt());
            QDate datascad = QDate::fromString(lavor.attribute("DataScadenza"),"dd/MM/yyyy");
            Livello livell=Livello(oper.attribute("Livello").toInt());
            qDebug() <<QString::fromStdString(nome);
            qDebug() <<QString::fromStdString(cognome);
            qDebug() <<datanasc.toString("dd/MM/yyyy");
            qDebug() <<QString::fromStdString(codfisc);
            qDebug() <<QString::fromStdString((gener == 0) ? "M" : "F");
            qDebug() <<QString::fromStdString(numtelef.getNumeroTelefono());
            qDebug() <<QString::fromStdString(repart);
            qDebug() <<orelav.getOre()<<":"<<orelav.getMinuti();
            qDebug() <<datascad.toString();
            qDebug() <<livell;*/
            dipendenti2.insertBack(new Operaio(oper));
            /*qDebug() <<"Operaio----------------------------- "<<i;
            qDebug() <<QString::fromStdString(dipendenti2.back()->getNome());
            qDebug() <<QString::fromStdString(dipendenti2.back()->getCognome());
            qDebug() <<dipendenti2.back()->getDataNascita().toString("dd/MM/yyyy");
            qDebug() <<QString::fromStdString(dipendenti2.back()->getCodiceFiscale());
            qDebug() <<dipendenti2.back()->getGenere();
            qDebug() <<QString::fromStdString(dipendenti2.back()->getNumeroTelefono().getNumeroTelefono());
            qDebug() <<QString::fromStdString(dipendenti2.back()->getReparto());
            qDebug() <<dipendenti2.back()->getOrePreviste().getOre()<<":"<<dipendenti2.back()->getOrePreviste().getMinuti();
            qDebug() <<dipendenti2.back()->getDataScadenza().toString("dd/MM/yyyy");
            qDebug() <<dynamic_cast<Operaio*>(dipendenti2.back())->getLivello();
            qDebug() <<dipendenti2.back()->getID();
            qDebug() <<"Operaio-------------------------fine "<<i;*/
        }
        if(root.childNodes().at(i).nodeName()=="Impiegato")
        {
            QDomElement impie=root.childNodes().at(i).toElement();
            dipendenti2.insertBack(new Impiegato(impie));
            /*qDebug() <<"Impiegato----------------------------- "<<i;
            qDebug() <<QString::fromStdString(dipendenti2.back()->getNome());
            qDebug() <<QString::fromStdString(dipendenti2.back()->getCognome());
            qDebug() <<dipendenti2.back()->getDataNascita().toString("dd/MM/yyyy");
            qDebug() <<QString::fromStdString(dipendenti2.back()->getCodiceFiscale());
            qDebug() <<dipendenti2.back()->getGenere();
            qDebug() <<QString::fromStdString(dipendenti2.back()->getNumeroTelefono().getNumeroTelefono());
            qDebug() <<QString::fromStdString(dipendenti2.back()->getReparto());
            qDebug() <<dipendenti2.back()->getOrePreviste().getOre()<<":"<<dipendenti2.back()->getOrePreviste().getMinuti();
            qDebug() <<dipendenti2.back()->getDataScadenza().toString("dd/MM/yyyy");
            qDebug() <<dynamic_cast<Impiegato*>(dipendenti2.back())->getPagaPerOra();
            qDebug() <<dipendenti2.back()->getID();
            qDebug() <<"Impiegato-------------------------fine "<<i;*/
        }
        if(root.childNodes().at(i).nodeName()=="Rappresentante")
        {
            QDomElement rappr=root.childNodes().at(i).toElement();
            dipendenti2.insertBack(new Rappresentante(rappr));
            /*qDebug() <<"Rappresentante----------------------------- "<<i;
            qDebug() <<QString::fromStdString(dipendenti2.back()->getNome());
            qDebug() <<QString::fromStdString(dipendenti2.back()->getCognome());
            qDebug() <<dipendenti2.back()->getDataNascita().toString("dd/MM/yyyy");
            qDebug() <<QString::fromStdString(dipendenti2.back()->getCodiceFiscale());
            qDebug() <<dipendenti2.back()->getGenere();
            qDebug() <<QString::fromStdString(dipendenti2.back()->getNumeroTelefono().getNumeroTelefono());
            qDebug() <<QString::fromStdString(dipendenti2.back()->getReparto());
            qDebug() <<dipendenti2.back()->getOrePreviste().getOre()<<":"<<dipendenti2.back()->getOrePreviste().getMinuti();
            qDebug() <<dipendenti2.back()->getDataScadenza().toString("dd/MM/yyyy");
            qDebug() <<dynamic_cast<Impiegato*>(dipendenti2.back())->getPagaPerOra();
            qDebug() <<dynamic_cast<Rappresentante*>(dipendenti2.back())->getVenditeEffettuate();
            qDebug() <<dipendenti2.back()->getID();
            qDebug() <<"Rappresentante-------------------------fine "<<i;*/
        }
        if(root.childNodes().at(i).nodeName()=="StudenteLavoratore")
        {
            QDomElement studlav=root.childNodes().at(i).toElement();
            dipendenti2.insertBack(new StudenteLavoratore(studlav));
            /*qDebug() <<"StudenteLavoratore----------------------------- "<<i;
            qDebug() <<QString::fromStdString(dipendenti2.back()->getNome());
            qDebug() <<QString::fromStdString(dipendenti2.back()->getCognome());
            qDebug() <<dipendenti2.back()->getDataNascita().toString("dd/MM/yyyy");
            qDebug() <<QString::fromStdString(dipendenti2.back()->getCodiceFiscale());
            qDebug() <<dipendenti2.back()->getGenere();
            qDebug() <<QString::fromStdString(dipendenti2.back()->getNumeroTelefono().getNumeroTelefono());
            qDebug() <<QString::fromStdString(dipendenti2.back()->getReparto());
            qDebug() <<dipendenti2.back()->getOrePreviste().getOre()<<":"<<dipendenti2.back()->getOrePreviste().getMinuti();
            qDebug() <<dipendenti2.back()->getDataScadenza().toString("dd/MM/yyyy");
            qDebug() <<dynamic_cast<StudenteLavoratore*>(dipendenti2.back())->getOccupazione();
            qDebug() <<dipendenti2.back()->getID();
            qDebug() <<"StudenteLavoratore-------------------------fine "<<i;*/
        }
    }

    qDebug() <<  "documento caricato";
}
