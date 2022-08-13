cmake_minimum_required(VERSION 3.5)

project(Skillbox_2)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(${PROJECT_NAME} main.cpp mainwindow.cpp mainwindow.ui)

target_link_libraries(Skillbox_2 Qt5::Widgets)
