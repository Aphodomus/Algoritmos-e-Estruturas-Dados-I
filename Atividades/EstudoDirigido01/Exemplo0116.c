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
    double x, A, H, P = 0;

    printf("\n");
    printf("%s\n","Exemplo0116 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("%s\n","Matricula: 716417");
    printf("\n");

    printf("Quanto vale o lado do triangulo equilatero: ");
    scanf("%lf", &x);

    H = (x*sqrt(3))/2;
    A = (pow(x, 2)*sqrt(3))/4;
    P = x*3;

    printf("A altura do triangulo equilatero -> %lf\n", H);
    printf("A area do triangulo equilatero -> %lf\n", A);
    printf("O perimetro do triangulo equilatero -> %lf\n", P);


    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin);
    getchar();

    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 6
b.) 5.8
c.) 12.3
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao das previsões
*/
