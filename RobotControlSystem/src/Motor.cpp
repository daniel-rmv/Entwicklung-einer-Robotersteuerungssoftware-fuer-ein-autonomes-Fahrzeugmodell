/*
 * Copyright (c) 2025 Daniel Würmli
 *
 * Licensed under the MIT License. See LICENSE file in the project root for full license information.
 */

#include "Motor.h"
#include <wiringPiI2C.h>
#include <iostream>

using namespace std;

// Konstruktor: Initialisiert den Motor mit einer ID und setzt die Geschwindigkeit auf 0
Motor::Motor(const string& motorId) : id(motorId), currentSpeed(0) {}

// Methode: Setzt die Geschwindigkeit des Motors
void Motor::setSpeed(int fd, int motorReg, int speed) {
    if (currentSpeed != speed) { // Nur, wenn die Geschwindigkeit anders ist
        currentSpeed = speed;
        wiringPiI2CWriteReg8(fd, motorReg, speed);
        cout << "Motor " << id << " auf Geschwindigkeit " << speed << " gesetzt." << endl;
    }
}

// Methode: Gibt die aktuelle Geschwindigkeit des Motors zurück
int Motor::getSpeed() const {
    return currentSpeed;
}