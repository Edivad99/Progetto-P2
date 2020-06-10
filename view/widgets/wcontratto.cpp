#include "wcontratto.h"

WContratto::WContratto(QWidget *parent) : QFrame(parent)
{
    initUI();
}

QDate WContratto::getDataScadenza() const
{
    return determinato->isChecked() ? scadenzaContratto->date() : QDate(0,0,0);
}

bool WContratto::isDeterminato() const
{
    return determinato->isChecked();
}

void WContratto::setContrattoIndeterminato()
{
    indeterminato->setChecked(true);
    determinato->setChecked(false);
    scadenzaContratto->setDate(QDate::currentDate().addMonths(1));
}

void WContratto::setContrattoDeterminato(QDate dataScadenza)
{
    indeterminato->setChecked(false);
    determinato->setChecked(true);
    scadenzaContratto->setDate(dataScadenza);
}

void WContratto::initUI()
{
    scadenzaContratto = new QDateEdit(QDate::currentDate().addMonths(1));
    determinato = new QRadioButton();
    indeterminato = new QRadioButton();

    QVBoxLayout *contrattoLayout = new QVBoxLayout(this);
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
