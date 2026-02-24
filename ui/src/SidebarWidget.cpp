#include <SidebarWidget.h>

#include <QLabel>

SidebarWidget::SidebarWidget(QWidget* parent)
    : QFrame(parent)
{
    setFixedWidth(250);

    auto* layout = new QVBoxLayout(this);

    layout->setContentsMargins(0,10,0,0);
    layout->setSpacing(5);

    auto createButton = [&](const QString& text)
    {
        auto* btn = new QPushButton(text);
        btn->setFixedSize(220, 40);
        layout->addWidget(btn, 0, Qt::AlignCenter);
        return btn;
    };

    QFrame* line = new QFrame();
    line->setObjectName("separator");
    line->setFrameShape(QFrame::NoFrame);
    line->setFixedHeight(1);
    line->setFixedWidth(220);
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    

    auto label = new QLabel("StudyTracker - FER");
    label->setAlignment(Qt::AlignCenter);
    

    layout->addWidget(label);
    layout->addSpacing(5);
    layout->addWidget(line, 0, Qt::AlignCenter);
    layout->addSpacing(5);

    
    auto* home = createButton("Home");
    auto* profile = createButton("Profile");
    auto* subjects = createButton("Subjects");
    auto* analytics = createButton("Analytics");



    layout->addStretch();

    connect(home, &QPushButton::clicked, this, &SidebarWidget::homeClicked);
    connect(profile, &QPushButton::clicked, this, &SidebarWidget::profileClicked);
    connect(subjects, &QPushButton::clicked, this, &SidebarWidget::subjectsClicked);
    connect(analytics, &QPushButton::clicked, this, &SidebarWidget::analyticsClicked);
}
