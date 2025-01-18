#ifndef NAVIGATIONSYSTEM_H
#define NAVIGATIONSYSTEM_H

#include "MotorController.h"  // Sicherstellen, dass MotorController definiert ist

class NavigationSystem {
private:
    MotorController& motorController;

public:
    NavigationSystem(MotorController& controller);
    void navigateForward(int durationMs);
    void navigateBackward(int durationMs);
    void turnRight(int degrees);
    void turnLeft(int degrees);
};

#endif // NAVIGATIONSYSTEM_H