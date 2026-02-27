#ifndef SIDEBAR_CLASS_H
#define SIDEBAR_CLASS_H

#include <QFrame>
#include <QWidget>
#include <QLayout>

#include <components/SidebarBtn.h>

class Sidebar : public QFrame {
    Q_OBJECT
        
public:
    explicit Sidebar(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();
    void setActiveButton(SidebarBtn* button);
    void connectButton(SidebarBtn* button, const QString& page);

    QVBoxLayout*    layout;

    QLabel*         mainSegTitle;
    QLabel*         productivitySegTitle;
    QLabel*         socialsSegTitle;
    QLabel*         settingsSegTitle;

    SidebarBtn*     dashboardBtn;
    SidebarBtn*     subjectsBtn;
    SidebarBtn*     analyticsBtn;
    SidebarBtn*     tasksBtn;
    SidebarBtn*     calendarBtn;
    SidebarBtn*     sessionsBtn;
    SidebarBtn*     leaderboardBtn;
    SidebarBtn*     profileBtn;
    SidebarBtn*     preferencesBtn;

    SidebarBtn* activeButton = nullptr;

signals:
    void navigateTo(const QString& page);
};


#endif


