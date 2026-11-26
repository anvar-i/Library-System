cmake_minimum_required(VERSION 3.20)
project(Library_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Library_System
        BookManagement.h
        BorrowerManagement.h
        DStructures.h
        History.h
        main.cpp
         Queue.h)
