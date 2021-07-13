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

    IO_id ("Exemplo208 - Programa - v0.1");

    x = IO_readchar ( "Entrar com um caractere ['0','A','a']: " );

    switch (x) {
      case '0':
        IO_printf ( "%s (%c = %d)\n", "Valor igual do simbolo zero", x, x );
      break;

      case 'A':
        IO_printf("%s (%c = %d)\n", "Valor igual a letra A", x, x);
      break;

      case 'a': 
        IO_printf("%s (%c = %d)\n", "Valor igual a letra a", x, x);
      break;

      default:
        IO_printf ( "%s (%c = %d)\n", "Valor diferente das opcoes ['0','A','a']", x, x );
    }

    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes
a.) 0
b.) A
c.) a
d.) 1
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    30/08		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
