cmake_minimum_required (VERSION 2.6)

project(localcommitment)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 9)
set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/extern")

add_executable(localcommitment src/main.cpp)

install(TARGETS localcommitment DESTINATION bin)
