/*
 Guia0215 - v0.11. - 19 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp"
#include "io.hpp"

void decorateWorld (const char* fileName) {

    //Criando muralhas
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
    world-> set (4, 3, BEEPER);
    world-> set (4, 4, BEEPER);
    world-> set (4, 4, BEEPER);
    world-> set (5, 3, BEEPER);
    world-> set (5, 4, BEEPER);
    world-> set (5, 4, BEEPER);
    world-> set (5, 5, BEEPER);
    world-> set (5, 5, BEEPER);
    world-> set (5, 5, BEEPER);

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
            //recordActions("Tarefa0215.txt");
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

    void execute ( int option) {
        switch (option) {
            case 0:
                move();
            break;

            case 1:
                moveN(1);
            break;

            case 2:
                North();
            break;

            case 3:
                South();
            break;

            case 4:
                East();
            break;

            case 5:
                West();
            break;

            case 6:
                MoveRightNearWall(1);
            break;

            case 7:
                pickBeepers();
            break;

            case 8:
                putTheBeepers(1);
            break;

            case 9:
                turnOff();
            break;

            default:
                show_Error("Error: Invalid Command.");  
        }
    }

    void recordMovements ( const char* fileName) {
        int action;
        std::ofstream archive (fileName);

            do {
                action = IO_readint("Command? ");
            
                if ( 0 <= action && action <= 9) {
                    execute(action);
                    archive << action << "\n";
                }
            } while (action != 0);
            archive.close();
    }

    void playActions ( const char* fileName) {
        int action;
        std::ifstream archive (fileName);

        archive >> action;
        while (!archive.eof()) {
            IO_print(IO_toString(action));
            delay(stepDelay);
            execute(action);
            archive >> action;
        }
        archive.close();
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
        MoveRightNearWall(6);
        pickBeepers();
        MoveRightNearWall(11);
        pickBeepers();
        MoveRightNearWall(11);
        pickBeepers();
        North();
        move();
        pickBeepers();
        MoveRightNearWall(5);
        South();
        move();
        MoveRightNearWall(3);
        pickBeepers();
        North();
        MoveRightNearWall(8);
        pickBeepers();
        North();
        MoveRightNearWall(4);
        North();
        move();
        East();
        moveN(3);
        South();
        moveN(8);
        putTheBeepers(10);
        West();
        moveN(6);
        East();
    }
}; 

int main() {

    world -> create (""); 
    decorateWorld ("Guia0215.txt");
    world -> show ();

    world -> reset();
    world -> read("Guia0215.txt");
    world -> show();

    set_Speed(1);

    MyRobot *robot = new MyRobot();

    robot -> create (1, 1, EAST, 0, "Karel");

    //robot -> doTask();

    robot-> playActions("Tarefa0215.txt");

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