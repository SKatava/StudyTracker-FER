#ifndef TASKSPAGE_CLASS_H
#define TASKSPAGE_CLASS_H

#include <QWidget>
#include <QLayout>

class TasksPage : public QWidget {
    Q_OBJECT
    
public:
    explicit TasksPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    
};

#endif
