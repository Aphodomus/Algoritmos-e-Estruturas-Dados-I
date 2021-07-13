/* 

  * Autor: Daniel Vitor de Oliveira Santos  
  * Matricula: 716417
  * Versao:  1.0               
  * Data: 29/08/2020

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main (int argc, char* argv []) {
    int x, y, A = 0;
    double z = 0;

    printf("\n");
    printf("%s\n","Exemplo0113 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("%s\n","Matricula: 716417");
    printf("\n");

    printf("Quanto vale o lado do retangulo: ");
    scanf("%i", &x);
    printf("Quanto vale o outro lado do retangulo: ");
    scanf("%i", &y);

    A = x*y;
    z = A/4;

    printf("A area do retangulo vale -> %i\n", A);
    printf("Um quarto da area do retangulo vale -> %lf\n", z);

    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin);
    getchar();

    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) 6
c.) 13
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao das previsões
*/
