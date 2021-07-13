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
    char x = '_';

    IO_id ("Exemplo205 - Programa - v0.1");

    x = IO_readchar ( "Entrar com um caractere: " );

    if ('a' <= x && x <= 'z') {
      IO_printf ( "%s (%c)\n", "Letra minuscula", x );
    } else {
      IO_printf ( "%s (%c)\n", "Valor diferente de minuscula", x );
      if ('A' <= x && x <= 'Z') {
        IO_printf ( "%s (%c)\n", "Letra maiuscula", x );
      } else {
        if ('0' <= x && x <= '9') {
          IO_printf ( "%s (%c)\n", "Algarismo", x );
        } else {
          IO_printf ( "%s (%c)\n", "Valor diferente de algarismo", x );
        }
      }
    }

    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes
a.) a
b.) A
c.) 0
d.) #
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    30/08		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
