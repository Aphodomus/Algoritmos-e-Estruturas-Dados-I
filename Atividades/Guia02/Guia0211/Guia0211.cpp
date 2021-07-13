/*
 Guia0211 - v0.11. - 19 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp"
#include "io.hpp"

void decorateWorld (const char* fileName) {
    world-> set (2, 1, VWALL);
    world-> set (3, 2, VWALL);
    world-> set (4, 3, VWALL);
    world-> set (6, 3, VWALL);
    world-> set (7, 2, VWALL);
    world-> set (8, 1, VWALL);
    world-> set (3, 1, HWALL);
    world-> set (4, 2, HWALL);
    world-> set (5, 3, HWALL);
    world-> set (6, 3, HWALL);
    world-> set (7, 2, HWALL);
    world-> set (8, 1, HWALL);
    //Colocar BEEPERs
    world -> set (7, 3, BEEPER);
    world -> set (7, 3, BEEPER);
    world -> set (7, 3, BEEPER);
    world -> set (8, 2, BEEPER);
    world -> set (8, 2, BEEPER);
    world -> set (9, 1, BEEPER);

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

    void doTask() {
        
        move();
        stepUpRight(3);
        
        moveN(1);

        stepDownRight();
        pickBeepers();
        stepDownRight();
        pickBeepers();
        stepDownRight();
        pickBeepers();

        stepUpLeft(3);

        moveN(1);

        stepDownLeft();
        putTheBeepers(3);
        stepDownLeft();
        putTheBeepers(2);
        stepDownLeft();
        putTheBeepers(1);

        move();
        East();
        turnOff();
    }
}; 

int main() {

    world -> create (""); 
    decorateWorld ("Guia0211.txt");
    world -> show ();

    world -> reset();
    world -> read("Guia0211.txt");
    world -> show();

    set_Speed(2);

    MyRobot *robot = new MyRobot();

    robot -> create (1, 1, EAST, 0, "Karel");

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