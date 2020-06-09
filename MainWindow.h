#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QCloseEvent>
#include <QInputDialog>
#include "view/tabella.h"
#include "view/analisistipendio.h"
#include <model/tabellamodel.h>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:

    QVBoxLayout *mainLayout;

    QFile* fileAperto;

    Tabella* tabellaTab;
    TabellaModel *tabellaModel;
    AnalisiStipendio* gw;

    void addMenuButtons();
    void setApplicationStyle();
    void checkUnsavedData();
    void closeEvent(QCloseEvent *event);

private slots:
    void apriClicked();
    void salvaClicked();
    void salvaConNomeClicked();
    void esportaStipendio();
    void analizzaStipendio();
};
#endif // MAINWINDOW_H
