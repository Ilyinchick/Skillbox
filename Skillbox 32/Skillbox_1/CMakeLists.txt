cmake_minimum_required(VERSION 3.21)
project(Skillbox_1)

set(CMAKE_CXX_STANDARD 14)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(json-develop)
add_executable(Skillbox_1 main.cpp)

target_link_libraries(Skillbox_1 PRIVATE nlohmann_json::nlohmann_json)
