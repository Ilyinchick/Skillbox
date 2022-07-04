cmake_minimum_required(VERSION 3.21)


add_executable(Skillbox_2 main.cpp Circle.cpp Triangle.cpp Rectangle.cpp)
target_include_directories(Skillbox_2 PUBLIC ${MY_VAR})