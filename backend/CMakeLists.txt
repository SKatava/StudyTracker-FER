set(NAME study_tracker-backend)
add_library(${NAME} STATIC)
target_sources(${NAME} PRIVATE
    src/sqlite/SQLiteSubjectRepository.cpp
    src/sqlite/Database.cpp
)

target_include_directories(${NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${NAME} PRIVATE
    study_tracker-core
    SQLite::SQLite3 
)
