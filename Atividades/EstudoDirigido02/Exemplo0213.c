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

    IO_id ("Exemplo213 - Programa - v0.1");

    x = IO_readint ("Entrar com um inteiro: ");

    if (x > 20 && x < 64) {
      IO_printf("O valor digitado (%i) pertence ao intervalo aberto 20:64", x);
    } else {
      IO_printf("O valor digitado (%i) nao pertence ao intervalo aberto 20:64", x);
    }

    IO_pause ( "\nApertar ENTER para terminar" );
    return ( 0 );
}


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes
a.) 2
b.) -200
c.) 1
d.) 103
e.) 293
f.) -1234
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    30/08		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
