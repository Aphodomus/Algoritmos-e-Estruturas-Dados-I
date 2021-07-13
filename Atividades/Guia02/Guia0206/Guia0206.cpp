/*
 Guia0206 - v0.6. - 19 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp"
#include "io.hpp"

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

    void doTask() {
        int step = 4;

        while(step > 0) {
            doPartialTask();
            step = step -1;
        }

        turnOff();
    }

    int pickBeepers() {
        int n = 0;

        while (nextToABeeper()) {
            pickBeeper();
            n = n + 1;
        }
        return (n);
    }

    void doSquare() {
        int step = 1;
        int n = 0;

        while ( step <= 4) {
            moveN(3);
            n = pickBeepers();

            if  (n > 0) {
                sprintf(msg_txt, "Recolhidos = %d", n);
                has_Text = true;
            }
            turnRight();
            step = step + 1;
        }
        turnOff();
    }

    void execute ( int option) {
        switch (option) {
            case 0:

            break;

            case 1:
                if ( leftIsClear ()) {
                    turnLeft();
                }
            break;

            case 2:
                while( !facingSouth()) {
                    turnLeft();
                }
            break;

            case 3:
                if ( rightIsClear()) {
                    turnRight();
                }
            break;

            case 4:
                while ( !facingWest()){
                    turnLeft();
                }
            break;

            case 5:
                if ( frontIsClear()) {
                    move();
                }
            break;

            case 6:
                while( !facingEast()) {
                    turnLeft();
                }
            break;

            case 7:
                if (nextToABeeper()) {
                    pickBeeper();
                }
            break;

            case 8:
                while (!facingNorth()) {
                    turnLeft();
                }
            break;

            case 9:
                if(beepersInBag()) {
                    putBeeper();
                }
            break;

            default:
                show_Error("Error: Invalid Command.");  
        }
    }

    /*
    * moveI - Metodo para mover o robot interativamente.
    * Lista de comandos disponiveis:
    * 0 - turnOff
    * 1 - turnLeft 
    * 2 - to South
    * 3 - turnRight
    * 4 - to West
    * 5 - move 
    * 6 - to East
    * 7 - pickBeeper 
    * 8 - to North
    * 9 - putBeeper
    */

    void movel() {
        int action;

        do {
            action = IO_readint("Command ? ");
            execute(action);
        } while(action != 0);
    }
};

int main() {

    world -> create (""); 
    decorateWorld ("Guia0206.txt");
    world -> show ();

    world -> reset();
    world -> read("Guia0206.txt");
    world -> show();

    set_Speed(2);

    MyRobot *robot = new MyRobot();

    robot -> create (1, 1, NORTH, 0, "Karel");

    //robot -> doTask();

    //robot -> doSquare();

    robot -> movel();

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
 */