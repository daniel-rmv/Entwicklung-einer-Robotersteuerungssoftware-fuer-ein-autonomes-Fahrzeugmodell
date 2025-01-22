#include "MotorController.h"
#include <iostream>
#include <wiringPiI2C.h>

using namespace std;

// Konstruktor: Erstellt Motor-Objekte (ohne direkte Verbindung)
MotorController::MotorController() {
    cout << "MotorController: Konstruktor aufgerufen." << endl;

    // Erstelle und speichere Motor-Objekte
    motors.emplace_back("M1");
    motors.emplace_back("M2");
    motors.emplace_back("M3");
    motors.emplace_back("M4");
}

// Methode: Initialisiert die Verbindung zum Motor Driver
void MotorController::initializeMotors() {
    cout << "MotorController: Initialisiere Motor Driver..." << endl;

    // Verbindung zum Motor Driver herstellen
    fd = wiringPiI2CSetup(0x34); // I2C-Adresse des Motor Drivers
    if (fd == -1) {
        cerr << "Fehler: Kann Motor Driver nicht über I2C ansprechen!" << endl;
        exit(1); // Beende das Programm bei Verbindungsfehler
    }

    cout << "MotorController: Verbindung erfolgreich hergestellt." << endl;
}

// Methode: Setzt die Geschwindigkeit für alle Motoren
void MotorController::setSpeed(int speed1, int speed2, int speed3, int speed4) {
    motors[0].setSpeed(fd, 0x33, speed1); // Motor 1
    motors[1].setSpeed(fd, 0x34, speed2); // Motor 2
    motors[2].setSpeed(fd, 0x35, speed3); // Motor 3
    motors[3].setSpeed(fd, 0x36, speed4); // Motor 4
}

// Methode: Stoppt alle Motoren, indem die Geschwindigkeit auf 0 gesetzt wird
void MotorController::stopAll() {
    setSpeed(0, 0, 0, 0);
    cout << "MotorController: Alle Motoren gestoppt." << endl;
}