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
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
/*
    Persona p1("davide", "albiero", QDate(29,10,1999), "eojrwijw", M, Telefono("3288686776"));
    Persona p2("davide", "albiero", QDate(29,10,1999), "eojrwijw", M, Telefono("3288686776"));

    std::cout << ((p1 == p2) ? "Vero" : "Falso") << std::endl;

    Operaio op1("davide", "albiero", QDate(29,10,1999), "eojrwijw", M, Telefono("3288686776"), "ele", OreLavorative(40,0), OreLavorative(20,0), OreLavorative(20,0), QDate(0,0,0), Livello1);
    Operaio op2("davide", "albiero", QDate(29,10,1999), "eojrwijw", M, Telefono("3288686776"), "ele", OreLavorative(40,0), OreLavorative(20,0), OreLavorative(20,0), QDate(0,0,0), Livello1);
    Operaio op3(op1);
    std::cout << ((op1 == op2) ? "Vero" : "Falso") << std::endl;//Questo è false
    std::cout << ((op1 == op3) ? "Vero" : "Falso") << std::endl;//Questo è true

    StudenteLavoratore sl1 ("davide", "albiero", QDate(29,10,1999), "eojrwijw", M, Telefono("3288686776"), Universita, "ele", OreLavorative(40,0), OreLavorative(20,0), OreLavorative(20,0), QDate(0,0,0));
    StudenteLavoratore sl2 ("davide", "albiero", QDate(29,10,1999), "eojrwijw", M, Telefono("3288686776"), Universita, "ele", OreLavorative(40,0), OreLavorative(20,0), OreLavorative(20,0), QDate(0,0,0));
    std::cout << ((sl1 != sl2) ? "Vero" : "Falso") << std::endl;
    std::cout << sl1.getID() << std::endl;*/

    return 0;


    MainWindow w;
    w.show();
    return a.exec();
}
