cmake_minimum_required (VERSION 2.6)
project (War)
add_executable(WAR main.cpp
        Squad.hpp
        Squad.cpp
        TacticalMarine.cpp TacticalMarine.hpp AssaultTerminator.cpp AssaultTerminator.hpp ISpaceMarine.hpp ISquad.hpp)