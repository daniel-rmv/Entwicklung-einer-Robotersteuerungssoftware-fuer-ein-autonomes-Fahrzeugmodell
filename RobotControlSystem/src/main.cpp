/*
 * Copyright (c) 2025 Daniel Würmli
 *
 * Licensed under the MIT License. See LICENSE file in the project root for full license information.
 */

#include "RobotSystem.h"

// Hauptprogramm: Einstiegspunkt des Programms
int main() {
    // Erstelle ein RobotSystem-Objekt
    RobotSystem robotSystem;

    // Initialisiere das Robotersystem
    robotSystem.init();

    // Starte das Robotersystem
    robotSystem.start();

    // Stoppe das Robotersystem
    robotSystem.stop();

    // Beende das Programm
    return 0;
}