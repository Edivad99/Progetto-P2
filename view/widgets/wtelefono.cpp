#include "wtelefono.h"

WTelefono::WTelefono(QWidget *parent) : QFrame(parent)
{
    initUI();
}

Telefono WTelefono::getNumeroTelefono() const
{
    return Telefono(numero->text().toStdString(), prefisso->text().toStdString());
}

void WTelefono::setNumeroTelefono(Telefono telefono)
{
    if(telefono.getNumeroTelefono() == "0")
    {
        prefisso->setText("");
        numero->setText("");
    }
    else
    {
        prefisso->setText(QString::fromStdString(telefono.getPrefisso()));
        numero->setText(QString::fromStdString(telefono.getNumeroTelefono()));
    }
}

void WTelefono::reset()
{
    prefisso->setText("39");
    numero->setText("");
}

void WTelefono::initUI()
{
    numero = new QLineEdit();
    prefisso = new QLineEdit();

    QHBoxLayout *telefonoLayout = new QHBoxLayout(this);
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
