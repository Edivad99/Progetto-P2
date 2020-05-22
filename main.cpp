#include "MainWindow.h"

#include <QApplication>
#include "util/telefono.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*Telefono t ("3484367845");
    Telefono t1 ("971456", "0444");
    std::cout << "Il mio numero di telefono e' " << t << " quello di casa e' " << t1 << std::endl;
    return 0;*/

    MainWindow w;
    w.show();
    return a.exec();
}
