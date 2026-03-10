#include <components/StudyTimer.h>
#include <QListView>
#include <QDate>

#include <core/services/AppContext.h>
#include <core/domain/Session.h>


StudyTimer::StudyTimer(QWidget* parent) : QFrame(parent)  {
    setupUI();    
    setupConnections();
}

void StudyTimer::setupUI() {
    layout      = new QVBoxLayout(this);
    bottomLayout= new QHBoxLayout();
    title       = new QLabel("Study Timer");
    time        = new QLabel("00:00:00");
    subjectList = new QComboBox();
    descriptionInput    = new QTextEdit();
    startBtn    = new QPushButton("Start");
    confirmBtn  = new QPushButton("Confirm");
    cancelBtn   = new QPushButton("Cancel");
    timer       = new QTimer();
       
    this->setFixedSize(600, 600);
    this->setObjectName("studyTimer");

    title->setObjectName("studyTimerTitle");
    time->setObjectName("time");
    
    subjectList->setFixedHeight(40);
    
    auto subjects = AppContext::Instance().Subjects().GetSubjects();

    for(auto& item : subjects) {
        subjectList->addItem(item.GetName().c_str());
    }

    descriptionInput->setPlaceholderText("Enter the description of the session here ...");

    startBtn->setObjectName("goodBtn");
    startBtn->setFixedHeight(40);
    confirmBtn->setFixedHeight(40);
    cancelBtn->setFixedHeight(40);

    bottomLayout->addWidget(startBtn);
    bottomLayout->addWidget(cancelBtn);
    bottomLayout->addWidget(confirmBtn);

    timer->setInterval(1000);

    layout->setSpacing(20);

    layout->addWidget(title, 0, Qt::AlignHCenter);
    layout->addWidget(subjectList);
    layout->addWidget(descriptionInput);
    layout->addStretch();
    layout->addWidget(time, 0, Qt::AlignHCenter);
    layout->addStretch();
    layout->addLayout(bottomLayout);
}

void StudyTimer::setupConnections() {
    connect(startBtn, &QPushButton::clicked, this, [this]() {

        if(timer->isActive()) {
            timer->stop();
            startBtn->setText("Start");
            time->setProperty("active", false);
            time->style()->unpolish(time);
            time->style()->polish(time);
        } else {
            timer->start();
            startBtn->setText("Stop");
            time->setProperty("active", true);
            time->style()->unpolish(time);
            time->style()->polish(time);
        }

    });

    connect(timer, &QTimer::timeout, this, [this]() {

        elapsedSeconds++;

        int hours = elapsedSeconds / 3600;
        int minutes = (elapsedSeconds % 3600) / 60;
        int seconds = elapsedSeconds % 60;

        QString t = QString("%1:%2:%3")
                        .arg(hours, 2, 10, QChar('0'))
                        .arg(minutes, 2, 10, QChar('0'))
                        .arg(seconds, 2, 10, QChar('0'));

        time->setText(t);
    });
    connect(confirmBtn, &QPushButton::clicked, this, [this]() {
        if(timer->isActive()) {
            timer->stop();
            startBtn->setText("Start");
            time->setProperty("active", false);
            time->style()->unpolish(time);
            time->style()->polish(time);
        }

        if(elapsedSeconds < 60) return;

        int subjectIndex = subjectList->currentIndex();
         
        if(subjectIndex < 0) return;

        auto subjects = AppContext::Instance().Subjects().GetSubjects();
        auto& subject = subjects[subjectIndex];

        uint32_t minutes = elapsedSeconds / 60;
        subject.SetInvestedStudyMinutes(subject.GetInvestedStudyMinutes() + minutes);

        QDate today = QDate::currentDate();
        QString dateString = today.toString("dd-MM-yyyy");

        Session session {-1, subject.GetId(), minutes, descriptionInput->toPlainText().toStdString(), dateString.toStdString()};

        AppContext::Instance().Subjects().UpdateSubject(subject);
        AppContext::Instance().Sessions().CreateSession(session);
        
        elapsedSeconds = 0;
        time->setText("00:00:00");
    });

    connect(cancelBtn, &QPushButton::clicked, this, [this]() {
        if(timer->isActive()) {
            timer->stop();
            startBtn->setText("Start");
            time->setProperty("active", false);
            time->style()->unpolish(time);
            time->style()->polish(time);
        }
         elapsedSeconds = 0;
        time->setText("00:00:00");
    });

}
