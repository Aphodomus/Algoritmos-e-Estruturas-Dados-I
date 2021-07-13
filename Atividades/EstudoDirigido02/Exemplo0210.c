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

void method00 () {

}

void method01 () {
 IO_println ( "Valor igual a um" );
} 

void method02 (int x) {
 IO_println ( IO_concat ( "Valor igual a (",
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
} 

void method03 (char* text1, int x) {
 IO_println ( IO_concat (
 IO_concat ( text1, " (" ),
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
}

int main ( void ) {
    int x = 0; 

    IO_id ("Exemplo210 - Programa - v0.1");

    x = IO_readint ("Entrar com um inteiro [0,1,2,3]: ");

    switch (x) {
      case 0:
        method00();
      break;

      case 1:
        method01();
      break;

      case 2: 
        method02(x);
      break;

      case 3: 
        method03("Valor igual a tres", x);
      break;

      default:
        IO_println ( IO_concat ( "Valor diferente das opcoes [0,1,2,3] (",
        IO_concat ( IO_toString_d ( x ), ")" ) ) );
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
