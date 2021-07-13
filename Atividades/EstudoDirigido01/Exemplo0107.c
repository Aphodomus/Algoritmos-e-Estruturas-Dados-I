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
    double x = 0;
    double y = 0;
    double z = 0;

    printf("\n");
    printf("%s\n","Exemplo0107 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("\n");

    printf("%s%lf\n", "x = ", x);
    printf("%s%lf\n", "y = ", y);

    printf("Entrar com um valor real: ");
    scanf("%lf", &x);

    printf("Entrar com outro valor real: ");
    scanf("%lf", &y);

    z = pow(x,y);

    printf("%s(%lf)*(%lf) = (%lf)\n", "z = ", x, y, z);

    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin);
    getchar();
    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 2.0 e 3.0
b.) 3.0 e 2.0
c.) -3.0 e 2.0
d.) -2.0 e -3.0
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao da exponenciação de 2 valores
*/
