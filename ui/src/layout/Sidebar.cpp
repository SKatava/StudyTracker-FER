#include <layout/Sidebar.h>
#include <QLabel>

#include <Icons.h>
#include <components/Separator.h>

Sidebar::Sidebar(QWidget* parent) : QFrame(parent) {
   setupUI();  
}


void Sidebar::setupUI() {
    mainSegTitle                        = new QLabel("    Main");
    productivitySegTitle                = new QLabel("    Productivity");
    socialsSegTitle                     = new QLabel("    Socials");
    settingsSegTitle                    = new QLabel("    Settings");

    dashboardBtn                        = new SidebarBtn(Icons::Dashboard, "Dashboard");
    subjectsBtn                         = new SidebarBtn(Icons::Subjects, "Subjects");
    analyticsBtn                        = new SidebarBtn(Icons::Analytics, "Analytics");
    tasksBtn                            = new SidebarBtn(Icons::Tasks, "Tasks");
    calendarBtn                         = new SidebarBtn(Icons::Calendar, "Calendar");
    sessionsBtn                         = new SidebarBtn(Icons::Sessions, "Sessions");
    leaderboardBtn                      = new SidebarBtn(Icons::Leaderboard, "Leaderboard");
    profileBtn                          = new SidebarBtn(Icons::Profile, "Profile");
    preferencesBtn                      = new SidebarBtn(Icons::Preferences, "Preferences");

    layout                              = new QVBoxLayout(this);

    this->setObjectName("sidebar");
    this->setFixedWidth(250);

    layout->setContentsMargins(0, 10, 0, 10);

    layout->addWidget(mainSegTitle);
    layout->addWidget(dashboardBtn);
    layout->addWidget(subjectsBtn);
    layout->addWidget(analyticsBtn);

    layout->addSpacing(16); 
    layout->addWidget(new Separator());
    layout->addSpacing(16); 
    
    layout->addWidget(productivitySegTitle);
    layout->addWidget(tasksBtn);
    layout->addWidget(calendarBtn);
    layout->addWidget(sessionsBtn);
    
    layout->addSpacing(16); 
    layout->addWidget(new Separator());
    layout->addSpacing(16); 

    layout->addWidget(socialsSegTitle);
    layout->addWidget(leaderboardBtn);
    
    layout->addSpacing(16); 
    layout->addWidget(new Separator());
    layout->addSpacing(16); 

    layout->addWidget(settingsSegTitle);
    layout->addWidget(profileBtn);
    layout->addWidget(preferencesBtn);

    layout->addStretch();

}

void Sidebar::setupConnections() {
    
}
