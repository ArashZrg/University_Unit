cmake_minimum_required(VERSION 3.26)
project(University_Unit)

set(CMAKE_CXX_STANDARD 20)

add_executable(University_Unit main.cpp
        DateTime/Time.cpp
        DateTime/Time.h
        DateTime/Date.cpp
        DateTime/Date.h
        People/Person.cpp
        People/Person.h
        People/Student.cpp
        People/Student.h
        People/Teacher.cpp
        People/Teacher.h
        Location/Location.cpp
        Location/Location.h
        Section/Section.cpp
        Section/Section.h
        DateTime/DateTime_Test.cpp
        Location/Location_Test.cpp
        People/People_Test.cpp
        Section/Section_Test.cpp
        Menu/Menu.cpp
        Menu/Menu.h)
