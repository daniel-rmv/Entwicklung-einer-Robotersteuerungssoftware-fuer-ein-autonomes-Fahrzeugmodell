/*
 * Copyright (c) 2025 Daniel Würmli
 *
 * Licensed under the MIT License. See LICENSE file in the project root for full license information.
 */

#ifndef MOTOR_H
#define MOTOR_H

#include <string>

// Die Motor-Klasse repräsentiert einen einzelnen Motor
class Motor {
private:
    std::string id;     // Eindeutige ID des Motors
    int currentSpeed;   // Aktuelle Geschwindigkeit des Motors in PWM

public:
    // Konstruktor: Initialisiert den Motor mit einer ID
    Motor(const std::string& motorId);

    // Setzt die Geschwindigkeit des Motors
    void setSpeed(int fd, int motorReg, int speed);

    // Gibt die aktuelle Geschwindigkeit des Motors zurück
    int getSpeed() const;
};

#endif // MOTOR_H