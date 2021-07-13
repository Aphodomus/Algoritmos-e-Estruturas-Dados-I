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
    double x, V = 0;

    printf("\n");
    printf("%s\n","Exemplo0117 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("%s\n","Matricula: 716417");
    printf("\n");

    printf("Quanto vale o lado do cubo: ");
    scanf("%lf", &x);

    V = pow((x*5), 3);

    printf("Supondo que o lado seja 5 vezes maior...\n");
    printf("O volume do cubo seria -> %lf\n", V);

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
b.) 5.8
c.) 7.9
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao das previsões
*/
