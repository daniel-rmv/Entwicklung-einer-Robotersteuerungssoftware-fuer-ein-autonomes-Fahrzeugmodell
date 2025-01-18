#include "RobotSystem.h"
#include <iostream>

// Konstruktor
RobotSystem::RobotSystem() : motorController(), navigationSystem(motorController) {}

// Initialisierung
void RobotSystem::init() {
    std::cout << "RobotSystem: Initialisiere..." << std::endl;
}

// Hauptprogramm starten
void RobotSystem::start() {
    std::cout << "RobotSystem: Starte..." << std::endl;
    navigationSystem.navigateForward(25000);
    //navigationSystem.navigateBackward(25000);
    //navigationSystem.turnLeft(90);
    std::cout << "RobotSystem: Alle Aktionen abgeschlossen." << std::endl;
}