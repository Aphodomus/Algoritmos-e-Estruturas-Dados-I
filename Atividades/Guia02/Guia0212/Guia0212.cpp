/*
 Guia0212 - v0.11. - 19 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp"
#include "io.hpp"

void decorateWorld (const char* fileName) {

    world-> set (2, 2, VWALL);
    world-> set (2, 3, VWALL);
    world-> set (2, 4, VWALL);
    world-> set (2, 6, VWALL);
    world-> set (2, 7, VWALL);
    world-> set (2, 8, VWALL);
    world-> set (4, 2, VWALL);
    world-> set (4, 3, VWALL);
    world-> set (4, 5, VWALL);
    world-> set (4, 7, VWALL);
    world-> set (4, 8, VWALL);
    world-> set (5, 2, VWALL);
    world-> set (5, 3, VWALL);
    world-> set (5, 5, VWALL);
    world-> set (5, 7, VWALL);
    world-> set (5, 8, VWALL);
    world-> set (7, 2, VWALL);
    world-> set (7, 3, VWALL);
    world-> set (7, 4, VWALL);
    world-> set (7, 6, VWALL);
    world-> set (7, 7, VWALL);
    world-> set (7, 8, VWALL);

    world-> set (3, 1, HWALL);
    world-> set (3, 4, HWALL);
    world-> set (3, 5, HWALL);
    world-> set (3, 8, HWALL);
    world-> set (4, 1, HWALL);
    world-> set (4, 4, HWALL);
    world-> set (4, 5, HWALL);
    world-> set (4, 8, HWALL);
    world-> set (5, 3, HWALL);
    world-> set (5, 6, HWALL);
    world-> set (6, 1, HWALL);
    world-> set (6, 4, HWALL);
    world-> set (6, 5, HWALL);
    world-> set (6, 8, HWALL);
    world-> set (7, 1, HWALL);
    world-> set (7, 4, HWALL);
    world-> set (7, 5, HWALL);
    world-> set (7, 8, HWALL);
    
    //Colocar BEEPERs
    world-> set (4, 5, BEEPER);
    world-> set (5, 3, BEEPER);
    world-> set (5, 7, BEEPER);
    world-> set (6, 5, BEEPER);

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

    void North() {
        while ( !facingNorth()) {
            turnLeft();
        }
    }

    void South() {
        while ( !facingSouth()) {
            turnLeft();
        }
    }

    void East() {
        while ( !facingEast()) {
            turnLeft();
        }
    }

    void West() {
        while ( !facingWest()) {
            turnLeft();
        }
    }

    void doPartialTask() {
        moveN(3);
        turnLeft();
    }

    void stepUpRight(int steps) {
        for (steps; steps > 0; steps--) {
            North();
            move();
            East();
            move();
        }
    }

    void stepDownRight() {
            move();
            South();
            move();
            East();
    }

    void stepUpLeft(int steps) {
        for(steps; steps > 0; steps--) {
            North();
            move();
            West();
            move();
        }
    }

    void stepDownLeft() {
        move();
        South();
        move();
        West();
    }

    void putTheBeepers(int steps) {
        for (steps; steps > 0; steps--) {
            putBeeper();
        }
    }

    int pickBeepers() {
        int n = 0;

        while (nextToABeeper()) {
            pickBeeper();
            n = n + 1;
        }
        return (n);
    }

    void MoveRightNearWall (int steps) {
        for (steps; steps > 0; steps--) {
            if (rightIsClear()) {
                turnRight();
                move();
            } else {
                while (!frontIsClear()) {
                    turnLeft();
                }
                move();
            }
        }
    }

    void doTask() {
        MoveRightNearWall(9);
        pickBeeper();

        MoveRightNearWall(11);
        pickBeeper();

        MoveRightNearWall(11);
        pickBeeper();

        MoveRightNearWall(11);
        pickBeeper();
        
        MoveRightNearWall(5);
        move();
        turnLeft();
        turnLeft();
    }
}; 

int main() {

    world -> create (""); 
    decorateWorld ("Guia0212.txt");
    world -> show ();

    world -> reset();
    world -> read("Guia0212.txt");
    world -> show();

    set_Speed(1);

    MyRobot *robot = new MyRobot();

    robot -> create (5, 1, SOUTH, 0, "Karel");

    robot -> doTask();
    
    //robot -> doSquare();

    world -> close();

    getchar();
    return(0);
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
 0.1        0.1     (OK) teste inicial
 0.2        0.1     (OK) teste da repeticao para virar a direita
 0.3        0.1     (OK) teste da repeticao para percorrer um quadrado
 0.4        0.1     (OK) teste da funcao "pickBeepers" no "doSquare"
 0.5        0.1     (OK) teste mensagem recolhidos
 0.6        0.1     (OK) teste da movimentação interativa
 0.7        0.1     (OK) teste de recordar acoes feitas
 0.8        0.1     (OK) teste de fazer as acoes recordadas
 0.9        0.1     (OK) teste de digitar a acao recordada
 0.10       0.1     (OK) teste apprendactions
 0.11       0.1     (OK) teste subindo as escadas
 */