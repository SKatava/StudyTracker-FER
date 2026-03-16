#include <components/SessionCard.h>

#include <Icons.h>

#include <core/services/AppContext.h>

#include <iostream>

SessionCard::SessionCard(QWidget* parent, const Session& session) : QFrame(parent) {
    setupUI(session);
    setupConnections();
}
    
void SessionCard::setupUI(const Session& session) {
    layout = new QHBoxLayout(this);
    subjectName = new QLabel("lol");
    infoLayout = new QVBoxLayout();
    description = new QLabel(session.description.c_str());
    date = new QLabel(session.date.c_str());
    duration = new QLabel(( std::to_string(session.minutes) + 'm' ).c_str());
    icon = new QLabel(Icons::Timer);
    
    auto subjects = AppContext::Instance().Subjects().GetSubjects();
    for(auto& item : subjects) {
        if(session.subjectId == item.GetId()) {
            subjectName->setText(item.GetName().c_str());
        }
    }

    this->setFixedHeight(150);
    this->setObjectName("sessionCard");

    icon->setObjectName("sessionIcon");
    icon->setFixedSize(50, 50);
    icon->setAlignment(Qt::AlignCenter);

    subjectName->setObjectName("primaryText");
    duration->setObjectName("primaryText");
    description->setObjectName("secondaryText");
    date->setObjectName("secondaryText");

    description->setWordWrap(true);
    description->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        
    infoLayout->addWidget(subjectName);
    infoLayout->addWidget(description);
    infoLayout->addStretch();
    infoLayout->addWidget(date);

    layout->setSpacing(20);

    layout->addWidget(icon);
    layout->addLayout(infoLayout);
    layout->addStretch();
    layout->addWidget(duration);

}

void SessionCard::setupConnections() {
    
}

