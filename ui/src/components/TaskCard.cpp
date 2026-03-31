#include <components/TaskCard.h>

#include <Icons.h>
#include <Fonts.h>
#include <core/services/AppContext.h>

TaskCard::TaskCard(QWidget* parent, const Task& task) : QFrame(parent) {
    setupUI(task);
    setupConnections();
}

void TaskCard::setupUI(const Task& task) {

    layout              = new QHBoxLayout(this);
    subject             = new QLabel("lol");
    infoLayout          = new QVBoxLayout();
    description         = new QLabel(task.description.c_str());
    start               = new QLabel(task.date_start.c_str());
    end                 = new QLabel(task.date_end.c_str());
    finish              = new QLabel(task.date_done.c_str());
    minutes             = new QLabel(( std::to_string(task.minutes) + 'm' ).c_str());
    icon                = new QLabel(Icons::Tasks);
    checkBox            = new QCheckBox();

    if (!Fonts::IconFamily.isEmpty()) {
        QFont iconFont(Fonts::IconFamily);
        iconFont.setPixelSize(32);        
        icon->setFont(iconFont);
    } else {
        qWarning() << "Icon font family not loaded - using fallback";
        icon->setText("📋");              // simple clipboard fallback
    }

    auto subjects = AppContext::Instance().Subjects().GetSubjects();
    for(auto& item : subjects) {
        if(task.subjectId == item.GetId()) {
            subject->setText(item.GetName().c_str());
        }
    }

    this->setFixedHeight(150);
    this->setObjectName("sessionCard");

    icon->setObjectName("sessionIcon");
    icon->setFixedSize(50, 50);
    icon->setAlignment(Qt::AlignCenter);

    checkBox->setFixedSize(50, 50);

    subject->setObjectName("primaryText");
    minutes->setObjectName("primaryText");
    description->setObjectName("secondaryText");
    start->setObjectName("secondaryText");

    description->setWordWrap(true);
    description->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    infoLayout->addWidget(subject);
    infoLayout->addWidget(description);
    infoLayout->addStretch();
    std::string range = task.date_start + " - " + task.date_end;
    QLabel* dateRange = new QLabel(range.c_str());
    dateRange->setObjectName("secondaryText");
    infoLayout->addWidget(dateRange);

    layout->setSpacing(20);

    layout->addWidget(checkBox);
    layout->addLayout(infoLayout);
    layout->addStretch();
    layout->addWidget(minutes);


}

void TaskCard::setupConnections() {

}
