cmake_minimum_required(VERSION 3.4)
project(Speller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCES src/sources/main.cpp src/sources/VectorChecker.cpp
        src/sources/HashMapChecker.cpp src/sources/Checker.cpp
        src/sources/HashTable.cpp src/sources/AVL.cpp)
add_executable(Speller ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE src/headers)