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
    char x [] = "abc";

    printf("\n");
    printf("%s\n","Exemplo0105 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("\n");

    printf("%s%s\n", "x = ", x);

    printf("Entrar com uma cadeira de caracteres: ");
    scanf("%s", x);
    printf("%s%s\n", "x = ", x);

    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin);
    getchar();
    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) def
b.) d e f
c.) d_e_f
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao da cadeia de caractere
*/
