cmake_minimum_required(VERSION 3.11)
project(032510611)

set(CMAKE_CXX_STANDARD 14)
find_package(yaml-cpp REQUIRED)

include_directories(include)

add_library(032510611
        include/ArmorPlate.hpp
        include/enum.hpp
        include/exprtk.hpp
        include/object.hpp
        include/robot.hpp
        include/target.hpp
        tools/ArmorPlate.cpp
        tools/enum.cpp
        tools/object.cpp
        tools/target.cpp
        include/Obstacle.hpp
        tools/Obstacle.cpp
        include/EnergyMechanism.hpp
        tools/EnergyMechanism.cpp
        include/mathtool.hpp
        include/EnemyRobot.hpp
        tools/EnemyRobot.cpp
        tools/robot.cpp
        include/SentryRobot.hpp
        tools/SentryRobot.cpp)
