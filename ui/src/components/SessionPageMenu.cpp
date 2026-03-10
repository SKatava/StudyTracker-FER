#include <components/SessionPageMenu.h>

#include <Icons.h>

SessionPageMenu::SessionPageMenu(QWidget* parent) : QFrame(parent) {
    setupUI();
    setupConnections();
}

void SessionPageMenu::setupUI() {
    layout              = new QHBoxLayout(this);
    newSessionBtn       = new CustomBtn(Icons::Timer, "New Session");
    historyBtn          = new CustomBtn(Icons::Clock, "History");
    lectureCheckInBtn   = new CustomBtn(Icons::CheckIn, "Lecture Check In");
    
    setFixedSize(600, 60);
    setObjectName("menu");

    setActiveButton(newSessionBtn);


    newSessionBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    historyBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    lectureCheckInBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    newSessionBtn->setObjectName("menuBtn");
    historyBtn->setObjectName("menuBtn");
    lectureCheckInBtn->setObjectName("menuBtn");

    layout->addWidget(newSessionBtn);
    layout->addWidget(historyBtn);
    layout->addWidget(lectureCheckInBtn);
}

void SessionPageMenu::setupConnections() {
    connect(newSessionBtn, &QPushButton::clicked, this, [this]() {
        setActiveButton(newSessionBtn);
    });
    connect(historyBtn, &QPushButton::clicked, this, [this]() {
        setActiveButton(historyBtn);
    });
    connect(lectureCheckInBtn, &QPushButton::clicked, this, [this]() {
        setActiveButton(lectureCheckInBtn);
    });
}

void SessionPageMenu::setActiveButton(CustomBtn* button) {
    if(activeBtn)
        activeBtn->SetActive(false); 
    activeBtn = button;
    if(activeBtn)
        activeBtn->SetActive(true);
}
