/*
 * Copyright (c) 2025 Daniel Würmli
 *
 * Licensed under the MIT License. See LICENSE file in the project root for full license information.
 */

#ifndef NAVIGATIONSYSTEM_H
#define NAVIGATIONSYSTEM_H

#include "MotorController.h"

// Die NavigationSystem-Klasse verwaltet die Bewegungen des Roboters
class NavigationSystem {
private:
    MotorController& motorController; // Referenz auf den MotorController

public:
    // Konstruktor: Verbindet NavigationSystem mit MotorController
    NavigationSystem(MotorController& controller);

    // Fährt den Roboter geradeaus
    void navigateForward(int durationMs);

    // Fährt den Roboter rückwärts
    void navigateBackward(int durationMs);

    // Dreht den Roboter nach rechts
    void turnRight(int degrees);

    // Dreht den Roboter nach links
    void turnLeft(int degrees);
};

#endif // NAVIGATIONSYSTEM_H