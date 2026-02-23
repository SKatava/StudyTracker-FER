#ifndef MAINWINDOW_CLASS_H
#define MAINWINDOW_CLASS_H

//QT headers
#include <QMainWindow>
#include <QStackedWidget>

//Personal header
#include <SidebarWidget.h>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    SidebarWidget* sidebar;
    QStackedWidget* pages;
};

#endif
