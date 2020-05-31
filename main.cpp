#include "MainWindow.h"

#include <QApplication>
#include <QDate>
#include <iostream>
#include <data/operaio.h>
#include <data/persona.h>
#include <data/studente_lavoratore.h>
#include <util/lista.h>
#include <util/telefono.h>
#include <util/orelavorative.h>
#include <data/impiegato.h>
#include <data/rappresentante.h>
#include <QFile>
#include <QStringList>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include "classetestxml.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //ClasseTestXML::TestXML();
    //return 0;

    MainWindow w;
    w.show();
    return a.exec();
}
