#include "wcspinbox.h"

WCSpinBox::WCSpinBox(QString text, int min, int max, int defaultValue, QWidget *parent) :QFrame(parent), _min(min), _max(max), _text(text)
{
    if(defaultValue < _min)
        _min = defaultValue;
    else if(defaultValue > _max)
        _max = defaultValue;
    initUI();
    livello->setValue(defaultValue);
}

int WCSpinBox::getValue() const
{
    return livello->value();
}

void WCSpinBox::setValue(int newValue)
{
    livello->setValue(newValue);
}

void WCSpinBox::initUI()
{
    livello = new QSpinBox();

    QVBoxLayout *livelloLayout = new QVBoxLayout(this);
    livelloLayout->setMargin(0);
    livelloLayout->setSpacing(0);
    livelloLayout->addWidget(new QLabel(_text));
    livello->setRange(_min, _max);
    livelloLayout->addWidget(livello);
    setLayout(livelloLayout);
}
