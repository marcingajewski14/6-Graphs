cmake_minimum_required(VERSION 3.1)

project(grafy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)


set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/catch2)
add_library(Catch2::Catch IMPORTED INTERFACE)
set_property(TARGET Catch2::Catch PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")

include(mazesrc.cmake)

add_subdirectory(Maze)
add_subdirectory(MazeUnitTest)

