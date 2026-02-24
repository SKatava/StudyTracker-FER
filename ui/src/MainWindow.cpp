#include <MainWindow.h>

//QT headers
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>

//Personal headers
#include <HomePage.h>
#include <ProfilePage.h>
#include <SubjectsPage.h>
#include <AnalyticsPage.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) 
{

    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    auto* layout = new QHBoxLayout(central);

    sidebar = new SidebarWidget();
    pages = new QStackedWidget();

    sidebar->setObjectName("sidebar");
    pages->setObjectName("content");

    layout->addWidget(sidebar);
    layout->addWidget(pages);

    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);

    HomePage* homePage = new HomePage();
    ProfilePage* profilePage = new ProfilePage();
    SubjectsPage* subjectsPage = new SubjectsPage();
    AnalyticsPage* analyticsPage = new AnalyticsPage();


    pages->addWidget(homePage);      
    pages->addWidget(profilePage);  
    pages->addWidget(subjectsPage);   
    pages->addWidget(analyticsPage);

    connect(sidebar, &SidebarWidget::homeClicked,
            this, [this]() { this->pages->setCurrentIndex(0); });

    connect(sidebar, &SidebarWidget::profileClicked,
            this, [this]() { this->pages->setCurrentIndex(1); });

    connect(sidebar, &SidebarWidget::subjectsClicked,
            this, [this]() { this->pages->setCurrentIndex(2); });

    connect(sidebar, &SidebarWidget::analyticsClicked,
            this, [this]() { this->pages->setCurrentIndex(3); });
}
