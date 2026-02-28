#include <components/SubjectCard.h>
#include <QProgressBar>


SubjectCard::SubjectCard(QWidget* parent) : QFrame(parent) {
   setupUI(); 
}

void SubjectCard::setupUI() {
    layout          = new QVBoxLayout(this);
    subjectTitle    = new QLabel("Matematička analiza");
    ECTS            = new QLabel("8 ECTS");
    percentage      = new QLabel("80% Complete");
    startSessionBtn = new QPushButton("Start Session");

    QProgressBar* progressBar = new QProgressBar();
    progressBar->setRange(0, 100);   // minimalna i maksimalna vrijednost
    progressBar->setValue(80);        // početna vrijednost
    progressBar->setTextVisible(false);

    this->setObjectName("subjectCard");
    this->setFixedSize(250, 250);
    subjectTitle->setObjectName("subjectCardTitle");

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
