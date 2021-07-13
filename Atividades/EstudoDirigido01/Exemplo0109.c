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
    int x = 0;
    double y = 3.5;
    char z = 'A';
    bool w = false;
    char s[80];

    printf("\n");
    printf("%s\n","Exemplo0109 - Programa = v1.0");
    printf("%s\n","Autor: Daniel Vitor de Oliveira Santos");
    printf("\n");

    printf("01. %s%d\n", "x = ", x);
    printf("02. %s%lf\n", "y = ", y);
    printf("03. %s%c\n", "z = ", z);



    x = (int) z;
    printf("04. %s%d -> %c\n", "x = ", x, z);

    x = (int) y;
    printf("05. %s%d -> %lf\n", "x = ", x, y);

    x = 97;
    z = (char) x;
    printf("06. %s%c -> %d\n", "z = ", z, x);

    x = (int) '0';
    z = (char) x;
    printf("07. %s%c -> %d\n", "z = ", z, x);

    x = w;
    printf("08. %s%d -> %d\n", "x = ", x, w);

    w = true;
    x = w;
    printf("09. %s%d -> %d\n", "x = ", x, w);

    x = (w == false);
    printf("10. %s%d -> %d\n", "x = ", x, w);

    x = !(w == false);
    printf("11. %s%d -> %d\n", "x = ", x, w);

    x = (w != false);
    printf("12. %s%d -> %d\n", "x = ", x, w);

    w = (x < y);
    printf ( "13. %s%d < %lf = %d\n" , "w = ", x, y, w );

    w = (x <= y);
    printf ( "14. %s%d <= %lf = %d\n" , "w = ", x, y, w );

    w = (y > x);
    printf ( "15. %s%lf > %d = %d\n" , "w = ", y, x, w );

    w = (y >= x);
    printf ( "16. %s%lf >= %d = %d\n" , "w = ", y, x, w );

    x = 4;
    w = (x % 2 == 0);
    printf ( "17. %s%(%d) ? %d\n" , "e par ", x, w );

    x = 4;
    w = (x % 2 != 0);
    printf ( "18. %s%(%d) ? %d\n" , "e impar ", x, w );

    z = 'x';
    w = ('a'<=z && z<='z');
    printf ( "19. %s%(%c) ? %d\n" , "e minuscula ", z, w );

    z = 'x';
    w = ('A'<=z && z<='Z');
    printf ( "20. %s%(%c) ? %d\n" , "e maiuscula ", z, w ); //Atencao !!!

    z = 'X';
    w = ( ! ('a'<=z && z<='z' ) );
    printf ( "19. %s%(%c) ? %d\n" , "nao e minuscula ", z, w );

    z = 'x';
    w = ('A'<=z && z<='Z');
    printf ( "20. %s%(%c) ? %d\n" , "e maiuscula ", z, w );

    z = 'X';
    w = ( (z < 'A') || ('Z' < z) );

    printf ( "19. %s%(%c) ? %d\n" , "nao e maiuscula ", z, w ); //Atencao !!!

    z = '0';
    w = ('0'==z || '1'==z);
    printf ( "21. %s%(%c) ? %d\n" , "e 0 ou 1 ", z, w ); //Atencao !!!

    strcpy ( s, "palavra" );
    printf ( "22. palavra = %s\n", s );

    w = (strcmp ( "zero", s ) != 0);
    printf ( "23. palavra == %s ? %d\n", s, w );

    strcpy ( s, "um dois" );
    printf ( "24. palavras = %s\n", s );

    w = (strcmp ( "zero", s ) != 0);
    printf ( "25. palavra == %s ? %d\n", s, w );



    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin);
    getchar();
    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao
*/
