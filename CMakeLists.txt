cmake_minimum_required(VERSION 3.22...3.31)

set(PROJECT_NAME study_tracker)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)           
set(CMAKE_AUTORCC ON)           
set(CMAKE_AUTOUIC ON)           

find_package(SQLite3 REQUIRED)
find_package(Qt6 6.8 REQUIRED COMPONENTS
    Core
    Widgets
)

add_subdirectory(core)
add_subdirectory(ui)

