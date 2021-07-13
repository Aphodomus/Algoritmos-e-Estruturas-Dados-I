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
  * Versao:  1.0                Data: 30/08/2020
  * 
*/

#include "io.h"

int main ( void ) {
    int x = 0; 

    IO_id ("Exemplo209 - Programa - v0.1");

    x = IO_readint ("Entrar com um inteiro [0,1,2,3]: ");

    switch (x) {
      case 0:
        IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
      break;

      case 1:
        IO_printf ( "%s (%d)\n", "Valor igual a um ", x );
      break;

      case 2: 
        IO_printf ( "%s (%d)\n", "Valor igual a dois", x );
      break;

      case 3: 
        IO_printf ( "%s (%d)\n", "Valor igual a tres", x );
      break;

      default:
        IO_printf ( "%s (%d)\n", "Valor diferente das opcoes [0,1,2,3]", x );
    }

    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes
a.) 0
b.) 1
c.) 2
d.) 3
e.) 4
f.) -1
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    30/08		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
