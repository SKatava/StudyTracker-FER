#include <layout/AddSubjectForm.h>

#include <components/DatePickerEdit.h>

AddSubjectForm::AddSubjectForm(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
    setupConnections();
}

void AddSubjectForm::setupUI() {
    layout              = new QVBoxLayout(this);
    buttonLayout        = new QHBoxLayout();
    inputLayout         = new QHBoxLayout();
    labelLayout         = new QHBoxLayout();
    nameInput           = new QLineEdit();
    ECTSInput           = new QLineEdit();
    LectureHoursInput   = new QLineEdit();
    dateInput           = new DatePickerEdit(this);
    addBtn              = new QPushButton("Add Subject");
    cancelBtn           = new QPushButton("Cancel");
    title               = new QLabel("Add New Subject");
    description         = new QLabel("Enter the subject details below.");
    nameLabel           = new QLabel("NAME");
    ECTSLabel           = new QLabel("ECTS");
    lectureHoursLabel   = new QLabel("LECTURE HOURS");
    dateLabel           = new QLabel("DATE");
    
    setAttribute(Qt::WA_StyledBackground, true);
    this->setObjectName("addSubjectForm");
    this->setFixedSize(500, 450);

    title->setObjectName("title");
    description->setObjectName("secondaryText");
    nameLabel->setObjectName("secondaryText");
    ECTSLabel->setObjectName("secondaryText");
    lectureHoursLabel->setObjectName("secondaryText");
    dateLabel->setObjectName("secondaryText");

    nameInput->setFixedHeight(40);
    nameInput->setPlaceholderText("e.g. Mathematics");

    ECTSInput->setFixedHeight(40);
    ECTSInput->setPlaceholderText("6");
    
    LectureHoursInput->setFixedHeight(40);
    LectureHoursInput->setPlaceholderText("60");

    inputLayout->setSpacing(20);
    labelLayout->setSpacing(20);

    layout->addWidget(title);
    layout->addSpacing(10);
    layout->addWidget(description);
    layout->addSpacing(20);

    layout->addWidget(nameLabel);
    layout->addWidget(nameInput);
    layout->addSpacing(20);

    labelLayout->addWidget(ECTSLabel, 1);
    labelLayout->addWidget(lectureHoursLabel, 1);

    inputLayout->addWidget(ECTSInput);
    inputLayout->addWidget(LectureHoursInput);

    layout->addLayout(labelLayout);
    layout->addLayout(inputLayout);


    layout->addSpacing(20);
    layout->addWidget(dateLabel);
    layout->addWidget(dateInput); 
    layout->addSpacing(20);

    layout->addStretch();

    addBtn->setFixedSize(150, 50);
    cancelBtn->setFixedSize(150, 50);

    buttonLayout->addStretch();
    buttonLayout->addWidget(cancelBtn);
    buttonLayout->addWidget(addBtn);

    layout->addLayout(buttonLayout);
}

void AddSubjectForm::setupConnections() {
    connect(addBtn, &QPushButton::clicked, this, [this]() {
        emit subjectCreated(nameInput->text());
        close();
    });

    connect(cancelBtn, &QPushButton::clicked, this, &QWidget::close);
}

Subject AddSubjectForm::getSubject() const {
    
}
