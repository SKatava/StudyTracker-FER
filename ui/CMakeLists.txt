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

    #components
    src/components/SidebarBtn.cpp
    include/components/SidebarBtn.h
    src/components/Separator.cpp
    include/components/Separator.h
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

