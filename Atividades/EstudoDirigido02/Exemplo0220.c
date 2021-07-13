/**
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: lista 02
  *
  * Objetivo:
  * Modelo de programa para a disciplina AED I
  * Sugestao para montar um trabalho pratico
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 04/09/2020
  * 
*/

#include "io.h"

int main ( void ) {
    double x = 0.0, y = 0.0, z = 0.0; 

    IO_id ("Exemplo220 - Programa - v0.1");

    x = IO_readdouble ("Entrar com um valor real: ");
    y = IO_readdouble ("Entrar com outro valor real: ");
    z = IO_readdouble ("Entrar com outro valor real: ");
   
    if (x == y || x == z || z == y) {
      IO_printf("\nExistem valores iguais, isso nao e permitido.");
    } else {
        if ( (x/2) > y && (x/2) < z) {
        IO_printf("\nA metade do primeiro valor (%.2lf) esta entre (%.2lf) e (%.2lf)", x/2, y, z);
      } else {
        IO_printf("\nA metade do primeiro valor (%.2lf) nao esta entre (%.2lf) e (%.2lf)", x/2, y, z);
      }
    }

    IO_pause ( "\nApertar ENTER para terminar" );
    return ( 0 );
}


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes
a.) 23 e 45
b.) 7 e -788
c.) -34 e 98
d.)  -3 e - 9
e.)  238943 e -2938842
f.) -3.5, 3.98 e 25.3
g.) -2.6, -5 e 19
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    04/09		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
