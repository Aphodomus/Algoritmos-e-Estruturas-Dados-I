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
  * Versao:  1.0                Data: 31/08/2020
  * 
*/

#include "io.h"

int main ( void ) {
  int x = 0; 

  IO_id ("Exemplo214 - Programa - v0.1");

  x = IO_readint ("Entrar com um inteiro: ");

  if (x%2 == 0) {
    if(x >= 20 && x <= 64) {
      IO_printf("O valor digitado (%i) e par e pertence ao intervalo fechado 20:64", x);
    } else {
      IO_printf("O valor digitado (%i) e par e não pertence ao intervalo fechado 20:64", x);
    }
  } else {
    if (x >= 20 && x <= 64) {
      IO_printf("O valor digitado (%i) e impar e pertence ao intervalo fechado 20:64", x);
    } else {
      IO_printf("O valor digitado (%i) e impar e nao pertence ao intervalo fechado 20:64", x);
    }
  }

  IO_pause ( "\nApertar ENTER para terminar" );
  return ( 0 );
}


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes
a.) 20
b.) 19
c.) 64
d.) 65
e.) 5
f.) 45
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    30/08		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
