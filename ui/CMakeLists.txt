qt_add_executable(study_tracker
    main.cpp
)

target_link_libraries(study_tracker PRIVATE
    Qt6::Core
    Qt6::Widgets
)

target_include_directories(study_tracker PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/models
)

