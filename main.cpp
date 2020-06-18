#include "MainWindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/icona.png"));
    a.setApplicationName("QBusiness");

    MainWindow w;
    w.show();
    return a.exec();
}
