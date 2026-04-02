#ifndef TASKLISTMENU_CLASS_H
#define TASKLISTMENU_CLASS_H

#include <QWidget>
#include <QLayout>
#include <QComboBox>

#include <components/CustomBtn.h>

class TaskListMenu : public QWidget {
    Q_OBJECT

public:
    explicit TaskListMenu(QWidget* parent = nullptr); 

private:
    void setupUI();
    void setupConnections();

    QHBoxLayout* layout;
    CustomBtn* newLogBtn;
    QComboBox* subjectFilter;

signals:
    void filterApplied(QString name);
    void openTaskForm();

};

#endif
