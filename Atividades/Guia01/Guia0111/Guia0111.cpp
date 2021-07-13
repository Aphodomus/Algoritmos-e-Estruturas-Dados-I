/*
 Guia0111 - v0.0. - 18 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp"

void decorateWorld(const char *filename) {

    world->save(filename);
}

class MyRobot : public Robot
{

public:
    void turnRight() {
        if (checkStatus())
        {
            turnLeft();
            turnLeft();
            turnLeft();
        }
    }

    void moveN(int steps) {
        for (steps; steps > 0; steps--)
        {
            move();
        }
    }

    void doPartialTask() {
        moveN(2);
        turnLeft();
    }

    void moveTwo() {
        moveN(2);
    }

    void turnRightMoveFive() {
        turnRight();
        moveN(5);
    }

    void moveThreePutBeeper() {
        moveN(3);
        putBeeper();
    }
    void doTask() {

        doPartialTask();
        moveTwo();

        putBeeper();

        moveThreePutBeeper();

        turnRight();
        moveThreePutBeeper();

        turnRightMoveFive();

        turnRightMoveFive();
        turnLeft();
        turnLeft();

        turnOff();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia0111.txt");
    world->show();

    world->reset();
    world->read("Guia0111.txt");
    world->show();

    set_Speed(2);

    MyRobot *robot = new MyRobot();

    robot->create(1, 1, EAST, 3, "Karel");

    robot->doTask();

    world->close();

    getchar();
    return (0);
}

/*-------------------------------------------- testes
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
Tentei poupar o número de códigos dentro do "doTask", mas ainda assim acho que ficou
muito extenso.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 18/08 esboco
---------------------------------------------- testes
Versao Teste
 0.1        0.1 (OK) teste inicial dos comandos
 */