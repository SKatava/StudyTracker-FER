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
    auto* layout = new QHBoxLayout(this);
    
    layout->setSpacing(10);

    auto* dailyContent = new QWidget();
    dailyContent->setObjectName("dailyContent");
    auto* statsContent = new QWidget();
    
    auto* statLayout = new QVBoxLayout(statsContent);
    statLayout->setContentsMargins(0, 0, 0, 0);

    statLayout->setSpacing(10);
    
    auto* main = new QWidget();
    main->setObjectName("dailyContent");
    auto* secondary = new QWidget();
    secondary->setObjectName("statsContent");

    statLayout->addWidget(main, 1);
    statLayout->addWidget(secondary, 2);

    layout->addWidget(dailyContent, 3);
    layout->addWidget(statsContent, 1);
}
