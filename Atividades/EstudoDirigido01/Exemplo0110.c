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
#include "io.h"

int main (int argc, char* argv []) {
    int x = 5;
    double y = 3.5;
    char z = 'A';
    bool w = true;
    chars a = IO_new_chars(STR_SIZE);
    chars b = IO_new_chars(STR_SIZE);
    chars c = IO_new_chars(STR_SIZE);

    printf("\n");
    IO_id("Exemplo0110 - Programa - v0.0");

    strcpy(a, "abc");
    strcpy(b, "def");

    c = IO_concat(a, b);
    IO_printf("\nc = [%s]+[%s]=[%s]\n", a, b, c);

    strcpy(a, "c = ");
    strcpy(c, STR_EMPTY);

    IO_printf("%s\n", IO_concat ( a, IO_toString_c (z)));
    IO_println( IO_concat ( a, IO_toString_d (x)));
    IO_println( IO_concat ( a, IO_toString_b (w)));

    strcpy ( b, STR_EMPTY );
    IO_print ( a );
    IO_print ( IO_concat ( b, IO_toString_f ( y ) ) );
    IO_print ( "\n" );
    
    z = IO_readchar ( "caractere = " );
    IO_println ( IO_concat ( a, IO_toString_c ( z ) ) );
    
    y = IO_readdouble ( "double = " );
    IO_println ( IO_concat ( a, IO_toString_f ( y ) ) );
    
    x = IO_readint ( "int = " );
    IO_println ( IO_concat ( a, IO_toString_d ( x ) ) );
    
    w = IO_readbool ( "bool = " );
    IO_println ( IO_concat ( a, IO_toString_b ( w ) ) );
    
    b = IO_readstring ( "chars = " );
    IO_println ( IO_concat ( a, b ) );
    
    b = IO_readln ( "line = " );
    IO_println ( IO_concat ( a, b ) );
    
    IO_pause("Apertar ENTER para terminar");

    return(0);
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) a
b.) 4.2
c.) 10
d.) 1
e.) abc def
f .) abc def
---------------------------------------------- historico
Versao      Data Modificacao
 0.1        29/08/2020
---------------------------------------------- testes
Versao Teste
0.1     01.  (ok)    identificacao de programa
             (ok)    leitura e exibicao das previsões
*/
