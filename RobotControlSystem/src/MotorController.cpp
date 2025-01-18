#include "MotorController.h"
#include <iostream>
#include <wiringPiI2C.h>

// Konstruktor
MotorController::MotorController() {
    fd = wiringPiI2CSetup(0x34); // Verbindung herstellen
    if (fd == -1) {
        std::cerr << "Fehler: Kann Motor Driver nicht über I2C ansprechen!" << std::endl;
        exit(1);
    }

    // Motoren erstellen
    motors.emplace_back("M1");
    motors.emplace_back("M2");
    motors.emplace_back("M3");
    motors.emplace_back("M4");
}

// Geschwindigkeit setzen
void MotorController::setSpeed(int speed1, int speed2, int speed3, int speed4) {
    motors[0].setSpeed(fd, 0x33, speed1);
    motors[1].setSpeed(fd, 0x34, speed2);
    motors[2].setSpeed(fd, 0x35, speed3);
    motors[3].setSpeed(fd, 0x36, speed4);
}

// Alle Motoren stoppen
void MotorController::stopAll() {
    setSpeed(0, 0, 0, 0);
    std::cout << "Alle Motoren gestoppt." << std::endl;
}