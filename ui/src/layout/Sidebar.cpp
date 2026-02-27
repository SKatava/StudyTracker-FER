#include <layout/Sidebar.h>
#include <QLabel>

#include <Icons.h>
#include <components/Separator.h>

Sidebar::Sidebar(QWidget* parent) : QFrame(parent) {
   setupUI(); 
   setupConnections();
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

    mainSegTitle->setContentsMargins(4, 0, 0, 8);
    productivitySegTitle->setContentsMargins(4, 0, 0, 8);
    socialsSegTitle->setContentsMargins(4, 0, 0, 8);
    settingsSegTitle->setContentsMargins(4, 0, 0, 8);

    layout->setContentsMargins(0, 10, 0, 10);
    layout->setSpacing(0);

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

    setActiveButton(dashboardBtn);
}

void Sidebar::setupConnections() {
    connectButton(dashboardBtn, "dashboard");
    connectButton(subjectsBtn, "subjects");
    connectButton(analyticsBtn, "analytics");
    connectButton(tasksBtn, "tasks");
    connectButton(calendarBtn, "calendar");
    connectButton(sessionsBtn, "sessions");
    connectButton(leaderboardBtn, "leaderboard");
    connectButton(profileBtn, "profile");
    connectButton(preferencesBtn, "preferences");
}

void Sidebar::setActiveButton(SidebarBtn* button) {
    if(activeButton)
        activeButton->SetActive(false); 
    activeButton = button;
    if(activeButton)
        activeButton->SetActive(true);
}

void Sidebar::connectButton(SidebarBtn* button, const QString& page) {
    connect(button, &QPushButton::clicked, this, [this, button, page]() {
        setActiveButton(button);
        emit navigateTo(page);
    });
}
