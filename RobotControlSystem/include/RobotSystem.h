#ifndef ROBOTSYSTEM_H
#define ROBOTSYSTEM_H

#include "NavigationSystem.h"

// Die RobotSystem-Klasse verwaltet das gesamte Robotersystem
class RobotSystem {
private:
    MotorController motorController;        // MotorController zur Verwaltung der Motoren
    NavigationSystem navigationSystem;      // NavigationSystem für Bewegungslogik

public:
    // Konstruktor: Initialisiert MotorController und NavigationSystem
    RobotSystem();

    // Initialisiert das Robotersystem
    void init();

    // Startet die Hauptaktionen des Roboters
    void start();

    // Stoppt den Roboter
    void stop();
};

#endif // ROBOTSYSTEM_H