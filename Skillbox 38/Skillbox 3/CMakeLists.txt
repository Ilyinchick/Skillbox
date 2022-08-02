cmake_minimum_required(VERSION 3.5)

project(Skillbox_3)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(Skillbox_3 Qt5::Widgets)

