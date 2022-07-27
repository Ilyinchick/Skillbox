cmake_minimum_required(VERSION 3.21)
project(Practice)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

find_package(Qt5Widgets REQUIRED)

add_executable(Practice main.cpp)
target_link_libraries(Practice Qt5::Widgets)
