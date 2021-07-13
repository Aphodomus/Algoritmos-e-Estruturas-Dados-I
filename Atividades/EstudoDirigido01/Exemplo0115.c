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
    double x, y, A, A_h3 = 0;

    printf("\n");
    printf("%s\n","Exemplo0115 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("%s\n","Matricula: 716417");
    printf("\n");

    printf("Quanto vale a base do triangulo: ");
    scanf("%lf", &x);
    printf("Quanto vale a altura do triangulo: ");
    scanf("%lf", &y);

    A = (x*y)/2;
    A_h3 = ((x*3)*y)/2;

    printf("Supondo que o triangulo tenha o triplo da altura...\n");
    printf("A area do triangulo normal -> %lf\n", A);
    printf("A area do triangulo com o triplo de altura -> %lf\n", A_h3);

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
