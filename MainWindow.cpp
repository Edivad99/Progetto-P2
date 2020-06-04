#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    //La barra dei menu va per prima
    addMenuButtons();
    fileAperto = nullptr;

    tabellaModel = new TabellaModel();
    tabellaTab = new Tabella(tabellaModel);

    mainLayout->addWidget(tabellaTab);
    setApplicationStyle();
    setLayout(mainLayout);
}

void MainWindow::addMenuButtons()
{
    QMenuBar* menuBar = new QMenuBar(this);

    QMenu* file = new QMenu("File", menuBar);
    QAction* apri = new QAction("Apri", file);
    apri->setShortcut(Qt::CTRL | Qt::Key_O);
    QAction* salva = new QAction("Salva", file);
    salva->setShortcut(Qt::CTRL | Qt::Key_S);
    QAction* salvaConNome = new QAction("Salva con nome", file);
    salvaConNome->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_S);
    QAction* esportaStipendio = new QAction("Esporta stipendi", file);
    esportaStipendio->setShortcut(Qt::CTRL | Qt::Key_E);
    QAction* analizzaStipendio = new QAction("Analizza stipendio", file);
    QAction* chiudi = new QAction("Chiudi", file);

    //Actions
    connect(apri, SIGNAL(triggered()), this, SLOT(apriClicked()));
    connect(salva, SIGNAL(triggered()), this, SLOT(salvaClicked()));
    connect(salvaConNome, SIGNAL(triggered()), this, SLOT(salvaConNomeClicked()));
    connect(esportaStipendio, SIGNAL(triggered()), this, SLOT(esportaStipendio()));
    connect(analizzaStipendio, SIGNAL(triggered()), this, SLOT(analizzaStipendio()));
    connect(chiudi, SIGNAL(triggered()), this, SLOT(close()));

    file->addAction(apri);
    file->addAction(salva);
    file->addAction(salvaConNome);
    file->addAction(esportaStipendio);
    file->addAction(analizzaStipendio);
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
    setMinimumSize(QSize(650,650));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //TODO: Da rimuovere e mettere nel file css appena possibile
    mainLayout->setMargin(0);
}

void MainWindow::checkUnsavedData()
{
    if(tabellaModel->deviSalvare())
    {
        QMessageBox::StandardButton response= QMessageBox::question(this, "Salvare i dati", "Vuoi salvare i dati modificati prima di continuare?", QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
        if(response == QMessageBox::Yes)
            salvaClicked();
    }
}

void MainWindow::apriClicked()
{
    checkUnsavedData();

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
            tabellaModel->salvato();
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
        QDomDocument dipendenti = tabellaModel->saveFile();
        QTextStream stream(fileAperto);
        stream << dipendenti.toString();
        fileAperto->close();
        tabellaModel->salvato();
    }
}

void MainWindow::esportaStipendio()
{
    bool ok;
    float bonus = QInputDialog::getDouble(this, "Bonus stipendio", "Imposta un bonus stipendio", 0, 0, 100000, 2, &ok);

    if(ok)
    {
        QString defaultName = QString("BustePaga").append(QDate::currentDate().toString("MMMMyyyy")).append(".csv");

        QString filter = "CSV File (*.csv)";
        QString fileName = QFileDialog::getSaveFileName(this, "Salva con nome", QDir::homePath() + "/" + defaultName, filter);

        if(!fileName.isEmpty())
        {
            QFile *fileAperto = new QFile(fileName);
            if(!fileAperto->open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QMessageBox::information(this, "Impossibile salvare nel file", fileAperto->errorString());
                return;
            }
            QTextStream out(fileAperto);
            out << tabellaModel->generaStipendio(bonus);
            fileAperto->close();
        }
    }

}

void MainWindow::analizzaStipendio()
{
    QString filter = "CSV File (*.csv)";
    QString fileName = QFileDialog::getOpenFileName(this, "Seleziona un file da importare", QDir::homePath(), filter);

    if(!fileName.isEmpty())
    {
        QFile *fileAperto = new QFile(fileName);
        if(!fileAperto->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this, "Impossibile aprire il file", fileAperto->errorString());
            return;
        }
        fileAperto->close();
        gw=new GraphWindow();
        gw->show();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (tabellaModel->deviSalvare())
    {
        checkUnsavedData();
    }
    event->accept();
}

