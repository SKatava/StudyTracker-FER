set(NAME study_tracker-core)
add_library(${NAME} STATIC)
target_sources(${NAME} PRIVATE
    src/domain/Subject.cpp

    src/services/AppContext.cpp
    src/services/SubjectService.cpp
    src/services/SessionService.cpp
    src/services/TaskService.cpp
    
)

target_include_directories(${NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${NAME} PRIVATE
    SQLite3::SQLite3 
)

