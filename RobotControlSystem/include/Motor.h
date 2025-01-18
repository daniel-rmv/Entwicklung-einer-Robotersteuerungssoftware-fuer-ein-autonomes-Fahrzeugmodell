#ifndef MOTOR_H
#define MOTOR_H

#include <string>

class Motor {
private:
    std::string id;     // Eindeutige ID des Motors
    int currentSpeed;   // Aktuelle Geschwindigkeit des Motors in PWM

public:
    Motor(const std::string& motorId); // Konstruktor
    void setSpeed(int fd, int motorReg, int speed); // Geschwindigkeit setzen
    int getSpeed() const; // Geschwindigkeit abfragen
};

#endif