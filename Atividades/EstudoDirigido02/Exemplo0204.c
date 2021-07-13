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
    double x = 0.0; 

    IO_id ("Exemplo204 - Programa - v0.1");

    x = IO_readdouble ( "Entrar com um valor real: " );

    if (1.0 <= x && x <= 10.0) {
      IO_printf ( "%s (%lf)\n", "Valor dentro do intervalo [1:10] ", x );
    } else {
      IO_printf ( "%s (%lf)\n", "Valor fora do intervalo [1:10] ", x );
      if (x < 1.0) {
        IO_printf ( "%s (%lf)\n", "Valor abaixo do intervalo [1:10] ", x );
      } else {
        IO_printf ( "%s (%lf)\n", "Valor acima do intervalo [1:10]", x );
      }
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
c.) 10
d.) -1
e.) 100
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    30/08		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
