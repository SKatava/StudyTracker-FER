#include <pages/DashboardPage.h>
#include <layout/AddSubjectForm.h>
#include <core/services/AppContext.h>
#include <events/SubjectEvent.h>

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
    connect(addSubjectBtn, &QPushButton::clicked, this, &DashboardPage::onAddButtonClicked);
    connect(&SubjectEvents::instance(), &SubjectEvents::subjectCreated, this, &DashboardPage::onSubjectCreated);

}

void DashboardPage::refreshSubjects() {
    QLayoutItem* item;
    while ((item = activeSubjectsLayout->takeAt(0)) != nullptr)
    {
        QWidget* w = item->widget();
        if (w && w != addSubjectBtn)
            delete w;
        delete item;
    } 

    auto subjects = AppContext::Instance().Subjects().GetSubjects();

    for(auto& item : subjects) {
        SubjectCard* card = new SubjectCard(nullptr, item);
        activeSubjectsLayout->addWidget(card);
    }

    activeSubjectsLayout->addWidget(addSubjectBtn);

}

void DashboardPage::onAddButtonClicked() {

    AddSubjectForm* form = new AddSubjectForm(this);

    form->move(
        (width() - form->width()) / 2,
        (height() - form->height()) / 2
    );

    form->show();
    form->raise();
}

void DashboardPage::onSubjectCreated(const Subject& subject) {
    auto& service = AppContext::Instance().Subjects();

    int id = service.CreateSubject(subject);
    
    auto subjects = service.GetSubjects();
    
    refreshSubjects();
}
