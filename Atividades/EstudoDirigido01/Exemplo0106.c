/* 

  * Autor: Daniel Vitor de Oliveira Santos  
  * Matricula: 716417
  * Versao:  1.0               
  * Data: 29/08/2020

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main (int argc, char* argv []) {
    int x = 0;
    int y = 0;
    int z = 0;

    printf("\n");
    printf("%s\n","Exemplo0106 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("\n");

    printf("%s%d\n", "x = ", x);
    printf("%s%i\n", "y = ", y);

    printf("Entrar com um valor inteiro: ");
    scanf("%i", &x);

    printf("Entrar com outro valor inteiro: ");
    scanf("%i", &y);

    z = x*y;

    printf("%s(%i)*(%i) = (%i)\n", "z = ", x, y, z);

    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin);
    getchar();
    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 3 e 5
b.) -3 e 5
c.) -3 e -5
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao da multiplicação de 2 valores
*/
