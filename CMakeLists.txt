cmake_minimum_required(VERSION 3.15)
project(Speller)

set(CMAKE_CXX_STANDARD 14)

add_executable(Speller main.cpp VectorChecker.cpp HashMapChecker.cpp Checker.cpp HashTable.cpp AVL.cpp)

#target_compile_options(Speller PRIVATE "-Wall")