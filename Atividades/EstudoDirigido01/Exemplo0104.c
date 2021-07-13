/* 

  * Autor: Daniel Vitor de Oliveira Santos  
  * Matricula: 716417
  * Versao:  1.0               
  * Data: 29/08/2020

*/

#include <stdio.h>
#include <stdbool.h>

int main (int argc, char* argv []) {
    bool x = false;

    printf("\n");
    printf("%s\n","Exemplo0104 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("\n");

    printf("%s%d\n", "x = ", x);

    printf("Entrar com um valor logico: ");
    scanf("%d", &x);
    printf("%s%d\n", "x = ", x);

    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin);
    getchar();
    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 1
b.) 0
c.) true
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao de valor logico
*/
