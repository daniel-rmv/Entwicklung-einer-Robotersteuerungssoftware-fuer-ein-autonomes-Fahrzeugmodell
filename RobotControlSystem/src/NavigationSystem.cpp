/*
 * Copyright (c) 2025 Daniel Würmli
 *
 * Licensed under the MIT License. See LICENSE file in the project root for full license information.
 */

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
        if (i % 14 == 0) { //                                                                                  ↑  ↑
            motorController.setSpeed(-15, 15, 15, -20); // Leichte Korrektur                    L    M2  ⎜━━⎜‾‾‾‾‾‾‾‾⎜━━⎜  M4   R
        } else { //                                                                             I           ⎜        ⎜          E
            motorController.setSpeed(-15, 15, 15, -15); // Standardgeschwindigkeit              N           ⎜        ⎜          C
        } //                                                                                    K           ⎜        ⎜          H
        usleep(10000); // Warte 10ms                                                    S    M1  ⎜━━⎜⎽⎽⎽⎽⎽⎽⎽⎽⎜━━⎜  M3   T
    } //                                                                                                       ↑  ↑             S

    motorController.stopAll(); // Stoppe die Motoren nach Abschluss
    cout << "NavigationSystem: Geradeaus fahren beendet." << endl;
}

// Methode: Fährt rückwärts für eine bestimmte Dauer
void NavigationSystem::navigateBackward(int durationMs) {
    cout << "NavigationSystem: Starte rückwärts fahren..." << endl;

    int iterations = durationMs / 10;

    for (int i = 0; i < iterations; i++) {
        if (i % 27 == 0) {
            motorController.setSpeed(15, -15, -16, 15); // Leichte Korrektur
        } else {
            motorController.setSpeed(15, -15, -15, 15); // Standardgeschwindigkeit rückwärts
        }
        usleep(10000);
    }

    motorController.stopAll();
    cout << "NavigationSystem: Rückwärts fahren beendet." << endl;
}

// Methode: Dreht den Roboter nach rechts um eine bestimmte Gradzahl
void NavigationSystem::turnRight(int degrees) {
    cout << "NavigationSystem: Starte rechts Drehung..." << endl;

    int iterations = degrees * 30; // Iterationen für 1 Grad = 30

    for (int i = 0; i < iterations; i++) {
        motorController.setSpeed(-10, 10, -10, 10); // Drehgeschwindigkeit
        usleep(2125);
    }

    motorController.stopAll();
    cout << "NavigationSystem: Rechts Drehung beendet." << endl;
}

// Methode: Dreht den Roboter nach links um eine bestimmte Gradzahl
void NavigationSystem::turnLeft(int degrees) {
    cout << "NavigationSystem: Starte links Drehung..." << endl;

    int iterations = degrees * 30; // Iterationen für 1 Grad = 30

    for (int i = 0; i < iterations; i++) {
        motorController.setSpeed(10, -10, 10, -10);
        usleep(2125);
    }

    motorController.stopAll();
    cout << "NavigationSystem: Links Drehung beendet." << endl;
}