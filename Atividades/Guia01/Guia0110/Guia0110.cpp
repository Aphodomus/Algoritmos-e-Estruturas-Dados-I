/*
 Guia0110 - v0.0. - 18 / 08 / 2020
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

/*  void moveN(int steps) {
        do {
            move();
            steps = steps -1;
        } while (steps > 0);
    }
*/
    void moveN(int steps) {
        for (steps; steps > 0; steps--) {
            move();
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

       if (nbeepers() > 0) {
            putBeeper();
       }

       doPartialTask();
       turnLeft();

       turnOff();
    }
};

int main () {
    world-> create("");
    decorateWorld("Guia0110.txt");
    world-> show ();

    world-> reset();
    world-> read("Guia0110.txt");
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
Neste teste eu utilizei o "do while", fez exatamente o mesmo que os exemplos anteriores
mas a diferença se dá que o "do while" vai executar o comando no bloco pelo menos uma
vez para no final verificar se é verdadeiro ou falso.
Posteriormente utilizei o comando "for", executou os comandos normalmente porém com a
vantagem de gastar bem menos linhas de código, deixando o script mais limpo e organizado.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 18/08 esboco
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
 0.8        0.1 (OK) teste com a quantidade de marcadores 
 0.9        0.1 (OK) teste com outra forma de repeticao
 1.0        0.1 (OK) teste com outra forma de repeticao "do while"
            0.1 (OK) teste com outra forma de alternativa "for"

 */