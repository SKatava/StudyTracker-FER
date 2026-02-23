#include <SubjectsPage.h>

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

SubjectsPage::SubjectsPage(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

void SubjectsPage::setupUI()
{
    auto* layout = new QVBoxLayout(this);

    titleLabel = new QLabel("Dashboard");
    titleLabel->setObjectName("Subjects");

    auto* testButton = new QPushButton("Test Action");

    layout->addWidget(titleLabel);
    layout->addWidget(testButton);
    layout->addStretch();
}
