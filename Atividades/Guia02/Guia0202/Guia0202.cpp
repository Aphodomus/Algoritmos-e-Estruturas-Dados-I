/*
 Guia0202 - v0.2. - 19 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp"

void decorateWorld (const char* fileName) {

    world -> set (4, 4, BEEPER);

    world -> save (fileName);

}

class MyRobot: public Robot {

 public:

    void turnRight() {
        int step = 0;

        if(checkStatus()) {
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

    void doPartialTask() {
        moveN(3);
        turnLeft();
    }
    void doSquare() {
        int step = 4;

        while ( step > 0) {
            moveN(3);
            turnRight();
            step = step -1;
        }
        turnOff();
    }

    void doTask() {
        int step = 4;

        while(step > 0) {
            doPartialTask();
            step = step -1;
        }

        turnOff();
    }
};

int main() {

    world -> create (""); 
    decorateWorld ("Guia0202.txt");
    world -> show ();

    world -> reset();
    world -> read("Guia0202.txt");
    world -> show();

    set_Speed(2);

    MyRobot *robot = new MyRobot();

    robot -> create (1, 1, NORTH, 0, "Karel");

    //robot -> doTask();

    robot -> doSquare();

    world -> close();

    getchar();
    return(0);
}

/*-------------------------------------------- testes
---------------------------------------------- documentacao complementar
Foi adicionado a funcao "doSquare"
Posição inicial mudada de EAST para NORTH
Funcao "doTask" comentada
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 19/08 esboco
---------------------------------------------- testes
Versao Teste
 0.1        0.1     (OK) teste inicial
 0.2        0.1     (OK) teste da repeticao para virar a direita
 */