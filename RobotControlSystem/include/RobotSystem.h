#ifndef ROBOTSYSTEM_H
#define ROBOTSYSTEM_H

#include "NavigationSystem.h"
#include "MotorController.h"

class RobotSystem {
private:
    MotorController motorController;
    NavigationSystem navigationSystem;

public:
    RobotSystem();
    void init();
    void start();
};

#endif