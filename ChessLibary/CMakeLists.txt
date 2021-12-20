cmake_minimum_required(VERSION 3.18)
project (chess_lib VERSION 1.0.0)

set(EXECUTABLE false)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

file(GLOB SOURCES "src/*.cpp")
set(EXECUTABLE_OUTPUT_PATH "build")


if (EXECUTABLE)
    message(STATUS "is an executable")
    list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/python_bindings.cpp")
    add_executable(chess_lib ${SOURCES})
else()
    message(STATUS "is a python package")
    list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
    find_package(PythonInterp REQUIRED)
    include_directories(${PYTHON_INCLUDE_DIRS})


    add_subdirectory(pybind11)
    pybind11_add_module(chess_lib ${SOURCES})
endif()