#ifndef WCONTRATTO_H
#define WCONTRATTO_H

#include <QDateEdit>
#include <QFrame>
#include <QLabel>
#include <QRadioButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

class WContratto : public QFrame
{
    Q_OBJECT
public:
    WContratto(QWidget *parent =0);

    QDate getDataScadenza() const;
    bool isDeterminato() const;

    void setContrattoIndeterminato();

    void setContrattoDeterminato(QDate dataScadenza);
private:
    QDateEdit *scadenzaContratto;
    QRadioButton *determinato, *indeterminato;

    void initUI();
};

#endif // WCONTRATTO_H
