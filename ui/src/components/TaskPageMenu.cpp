#include <components/TaskPageMenu.h>

#include <Icons.h>

TaskPageMenu::TaskPageMenu(QWidget* parent) : QFrame(parent) {
    setupUI();
    setupConnections();
}

void TaskPageMenu::setupUI() {
    layout              = new QHBoxLayout(this);
    allBtn              = new CustomBtn(Icons::Task, "All");
    todoBtn             = new CustomBtn(Icons::CheckNot, "To-Do");
    doneBtn             = new CustomBtn(Icons::CheckDone, "Done");
    
    setFixedSize(600, 60);
    setObjectName("menu");

    setActiveButton(allBtn);


    allBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    todoBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    doneBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    allBtn->setObjectName("menuBtn");
    todoBtn->setObjectName("menuBtn");
    doneBtn->setObjectName("menuBtn");

    layout->addWidget(allBtn);
    layout->addWidget(todoBtn);
    layout->addWidget(doneBtn);
}

void TaskPageMenu::setupConnections() {
    connect(allBtn, &QPushButton::clicked, this, [this]() {
        setActiveButton(allBtn);
        emit navigateTo("All");
    });
    connect(todoBtn, &QPushButton::clicked, this, [this]() {
        setActiveButton(todoBtn);
        emit navigateTo("To-Do");
    });
    connect(doneBtn, &QPushButton::clicked, this, [this]() {
        setActiveButton(doneBtn);
        emit navigateTo("Done");
    });
}

void TaskPageMenu::setActiveButton(CustomBtn* button) {
    if(activeBtn)
        activeBtn->SetActive(false); 
    activeBtn = button;
    if(activeBtn)
        activeBtn->SetActive(true);
}
