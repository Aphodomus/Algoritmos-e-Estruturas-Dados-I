/* 

  * Autor: Daniel Vitor de Oliveira Santos  
  * Matricula: 716417
  * Versao:  1.0               
  * Data: 29/08/2020

*/

#include <stdio.h>

int main (int argc, char* argv []) {
    double x = 0.0;

    printf("\n");
    printf("%s\n","Exemplo0102 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("\n");

    printf("%s%lf\n", "x = ", x);

    printf("Entrar com um valor real: ");
    scanf("%lf", &x);
    printf("%s%lf\n", "x = ", x);

    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin);
    getchar();
    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0.5
b.) -0.5
c.) 1.23456789
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao de real
*/
