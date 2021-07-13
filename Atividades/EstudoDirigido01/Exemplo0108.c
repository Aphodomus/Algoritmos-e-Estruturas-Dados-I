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
    char x [] = "abc";
    char y [] = "def";
    char z [80];
    strcpy(z, "");

    printf("\n");
    printf("%s\n","Exemplo0108 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("\n");

    printf("%s%s\n", "x = ", x);
    printf("%s%s\n", "y = ", y);

    printf("Entrar com caracteres: ");
    scanf("%s", &x);

    printf("Entrar com outros caracteres: ");
    scanf("%s", &y);

    strcpy(z, x);
    strcpy(z, y);

    printf("%s[%s]*[%s] = [%s]\n", "z = ", x, y, z);

    strcpy(z, strcat(strdup(x), y));

    printf("%s[%s]*[%s] = [%s]\n", "z = ", x, y, z);

    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin);
    getchar();
    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 12 e 24
b.) ab e cd
c.) a e bc
d.) ab e c
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao da concatenação de 2 strings
*/
