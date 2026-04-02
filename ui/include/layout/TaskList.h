#ifndef TASKLIST_CLASS_H
#define TASKLIST_CLASS_H

#include <vector>

#include <QWidget>
#include <QFrame>
#include <QLayout>
#include <QScrollArea>

#include <components/TaskCard.h>
#include <components/TaskListMenu.h>

class TaskList : public QWidget {
    Q_OBJECT

public:
    explicit TaskList(QWidget* parent = nullptr);
private:
    void setupUI();
    void setupConnections();

    QVBoxLayout* layout;
    QScrollArea* scroll;

    QWidget* container;
    QVBoxLayout* containerLayout;
    
    TaskListMenu* menu;

    std::vector<TaskCard*> cards;  

private slots:
    void onFilterApplied(QString name);
    void onOpenTaskForm();
};

#endif
