#include "RobotSystem.h"
#include <iostream>

using namespace std;

// Konstruktor: Initialisiert MotorController und NavigationSystem
RobotSystem::RobotSystem()
    : motorController(), navigationSystem(motorController) {}

// Initialisierungsmethode
void RobotSystem::init() {
    cout << "RobotSystem: Initialisiere..." << endl;
    motorController.initializeMotors(); // Initialisiere die Motorverbindung
    cout << "RobotSystem: Initialisierung abgeschlossen." << endl;
}

// Startet das Robotersystem
void RobotSystem::start() {
    cout << "RobotSystem: Starte Aktionen..." << endl;
    navigationSystem.navigateForward(5000); // 5 Sekunden geradeaus fahren
    navigationSystem.turnRight(90); // 90 Grad nach rechts drehen
    navigationSystem.navigateBackward(5000); // 5 Sekunden rückwärts fahren
    cout << "RobotSystem: Aktionen abgeschlossen." << endl;
}

// Stoppt das Robotersystem
void RobotSystem::stop() {
    cout << "RobotSystem: Stoppe das System..." << endl;
    motorController.stopAll(); // Alle Motoren stoppen
}