cmake_minimum_required(VERSION 3.20)
project("FrankenWaddle")

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h" "src/*.h")

add_executable(app ${SOURCES} ${HEADERS})

set_property(TARGET app PROPERTY CXX_STANDARD 20)
