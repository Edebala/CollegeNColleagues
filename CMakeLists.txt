cmake_minimum_required(VERSION 3.20)
project(CollegeNColleagues)

set(CMAKE_CXX_STANDARD 14)

add_executable(CollegeNColleagues
        test/main.cpp
        include/creature.h
        include/effects.h
        include/items.h
        include/spells.h
        src/creature.cpp
        src/effects.cpp
        src/items.cpp
        src/spells.cpp)
