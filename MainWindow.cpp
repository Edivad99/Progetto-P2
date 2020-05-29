#include "MainWindow.h"

#include <model/tabellamodel.h>

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    tabWidget = new QTabWidget();
    //La barra dei menu va per prima
    addMenuButtons();

    tabellaModel = new TabellaModel();

    tabWidget->addTab(new HomeTab(), "Home");
    tabWidget->addTab(new TabellaTab(tabellaModel), "Tabella");

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

    //Actions
    connect(imp, SIGNAL(triggered()), this, SLOT(importaClicked()));
    connect(exp, SIGNAL(triggered()), this, SLOT(esportaClicked()));
    connect(chiudi, SIGNAL(triggered()), this, SLOT(close()));

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

void MainWindow::importaClicked()
{
    QString filter = "XML (*.xml) ;; CSV (*.csv)";
    QString fileName = QFileDialog::getOpenFileName(this, "Seleziona un file da importare", QDir::homePath(), filter);
    QFile *file = new QFile(fileName);

    tabellaModel->readFromFile(file);
}

void MainWindow::esportaClicked()
{

}

