#include "wlivello.h"

WLivello::WLivello(int min, int max, QWidget *parent) :QFrame(parent), _min(min), _max(max)
{
    initUI();
}

int WLivello::getLivello() const
{
    return livello->value();
}

void WLivello::initUI()
{
    livello = new QSpinBox();

    QVBoxLayout *livelloLayout = new QVBoxLayout(this);
    livelloLayout->setMargin(0);
    livelloLayout->setSpacing(0);
    livelloLayout->addWidget(new QLabel("Livello"));
    livello->setRange(_min, _max);
    livelloLayout->addWidget(livello);
    setLayout(livelloLayout);
}
