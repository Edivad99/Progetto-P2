#include "hometab.h"

HomeTab::HomeTab(QWidget *parent) :QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);

    QLabel *text = new QLabel();
    text->setText("Sei nella HOME");
    mainLayout->addWidget(text);


    mainLayout->setMargin(0);
    setLayout(mainLayout);
}
