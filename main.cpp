#include "MainWindow.h"

#include <QApplication>
#include <QDate>
#include <iostream>
#include <model/operaio.h>
#include <model/lavoratore.h>
#include <model/impiegato.h>
#include <model/rappresentante.h>
#include <model/persona.h>
#include <model/studente_lavoratore.h>
#include <util/lista.h>
#include <util/telefono.h>
#include <util/orelavorative.h>
#include <QFile>
#include <QStringList>
#include <QString>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    /*lista<int> l;
    std::cout << "La lista e' vuota: " << (l.isEmpty() ? "Si" : "No") << std::endl;
    for(int i=0; i < 10; i++)
        l.insertBack(i+1);
    for(lista<int>::constiterator cit = l.begin(); cit != l.end(); ++cit)
        std::cout<< *(cit) << " ";
    std::cout << std::endl;//0 1 2 3 4 5 6 7 8 9
    for(lista<int>::constiterator cit = --(l.end()); cit != --l.begin(); --cit)
        std::cout<< *(cit) << " ";
    std::cout << std::endl;//0 9 8 7 6 5 4 3 2 1

    std::cout << "La lista e' vuota: " << (l.isEmpty() ? "Si" : "No") << std::endl;

    StudenteLavoratore sl1 ("davide", "albiero", QDate(29,10,1999), "eojrwijw", M, Telefono("3288686776"), Universita, "ele", OreLavorative(40,0), OreLavorative(20,0), OreLavorative(20,0), QDate(0,0,0));
    StudenteLavoratore sl2 ("davide", "albiero", QDate(29,10,1999), "eojrwijw", M, Telefono("3288686776"), Universita, "ele", OreLavorative(40,0), OreLavorative(20,0), OreLavorative(20,0), QDate(0,0,0));
    std::cout << ((sl1 != sl2) ? "Vero" : "Falso") << std::endl;
    std::cout << sl1.getID() << std::endl;*/

    lista<int> l;
    for (int i = 0; i < 10; i++)
        l.insertBack(i + 1);
    for (lista<int>::constiterator cit = l.begin(); cit != l.end(); ++cit)
        cout << *(cit) << " ";
    cout << endl;//1 2 3 4 5 6 7 8 9 10

    for (lista<int>::constiterator cit = l.begin(); cit != l.end();)
    {
        if (*cit == 1)
        {
            cit = l.erase(cit);
        }
        else
        {
            cout << *(cit) << " ";
            ++cit;
        }
    }

    return 0;*/

    /*Letture da csv*/

    QFile file("..\\Progetto-P2\\dipendenti.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return 1;
    }

    QStringList wordlist;
    lista<Lavoratore*> dipendenti;
    while (!file.atEnd()) {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            wordlist=line.split(";");
            QString a=wordlist.first();
            wordlist.pop_front();
            if(a=="Operaio")
            {
                dipendenti.insertBack(new Operaio(wordlist[0].toUtf8().constData(),
                                      wordlist[1].toUtf8().constData(),
                        QDate(wordlist[2].split("/")[0].toInt(),wordlist[2].split("/")[1].toInt(),wordlist[2].split("/")[2].toInt()),
                        wordlist[3].toUtf8().constData(),
                        Genere(wordlist[4].toInt()),
                        Telefono(wordlist[5].toUtf8().constData()),
                        wordlist[7].toUtf8().constData(),
                        OreLavorative(wordlist[8].split(":")[0].toInt(),wordlist[8].split(":")[1].toInt()),
                        QDate(wordlist[9].split("/")[0].toInt(),wordlist[9].split("/")[1].toInt(),wordlist[9].split("/")[2].toInt()),
                        Livello(wordlist[10].toInt())));
            }
            else
            {
                if(a=="Impiegato")
                {
                    dipendenti.insertBack(new Impiegato(wordlist[0].toUtf8().constData(),
                                          wordlist[1].toUtf8().constData(),
                            QDate(wordlist[2].split("/")[0].toInt(),wordlist[2].split("/")[1].toInt(),wordlist[2].split("/")[2].toInt()),
                            wordlist[3].toUtf8().constData(),
                            Genere(wordlist[4].toInt()),
                            Telefono(wordlist[5].toUtf8().constData()),
                            wordlist[7].toUtf8().constData(),
                            OreLavorative(wordlist[8].split(":")[0].toInt(),wordlist[8].split(":")[1].toInt()),
                            wordlist[11].toFloat(),
                            QDate(wordlist[9].split("/")[0].toInt(),wordlist[9].split("/")[1].toInt(),wordlist[9].split("/")[2].toInt())));
                }
                else
                {
                    if(a=="Rappresentante")
                    {
                        dipendenti.insertBack(new Rappresentante(wordlist[0].toUtf8().constData(),
                                              wordlist[1].toUtf8().constData(),
                                QDate(wordlist[2].split("/")[0].toInt(),wordlist[2].split("/")[1].toInt(),wordlist[2].split("/")[2].toInt()),
                                wordlist[3].toUtf8().constData(),
                                Genere(wordlist[4].toInt()),
                                Telefono(wordlist[5].toUtf8().constData()),
                                wordlist[7].toUtf8().constData(),
                                OreLavorative(wordlist[8].split(":")[0].toInt(),wordlist[8].split(":")[1].toInt()),
                                wordlist[11].toFloat(),wordlist[12].toFloat(),
                                QDate(wordlist[9].split("/")[0].toInt(),wordlist[9].split("/")[1].toInt(),
                                wordlist[9].split("/")[2].toInt())));
                    }
                    else
                    {
                        if(a=="StudenteLavoratore")
                        {
                            dipendenti.insertBack(new StudenteLavoratore(wordlist[0].toUtf8().constData(),
                                                  wordlist[1].toUtf8().constData(),
                                    QDate(wordlist[2].split("/")[0].toInt(), wordlist[2].split("/")[1].toInt(),wordlist[2].split("/")[2].toInt()),
                                    wordlist[3].toUtf8().constData(),
                                    Genere(wordlist[4].toInt()),
                                    Telefono(wordlist[5].toUtf8().constData()),
                                    Occupazione(wordlist[6].toInt()),
                                    wordlist[7].toUtf8().constData(),
                                    OreLavorative(wordlist[8].split(":")[0].toInt(),wordlist[8].split(":")[1].toInt()),
                                    QDate(wordlist[9].split("/")[0].toInt(), wordlist[9].split("/")[1].toInt(), wordlist[9].split("/")[2].toInt())));
                        }
                    }
                }
            }
            wordlist.clear();
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}
