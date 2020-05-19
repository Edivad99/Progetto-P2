#ifndef TABELLATAB_H
#define TABELLATAB_H

#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class TabellaTab : public QWidget
{
    Q_OBJECT
public:
    TabellaTab(QWidget *parent = 0);
private:
    QVBoxLayout *mainLayout;
};

#endif // TABELLATAB_H
