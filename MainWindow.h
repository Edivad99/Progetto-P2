#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QFileDialog>
#include <QDir>
#include "view/hometab.h"
#include "view/tabellatab.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:

    QVBoxLayout *mainLayout;
    QTabWidget *tabWidget;

    TabellaModel *tabellaModel;

    void addMenuButtons();
    void setApplicationStyle();

private slots:
    void apriClicked();
    void salvaClicked();
    void salvaConNomeClicked();
};
#endif // MAINWINDOW_H
