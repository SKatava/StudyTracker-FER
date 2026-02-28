qt_add_executable(study_tracker
    src/main.cpp
    src/Application.cpp

    #layout
    src/layout/MainWindow.cpp
    include/layout/MainWindow.h
    src/layout/Titlebar.cpp
    include/layout/Titlebar.h
    src/layout/Sidebar.cpp
    include/layout/Sidebar.h
    src/layout/FlowLayout.cpp
    include/layout/FlowLayout.h

    #components
    src/components/SidebarBtn.cpp
    include/components/SidebarBtn.h
    src/components/Separator.cpp
    include/components/Separator.h
    src/components/SubjectCard.cpp
    include/components/SubjectCard.h
    src/components/Header.cpp
    include/components/Header.h

    #pages
    src/pages/DashboardPage.cpp
    include/pages/DashboardPage.h
    src/pages/SubjectsPage.cpp
    include/pages/SubjectsPage.h
    src/pages/AnalyticsPage.cpp
    include/pages/AnalyticsPage.h
    src/pages/TasksPage.cpp
    include/pages/TasksPage.h
    src/pages/CalendarPage.cpp
    include/pages/CalendarPage.h
    src/pages/SessionsPage.cpp
    include/pages/SessionsPage.h
    src/pages/LeaderboardPage.cpp
    include/pages/LeaderboardPage.h
    src/pages/ProfilePage.cpp
    include/pages/ProfilePage.h
    src/pages/PreferencesPage.cpp
    include/pages/PreferencesPage.h



)

qt_add_resources(APP_RESOURCES resources/resources.qrc)

target_sources(study_tracker PRIVATE ${APP_RESOURCES})

target_link_libraries(study_tracker PRIVATE
    Qt6::Core
    Qt6::Widgets
)

target_include_directories(study_tracker PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

