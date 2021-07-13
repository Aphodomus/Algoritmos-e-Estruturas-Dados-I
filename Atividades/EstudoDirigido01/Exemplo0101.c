/* 

  * Autor: Daniel Vitor de Oliveira Santos  
  * Matricula: 716417
  * Versao:  1.0               
  * Data: 29/08/2020

*/

#include <stdio.h>
#include "io.h"

int main (int argc, char* argv []) {
    int x = 0;
    
    printf("\n");
    printf("\n","Exemplo0101 - Programa = v1.0");
    printf("\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("\n");

    printf("%s%d\n", "x = ", x);

    printf("Entrar com um valor inteiro: ");
    scanf("%d", &x);
    printf("%s%i\n", "x = ", x);

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
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
 0.1 29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao de inteiro
*/
