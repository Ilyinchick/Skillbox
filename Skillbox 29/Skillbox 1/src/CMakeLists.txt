cmake_minimum_required(VERSION 3.21)
project(Skillbox_1)

add_executable(Skillbox_1 main.cpp Dog.cpp Talent.cpp Dancing.cpp Counting.cpp Swimming.cpp InputControl.cpp)
target_include_directories(Skillbox_1 PUBLIC ${MY_VAR})