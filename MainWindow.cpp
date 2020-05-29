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
    QAction* apri = new QAction("Apri", file);
    QAction* salva = new QAction("Salva", file);
    QAction* salvaConNome = new QAction("Salva con nome", file);
    QAction* chiudi = new QAction("Chiudi", file);

    //Actions
    connect(apri, SIGNAL(triggered()), this, SLOT(apriClicked()));
    connect(salva, SIGNAL(triggered()), this, SLOT(salvaClicked()));
    connect(salvaConNome, SIGNAL(triggered()), this, SLOT(salvaConNomeClicked()));
    connect(chiudi, SIGNAL(triggered()), this, SLOT(close()));

    file->addAction(apri);
    file->addAction(salva);
    file->addAction(salvaConNome);
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

void MainWindow::apriClicked()
{
    QString filter = "XML File (*.xml) ;; CSV File (*.csv)";
    QString fileName = QFileDialog::getOpenFileName(this, "Seleziona un file da importare", QDir::homePath(), filter);

    if(!fileName.isEmpty())
    {
        QFile *file = new QFile(fileName);
        if(!file->open(QIODevice::ReadWrite))
        {
            QMessageBox::information(this, "Impossibile aprire il file", file->errorString());
            return;
        }
        tabellaModel->readFromFile(file);
    }
}

void MainWindow::salvaClicked()
{
    if (tabellaModel->currentFile == nullptr)
    {
        MainWindow::salvaConNomeClicked();
    }
    else
    {
        tabellaModel->saveFile();
    }
}

void MainWindow::salvaConNomeClicked()
{
    QString filter = "XML File (*.xml) ;; CSV File (*.csv)";
    QString fileName = QFileDialog::getSaveFileName(this, "Salva con nome", QDir::homePath(), filter);

    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QMessageBox::information(this, tr("Impossibile salvare nel file"), file.errorString());
            return;
        }
        if(fileName.endsWith(".xml"))
        {
            QDomDocument dipendenti = tabellaModel->saveFile();
            QTextStream stream(&file);
            stream << dipendenti.toString();
            file.close();
            //Se il salvataggio va a buon fine mi salvo file così posso usaro nel salva
            tabellaModel->currentFile = &file;
        }
    }
}

