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
    int x = 0, y = 0; 

    IO_id ("Exemplo217 - Programa - v0.1");

    x = IO_readint ("Entrar com um inteiro: ");
    y = IO_readint ("Entrar com outro valor inteiro: ");
    
    if (x%2 != 0 && x >= 0) {
      IO_printf("O primeiro valor digitado e impar e positivo (%i)\n", x);
    } else {
      if (x%2 != 0 && x < 0) {
        IO_printf("O primeiro valor digitado e impar e negativo (%i)\n", x);
      } else {
        if (x%2 == 0 && x >= 0) {
          IO_printf("O primeiro valor digitado e par e positivo (%i)\n", x);
        } else {
          IO_printf("O primeiro valor digitado e par e negativo (%i)\n", x);
        }
      }
    }
    if (y%2 != 0 && y >= 0) {
      IO_printf("O segundo valor digitado e impar e positivo (%i)\n", y);
    } else {
      if (y%2 != 0 && y < 0) {
        IO_printf("O segundo valor digitado e impar e negativo (%i)\n", y);
      } else {
        if (y%2 == 0 && y >= 0) {
          IO_printf("O segundo valor digitado e par e positivo (%i)\n", y);
        } else {
          IO_printf("O segundo valor digitado e par e negativo (%i)\n", y);
        }
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
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    03/09		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
