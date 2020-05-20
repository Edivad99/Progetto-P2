#include "tabellatab.h"

TabellaTab::TabellaTab(QWidget *parent): QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    actionTable = new QVBoxLayout();

    table = new QTableWidget(5,6);
    table->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    aggiungiTestoEsempio();


    QLabel *text = new QLabel();
    text->setText("Opzioni");
    actionTable->addWidget(text);


    mainLayout->addWidget(table);
    mainLayout->addLayout(actionTable);

    mainLayout->setMargin(0);
    setLayout(mainLayout);
}

void TabellaTab::aggiungiTestoEsempio()
{
    for(int i=0; i<table->rowCount(); i++)
    {
        for(int j=0; j<table->columnCount(); j++)
        {
            QTableWidgetItem *pCell = table->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                table->setItem(i, j, pCell);
            }
            std::stringstream text;
            text << "(" << i << "," << j << ")";
            pCell->setText(QString::fromStdString(text.str()));
        }
    }
}
