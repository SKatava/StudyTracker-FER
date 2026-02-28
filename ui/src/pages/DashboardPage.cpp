#include <pages/DashboardPage.h>
#include <QLabel>

#include <components/SubjectCard.h>
#include <components/Header.h>
#include <layout/FlowLayout.h>

DashboardPage::DashboardPage(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void DashboardPage::setupUI() {
    QVBoxLayout* rootLayout = new QVBoxLayout(this);

    Header* activeSubjectsHeader = new Header(nullptr, "Active Subjects");
    QWidget* activeSubjects = new QWidget();

    rootLayout->setContentsMargins(10, 10, 10, 10);
    rootLayout->addWidget(activeSubjectsHeader);
    rootLayout->addWidget(activeSubjects);
    rootLayout->addStretch();

    FlowLayout* layout = new FlowLayout(activeSubjects, 0, 10, 10);
    
    for(int i = 0; i < 6; i++) {
        SubjectCard* card = new SubjectCard();
        layout->addWidget(card);
    }
}

void DashboardPage::setupConnections() {

}
