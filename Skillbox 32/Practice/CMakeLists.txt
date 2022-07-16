cmake_minimum_required(VERSION 3.21)
project(Practice)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(Practice main.cpp)

target_link_libraries(Practice PRIVATE nlohmann_json::nlohmann_json)
