#include "NavigationSystem.h"
#include <iostream>
#include <unistd.h>

// Konstruktor
NavigationSystem::NavigationSystem(MotorController& controller) : motorController(controller) {}

// Geradeaus fahren
void NavigationSystem::navigateForward(int durationMs) {
    std::cout << "NavigationSystem: Starte geradeaus fahren..." << std::endl;
    int iterations = durationMs / 10;
    for (int i = 0; i < iterations; i++) {
        if (i % 2 == 0) {
            motorController.setSpeed(-10, 10, 10, -10);
        } else {
            motorController.setSpeed(-10, 10, 10, -11);
        }
        usleep(10000);
    }
    motorController.stopAll();
    std::cout << "NavigationSystem: Geradeaus fahren beendet." << std::endl;
}

// Rückwärts fahren
void NavigationSystem::navigateBackward(int durationMs) {
    std::cout << "NavigationSystem: Starte rückwärts fahren..." << std::endl;
    int iterations = durationMs / 10;
    for (int i = 0; i < iterations; i++) {
        if (i % 2 == 0) {
            motorController.setSpeed(10, -10, -10, 10);
        } else {
            motorController.setSpeed(10, -10, -10, 9);
        }
        usleep(10000);
    }
    motorController.stopAll();
    std::cout << "NavigationSystem: Rückwärts fahren beendet." << std::endl;
}

// Nach rechts drehen
void NavigationSystem::turnRight(int degrees) {
    std::cout << "NavigationSystem: Starte rechts Drehung..." << std::endl;
    int iterations = degrees * 29;
    for (int i = 0; i < iterations; i++) {
        motorController.setSpeed(-10, 10, -10, 10);
    }
    motorController.stopAll();
    std::cout << "NavigationSystem: Rechts Drehung beendet." << std::endl;
}

// Nach links drehen
void NavigationSystem::turnLeft(int degrees) {
    std::cout << "NavigationSystem: Starte links Drehung..." << std::endl;
    int iterations = degrees * 29;
    for (int i = 0; i < iterations; i++) {
        motorController.setSpeed(10, -10, 10, -10);
    }
    motorController.stopAll();
    std::cout << "NavigationSystem: Links Drehung beendet." << std::endl;
}