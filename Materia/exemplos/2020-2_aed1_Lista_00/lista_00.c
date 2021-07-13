/**
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: lista 00
  *
  * Objetivo:
  * Modelo de programa para a disciplina AED I
  * Sugestao para montar um trabalho pratico
  *
  * Autor:   Matricula: 999999  Nome: xxx yyy zzz
  * Versao:  1.0                Data: 01/mm/20aa
  *
  * Dados:
  * - opcao de execucao escolhida pelo usuario
  *
  * Resultados:
  * - execucao de um teste de cada vez a escolha do usuario
  *
  * Condicoes:
  * - so' aceitara' as opcoes oferecidas.
  * - a classe IO devera' estar acessivel.
  *
  * Arquivos:
  *
  * - lista_00.c
  * - lista_00     ( no Linux   )
  * - lista_00.exe ( no Windows )
  * - io.h         ( por exemplo em C:\_____\include\io.h )
  *
  * Forma de compilacao:
  * - acionar o compilador no modo console (terminal/janela de comandos):
  *
  *   Linux  : gcc -o ./lista_00     ./lista_00.c
  *   Windows: gcc -o   lista_00.exe   lista_00.c
  *
  * Forma de uso:
  * - acionar o programa   no modo console (terminal/janela de comandos):
  *
  *   Linux  :  ./lista_00
  *   Windows:    lista_00
  *
  * Referencias:
  * - Exemplos mostrados em sala de aula
  * - Apostila: Fundamentos de Programacao - Notas de aulas
  *
  */

// ---------------------------------------------- classes nativas
//                                                ou auxiliares

#include "io.h"     // se na mesma pasta

//#include <io.h>     // se em pasta padrao

// ---------------------------------------------- definicao de classe

/**
  * Modelo para definir exemplo de um programa.
  * Obs.: E' recomendado ter o nome do programa
  *       sem espacos em branco, acentos ou cedilha.
  */

// ---------------------------------------------- tratamento de erro


// ---------------------------------------------- definicao de constantes


// ---------------------------------------------- definicao de armazenadores globais


// ---------------------------------------------- definicao de prototipos


// ---------------------------------------------- definicao de metodos

/**
  * Metodo01.
  */
void metodo01 ( )
{
 // identificar
    IO_println ( "\nMetodo01" );
 // encerrar
    IO_pause   ( "Apertar ENTER para continuar." );
} // fim metodo01 ( )

/**
  * Metodo02.
  */
void metodo02 ( )
{
 // identificar
    IO_println ( "\nMetodo02" );
 // encerrar
    IO_pause   ( "Apertar ENTER para continuar." );
} // fim metodo02 ( )

/**
  * Metodo03.
  */
void metodo03 ( )
{
 // identificar
    IO_println ( "\nMetodo03" );
 // encerrar
    IO_pause   ( "Apertar ENTER para continuar." );
} // fim metodo03 ( )


// ---------------------------------------------- definicao do metodo principal

int main ( void )
{
 // definir dados
    int opcao = 0;

 // repetir ate' desejar parar
    do
    {
     // identificar
        IO_clrscr ( );         // para limpar a tela
        IO_printf  ( "\n" );   // para saltar linha
        IO_println ( "Lista_00 - v.0.0 - 01/mm/20aa\n"       );
        IO_println ( "Preparacao para a Lista 01\n"          );
        IO_println ( "Matricula: 999999 Nome: xxx yyy zzz\n" );
        IO_println ( "" );     // para saltar linha

     // mostrar opcoes
        IO_println ( "Opcoes:"       );
        IO_println ( "0 - parar"     );
        IO_println ( "1 - metodo 01" );
        IO_println ( "2 - metodo 02" );
        IO_println ( "3 - metodo 03" );
        IO_println ( "" );     // para saltar linha

     // ler opcao
        opcao = IO_readint ( "Qual a sua opcao? " );

     // escolher acao
        switch ( opcao )
        {
           case 0:
              break;
           case 1:
              metodo01 ( );
              break;
           case 2:
              metodo02 ( );
              break;
           case 3:
              metodo03 ( );
              break;
           default:
              IO_pause ( "\nERRO: Opcao invalida.\n" );
              break;
        } // fim escolher
    }
    while ( opcao != 0 );

 // encerrar execucao
    IO_pause ( "\nApertar ENTER para terminar.\n" );

} // end main ( )


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes


---------------------------------------------- historico

Versao	Data		    Modificacao
  0.1	__/__		    esboco

 ---------------------------------------------- testes

Versao	Teste
  0.1	01. ( OK )		identificacao de programa

*/
