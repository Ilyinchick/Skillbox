cmake_minimum_required(VERSION 3.21)

add_executable(Skillbox_3 main.cpp Director.cpp Manager.cpp Worker.cpp Man.cpp)

target_include_directories(Skillbox_3 PUBLIC ${MY_VAR})