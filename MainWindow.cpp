#include "MainWindow.h"

#include <model/tabellamodel.h>

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    tabWidget = new QTabWidget();
    //La barra dei menu va per prima
    addMenuButtons();
    fileAperto = nullptr;

    tabellaModel = new TabellaModel();

    homeTab = new HomeTab();
    tabellaTab = new TabellaTab(tabellaModel);

    tabWidget->addTab(homeTab, "Home");
    tabWidget->addTab(tabellaTab, "Tabella");

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
    QString filter = "XML File (*.xml)";
    QString fileName = QFileDialog::getOpenFileName(this, "Seleziona un file da importare", QDir::homePath(), filter);

    if(!fileName.isEmpty())
    {
        fileAperto = new QFile(fileName);
        QDomDocument documentoLetto("Documento");
        if(!fileAperto->open(QIODevice::ReadWrite | QIODevice::Text) || !documentoLetto.setContent(fileAperto))
        {
            QMessageBox::information(this, "Impossibile aprire il file", fileAperto->errorString());
            return;
        }
        fileAperto->close();
        tabellaModel->readFromFile(documentoLetto);
        tabellaTab->updateTabella();
    }
}

void MainWindow::salvaClicked()
{
    if (fileAperto != nullptr)
    {
        if(!fileAperto->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QMessageBox::information(this, "Impossibile salvare nel file", fileAperto->errorString());
            return;
        }
        if(fileAperto->fileName().endsWith(".xml"))
        {
            QDomDocument dipendenti = tabellaModel->saveFile();
            QTextStream stream(fileAperto);
            stream << dipendenti.toString();
            fileAperto->close();
        }
    }
    else
    {
        MainWindow::salvaConNomeClicked();
    }
}

void MainWindow::salvaConNomeClicked()
{
    QString filter = "XML File (*.xml)";
    QString fileName = QFileDialog::getSaveFileName(this, "Salva con nome", QDir::homePath(), filter);

    if(!fileName.isEmpty())
    {
        delete fileAperto;
        fileAperto = new QFile(fileName);
        if(!fileAperto->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QMessageBox::information(this, "Impossibile salvare nel file", fileAperto->errorString());
            return;
        }
        if(fileName.endsWith(".xml"))
        {
            QDomDocument dipendenti = tabellaModel->saveFile();
            QTextStream stream(fileAperto);
            stream << dipendenti.toString();
            fileAperto->close();
        }
    }
}

