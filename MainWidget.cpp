#include "MainWidget.h"



MainWidget::MainWidget(QWidget *parent): QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);

    addMenuButtons();

    setApplicationStyle();
    setLayout(mainLayout);
}

void MainWidget::addMenuButtons()
{
    QMenuBar* menuBar = new QMenuBar(this);

    QMenu* file = new QMenu("File", menuBar);
    QAction* imp = new QAction("Importa", file);
    QAction* exp = new QAction("Esporta", file);
    QAction* chiudi = new QAction("Chiudi", file);
    file->addAction(imp);
    file->addAction(exp);
    file->addAction(chiudi);

    QMenu* help = new QMenu("Help", menuBar);
    QAction* guide = new QAction("Guida", help);
    help->addAction(guide);

    menuBar->addMenu(file);
    menuBar->addMenu(help);

    mainLayout->addWidget(menuBar);
}

void MainWidget::setApplicationStyle()
{
    setMinimumSize(QSize(400,400));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //TODO: Da rimuovere e mettere nel file css appena possibile
    mainLayout->setMargin(0);
}

