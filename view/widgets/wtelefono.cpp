#include "wtelefono.h"

WTelefono::WTelefono(QWidget *parent) : QFrame(parent)
{
    initUI();
}

Telefono WTelefono::getNumeroTelefono()
{
    return Telefono(numero->text().toStdString(), prefisso->text().toStdString());
}

void WTelefono::initUI()
{
    numero = new QLineEdit();
    prefisso = new QLineEdit();

    QHBoxLayout *telefonoLayout = new QHBoxLayout();
    telefonoLayout->setSpacing(0);
    telefonoLayout->setMargin(0);
    prefisso->setPlaceholderText("Prefisso");
    prefisso->setText("39");
    prefisso->setValidator(new QIntValidator());
    numero->setPlaceholderText("Numero di Telefono");
    numero->setValidator(new QIntValidator());
    telefonoLayout->addWidget(prefisso, 20);
    telefonoLayout->addWidget(numero, 80);
    setLayout(telefonoLayout);
}
