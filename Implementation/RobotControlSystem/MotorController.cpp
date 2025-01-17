#include <iostream>
#include <vector>
#include <wiringPiI2C.h>
#include "Motor.cpp"

// Die MotorController-Klasse verwaltet alle Motoren und ihre Steuerung
class MotorController {
private:
  std::vector<Motor> motors; // Liste der Motoren (M1, M2, M3, M4)
  int fd; // I2C-Dateideskriptor, um mit dem Motor Driver zu kommunizieren

public:
  // Konstruktor: Initialisiert die I2C-Verbindung und erstellt Motor-Objekte
  MotorController() {
    fd = wiringPiI2CSetup(0x34); // Verbindet sich mit der I2C-Adresse des Motor Drivers
    if (fd == -1) { // Überprüft, ob die Verbindung erfolgreich war
      std::cerr << "Fehler: Kann Motor Driver nicht über I2C ansprechen!" << std::endl;
      exit(1); // Beendet das Programm, wenn die Verbindung fehlschlägt
    }

    // Erstellt und speichert Motor-Objekte mit eindeutigen IDs
    motors.emplace_back("M1"); // Motor 1 hinzufügen
    motors.emplace_back("M2"); // Motor 2 hinzufügen
    motors.emplace_back("M3"); // Motor 3 hinzufügen
    motors.emplace_back("M4"); // Motor 4 hinzufügen
  }

  // Setzt die Geschwindigkeit für alle Motoren
  void setSpeed(int speed1, int speed2, int speed3, int speed4) {
    // Geschwindigkeit für jeden Motor separat setzen
    motors[0].setSpeed(fd, 0x33, speed1); // Motor 1, Register 0x33
    motors[1].setSpeed(fd, 0x34, speed2); // Motor 2, Register 0x34
    motors[2].setSpeed(fd, 0x35, speed3); // Motor 3, Register 0x35
    motors[3].setSpeed(fd, 0x36, speed4); // Motor 4, Register 0x36
  }

  // Stoppt alle Motoren, indem die Geschwindigkeit auf 0 gesetzt wird
  void stopAll() {
    setSpeed(0, 0, 0, 0); // Alle Motoren anhalten
    std::cout << "Alle Motoren gestoppt." << std::endl; // Meldung ausgeben
  }
};