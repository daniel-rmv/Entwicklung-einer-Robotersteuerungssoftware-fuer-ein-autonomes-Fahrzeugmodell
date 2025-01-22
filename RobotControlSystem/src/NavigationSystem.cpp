#include "NavigationSystem.h"
#include <iostream>
#include <unistd.h>

using namespace std;

// Konstruktor: Initialisiert das Navigationssystem mit einer Referenz auf den MotorController
NavigationSystem::NavigationSystem(MotorController& controller) : motorController(controller) {}

// Methode: Fährt den Roboter geradeaus für eine bestimmte Dauer
void NavigationSystem::navigateForward(int durationMs) {
    cout << "NavigationSystem: Starte geradeaus fahren..." << endl;

    // Berechnung der Iterationen basierend auf der Gesamtdauer (10ms pro Iteration)
    int iterations = durationMs / 10;

    for (int i = 0; i < iterations; i++) {
        if (i % 2 == 0) {
            motorController.setSpeed(-10, 10, 10, -10); // Standardgeschwindigkeit
        } else {
            motorController.setSpeed(-10, 10, 10, -11); // Leichte Korrektur
        }
        usleep(10000); // Warte 10ms
    }

    motorController.stopAll(); // Stoppe die Motoren nach Abschluss
    cout << "NavigationSystem: Geradeaus fahren beendet." << endl;
}

// Methode: Fährt rückwärts für eine bestimmte Dauer
void NavigationSystem::navigateBackward(int durationMs) {
    cout << "NavigationSystem: Starte rückwärts fahren..." << endl;

    int iterations = durationMs / 10;

    for (int i = 0; i < iterations; i++) {
        if (i % 2 == 0) {
            motorController.setSpeed(10, -10, -10, 10); // Standardgeschwindigkeit rückwärts
        } else {
            motorController.setSpeed(10, -10, -10, 9); // Leichte Korrektur
        }
        usleep(10000);
    }

    motorController.stopAll();
    cout << "NavigationSystem: Rückwärts fahren beendet." << endl;
}

// Methode: Dreht den Roboter nach rechts um eine bestimmte Gradzahl
void NavigationSystem::turnRight(int degrees) {
    cout << "NavigationSystem: Starte rechts Drehung..." << endl;

    int iterations = degrees * 29; // Beispiel: Iterationen für 1 Grad = 29

    for (int i = 0; i < iterations; i++) {
        motorController.setSpeed(-10, 10, -10, 10); // Drehgeschwindigkeit
    }

    motorController.stopAll();
    cout << "NavigationSystem: Rechts Drehung beendet." << endl;
}

// Methode: Dreht den Roboter nach links um eine bestimmte Gradzahl
void NavigationSystem::turnLeft(int degrees) {
    cout << "NavigationSystem: Starte links Drehung..." << endl;

    int iterations = degrees * 29;

    for (int i = 0; i < iterations; i++) {
        motorController.setSpeed(10, -10, 10, -10);
    }

    motorController.stopAll();
    cout << "NavigationSystem: Links Drehung beendet." << endl;
}