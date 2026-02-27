#ifndef MAINWINDOW_CLASS_H
#define MAINWINDOW_CLASS_H

//QT headers
#include <QMainWindow>
#include <QStackedWidget>
#include <QLayout>

//Personal header
#include <layout/Titlebar.h>
#include <layout/Sidebar.h>
#include <pages/DashboardPage.h>
#include <pages/SubjectsPage.h>
#include <pages/AnalyticsPage.h>
#include <pages/TasksPage.h>
#include <pages/CalendarPage.h>
#include <pages/SessionsPage.h>
#include <pages/LeaderboardPage.h>
#include <pages/ProfilePage.h>
#include <pages/PreferencesPage.h>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    QWidget* central;
    QWidget* body;

    QVBoxLayout* rootLayout;
    QHBoxLayout* bodyLayout;

    QStackedWidget* pages;

    Titlebar*           titlebar;
    Sidebar*            sidebar;
    DashboardPage*      dashboardPage;
    SubjectsPage*       subjectsPage;
    AnalyticsPage*      analyticsPage;
    TasksPage*          tasksPage;
    CalendarPage*       calendarPage;
    SessionsPage*       sessionsPage;
    LeaderboardPage*    leaderboardPage;
    ProfilePage*        profilePage;
    PreferencesPage*    preferencesPage;


    QMap<QString, QWidget*> pageMap;

private slots:
    void navigateToPage(const QString& page);
};

#endif
