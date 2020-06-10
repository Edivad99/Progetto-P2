#ifndef WORELAVORO_H
#define WORELAVORO_H

#include "wcspinbox.h"

#include <QFrame>

#include <util/orelavorative.h>

class WOreLavoro : public QFrame
{
    Q_OBJECT
public:
    WOreLavoro(QWidget *parent =0);

    OreLavorative getOreLavoro() const;
    void setOreLavoro(OreLavorative nuovo);

private:
    WCSpinBox *ore,*minuti;
    void initUI();
};

#endif // WORELAVORO_H
