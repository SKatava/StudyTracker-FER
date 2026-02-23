qt_add_executable(study_tracker
    src/main.cpp
    src/MainWindow.cpp
    src/SidebarWidget.cpp
    src/HomePage.cpp
    src/ProfilePage.cpp
    src/SubjectsPage.cpp
    src/AnalyticsPage.cpp

    include/MainWindow.h
    include/SidebarWidget.h
    include/HomePage.h
    include/ProfilePage.h
    include/SubjectsPage.h
    include/AnalyticsPage.h
)

target_link_libraries(study_tracker PRIVATE
    Qt6::Core
    Qt6::Widgets
)

target_include_directories(study_tracker PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

