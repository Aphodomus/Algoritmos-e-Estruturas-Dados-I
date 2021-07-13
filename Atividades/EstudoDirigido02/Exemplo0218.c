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
    double x = 0.0, y = 0.0; 

    IO_id ("Exemplo218 - Programa - v0.1");

    x = IO_readdouble ("Entrar com um real: ");
    y = IO_readdouble ("Entrar com outro valor inteiro: ");
    
    if (x*2 > y) {
      IO_printf("O dobro do primeiro e maior que o segundo (%f) > (%f)", x*2, y);
    } else {
      if (x*2 < y) {
        IO_printf("O dobro do primeiro e menor que o segundo (%f) < (%f)", x*2, y);
      } else {
        if (x*2 == y) {
          IO_printf("O dobro do primeiro e igual ao segundo (%f) = (%f)", x*2, y);
        } else {
          IO_printf("Erro no Programa.");
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
f.) -0.3 e 29
g.) 2.56 e 9.71
h.) -8.4 e -2.3
---------------------------------------------- historico

Versao	    Data		    Modificacao
  0.1	    03/09		    esboco

 ---------------------------------------------- testes

Versao	    Teste
  0.1	    01. (ok)		identificacao de programa

*/
