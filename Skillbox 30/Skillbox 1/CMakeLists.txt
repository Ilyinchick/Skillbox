cmake_minimum_required(VERSION 3.21)
project(Skillbox_1)

set(CMAKE_CXX_STANDARD 14)
set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL_OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 6ea2dec23c3df14ac3b27b7d2d6bbff0cb7ba1b0)
FetchContent_MakeAvailable(cpr)

add_executable(Skillbox_1 main.cpp)
target_link_libraries(Skillbox_1 PRIVATE cpr::cpr)

