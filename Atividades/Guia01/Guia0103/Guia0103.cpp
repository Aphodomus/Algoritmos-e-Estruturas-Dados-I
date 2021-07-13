/*
 Guia0103 - v0.0. - 17 / 08 / 2020
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

    void doPartialTask() {
        move();
        move();
        move();
        turnLeft();
    }

    void doTask() {
       doPartialTask();
       doPartialTask();
       doPartialTask();
       doPartialTask();
       turnLeft();

       turnOff();
    }
};

int main () {
    world-> create("");
    decorateWorld("Guia0103.txt");
    world-> show ();

    world-> reset();
    world-> read("Guia0103.txt");
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
Dá para chamar uma função várias vezes dentro de outra função, como o "doTask" fez repetindo
a função "doPartialTask" várias vezes, esse processo poupa bastante código.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 17/08 esboco
---------------------------------------------- testes
Versao Teste
 0.1        0.1 (OK) teste inicial
 0.2        0.1 (OK) teste da tarefa
 0.3        0.1 (OK) teste da tarefa parcial
 */