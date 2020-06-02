#ifndef WTELEFONO_H
#define WTELEFONO_H

#include <QFrame>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QIntValidator>
#include <util/telefono.h>

class WTelefono : public QFrame
{
    Q_OBJECT
public:
    WTelefono(QWidget *parent =0);

    Telefono getNumeroTelefono() const;
private:
    QLineEdit *prefisso, *numero;

    void initUI();
};

#endif // WTELEFONO_H