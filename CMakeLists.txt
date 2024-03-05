cmake_minimum_required(VERSION 3.20)
project("FrankenWaddle")

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h" "src/*.h")

add_executable(app ${SOURCES} ${HEADERS})

set_property(TARGET app PROPERTY CXX_STANDARD 20)