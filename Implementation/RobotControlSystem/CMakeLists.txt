cmake_minimum_required(VERSION 3.30)
project(RobotControlSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(RobotControlSystem
        RobotSystem.cpp
        NavigationSystem.cpp
        MotorController.cpp
        Motor.cpp
)

include_directories(/usr/local/include)
target_link_libraries(RobotControlSystem /usr/local/lib/libwiringPi.so)
