cmake_minimum_required(VERSION 3.21)

add_executable(Skillbox_1 main.cpp Shared_ptr_toy.cpp Toy.cpp Dog.cpp)

target_include_directories(Skillbox_1 PUBLIC ${MY_VAR})