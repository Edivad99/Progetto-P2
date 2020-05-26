#ifndef HOMETAB_H
#define HOMETAB_H

#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>


class HomeTab : public QWidget
{
    Q_OBJECT
public:
    HomeTab(QWidget *parent = 0);
private:
    QVBoxLayout *mainLayout;
};

#endif // HOMETAB_H
