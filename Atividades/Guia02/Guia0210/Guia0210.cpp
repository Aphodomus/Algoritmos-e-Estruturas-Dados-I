/*
 Guia0210 - v0.10. - 19 / 08 / 2020
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

    void recordActions ( const char* fileName) {
        int action;
        std::ofstream archive (fileName);
        action = IO_readint("Command? ");

            while(action >= 0) {
            
                if ( 0 <= action && action <= 9) {
                    execute(action);
                    archive << action << "\n";
                }
                action = IO_readint("Command? ");
            }
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

    chars dictionary (int action) {
        static char word[80];
        strcpy(word, "");

        switch(action) {
            case 1:
                strcpy(word, "turnLeft(); ");
            break;
            
            case 2:
                strcpy(word, "faceSouth(); ");
            break;

            case 3:
                strcpy(word, "turnRight(); ");
            break;

            case 4:
                strcpy(word, "faceWest(); ");
            break;

            case 5:
                strcpy(word, "move(); ");
            break;

            case 6:
                strcpy(word, "faceEast(); ");
            break;

            case 7:
                strcpy(word, "pickBeeper(); ");
            break;

            case 8:
                strcpy(word, "faceNorth(); ");
            break;

            case 9:
                strcpy(word, "putBeeper(); ");
            break;

            default:
                show_Error("Error: Invalid Command.");
        }
        return(&(word[0]));
    }

    void translateActions(const char* fileName) {
        int action;
        std::ifstream archive (fileName);
        archive >> action;
        
        while(!archive.eof()) {
            IO_print(dictionary(action));
            getchar();
            execute(action);
            archive >> action;
        }
        archive.close();
    }

    void appendActions (const char* fileName) {
        int action;
        std::fstream archive (fileName, std::ios::app);

        do {
            action = IO_readint("Command? ");
            
            if( 0 <= action && action <= 9) {
                execute(action);
                archive << action;
            }
        } while (action != 0);
        archive.close();
    }
}; 

int main() {

    world -> create (""); 
    decorateWorld ("Guia0210.txt");
    world -> show ();

    world -> reset();
    world -> read("Guia0210.txt");
    world -> show();

    set_Speed(2);

    MyRobot *robot = new MyRobot();

    robot -> create (1, 1, NORTH, 0, "Karel");

    //robot -> doTask();
    
    //robot -> doSquare();

    robot -> recordActions("Tarefa0210.txt");

    robot -> translateActions("Tarefa0210.txt");

    show_Text("Pause on recording");

    robot -> appendActions("Tarefa0210.txt");

    robot -> playActions("Tarefa0210.txt");

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
 0.7        0.1     (OK) teste de recordar acoes feitas
 0.8        0.1     (OK) teste de fazer as acoes recordadas
 0.9        0.1     (OK) teste de digitar a acao recordada
 0.10       0.1     (OK) teste apprendactions
 */