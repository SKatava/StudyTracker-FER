#include <HomePage.h>

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

HomePage::HomePage(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

void HomePage::setupUI()
{
    auto* layout = new QVBoxLayout(this);

    titleLabel = new QLabel("Dashboard");
    titleLabel->setObjectName("Home");

    auto* testButton = new QPushButton("Test Action");

    layout->addWidget(titleLabel);
    layout->addWidget(testButton);
    layout->addStretch();
}
