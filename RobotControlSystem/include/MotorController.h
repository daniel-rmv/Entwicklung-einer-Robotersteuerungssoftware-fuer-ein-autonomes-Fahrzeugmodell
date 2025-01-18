#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <vector>
#include "Motor.h"

class MotorController {
private:
    std::vector<Motor> motors; // Liste der Motoren
    int fd; // I2C-Dateideskriptor

public:
    MotorController(); // Konstruktor
    void setSpeed(int speed1, int speed2, int speed3, int speed4); // Geschwindigkeit setzen
    void stopAll(); // Alle Motoren stoppen
};

#endif