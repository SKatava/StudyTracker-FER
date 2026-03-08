#include <pages/DashboardPage.h>
#include <layout/AddSubjectForm.h>
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
    connect(addSubjectBtn, &QPushButton::clicked, this, &DashboardPage::onAddButtonClicked);
}

void DashboardPage::onAddButtonClicked() {

    AddSubjectForm* form = new AddSubjectForm(this);

    form->move(
        (width() - form->width()) / 2,
        (height() - form->height()) / 2
    );

    form->show();
    form->raise();

    connect(form, &AddSubjectForm::subjectCreated,
            this, &DashboardPage::onSubjectCreated);
}

void DashboardPage::onSubjectCreated(QString name)
{
    auto& service = AppContext::Instance().Subjects();
    Subject subject;
    subject.SetName(name.toStdString());

    service.CreateSubject(subject);

    auto subjects = service.GetSubjects();
    auto& item = subjects.back();

    SubjectCard* card = new SubjectCard(nullptr, item);
    activeSubjectsLayout->removeWidget(addSubjectBtn);
    activeSubjectsLayout->addWidget(card);
    activeSubjectsLayout->addWidget(addSubjectBtn);
}
