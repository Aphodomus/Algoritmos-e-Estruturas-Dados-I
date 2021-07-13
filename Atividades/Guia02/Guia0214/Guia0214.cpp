/*
 Guia0214 - v0.11. - 19 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp"
#include "io.hpp"

void decorateWorld (const char* fileName) {

    world-> set (2, 3, VWALL);
    world-> set (2, 4, VWALL);
    world-> set (2, 5, VWALL);
    world-> set (2, 6, VWALL);
    world-> set (2, 7, VWALL);
    world-> set (2, 8, VWALL);

    world-> set (3, 3, VWALL);
    world-> set (3, 4, VWALL);
    world-> set (3, 5, VWALL);
    world-> set (3, 6, VWALL);
    world-> set (3, 7, VWALL);

    world-> set (4, 3, VWALL);
    world-> set (4, 4, VWALL);
    world-> set (4, 5, VWALL);
    world-> set (4, 6, VWALL);
    world-> set (4, 7, VWALL);

    world-> set (5, 3, VWALL);
    world-> set (5, 4, VWALL);
    world-> set (5, 5, VWALL);
    world-> set (5, 6, VWALL);
    world-> set (5, 7, VWALL);
    world-> set (5, 8, VWALL);

    world-> set (3, 2, HWALL);
    world-> set (3, 8, HWALL);

    world-> set (4, 2, HWALL);
   
    world-> set (5, 2, HWALL);
    world-> set (5, 8, HWALL);
    
    //Colocar BEEPERs
    world-> set (3, 3, BEEPER);
    world-> set (3, 3, BEEPER);
    world-> set (3, 3, BEEPER);
    world-> set (3, 4, BEEPER);
    world-> set (3, 4, BEEPER);
    world-> set (3, 5, BEEPER);
    world-> set (4, 3, BEEPER);
    world-> set (4, 3, BEEPER);
    world-> set (4, 3, BEEPER);
    world-> set (4, 4, BEEPER);
    world-> set (4, 4, BEEPER);
    world-> set (5, 3, BEEPER);
    world-> set (5, 3, BEEPER);
    world-> set (5, 3, BEEPER);

    world -> save (fileName);

}

class MyRobot: public Robot {

 public:

    //Virar para a direita
    void turnRight() {
        int step = 0;

        if(checkStatus()) {
            for (step = 1; step <= 3; step = step + 1) {
                turnLeft();
            }
        }
    }

    //Mover um numero X de passos
    void moveN(int steps) {
        int step = 0;

        for (step = steps; step > 0; step = step - 1) {
            move();
        }
    }

    //Virar para NORTH
    void North() {
        while ( !facingNorth()) {
            turnLeft();
        }
    }

    //Virar para SOUTH
    void South() {
        while ( !facingSouth()) {
            turnLeft();
        }
    }

    //Virar para EAST
    void East() {
        while ( !facingEast()) {
            turnLeft();
        }
    }

    //Virar para WEST
    void West() {
        while ( !facingWest()) {
            turnLeft();
        }
    }

    //Colocar um numero X de BEEPERs
    void putTheBeepers(int steps) {
        for (steps; steps > 0; steps--) {
            putBeeper();
        }
    }

    //Recordar a posição
    void recordActions (const char *fileName ) {
        std::fstream archive ( fileName, std::ios::app );

        int x = xAvenue();
        int y = yStreet();

        archive << x << "\n";
        archive << y << "\n\n";
        archive.close ( );
    }

    //Pegar BEEPERs até acabar
    int pickBeepers() {
        int n = 0;

        while (nextToABeeper()) {
            pickBeeper();
            recordActions("Tarefa0214b.txt");
            n = n + 1;
        }
        return (n);
    }

    //Mover pela muralha
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

    //Comandos principais
    void doTask() {
        move();
        North();
        moveN(8);
        East();
        moveN(2);
        South();
        move();
        MoveRightNearWall(4);
        pickBeepers();
        MoveRightNearWall(1);
        pickBeepers();
        North();
        MoveRightNearWall(9);
        pickBeepers();
        MoveRightNearWall(1);
        pickBeepers();
        North();
        MoveRightNearWall(11);
        pickBeepers();
        MoveRightNearWall(6);
        move();
        MoveRightNearWall(5);
        pickBeepers();
        MoveRightNearWall(6);
        North();
        move();
        East();
        moveN(3);
        South();
        moveN(8);
        putTheBeepers(14);
        West();
        moveN(6);
        East();
        
    }
}; 

int main() {

    world -> create (""); 
    decorateWorld ("Guia0214.txt");
    world -> show ();

    world -> reset();
    world -> read("Guia0214.txt");
    world -> show();

    set_Speed(1);

    MyRobot *robot = new MyRobot();

    robot -> create (1, 1, EAST, 0, "Karel");

    robot -> doTask();

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
 */