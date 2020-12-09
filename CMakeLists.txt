cmake_minimum_required(VERSION 3.17)

project(Multithreading)

set(CMAKE_CXX_STANDARD 17)

# Add source files
file(GLOB_RECURSE SOURCE_FILES
        src/*.c
        src/*.cpp)

# Add header files
file(GLOB_RECURSE HEADER_FILES
        include/*.h
        include/*.hpp)

include_directories(include)

add_executable(Multithreading ${HEADER_FILES} ${SOURCE_FILES})