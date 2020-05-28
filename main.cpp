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

    return 0;


    MainWindow w;
    w.show();
    return a.exec();
}
