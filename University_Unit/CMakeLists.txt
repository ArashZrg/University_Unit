cmake_minimum_required(VERSION 3.26)
project(University_Unit)

set(CMAKE_CXX_STANDARD 20)

add_executable(University_Unit main.cpp
        Time.cpp
        Time.h
        Date.cpp
        Date.h
        Person.cpp
        Person.h
        Student.cpp
        Student.h
        Teacher.cpp
        Teacher.h)
