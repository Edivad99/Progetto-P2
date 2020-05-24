#include "MainWindow.h"

#include <QApplication>
#include "util/telefono.h"
#include "util/orelavorative.h"
#include <QDate>
#include <QUuid>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*Telefono t ("3484367845");
    Telefono t1 ("971456", "0444");
    std::cout << "Il mio numero di telefono e' " << t << " quello di casa e' " << t1 << std::endl;

    OreLavorative o (40);
    OreLavorative o1 (40);
    std::cout << o.getOre() << std::endl;
    o1.aggiungiOre(2);
    o1.aggiungiMinuti(15);
    std::cout << o1 << std::endl;
    o.aggiungiOre(-50);
    std::cout << o << std::endl;
    std::cout << (o<o1) << std::endl;

    return 0;*/

    MainWindow w;
    w.show();
    return a.exec();
}
