#ifndef SESSIONPAGEMENU_CLASS_H
#define SESSIONPAGEMENU_CLASS_H

#include <QFrame>
#include <QWidget>
#include <QPushButton>
#include <QLayout>

#include <components/CustomBtn.h>

class SessionPageMenu : public QFrame {
    Q_OBJECT

public:
    explicit SessionPageMenu(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();
    
    void setActiveButton(CustomBtn* button);

    QHBoxLayout* layout; 

    CustomBtn* newSessionBtn;
    CustomBtn* historyBtn;
    CustomBtn* lectureCheckInBtn;
    CustomBtn* activeBtn {nullptr};

};

#endif
