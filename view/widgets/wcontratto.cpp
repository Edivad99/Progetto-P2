#include "wcontratto.h"

WContratto::WContratto(QWidget *parent) : QFrame(parent)
{
    initUI();
}

QDate WContratto::getDataScadenza()
{
    return scadenzaContratto->date();
}

bool WContratto::isDeterminato()
{
    return determinato->isChecked();
}

void WContratto::initUI()
{
    scadenzaContratto = new QDateEdit(QDate::currentDate().addMonths(1));
    determinato = new QRadioButton();
    indeterminato = new QRadioButton();

    QVBoxLayout *contrattoLayout = new QVBoxLayout();
    contrattoLayout->setSpacing(0);
    contrattoLayout->setMargin(0);
    contrattoLayout->addWidget(new QLabel("Tipologia di Contratto"));

    indeterminato->setText("Indeterminato");
    indeterminato->setChecked(true);
    contrattoLayout->addWidget(indeterminato);

    QHBoxLayout *determinatoLayout = new QHBoxLayout();
    determinato->setText("Determinato");
    determinatoLayout->addWidget(determinato);
    determinatoLayout->addWidget(scadenzaContratto);

    contrattoLayout->addLayout(determinatoLayout);
    setLayout(contrattoLayout);
}
