#include <components/SubjectCard.h>
#include <QProgressBar>


SubjectCard::SubjectCard(QWidget* parent, const Subject& subject) : QFrame(parent) {
   setupUI(subject); 
}

void SubjectCard::setupUI(const Subject& subject) {
    std::string name = subject.GetName().c_str();
    std::string ECTS_ = std::to_string(subject.GetECTS()) + " ECTS";
    std::string completition = std::to_string(subject.GetInvestedMinutes() / (subject.GetNeededMinutes()+1) * 100) + " Complete";

    layout          = new QVBoxLayout(this);
    bottomLayout    = new QHBoxLayout();
    subjectTitle    = new QLabel(name.c_str());
    ECTS            = new QLabel(ECTS_.c_str());
    percentage      = new QLabel(completition.c_str());
    lecture         = new QLabel("Lecture");
    startSessionBtn = new QPushButton("Start Session");
    checkInBtn      = new QPushButton("Check In");
    hoursInput      = new QLineEdit();

    QProgressBar* progressBar = new QProgressBar();
    progressBar->setRange(0, 100);
    progressBar->setTextVisible(false);
    progressBar->setFixedHeight(10);

    this->setObjectName("subjectCard");
    this->setFixedSize(300, 200);
    subjectTitle->setObjectName("subjectCardTitle");
    ECTS->setObjectName("subjectCardContent");
    lecture->setObjectName("subjectCardContent");

    startSessionBtn->setObjectName("goodBtn");
    startSessionBtn->setFixedHeight(30);
    checkInBtn->setFixedHeight(30);
    hoursInput->setFixedHeight(30);
    hoursInput->setPlaceholderText("hr");

    bottomLayout->addWidget(lecture, 1);
    bottomLayout->addWidget(hoursInput, 1);
    bottomLayout->addWidget(checkInBtn, 2);

    layout->addWidget(subjectTitle);
    layout->addStretch();
    layout->addWidget(ECTS);
    layout->addWidget(progressBar);
    layout->addWidget(percentage);
    layout->addStretch();
    layout->addWidget(startSessionBtn);
    layout->addLayout(bottomLayout);
}

void SubjectCard::setupConnections() {
    
}
