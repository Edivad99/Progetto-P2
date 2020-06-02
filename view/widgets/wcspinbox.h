#ifndef WCSPINBOX_H
#define WCSPINBOX_H

#include <QFrame>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QLabel>


class WCSpinBox : public QFrame
{
    Q_OBJECT
public:
    WCSpinBox(QString text, int min, int max, int defaultValue, QWidget *parent =0);

    int getValue() const;
    void setValue(int newValue);
private:
    int _min, _max;
    QString _text;
    QSpinBox *livello;


    void initUI();
};

#endif // WCSPINBOX_H
