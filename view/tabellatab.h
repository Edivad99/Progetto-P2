#ifndef TABELLATAB_H
#define TABELLATAB_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <sstream>

class TabellaTab : public QWidget
{
    Q_OBJECT
public:
    TabellaTab(QWidget *parent = 0);
private:
    QHBoxLayout *mainLayout;
    QVBoxLayout *actionTable;
    QTableWidget* table;


    void aggiungiTestoEsempio();
};

#endif // TABELLATAB_H
