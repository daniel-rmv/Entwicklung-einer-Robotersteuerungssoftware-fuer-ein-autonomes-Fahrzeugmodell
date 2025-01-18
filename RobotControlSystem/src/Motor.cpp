#include "Motor.h"
#include <wiringPiI2C.h>
#include <iostream>

// Konstruktor
Motor::Motor(const std::string& motorId) : id(motorId), currentSpeed(0) {}

// Geschwindigkeit setzen
void Motor::setSpeed(int fd, int motorReg, int speed) {
    currentSpeed = speed;
    wiringPiI2CWriteReg8(fd, motorReg, speed);
    std::cout << "Motor " << id << " auf Geschwindigkeit " << speed << " gesetzt." << std::endl;
}

// Geschwindigkeit abfragen
int Motor::getSpeed() const {
    return currentSpeed;
}