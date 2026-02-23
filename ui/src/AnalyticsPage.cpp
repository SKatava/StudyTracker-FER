#include <AnalyticsPage.h>

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

AnalyticsPage::AnalyticsPage(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

void AnalyticsPage::setupUI()
{
    auto* layout = new QVBoxLayout(this);

    titleLabel = new QLabel("Dashboard");
    titleLabel->setObjectName("Analytics");

    auto* testButton = new QPushButton("Test Action");

    layout->addWidget(titleLabel);
    layout->addWidget(testButton);
    layout->addStretch();
}
