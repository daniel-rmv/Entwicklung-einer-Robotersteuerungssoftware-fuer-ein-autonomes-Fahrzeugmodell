/*
 * Copyright (c) 2025 Daniel Würmli
 *
 * Licensed under the MIT License. See LICENSE file in the project root for full license information.
 */

#include "RobotSystem.h"
#include <iostream>

using namespace std;

// Konstruktor: Initialisiert MotorController und NavigationSystem
RobotSystem::RobotSystem() : motorController(), navigationSystem(motorController) {}

// Initialisierungsmethode
void RobotSystem::init() {
    cout << "RobotSystem: Initialisiere..." << endl;
    motorController.initializeMotors(); // Initialisiere die Motorverbindung
    cout << "RobotSystem: Initialisierung abgeschlossen." << endl;
}

// Startet das Robotersystem
void RobotSystem::start() {
    cout << "RobotSystem: Starte Aktionen..." << endl;
    navigationSystem.navigateForward(30000);
    cout << "RobotSystem: Aktionen abgeschlossen." << endl;
}

// Stoppt das Robotersystem
void RobotSystem::stop() {
    cout << "RobotSystem: Stoppe das System..." << endl;
    motorController.stopAll(); // Alle Motoren stoppen
}