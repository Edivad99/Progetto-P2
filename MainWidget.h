#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget() = default;

private:

    QVBoxLayout *mainLayout;


    void addMenuButtons();
    void setApplicationStyle();
};
#endif // WIDGET_H
