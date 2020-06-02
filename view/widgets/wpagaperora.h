#ifndef WPAGAPERORA_H
#define WPAGAPERORA_H

#include <QFrame>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QLabel>

class WPagaPerOra : public QFrame
{
public:
    WPagaPerOra(QWidget *parent =0);

    float getPaga() const;

private:
    QDoubleSpinBox *pagaPerOra;

    void initUI();
};

#endif // WPAGAPERORA_H
