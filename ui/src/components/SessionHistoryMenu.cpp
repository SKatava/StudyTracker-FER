#include <components/SessionHistoryMenu.h>

#include <core/services/AppContext.h>

#include <Icons.h>

SessionHistoryMenu::SessionHistoryMenu(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void SessionHistoryMenu::setupUI() {
    layout = new QHBoxLayout(this);
    newLogBtn = new CustomBtn(Icons::Add, "New Log");
    subjectFilter = new QComboBox();

    setContentsMargins(0, 0, 0, 0);

    subjectFilter->setFixedHeight(40);
    newLogBtn->setFixedHeight(40);
    newLogBtn->setObjectName("newLogBtn");

    subjectFilter->addItem("All");
    auto subjects = AppContext::Instance().Subjects().GetSubjects();
    for(auto& item : subjects) {
        subjectFilter->addItem(item.GetName().c_str());
    }

    layout->addWidget(subjectFilter, 4);
    layout->addWidget(newLogBtn, 2);
}

void SessionHistoryMenu::setupConnections() {
    connect(subjectFilter, &QComboBox::currentIndexChanged, this, [this]() {
        emit filterApplied(subjectFilter->currentText());
    });
    connect(newLogBtn, &QPushButton::clicked, this, [this]() {
        emit openSessionForm();
    });
}
