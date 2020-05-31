#include "MainWindow.h"

#include <QApplication>
#include "classetestxml.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/icona.png"));

    //ClasseTestXML::TestXML();
    //return 0;

    MainWindow w;
    w.show();
    return a.exec();
}
