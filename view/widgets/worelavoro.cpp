#include "worelavoro.h"

WOreLavoro::WOreLavoro(QWidget *parent) : QFrame(parent)
{
    initUI();
}

OreLavorative WOreLavoro::getOreLavoro() const
{
    return OreLavorative(ore->getValue(), minuti->getValue());
}

void WOreLavoro::setOreLavoro(OreLavorative nuovo)
{
    ore->setValue(nuovo.getOre());
    minuti->setValue(nuovo.getMinuti());
}

void WOreLavoro::initUI()
{
    ore = new WCSpinBox("Ore di lavoro previste", 0, 200, 160);
    minuti = new WCSpinBox("Minuti", 0, 59, 0);

    QHBoxLayout *oreLavoroLayout = new QHBoxLayout(this);
    oreLavoroLayout->setSpacing(0);
    oreLavoroLayout->setMargin(0);
    oreLavoroLayout->addWidget(ore, 60);
    oreLavoroLayout->addWidget(minuti, 40);
    setLayout(oreLavoroLayout);
}
