/*
 * Copyright (c) 2025 Daniel Würmli
 *
 * Licensed under the MIT License. See LICENSE file in the project root for full license information.
 */

#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <vector>
#include "Motor.h"

// Die MotorController-Klasse verwaltet alle Motoren und ihre Steuerung
class MotorController {
private:
    std::vector<Motor> motors; // Liste der Motoren
    int fd; // I2C-Dateideskriptor zur Kommunikation mit dem Motor Driver

public:
    // Konstruktor: Erstellt Motor-Objekte (Verbindung wird später hergestellt)
    MotorController();

    // Initialisiert die Verbindung zum Motor Driver
    void initializeMotors();

    // Setzt die Geschwindigkeit für alle Motoren
    void setSpeed(int speed1, int speed2, int speed3, int speed4);

    // Stoppt alle Motoren
    void stopAll();
};

#endif // MOTORCONTROLLER_H