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
    int x, y, A, P = 0;

    printf("\n");
    printf("%s\n","Exemplo0114 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("%s\n","Matricula: 716417");
    printf("\n");

    printf("Quanto vale o lado do retangulo: ");
    scanf("%i", &x);
    printf("Quanto vale o outro lado do retangulo: ");
    scanf("%i", &y);

    A = (x*2)*(y*2);
    P = (x*2)*2 + (y*2)*2;

    printf("Supondo que o retangulo tenho o dobro do tamanho dos lados...\n");
    printf("A area do retangulo vale -> %i\n", A);
    printf("O perimetro do retangulo vale -> %i\n", P);

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
