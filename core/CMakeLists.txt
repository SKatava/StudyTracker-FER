set(NAME studyTracker-core)
add_library(${NAME} STATIC)
target_sources(${NAME} PRIVATE
    src/domain/Subject.cpp
    src/persistence/Database.cpp
)

target_include_directories(${NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${NAME} PRIVATE
    SQLite::SQLite3 
)

