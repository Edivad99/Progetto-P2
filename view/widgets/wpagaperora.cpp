#include "wpagaperora.h"

WPagaPerOra::WPagaPerOra(QWidget *parent):QFrame(parent)
{
    initUI();
}

float WPagaPerOra::getPaga() const
{
    return pagaPerOra->value();
}

void WPagaPerOra::setPaga(float newPaga)
{
    pagaPerOra->setValue(newPaga);
}

void WPagaPerOra::initUI()
{
    pagaPerOra = new QDoubleSpinBox();

    QVBoxLayout *pagaLayout = new QVBoxLayout(this);
    pagaLayout->setMargin(0);
    pagaLayout->setSpacing(0);
    pagaLayout->addWidget(new QLabel("Paga oraria"));
    pagaPerOra->setRange(0, 10000);
    pagaLayout->addWidget(pagaPerOra);
    setLayout(pagaLayout);
}
