#include "wstipendiomensile.h"

WStipendioMensile::WStipendioMensile(QDate data, float *stipendio, QWidget *parent): QFrame(parent), _data(data), _stipendio(stipendio)
{
    initUI();
}

void WStipendioMensile::initUI()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);

    layout->addWidget(new QLabel("<h3><b>" + GeneralUtil::capitalizeFirstLetter(_data.toString("MMMM")) + "</b></h3>"));
    layout->addWidget(new QLabel("Operaio: " + QString::number(_stipendio[0]) + " €"));
    layout->addWidget(new QLabel("Impiegato: " + QString::number(_stipendio[1]) + " €"));
    layout->addWidget(new QLabel("Raprresentante: " + QString::number(_stipendio[2]) + " €"));
    layout->addWidget(new QLabel("StudenteLavoratore: " + QString::number(_stipendio[3]) + " €"));
    layout->addWidget(new QLabel("Altro: " + QString::number(_stipendio[4]) + " €"));
    layout->addWidget(new QLabel("Totale: " + QString::number(std::accumulate(_stipendio, _stipendio + 4, 0)) + " €"));
    setLayout(layout);
}
