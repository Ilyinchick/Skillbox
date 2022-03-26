cmake_minimum_required(VERSION 3.21)

add_executable(Skillbox_2  main.cpp     ${MY_VAR}/ram.h ram.cpp     ${MY_VAR}/cpu.h cpu.cpp     ${MY_VAR}/disk.h disk.cpp
        ${MY_VAR}/gpu.h gpu.cpp     ${MY_VAR}/kbd.h kbd.cpp        ${MY_VAR}/inputControl.h inputControl.cpp)

target_include_directories(Skillbox_2 PUBLIC ${MY_VAR})
