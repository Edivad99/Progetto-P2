#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    tabWidget = new QTabWidget();
    //La barra dei menu va per prima
    addMenuButtons();
    tabWidget->setMovable(true);
    tabWidget->addTab(new HomeTab(), "Home");
    tabWidget->addTab(new TabellaTab(), "Tabella");

    mainLayout->addWidget(tabWidget);
    setApplicationStyle();
    setLayout(mainLayout);
}

void MainWindow::addMenuButtons()
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

void MainWindow::setApplicationStyle()
{
    setWindowState(Qt::WindowMaximized);
    setMinimumSize(QSize(400,400));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //TODO: Da rimuovere e mettere nel file css appena possibile
    mainLayout->setMargin(0);
}

