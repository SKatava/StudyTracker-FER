#include <layout/AddSessionForm.h>

#include <events/DomainEvents.h>



AddSessionForm::AddSessionForm(QWidget* parent) : QFrame(parent) {
    setupUI();
    setupConnections();
}

void AddSessionForm::setupUI() {
    layout = new QVBoxLayout(this);
    buttonLayout = new QHBoxLayout();
    inputLayout = new QHBoxLayout();
    labelLayout = new QHBoxLayout();
    cancelBtn = new QPushButton("Cancel");
    confirmBtn = new QPushButton("Confirm");
    subjectList = new QComboBox();
    dateInput = new DatePickerEdit();
    descInput = new QTextEdit();
    minutesInput = new QLineEdit();

    this->setObjectName("addSessionForm");
    this->setFixedSize(500, 450);

    subjectList->setFixedHeight(40);
    descInput->setFixedHeight(60);
    minutesInput->setFixedHeight(40);
    dateInput->setFixedHeight(40);

    cancelBtn->setFixedSize(150, 50);
    confirmBtn->setFixedSize(150, 50);

    auto subjects = AppContext::Instance().Subjects().GetSubjects();

    for(auto& item : subjects) {
        subjectList->addItem(item.GetName().c_str());
    }

    buttonLayout->addStretch();
    buttonLayout->addWidget(cancelBtn);
    buttonLayout->addWidget(confirmBtn);
    
    QLabel* label = new QLabel("Duration");
    label->setObjectName("secondaryText");
    labelLayout->addWidget(label);

    label = new QLabel("Date");
    label->setObjectName("secondaryText");
    labelLayout->addWidget(label);
    labelLayout->setSpacing(20);

    inputLayout->addWidget(minutesInput);
    inputLayout->addWidget(dateInput);
    inputLayout->setSpacing(10);

    label = new QLabel("Add New Session");
    label->setObjectName("title");
    layout->addWidget(label);
    layout->addSpacing(5);

    label = new QLabel("Enter the session details below.");
    label->setObjectName("secondaryText");
    layout->addWidget(label);
    layout->addSpacing(10);

    label = new QLabel("Subject");
    label->setObjectName("secondaryText");
    layout->addWidget(label);
    layout->addWidget(subjectList);
    layout->addSpacing(10);

    label = new QLabel("Description");
    label->setObjectName("secondaryText");
    layout->addWidget(label);
    layout->addWidget(descInput);
    layout->addSpacing(10);
    
    layout->addLayout(labelLayout);
    layout->addLayout(inputLayout);

    layout->addStretch();

    layout->addLayout(buttonLayout);
}

void AddSessionForm::setupConnections() {
    connect(confirmBtn, &QPushButton::clicked, this, [this]() {
        Session session = getSession();
        emit DomainEvents::instance().sessionCreated(session);
        close();
    });

    connect(cancelBtn, &QPushButton::clicked, this, &QWidget::close);
}

Session AddSessionForm::getSession() const {
    int subjectIndex = subjectList->currentIndex();
    auto subjects = AppContext::Instance().Subjects().GetSubjects();
    auto& subject = subjects[subjectIndex];

    std::string subjectName = subject.GetName();
    std::string desc = descInput->toPlainText().toStdString();
    int subjectID = subject.GetId();
    int minutes = minutesInput->text().toInt();
    std::string date = dateInput->date().toString("dd-MM-yyyy").toStdString();

    Session session(-1, subjectID, minutes, desc, date);

    subject.SetInvestedStudyMinutes(subject.GetInvestedStudyMinutes() + minutes);
    AppContext::Instance().Subjects().UpdateSubject(subject);
    AppContext::Instance().Sessions().CreateSession(session);
    return session;
}
