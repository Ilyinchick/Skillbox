cmake_minimum_required(VERSION 3.5)

project(Skillbox_38-2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets WebEngineWidgets)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(Skillbox_38-2 PRIVATE Qt6::Widgets Qt6::WebEngineWidgets)

