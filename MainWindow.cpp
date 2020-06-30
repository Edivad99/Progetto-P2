#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
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
    analizzaStipendio->setShortcut(Qt::CTRL | Qt::Key_A);
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
    guide->setShortcut(Qt::Key_F1);
    QAction* info = new QAction("Info", help);
    connect(guide, SIGNAL(triggered()), this, SLOT(apriGuida()));
    connect(info, SIGNAL(triggered()), this, SLOT(apriInfo()));
    help->addAction(guide);
    help->addAction(info);

    menuBar->addMenu(file);
    menuBar->addMenu(help);

    mainLayout->addWidget(menuBar);
}

void MainWindow::setApplicationStyle()
{
    setWindowState(Qt::WindowMaximized);
    setMinimumSize(QSize(650,650));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
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
        try
        {
            tabellaModel->readFromFile(documentoLetto);
            tabellaTab->updateTabella();
        }
        catch (std::exception *e)
        {
            tabellaModel->eliminaLavoratori();
            tabellaModel->salvato();
            QMessageBox::warning(this, "Impossibile leggere il file", e->what());
        }

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
        QString defaultName = QString("BustePaga").append(GeneralUtil::capitalizeFirstLetter(QDate::currentDate().toString("MMMMyyyy"))).append(".csv");

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
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Seleziona uno o più file da importare", QDir::homePath(), filter);

    lista<QStringList*> *csvData = new lista<QStringList*>();

    for(int i = 0; i < fileNames.size(); i++)
    {
        if(!fileNames.at(i).isEmpty())
        {
            QFile *fileAperto = new QFile(fileNames.at(i));
            if(!fileAperto->open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QMessageBox::information(this, "Impossibile aprire il file", fileAperto->errorString());
                delete csvData;
                return;
            }

            QStringList *wordlist = new QStringList();
            QTextStream in(fileAperto);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                wordlist->push_back(line);
            }

            fileAperto->close();
            csvData->insertBack(wordlist);
        }
    }
    try
    {
        if(!csvData->isEmpty()) {
            gw=new AnalisiStipendio(csvData);
            gw->show();
        }
    }
    catch(std::exception)
    {
        QMessageBox::warning(this, "Impossibile leggere il file", "Il contenuto del file non rispetta i requisiti!");
    }
}

void MainWindow::apriGuida() const {
    QMessageBox box(QMessageBox::Information, "Guida",
                    QString("Per usare l'applicazione con dei dati già inseriti si consiglia di aprire il file <u><i>dipendenti.xml</i></u> in <u>File>Apri</u><br>"
                            "Per vedere lo storico degli stipendi si consiglia di aprire i file con nome <u><i>BustePagaXY.csv</i></u> in <u>File>Analizza stipendio</u>"), QMessageBox::Ok);
    box.exec();
}

void MainWindow::apriInfo() const
{
    QMessageBox box(QMessageBox::Information, "Informazioni applicazione",
                    QString("Software realizzato da:"
                            "<ul><li>Davide Albiero</li> <li>Cristiano Panighel</li> <li>Matteo Vignaga</li></ul>"
                            "Progetto di Programmazione a Oggetti, UniPD 2020"), QMessageBox::Ok);
    box.exec();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (tabellaModel->deviSalvare())
    {
        checkUnsavedData();
    }
    event->accept();
}

