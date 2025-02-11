cmake_minimum_required(VERSION 3.20)
project(RobotControlSystem)

# C++23 Standard verwenden
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Alle Quell-Dateien
set(SOURCES
        src/main.cpp
        src/RobotSystem.cpp
        src/NavigationSystem.cpp
        src/MotorController.cpp
        src/Motor.cpp
        src/LidarSensor.cpp
)

# Executable erstellen
add_executable(RobotControlSystem ${SOURCES})

# Include-Verzeichnisse hinzufügen
target_include_directories(RobotControlSystem PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Suche WiringPi und verlinke es
find_library(WIRINGPI_LIB wiringPi REQUIRED)
if (WIRINGPI_LIB)
    target_link_libraries(RobotControlSystem PRIVATE ${WIRINGPI_LIB})
else()
    message(FATAL_ERROR "WiringPi-Bibliothek nicht gefunden! Bitte installieren!")
endif()