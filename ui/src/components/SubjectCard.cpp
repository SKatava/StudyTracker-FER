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
    subjectTitle    = new QLabel(name.c_str());
    ECTS            = new QLabel(ECTS_.c_str());
    percentage      = new QLabel(completition.c_str());
    startSessionBtn = new QPushButton("Start Session");

    QProgressBar* progressBar = new QProgressBar();
    progressBar->setRange(0, 100);
    progressBar->setTextVisible(false);
    progressBar->setFixedHeight(10);

    this->setObjectName("subjectCard");
    this->setFixedSize(300, 200);
    subjectTitle->setObjectName("subjectCardTitle");
    ECTS->setObjectName("subjectCardContent");

    startSessionBtn->setFixedSize(150, 50);

    layout->addWidget(subjectTitle);
    layout->addStretch();
    layout->addWidget(ECTS);
    layout->addWidget(progressBar);
    layout->addWidget(percentage);
    layout->addStretch();
    layout->addWidget(startSessionBtn, 0, Qt::AlignCenter);
}

void SubjectCard::setupConnections() {
    
}
