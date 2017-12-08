cmake_minimum_required (VERSION 2.6)

project(localcommitment)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 9)
set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/extern")

add_executable(localcommitment src/main.cpp)

install(TARGETS localcommitment DESTINATION bin)
install(SCRIPT "${PROJECT_SOURCE_DIR}/post_install.cmake")

# uninstall target
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
