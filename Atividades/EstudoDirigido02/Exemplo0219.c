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
  * Versao:  1.0                Data: 03/09/2020
  * 
*/

#include "io.h"

int main ( void ) {
    double x = 0.0, y = 0.0, z = 0.0; 

    IO_id ("Exemplo219 - Programa - v0.1");

    x = IO_readdouble ("Entrar com um inteiro: ");
    y = IO_readdouble ("Entrar com outro valor inteiro: ");
    z = IO_readdouble ("Entrar com outro valor inteiro: ");
   
    if (x == y || x == z || z == y) {
      IO_printf("\nExistem valores iguais, isso nao e permitido.");
    } else {
        if ( x > y && x < z) {
        IO_printf("\nO valor (%lf) esta entre (%lf) e (%lf)", x, y, z);
      } else {
        IO_printf("\nO valor (%lf) nao esta entre (%lf) e (%lf)", x, y, z);
      }
    }

    IO_pause ( "\nApertar ENTER para terminar" );
    return ( 0 );
}


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes
a.) 3, 3 e 3
b.) 5, 9 e 7
c.) -5, -10 58
d.)  2, 9 e 2
e.)  17, 2 e 29
f.) -3.5, 3.98 e 25.3
g.) -2.6, -5 e 19
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    03/09		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
