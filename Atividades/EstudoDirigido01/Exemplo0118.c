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
    double c, a, l, V = 0;

    printf("\n");
    printf("%s\n","Exemplo0118 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("%s\n","Matricula: 716417");
    printf("\n");

    printf("Paralelepipedo\n");
    printf("Quanto vale o comprimento: ");
    scanf("%lf", &c);
    printf("Quanto vale a largura: ");
    scanf("%lf", &l);
    printf("Quanto vale a altura: ");
    scanf("%lf", &a);

    V = (c/6)*(a/6)*(l/6);

    printf("Supondo que as dimensoes sejam 6 vezes menores...\n");
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
