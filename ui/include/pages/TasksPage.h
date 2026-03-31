#ifndef TASKSPAGE_CLASS_H
#define TASKSPAGE_CLASS_H

#include <QWidget>
#include <QLayout>
#include <QStackedWidget>

#include <components/TaskPageMenu.h>
#include <layout/TaskList.h>

class TasksPage : public QWidget {
    Q_OBJECT
    
public:
    explicit TasksPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    QVBoxLayout* layout;
    TaskPageMenu* menu;
    TaskList* list;
    QStackedWidget* pages;
    
};

#endif
