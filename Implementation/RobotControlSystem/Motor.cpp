#include <iostream>
#include <wiringPiI2C.h>
#include <string>

// Die Motor-Klasse repräsentiert einen einzelnen Motor und seine Eigenschaften
class Motor {
private:
    std::string id;     // Eindeutige ID des Motors
    int currentSpeed;   // Aktuelle Geschwindigkeit des Motors in PWM

public:
    // Konstruktor: Initialisiert den Motor mit einer ID und setzt die Geschwindigkeit auf 0 PWM
    Motor(const std::string& motorId) : id(motorId), currentSpeed(0) {}

    // Methode: Setzt die Geschwindigkeit des Motors und schreibt sie in das entsprechende I2C-Register
    void setSpeed(int fd, int motorReg, int speed) {
        currentSpeed = speed; // Aktuelle Geschwindigkeit aktualisieren
        wiringPiI2CWriteReg8(fd, motorReg, speed); // Geschwindigkeit ins I2C-Register schreiben
        std::cout << "Motor " << id << " auf Geschwindigkeit " << speed << " gesetzt." << std::endl;
    }

    // Gibt die aktuelle Geschwindigkeit des Motors zurück
    int getSpeed() const {
        return currentSpeed;
    }
};