#include "MainWindow.h"

#include <QApplication>
#include <QDate>
#include <iostream>
#include <model/operaio.h>
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


    MainWindow w;
    w.show();
    return a.exec();
}
