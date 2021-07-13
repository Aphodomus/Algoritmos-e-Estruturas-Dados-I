/*
 Guia0115 - v0.0. - 19 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matricula: 716417
*/

#include "karel.hpp"

void decorateWorld(const char *filename) {

    //Criando as Muralhas
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

    //Criando os BEEPERs
    world-> set (5, 3, BEEPER);
    world-> set (5, 3, BEEPER);
    world-> set (5, 3, BEEPER);
    world-> set (5, 3, BEEPER);
    world-> set (5, 3, BEEPER);
    world-> set (5, 3, BEEPER);

    //Salvando o Mundo
    world->save(filename);
}

class MyRobot : public Robot
{

public:
    //Virar para a Direita
    void turnRight() {
        if (checkStatus()) {
            turnLeft();
            turnLeft();
            turnLeft();
        }
    }

    //Mover uma determinada quantidade de passos
    void moveN(int steps) {
        for (steps; steps > 0; steps--) {
            move();
        }
    }

    //Pegar um determinado numero de BEEPERs
    void pickTheBeepers(int steps) {
        for (steps; steps > 0; steps--) {
            pickBeeper();
        }
    }

    //Colocar um determinado numero de BEEPERs
    void putTheBeepers(int steps) {
        for (steps; steps > 0; steps--) {
            putBeeper();
        }
    }

    //Virar a esquerda e mover 6
    void turnLeftMoveSix() {
        turnLeft();
        moveN(6);
    }

    //Fazer a tarefa
    void doTask() {

        move();
        turnLeftMoveSix();
        turnRight();
        moveN(4);
        turnRight();
        move();
        turnRight();
        move();
        turnLeft();
        moveN(3);

        pickTheBeepers(6);
        
        turnLeft();
        turnLeft();
        moveN(3);
        turnRight();
        move();
        turnLeft();
        move();
        turnLeft();
        moveN(3);

        putTheBeepers(1);

        move();
        turnLeft();
        moveN(4);

        putTheBeepers(2);

        move();
        turnLeft();
        moveN(3);

        putTheBeepers(3);

        turnRight();
        move();
        turnRight();
        moveN(4);
        turnLeft();
        turnLeft();
        
    }
};

//Codigo principal
int main() {
    world->create("");
    decorateWorld("Guia0115.txt");
    world->show();

    world->reset();
    world->read("Guia0115.txt");
    world->show();

    set_Speed(1);

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
 0.1 19/08 esboco
---------------------------------------------- testes
Versao Teste
 0.1        0.1 (OK) teste inicial
 */