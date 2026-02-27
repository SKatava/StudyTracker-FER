#ifndef MAINWINDOW_CLASS_H
#define MAINWINDOW_CLASS_H

//QT headers
#include <QMainWindow>
#include <QStackedWidget>
#include <QLayout>

//Personal header
#include <layout/Titlebar.h>
#include <layout/Sidebar.h>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    QWidget* central;
    QWidget* body;

    QVBoxLayout* rootLayout;
    QHBoxLayout* bodyLayout;

    QStackedWidget* pages;

    Titlebar* titlebar;
    Sidebar* sidebar;
};

#endif
