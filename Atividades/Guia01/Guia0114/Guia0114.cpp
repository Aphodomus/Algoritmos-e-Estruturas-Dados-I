/*
 Guia0114 - v0.0. - 18 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp"

void decorateWorld(const char *filename) {

    world-> set (5, 3, VWALL);
    world-> set (5, 4, VWALL);
    world-> set (5, 5, VWALL);
    
    world-> set (3, 6, HWALL);
    world-> set (4, 6, HWALL);
    world-> set (5, 6, HWALL);

    world-> set (3, 2, HWALL);
    world-> set (4, 2, HWALL);
    world-> set (5, 2, HWALL);

    world-> set (2, 3, VWALL);
    world-> set (2, 4, VWALL);
    world-> set (2, 5, VWALL);
    world-> set (2, 6, VWALL);

    world-> set (2, 3, BEEPER);
    world-> set (3, 7, BEEPER);
    world-> set (5, 2, BEEPER);

    world->save(filename);
}

class MyRobot : public Robot
{

public:
    void turnRight() {
        if (checkStatus()) {
            turnLeft();
            turnLeft();
            turnLeft();
        }
    }

    void moveN(int steps) {
        for (steps; steps > 0; steps--) {
            move();
        }
    }

    void turnRightMoveFive() {
        turnRight();
        moveN(5);
    }

    void moveThreePickBeeper() {
        moveN(3);
        pickBeeper();
    }

      void moveThree() {
        moveN(3);
    }

    void twoTurnLeft() {
        turnLeft();
        turnLeft();
    }

    void turnLeftMoveFour() {
        moveN(4);
        turnLeft();
    }
    void turnRightMoveFour() {
        moveN(4);
        turnRight();
    }

    void moveTwo() {
        moveN(2);
    }

    void movePutBeeper() {
        move();
        pickBeeper();
    }

    void doTask() {

        move();
        turnLeft();
        move();
        movePutBeeper();
        turnRightMoveFour();
        movePutBeeper();
        moveThree();
        turnRightMoveFive();
        turnRight();
        movePutBeeper();
        twoTurnLeft();
        move();
        turnLeft();
        turnLeftMoveFour();
        moveThree();
        turnLeft();
        moveThree();
        do {
            putBeeper();
        } while (beepersInBag() > 0);
        turnLeft();
        moveTwo();
        turnLeft();
        moveThree();
        turnRight();
        move();
        turnRightMoveFive();
        turnRightMoveFive();
        twoTurnLeft();
        
        turnOff();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia0114.txt");
    world->show();

    world->reset();
    world->read("Guia0114.txt");
    world->show();

    set_Speed(2);

    MyRobot *robot = new MyRobot();

    robot->create(1, 1, EAST, 0, "Karel");

    robot->doTask();

    world->close();

    getchar();
    return (0);
}

/*-------------------------------------------- testes
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 18/08 esboco
---------------------------------------------- testes
Versao Teste
 0.1        0.1 (OK) teste inicial dos comandos
 */