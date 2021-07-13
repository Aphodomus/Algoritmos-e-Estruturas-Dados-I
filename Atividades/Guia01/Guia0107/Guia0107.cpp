/*
 Guia0107 - v0.0. - 17 / 08 / 2020
 Nome: Daniel Vitor de Oliveira Santos
 Matrícula: 716417
*/

#include "karel.hpp" 

void decorateWorld(const char* filename) {
    world-> set (4, 4, BEEPER);
    
    world-> save (filename);
}

class MyRobot: public Robot {
    
    public:
    
    void turnRight() {
        if (checkStatus ()) {
            turnLeft();
            turnLeft();
            turnLeft();
        }
    }

    void moveN(int steps) {
        if (steps > 0) {
            move();
            moveN(steps -1);
        }
    }

    void doPartialTask() {
        moveN(3);
        turnLeft();
    }

    void doTask() {

       doPartialTask();
       doPartialTask();

       if (nextToABeeper()) {
            pickBeeper();
       }

       doPartialTask();

       if (beepersInBag()) {
            putBeeper();
       }

       doPartialTask();
       turnLeft();

       turnOff();
    }
};

int main () {
    world-> create("");
    decorateWorld("Guia0107.txt");
    world-> show ();

    world-> reset();
    world-> read("Guia0107.txt");
    world-> show();

    set_Speed(3);

    MyRobot*robot= new MyRobot();

    robot-> create (1, 1, EAST, 0, "Karel");

    robot-> doTask();

    world-> close();

    getchar();
    return (0);
}

/*-------------------------------------------- testes
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
Novamente com o uso do "if" deu para notar que ele adiciona uma condição, e caso ela
seja verdadeira, ele executa o bloco, caso não seja verdadeira ele ignora o comando
dentro do bloco e segue o fluxo do script normalmente.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 17/08 esboco
---------------------------------------------- testes
Versao Teste
 0.1        0.1 (OK) teste inicial
 0.2        0.1 (OK) teste da tarefa
 0.3        0.1 (OK) teste da tarefa parcial
 0.4        0.1 (OK) teste do apanhar marcador
 0.5        0.1 (OK) teste do colocar marcador
 0.6        0.1 (OK) teste de repetição do movimento com "if"
 0.7        0.1 (OK) teste com marcador na posicao (4,4)
            0.2 (OK) teste sem marcador na posicao (4,4)
 */