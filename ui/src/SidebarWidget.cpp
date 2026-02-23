#include <SidebarWidget.h>


SidebarWidget::SidebarWidget(QWidget* parent)
    : QFrame(parent)
{
    setFixedWidth(250);

    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(10);

    QString btnStyle =
        "QPushButton { background-color: #000; color: white; padding: 6px; }"
        "QPushButton:hover { background-color: #0e0e0e; }";

    auto createButton = [&](const QString& text)
    {
        auto* btn = new QPushButton(text);
        btn->setFixedSize(250, 60);
        btn->setStyleSheet(btnStyle);
        layout->addWidget(btn);
        return btn;
    };

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
