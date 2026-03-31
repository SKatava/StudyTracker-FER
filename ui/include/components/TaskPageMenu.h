#ifndef TASKPAGEMENU_CLASS_H
#define TASKPAGEMENU_CLASS_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLayout>
#include <QString>


#include <components/CustomBtn.h>

class TaskPageMenu : public QFrame {
    Q_OBJECT

public:
    explicit TaskPageMenu(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();
    
    void setActiveButton(CustomBtn* button);

    QHBoxLayout* layout; 

    CustomBtn* allBtn;
    CustomBtn* todoBtn;
    CustomBtn* doneBtn;
    CustomBtn* activeBtn {nullptr};

signals:
    void navigateTo(QString page);

};

#endif
