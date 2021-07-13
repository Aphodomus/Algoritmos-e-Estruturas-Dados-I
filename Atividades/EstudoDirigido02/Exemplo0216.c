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
    int x, y = 0; 

    IO_id ("Exemplo216 - Programa - v0.1");

    x = IO_readint ("Entrar com um inteiro: ");
    y = IO_readint ("Entrar com outro valor inteiro: ");
    
    if (x%2 == 0) {
      IO_printf("O primeiro valor digitado nao e impar\n");
    } else {
      IO_printf("O primeiro valor digitado e impar\n");
    }
    if (y%2 == 0) {
      IO_printf("O segundo valor digitado e par\n");
    } else {
      IO_printf("O segundo valor digitado nao e par\n");
    }

    IO_pause ( "\nApertar ENTER para terminar" );
    return ( 0 );
}


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes
a.) 14
b.) 15
c.) 33
d.) 32
e.) 75
f.) 76
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    30/08		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
