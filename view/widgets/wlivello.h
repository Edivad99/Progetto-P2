#ifndef WLIVELLO_H
#define WLIVELLO_H

#include <QFrame>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QLabel>


class WLivello : public QFrame
{
    Q_OBJECT
public:
    WLivello(int min, int max, QWidget *parent =0);

    int getLivello() const;
private:
    int _min, _max;
    QSpinBox *livello;


    void initUI();
};

#endif // WLIVELLO_H
