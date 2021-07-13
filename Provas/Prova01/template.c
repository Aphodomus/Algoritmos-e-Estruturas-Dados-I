/**
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico 01
  *
  * Autor    : Daniel Vitor de Oliveira Santos
  * Matricula: 716417
  *
  * Instrucoes:
  *
  * 1. Alterar APENAS o nome e a matricula em main( ).
  *
  * 2. Desenvolver cada questao como um metodo.
  *
  * 3. O uso da biblioteca io.h e' opcional.
  *
  * 4. Comentarios deverao ser usados para informar
  *    sobre escolhas, restricoes, limites de uso
  *    no projeto de algoritmos.
  *
  * 5. Testes e valores usados para verificar a
  *    correcao de cada metodo deverao ser informados
  *    ao final do programa, como comentarios.
  *
  * 4. Para compilar e testar:
  *
  *    mk template inputs_001.txt outputs_001.txt
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

double doTheSequence (int inteiro) {
    int contador = 0, expoente = 0, numerador = 0, proximo = 0;
    double denominador = 0.0, soma = 0.0, fracao = 0.0;
   
    
    for (contador = 0; inteiro > contador; contador = contador + 1) {
        if (contador == 0 ) {
            IO_printf("Valor: 1/1\n");
            soma = soma + 1;
        } else {
            expoente = expoente + 1;
            proximo = proximo + 1;
            denominador = pow(2, expoente);
            numerador = numerador + proximo;
            fracao = numerador/denominador;
            soma = soma + fracao;
            IO_printf("Valor: %d/%0.lf\n", numerador, denominador);
        }
    } 
    IO_printf("\nSoma = %lf\n", soma);
}

bool isWord (char x) {
    bool result = false;
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) {
        result = true;
    }
    return(result);
}

bool isDigit (char x) {
    bool result = false;
    if ('0' <= x && x <= '9') {
        result = true;
    }
    return(result);
}

bool placa (char x, int posicao) {
   bool resultado = false;

   if (posicao >= 0 || posicao <= 2) {
      if (isWord(x) == true) {
         resultado = true;
      } else {
         return(resultado);
      }
   } 
   if (posicao == 3) {
      if (isDigit(x) == true) {
         resultado == true;
      } else {
         return(resultado);
      }
   }
   if (posicao == 4) {
      if (isWord(x) == true) {
         resultado = true;
      } else {
         return(resultado);
      }
   }
   if (posicao > 4 || posicao <= 6) {
      if (isDigit(x) == true) {
         resultado == true;
      } else {
         return(resultado);
      }
   }

   return(resultado);
}

/**
  * Metodo01.
  */
void metodo01 () {
   int valor = 0, contador = 0, aleatorio = 0;

   IO_println ( "\nMetodo01" );

   valor = IO_readint("Determine um valor: ");

   for (contador = 0; contador < 7; contador = contador + 1) {
      aleatorio = rand() % 100;
      
      if(aleatorio == valor) {
         IO_printf("OK\n");
      }
      if (aleatorio > valor ) {
         IO_printf("UP\n");
      }
      if (aleatorio < valor ) {
         IO_printf("DOWN\n");
      }
   }

} // fim metodo01 ( )

/**
  * Metodo02.
  */

void metodo02 () {
   int quantidade = 0;
   double resultado = 0.0;

   IO_println ( "\nMetodo02" );

   quantidade = IO_readint("Digite uma quantidade: ");

   resultado = doTheSequence(quantidade);

} // fim metodo02 ( )

/**
  * Metodo03.
  */


void metodo03 ( ) {
   int quantidade = 0, contador = 0, tamanho = 0, x = 0;
   chars palavra = IO_new_chars(STR_SIZE);
   char simbolo = '_';

   IO_println ( "\nMetodo03" );

   quantidade = IO_readint("Digite quantas placas deseja verificar: ");

   for (contador = 0; contador < quantidade; contador = contador + 1) {
      palavra = IO_readstring("Digite a placa a ser verificada: ");
      tamanho = strlen(palavra);

      for (x = 0; x < tamanho; x = x + 1) {
         simbolo = palavra[x];
         if (placa(simbolo, x) == true) {
            IO_printf("Valor = %c\n", simbolo);
         }
      }
   }

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
      IO_printf  ( "\n" );   // para saltar linha
      IO_println ( "Exercicio_01 - v.0.0 - 01/mm/20aa\n"       );
      IO_println ( "Matricula: 716417 Nome: Daniel Vitor de Oliveira Santos\n" );
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

      scanf ( "%d", &opcao );

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
            IO_printf ( "\nERRO: Opcao invalida.\n" );
            break;
      } // fim escolher
   }
   while ( opcao != 0 );

} // end main ( )


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes


---------------------------------------------- testes

*/
