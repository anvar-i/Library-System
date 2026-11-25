cmake_minimum_required(VERSION 4.4)
project(Library_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Library_System
        BookManagement.h
        BorrowerManagement.h
        DStructures.h
        History.h
        main.cpp
        Menu.h
        Registration.h)
