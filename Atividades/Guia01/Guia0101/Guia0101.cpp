/*
 Guia0101 - v0.0. - __ / __ / _____
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
};

int main () {
    world-> create("");
    decorateWorld("Guia0101.txt");
    world-> show ();

    world-> reset();
    world-> read("Guia0101.txt");
    world-> show();

    set_Speed(3);

    MyRobot*robot= new MyRobot();

    robot-> create (1, 1, EAST, 0, "Karel");

    robot-> move();
    robot-> move();
    robot-> turnLeft();
    robot-> move();
    robot-> move();
    robot-> turnLeft();
    robot-> move();
    robot-> move();
    robot-> turnLeft();
    robot-> move();
    robot-> move();
    robot-> turnLeft();
    robot-> turnLeft();
    robot-> turnOff();

    world-> close();

    getchar();
    return (0);
}

/*-------------------------------------------- testes
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 17/08 esboco
---------------------------------------------- testes
Versao Teste
 0.1        0.1 (OK) teste inicial
 */