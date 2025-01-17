#include <iostream>
#include <unistd.h>
#include "MotorController.cpp"

// Die NavigationSystem-Klasse verwaltet die Bewegung des Roboters
class NavigationSystem {
private:
    MotorController& motorController; // Referenz auf den MotorController, um Motoren zu steuern

public:
    // Konstruktor: Verbindet NavigationSystem mit dem MotorController
    NavigationSystem(MotorController& controller) : motorController(controller) {}

    // Methode: Fährt den Roboter geradeaus mit Feintuning
    void navigateForward(int durationMs) {
        std::cout << "NavigationSystem: Starte geradeaus fahren mit Feintuning..." << std::endl;

        // Berechnung der Anzahl von Schleifendurchläufen basierend auf der Gesamtzeit und 10ms pro Iteration
        int iterations = durationMs / 10;
        for (int i = 0; i < iterations; i++) { // Schleife für die Bewegung
            if (i % 2 == 0) {
                motorController.setSpeed(-10, 10, 10, -10); // Alle Motoren auf Standardgeschwindigkeit setzen
            } else {
                motorController.setSpeed(-10, 10, 10, -11); // Minimal andere Geschwindigkeit für Motor 4, da der Roboter sonst mit einer Tendenz nach rechts fahren würde
                // M4 = rechte, vordere Motor
            }
            usleep(10000); // Warten für 10 ms
        }

        motorController.stopAll(); // Stoppt alle Motoren nach Abschluss der Bewegung
        std::cout << "NavigationSystem: Geradeaus fahren beendet." << std::endl;
    }

    // Methode: Fährt den Roboter rückwärts mit Feintuning
    void navigateBackward(int durationMs) {
        std::cout << "NavigationSystem: Starte rückwärts fahren mit Feintunig." << std::endl;

        // Berechnung der Anzahl von Schleifendurchläufen basierend auf der Gesamtzeit und 10ms pro Iteration
        int iterations = durationMs / 10;
        for (int i = 0; i < iterations; i++) { // Schleife für die Bewegung
            if (i % 2 == 0) {
                motorController.setSpeed(10, -10, -10, 10); // Alle Motoren auf Standardgeschwindigkeit setzen
            } else {
                motorController.setSpeed(10, -10, -10, 9); // Minimal andere Geschwindigkeit für Motor 4, da der Roboter sonst mit einer Tendenz nach links fahren würde
                // M4 = rechte, vordere Motor
            }
            usleep(10000); // Warten für 10 ms
        }

        motorController.stopAll(); // Stoppt alle Motoren nach Abschluss der Bewegung
        std::cout << "NavigationSystem: Rückwärts fahren beendet." << std::endl;
    }

    // Methode: Dreht der Roboter nach rechts um die gewünschte Anzahl Grad
    void turnRight(int degrees) {
        std::cout << "NavigationSystem: Starte rechts Drehung." << std::endl;

        // Berechnung der Anzahl von Schleifendurchläufen basierend auf der Anzahl Grad
        int iterations = degrees * 29;
        for (int i = 0; i < iterations; i++) { // Schleife für die Drehung
            motorController.setSpeed(-10, 10, -10, 10); // Alle Motoren auf Drehgeschwindigkeit setzen
        }

        motorController.stopAll(); // Stoppt alle Motoren nach Abschluss der Bewegung

        for (int i = 0; i < 1; i++) {
        motorController.setSpeed(-5, 5, -5, 5); // Alle Motoren auf Drehgeschwindigkeit setzen -> langsam für Perfektion
        }

        motorController.stopAll(); // Stoppt alle Motoren nach Abschluss der Bewegung
        std::cout << "NavigationSystem: rechts Drehung beendet." << std::endl;
    }

    // Methode: Dreht der Roboter nach rechts um die gewünschte Anzahl Grad
    void turnLeft(int degrees) {
        std::cout << "NavigationSystem: Starte links Drehung." << std::endl;

        // Berechnung der Anzahl von Schleifendurchläufen basierend auf der Anzahl Grad
        int iterations = degrees * 29;
        for (int i = 0; i < iterations; i++) { // Schleife für die Drehung
            motorController.setSpeed(10, -10, 10, -10); // Alle Motoren auf Drehgeschwindigkeit setzen
        }

        motorController.stopAll(); // Stoppt alle Motoren nach Abschluss der Bewegung

        for (int i = 0; i < 1; i++) {
            motorController.setSpeed(5, -5, 5, -5); // Alle Motoren auf Drehgeschwindigkeit setzen -> langsam für Perfektion
        }

        motorController.stopAll(); // Stoppt alle Motoren nach Abschluss der Bewegung
        std::cout << "NavigationSystem: links Drehung beendet." << std::endl;
    }
};