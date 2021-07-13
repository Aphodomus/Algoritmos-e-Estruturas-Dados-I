/*
 Guia0102 - v0.0. - 17 / 08 / 2020
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

    void doTask() {
        move();
        move();
        turnLeft();
        move();
        move();
        turnLeft();
        move();
        move();
        turnLeft();
        move();
        move();
        turnLeft();
        turnLeft();
        
        turnOff();
    }
};

int main () {
    world-> create("");
    decorateWorld("Guia0102.txt");
    world-> show ();

    world-> reset();
    world-> read("Guia0102.txt");
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
Fez o mesmo processo do teste anterior, porém dessa vez com os comandos na função doTask
que eu posso chamar no meu programa principal "main".
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 17/08 esboco
---------------------------------------------- testes
Versao Teste
 0.1        0.1 (OK) teste inicial
 0.2        0.1 (OK) teste da tarefa
 */