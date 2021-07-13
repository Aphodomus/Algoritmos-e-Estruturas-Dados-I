/*
 Guia0301 - v0.1. - 19 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp"
#include "io.hpp"

void decorateWorld(const char* filename) {
    world -> set (4, 4, BEEPER);

    world -> save (filename);

}

class MyRobot: public Robot {

    public:

    void turnRight() {
        int step = 0;

        if (checkStatus()) {
            for (step = 1; step <= 3; step = step + 1) {
                turnLeft();
            }
        }
    }
    
    void moveN(int steps) {
        int step = 0;

        for (step = steps; step > 0; step = step - 1) {
            move();
        }
    }
} 