cmake_minimum_required(VERSION 3.23)
project(CollegeNColleagues)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(CollegeNColleagues
        include/classes.h
        include/effects.h
        include/interfaces.hpp
        include/items.h
        include/map.hpp
        include/spells.h
        src/Business.cpp
        src/main.cpp
        src/map.cpp
        test/main.cpp)
