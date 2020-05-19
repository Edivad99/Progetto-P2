#include "tabellatab.h"

TabellaTab::TabellaTab(QWidget *parent): QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);

    QLabel *text = new QLabel();
    text->setText("Sei nella Tabella");
    mainLayout->addWidget(text);


    mainLayout->setMargin(0);
    setLayout(mainLayout);
}
