#include <layout/MainWindow.h>

//QT headers
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>

//Personal headers

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent)  {
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);

    setupUI();
    setupConnections();
}

void MainWindow::setupUI() {
    central         = new QWidget(this);
    rootLayout      = new QVBoxLayout(central);
    titlebar        = new Titlebar();
    body            = new QWidget();
    bodyLayout      = new QHBoxLayout(body);
    sidebar         = new Sidebar();
    dashboardPage   = new DashboardPage();
    subjectsPage    = new SubjectsPage();
    analyticsPage   = new AnalyticsPage();
    tasksPage       = new TasksPage();
    calendarPage    = new CalendarPage();
    sessionsPage    = new SessionsPage();
    leaderboardPage = new LeaderboardPage();
    profilePage     = new ProfilePage();
    preferencesPage = new PreferencesPage();
    pages           = new QStackedWidget();
    
    setCentralWidget(central);

    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);

    rootLayout->addWidget(titlebar);
    rootLayout->addWidget(body);

    bodyLayout->setContentsMargins(10, 10, 10, 10);
    bodyLayout->setSpacing(20);

    bodyLayout->addWidget(sidebar);

    pages->addWidget(dashboardPage);
    pages->addWidget(subjectsPage);
    pages->addWidget(analyticsPage);
    pages->addWidget(tasksPage);
    pages->addWidget(calendarPage);
    pages->addWidget(sessionsPage);
    pages->addWidget(leaderboardPage);
    pages->addWidget(profilePage);
    pages->addWidget(preferencesPage);
    
    bodyLayout->addWidget(pages);
}

void MainWindow::setupConnections() {
    pageMap["dashboard"] = dashboardPage;
    pageMap["subjects"] = subjectsPage;
    pageMap["analytics"] = analyticsPage;
    pageMap["tasks"] = tasksPage;
    pageMap["calendar"] = calendarPage;
    pageMap["sessions"] = sessionsPage;
    pageMap["leaderboard"] = leaderboardPage;
    pageMap["profile"] = profilePage;
    pageMap["preferences"] = preferencesPage;

    connect(sidebar, &Sidebar::navigateTo, this, &MainWindow::navigateToPage);
}

void MainWindow::navigateToPage(const QString& page) {
    if(pageMap.contains(page)) {
        pages->setCurrentWidget(pageMap[page]);
    }
}
