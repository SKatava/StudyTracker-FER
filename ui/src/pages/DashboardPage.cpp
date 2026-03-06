#include <pages/DashboardPage.h>
#include <core/services/AppContext.h>

DashboardPage::DashboardPage(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void DashboardPage::setupUI() {
    activeSubjects          = new QWidget();
    activeSubjectsHeader    = new Header(nullptr, "Active Subjects");
    addSubjectBtn           = new QPushButton("+ Add Subject");
    rootLayout              = new QVBoxLayout(this);
    activeSubjectsLayout    = new FlowLayout(activeSubjects, 0, 10, 10);

    rootLayout->setContentsMargins(10, 10, 10, 10);
    rootLayout->addWidget(activeSubjectsHeader);
    rootLayout->addWidget(activeSubjects);
    rootLayout->addStretch();

    auto subjects = AppContext::Instance().Subjects().GetSubjects();

    for(auto& item : subjects) {
        SubjectCard* card = new SubjectCard(nullptr, item);
        activeSubjectsLayout->addWidget(card);
    }
    
    addSubjectBtn->setFixedSize(280, 200);
    addSubjectBtn->setObjectName("addSubjectBtn");

    activeSubjectsLayout->addWidget(addSubjectBtn);
}

void DashboardPage::setupConnections() {

}
