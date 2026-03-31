#ifndef TASKCARD_CLASS_H
#define TASKCARD_CLASS_H

#include <QFrame>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QCheckBox>

#include <core/domain/Task.h>

class TaskCard : public QFrame {
    Q_OBJECT

    public:
        TaskCard(QWidget* parent, const Task& task);
    private:
        void setupUI(const Task& task);
        void setupConnections();
        
        bool done {0};

        QHBoxLayout* layout;
        QVBoxLayout* infoLayout;
        QCheckBox* checkBox;
        QLabel* subject;
        QLabel* description;
        QLabel* minutes;
        QLabel* start;
        QLabel* end;
        QLabel* finish;
        QLabel* icon;
        
        
        
};

#endif

