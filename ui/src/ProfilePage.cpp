#include <ProfilePage.h>

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

ProfilePage::ProfilePage(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

void ProfilePage::setupUI()
{
    auto* layout = new QVBoxLayout(this);

    titleLabel = new QLabel("Dashboard");
    titleLabel->setObjectName("Subjets");

    auto* testButton = new QPushButton("Test Action");

    layout->addWidget(titleLabel);
    layout->addWidget(testButton);
    layout->addStretch();
}
