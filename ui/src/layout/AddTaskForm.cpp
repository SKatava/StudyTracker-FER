#include <layout/AddTaskForm.h>

#include <events/DomainEvents.h>



AddTaskForm::AddTaskForm(QWidget* parent) : QFrame(parent) {
    setupUI();
    setupConnections();
}

void AddTaskForm::setupUI() {
    layout = new QVBoxLayout(this);
    buttonLayout = new QHBoxLayout();
    inputLayout = new QHBoxLayout();
    labelLayout = new QHBoxLayout();
    cancelBtn = new QPushButton("Cancel");
    confirmBtn = new QPushButton("Confirm");
    subjectList = new QComboBox();
    startDateInput = new DatePickerEdit();
    endDateInput = new DatePickerEdit();
    descInput = new QTextEdit();

    this->setObjectName("addSessionForm");
    this->setFixedSize(500, 450);

    subjectList->setFixedHeight(40);
    descInput->setFixedHeight(60);
    startDateInput->setFixedHeight(40);
    endDateInput->setFixedHeight(40);

    cancelBtn->setFixedSize(150, 50);
    confirmBtn->setFixedSize(150, 50);

    auto subjects = AppContext::Instance().Subjects().GetSubjects();

    for(auto& item : subjects) {
        subjectList->addItem(item.GetName().c_str());
    }

    buttonLayout->addStretch();
    buttonLayout->addWidget(cancelBtn);
    buttonLayout->addWidget(confirmBtn);
    
    QLabel* label = new QLabel("Start date");
    label->setObjectName("secondaryText");
    labelLayout->addWidget(label);

    label = new QLabel("End date");
    label->setObjectName("secondaryText");
    labelLayout->addWidget(label);
    labelLayout->setSpacing(20);

    inputLayout->addWidget(startDateInput);
    inputLayout->addWidget(endDateInput);
    inputLayout->setSpacing(10);

    label = new QLabel("Add New Task");
    label->setObjectName("title");
    layout->addWidget(label);
    layout->addSpacing(5);

    label = new QLabel("Enter the task details below.");
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

void AddTaskForm::setupConnections() {
    connect(confirmBtn, &QPushButton::clicked, this, [this]() {
        Task task = getTask();
        DomainEvents::instance().emitTaskCreated(task);
        close();
    });

    connect(cancelBtn, &QPushButton::clicked, this, &QWidget::close);
}

Task AddTaskForm::getTask() const {
    int subjectIndex = subjectList->currentIndex();
    auto subjects = AppContext::Instance().Subjects().GetSubjects();
    auto& subject = subjects[subjectIndex];

    std::string subjectName = subject.GetName();
    std::string desc = descInput->toPlainText().toStdString();
    int subjectID = subject.GetId();
    std::string startDate = startDateInput->date().toString("dd-MM-yyyy").toStdString();
    std::string endDate = endDateInput->date().toString("dd-MM-yyyy").toStdString();

    Task task {.subjectId = subjectID, .description = desc, .date_start = startDate, .date_end = endDate};

    AppContext::Instance().Tasks().CreateTask(task);
    return task;
}
