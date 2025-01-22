cmake_minimum_required(VERSION 3.30)
project(RobotControlSystem)

# C++23 Standard verwenden
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Füge alle Quell-Dateien hinzu
add_executable(RobotControlSystem
        src/main.cpp
        src/RobotSystem.cpp
        src/NavigationSystem.cpp
        src/MotorController.cpp
        src/Motor.cpp
        src/LidarSensor.cpp
)

# Füge den Include-Ordner hinzu, damit Header-Dateien gefunden werden
target_include_directories(RobotControlSystem PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Suche und verlinke die WiringPi-Bibliothek
find_library(WIRINGPI_LIB wiringPi REQUIRED)
target_link_libraries(RobotControlSystem PRIVATE ${WIRINGPI_LIB})