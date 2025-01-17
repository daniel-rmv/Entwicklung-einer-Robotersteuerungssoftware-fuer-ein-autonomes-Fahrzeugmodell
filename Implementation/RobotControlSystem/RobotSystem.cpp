#include <iostream>
#include "NavigationSystem.cpp"

// Die RobotSystem-Klasse verwaltet das Gesamtsystem des Roboters
class RobotSystem {
private:
    MotorController motorController;        // MotorController zur Verwaltung aller Motoren
    NavigationSystem navigationSystem;      // NavigationSystem für Bewegungslogik

public:
    // Konstruktor: Initialisiert MotorController und NavigationSystem
    RobotSystem() : motorController(), navigationSystem(motorController) {}

    // Initialisierungsmethode: Führt allgemeine Startaufgaben aus
    void init() {
        std::cout << "RobotSystem: Initialisiere..." << std::endl;
    }

    // Startmethode: Führt die Hauptaktionen des Roboters aus
    void start() {
        std::cout << "RobotSystem: Starte..." << std::endl;

        // Geradeaus & rückwärts fahren mit Feintuning für je 25 Sekunden
        //navigationSystem.navigateForward(25000);
        //navigationSystem.navigateBackward(25000);
        navigationSystem.turnLeft(90);

        std::cout << "RobotSystem: Alle Aktionen abgeschlossen." << std::endl;
    }
};

// Main-Methode: Einstiegspunkt des Programms
int main() {
    RobotSystem robotSystem; // Erstelle ein RobotSystem-Objekt
    robotSystem.init();      // Initialisiere das Robotersystem
    robotSystem.start();     // Starte das Robotersystem
    return 0;
}