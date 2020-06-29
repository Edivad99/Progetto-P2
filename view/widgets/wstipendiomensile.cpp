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
    QStringList categorie = TabellaModel::categorie();
    for(int i = 0; i < categorie.size(); i++)
    {
        layout->addWidget(new QLabel(categorie.at(i) + ": " + QString::number(_stipendio[i]) + " €"));
    }
    layout->addWidget(new QLabel("Altro: " + QString::number(_stipendio[categorie.size()]) + " €"));
    layout->addWidget(new QLabel("Totale: " + QString::number(std::accumulate(_stipendio, _stipendio + categorie.size(), 0)) + " €"));
    setLayout(layout);
}
