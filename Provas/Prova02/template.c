/**
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico 02
  *
  * Autor    : Daniel Vito de Oliveira Santos
  * Matricula: 716417
  *
  * Instrucoes:
  *
  * 1. Alterar APENAS o nome e a matricula em main( ).
  *
  * 2. Desenvolver cada questao como um metodo.
  *
  * 3. O uso da biblioteca io.h e' opcional,
  *    mas se for usar outra, enviar o arquivo correspondente.
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
typedef struct s_int_Matrix {
    int lines;
    int columns;
    ints* data;
    int ix, iy;
} int_Matrix;

typedef int_Matrix* ref_int_Matrix;

ref_int_Matrix new_int_Matrix (int lines, int columns) {
    //reserva de espaco
    ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));

    //estabelecer valores padroes
    if (tmpMatrix != NULL) {
        tmpMatrix -> lines = 0;
        tmpMatrix -> columns = 0;
        tmpMatrix -> data = NULL;
        //reservar espaco
        if (lines > 0 && columns > 0) {
            tmpMatrix -> lines = lines;
            tmpMatrix -> columns = columns;
            tmpMatrix -> data = malloc (lines*sizeof(ints));
            for (tmpMatrix -> ix = 0; (tmpMatrix -> ix) < (tmpMatrix -> lines); tmpMatrix -> ix = tmpMatrix -> ix + 1) {
                tmpMatrix -> data[tmpMatrix -> ix] = (ints) malloc (columns*sizeof(int));
            }
        }
        tmpMatrix -> ix = 0;
        tmpMatrix -> iy = 0;
    }
    return(tmpMatrix);
}

ref_int_Matrix freadIntMatrix (chars fileName) {
    ref_int_Matrix matrix = NULL;
    int lines = 0;
    int columns = 0;
    FILE* arquivo = fopen(fileName, "rt");

    //ler a quantidade de dados
    fscanf(arquivo, "%d", &lines);
    fscanf(arquivo, "%d", &columns);

    if (lines <= 0 || columns <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        //reservar espaco para armazenar
        matrix = new_int_Matrix(lines, columns);

        //testar se a espaco
        if (matrix -> data == NULL) {
            //nao existe espaco
            matrix -> lines = 0;
            matrix -> columns= 0;
            matrix -> ix = 0;
            matrix -> iy = 0;
        } else {
            //ler e guardar valores na matriz
            matrix -> ix = 0;
            while (! feof(arquivo) && ((matrix -> ix) < (matrix -> lines))) {
                matrix -> iy = 0;
                while (! feof(arquivo) && ((matrix -> iy) < (matrix -> columns))) {
                    //guardar valor
                    fscanf(arquivo, "%d", &(matrix -> data[matrix -> ix][matrix -> iy]));
                    //passar ao proximo
                    matrix -> iy = matrix -> iy + 1;
                }
                matrix -> ix = matrix -> ix + 1;
            }
            matrix -> ix = 0;
            matrix -> iy = 0;
        }
    }
    return(matrix);
}

//Ler as linhas de uma matriz
int freadIntMatrix_lines (chars fileName) {
   FILE* arquivo = fopen(fileName, "rt");
   int lines = 0, columns = 0;

   fscanf(arquivo, "%d", &lines);
   fscanf(arquivo, "%d", &columns);

   return(lines);
}

//Ler as colunas de uma matriz
int freadIntMatrix_columns (chars fileName) {
   FILE* arquivo = fopen(fileName, "rt");
   int lines = 0, columns = 0;

   fscanf(arquivo, "%d", &lines);
   fscanf(arquivo, "%d", &columns);

   return(columns);
}

//Liberar espaco
void free_int_Matrix (ref_int_Matrix tmpMatrix) {
    //testar se existe dados
    if (tmpMatrix != NULL) {
        for (tmpMatrix -> ix = 0; (tmpMatrix -> ix) < (tmpMatrix -> lines); tmpMatrix -> ix = tmpMatrix -> ix + 1) {
            free(tmpMatrix -> data [tmpMatrix -> ix]);
        }
        free(tmpMatrix -> data);
        free(tmpMatrix);
    }
}

//Printar uma matrix na tela
void printIntMatrix (ref_int_Matrix matrix) {
    for (matrix -> ix = 0; (matrix -> ix) < (matrix -> lines); matrix -> ix = matrix -> ix + 1) {
        for (matrix -> iy = 0; (matrix -> iy) < (matrix -> columns); matrix -> iy = matrix -> iy + 1) {
            printf("%3d\t", matrix -> data[matrix -> ix][matrix -> iy]);
        }
        printf("\n");
    }
}

//Soma da coluna solicitada
int somaDaColuna (ref_int_Matrix matrix, int valor) {
   int soma = 0;

   for (matrix -> ix = 0; (matrix -> ix) < (matrix -> lines); matrix -> ix = matrix -> ix + 1) {
        for (matrix -> iy = 0; (matrix -> iy) < (matrix -> columns); matrix -> iy = matrix -> iy + 1) {
            if (matrix -> iy == valor) {
               soma = soma + matrix -> data[matrix -> ix][matrix -> iy];
            }
        }
    }

   return(soma);
}

//Calcular a menor soma entre todas as colunas e mostrar qual coluna teve a menor soma
int menorSomaDeColunas (ref_int_Matrix matrix) {
   int menorSoma = 0, soma1 = 0, soma2 = 0, soma3 = 0, soma4 = 0, colunaMenorSoma;

   for (matrix -> ix = 0; (matrix -> ix) < (matrix -> lines); matrix -> ix = matrix -> ix + 1) {
        for (matrix -> iy = 0; (matrix -> iy) < (matrix -> columns); matrix -> iy = matrix -> iy + 1) {
            if (matrix -> iy == 0) {
               soma1 = soma1 + matrix -> data[matrix -> ix][matrix -> iy];
            }
            if (matrix -> iy == 1) {
               soma2 = soma2 + matrix -> data[matrix -> ix][matrix -> iy];
            }
            if (matrix -> iy == 2) {
               soma3 = soma3 + matrix -> data[matrix -> ix][matrix -> iy];
            }
            if (matrix -> iy == 3) {
               soma4 = soma4 + matrix -> data[matrix -> ix][matrix -> iy];
            }
        }
   }

   if (soma1 < soma2 && soma1 < soma3 && soma1 < soma4) {
      menorSoma = soma1;
      colunaMenorSoma = 0;
   } else {
      if (soma2 < soma1 && soma2 < soma3 && soma2 < soma4) {
         menorSoma = soma2;
         colunaMenorSoma = 1;
      } else {
         if (soma3 < soma1 && soma3 < soma2 && soma3 < soma4) {
            menorSoma = soma3;
            colunaMenorSoma = 2;
         } else {
            if (soma4 < soma1 && soma4 < soma2 && soma4 < soma3) {
               menorSoma = soma4;
               colunaMenorSoma = 3;
            }
         }
      }
   }
   printf("\nColuna com a menor soma = %d\n", colunaMenorSoma);

   return(menorSoma);
}

//Ler um arranjo
int ler_arranjo (chars fileName, double array[], int tamanho) {
   int x = 0, y = 0;
   FILE* arquivo = fopen(fileName, "rt");

   IO_fscanf(arquivo, "%d", &x);

   x = 0;
   while (! feof(arquivo) && x < tamanho) {
      IO_fscanf(arquivo, "%d", &y);
      array[x] = y;
      x = x + 1;
   }

   return (array);
}

//Gravar o arranjo
void gravar_arranjo (chars fileName[], int tamanho, double array[]) {
   FILE* arquivo = fopen(fileName, "wt");
   int x = 0;

   for (x = 0; x < tamanho; x = x + 1) {
      IO_fprintf(arquivo, "%.2lf\n", array[x]);
   }
   fclose(arquivo);
}

//Intercalar os valores de 2 arrays
int intercalar ( double array3 [ ], int tamanho3, int tamanho1, double array1 [ ], int tamanho2, double array2 [ ] ) {
   int contador = 0, contador2 = 0, tamanhoTotal = 0;

   for (contador = 0; contador < tamanho3 && contador2 < tamanho1 && contador2 < tamanho2; contador = contador + 2) {
      if (array1[contador2] < array2[contador2]) {
         array3[contador] = array1[contador2];
         array3[contador + 1] = array2[contador2];
         contador2 = contador2 + 1;
      } else {
         if (array2[contador2] < array1[contador2]) {
            array3[contador] = array2[contador2];
            array3[contador + 1] = array1[contador2];
            contador2 = contador2 + 1;
         } else {
            if (array2[contador2] == array1[contador2]) {
               array3[contador] = array2[contador2];
               array3[contador + 1] = 0;
               contador2 = contador2 + 1;
            }
         }
      }
   }

   gravar_arranjo("A3.txt", tamanho3, array3);
   
}

//Verificar tamanho do array
int freadArraySize (chars fileName) {
    int n = 0;
    FILE* arquivo = fopen(fileName, "rt");

    IO_fscanf(arquivo, "%d", &n);

    if (n <= 0) {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }

    return(n);
}
//Printar array
void printIntArray (int n, double array[]) {
    int x = 0;

    for (x = 0; x < n; x = x + 1 ) {
        IO_printf("%2d: %.2lf\n", x, array[x]);
    }
}


/**
  * Metodo01.
  */
void metodo01 ( ) {
// definir dados
   int tamanho1 = 0, tamanho2 = 0, tamanho3 = 0;
   double arranjo1 [ STR_SIZE ];
   double arranjo2 [ STR_SIZE ];
   double arranjo3 [ STR_SIZE ];

   IO_println ( "\nMetodo01" );

//Verificar o tamanhos dos arrays
   tamanho1 = freadArraySize("A1.txt");
   tamanho2 = freadArraySize("A2.txt");

//Ler Arrays
   ler_arranjo ( "A1.txt", arranjo1, tamanho1 );
   printf("\nArray1:\n");
   printIntArray(tamanho1, arranjo1);

   ler_arranjo ( "A2.txt", arranjo2, tamanho2 );
   printf("\nArray2:\n");
   printIntArray(tamanho2, arranjo2);
 
   tamanho3 = tamanho1 + tamanho2;

   intercalar ( arranjo3, tamanho3, tamanho1, arranjo1, tamanho2, arranjo2 );
   printf("\nArray3: Intercalacao\n");
   tamanho3 = freadArraySize("A3.txt");
   printIntArray(tamanho3, arranjo3);

   IO_pause("Apertar ENTER para continuar");

} // fim metodo01 ( )

void separarNomes ( char *prenomes, char *sobrenomes, char *fileName ) {
   FILE* arquivo = fopen(fileName, "rt");
   chars linha = IO_new_chars(STR_SIZE);
   
   int tamanho = 0, x = 0;

   fscanf(arquivo, "%d", &tamanho);

   strcpy(linha, IO_freadln(arquivo));

   while (x <= tamanho) {
      printf("%s\n", linha);
      strcpy(linha, IO_freadln(arquivo));
      x = x + 1;
      
   }

   fclose(arquivo);
}


/**
  * Metodo02.
  */
void metodo02 ( )
{
// definir dados

// identificar
   IO_println ( "\nMetodo02" );
// separar nomes e sobrenomes
   separarNomes ( "PRENOMES.TXT", "SOBRENOMES.TXT", "NOMES.TXT" );

   IO_pause("Apertar ENTER para continuar");
} // fim metodo02 ( )

void ler_matriz (ref_int_Matrix matrix, int linhas, int colunas) {

}

void gravar_matriz ( char nomeArquivo[ ],
                     int linhas, int colunas,
                     int matriz [ ][ colunas ] )
{
}

void menorSomaPrimeiro ( int linhas, int colunas, 
                         int matriz [ ][ colunas ] )
{
}

/**
  * Metodo03.
  */
void metodo03 ( )
{
// definir dados
   int linhas  = 0;
   int colunas = 0;
   int valor = 0;
   int soma = 0;
   int menorSoma = 0;

// identificar
   IO_println ( "\nMetodo03" );

   linhas = freadIntMatrix_lines("M1.txt");
   colunas = freadIntMatrix_columns("M1.txt");

   ref_int_Matrix matrix;

   // ler matriz de arquivo
   matrix = freadIntMatrix("M1.txt");

   printf("\nMatriz inicial:\n");
   printf("\n");
   printIntMatrix(matrix);

   valor = IO_readint("\nQual coluna voce deseja somar: ");

   if (valor <= colunas - 1) {
      soma = somaDaColuna(matrix, valor);
      printf("\nSoma da coluna %d = %d\n", valor, soma);
      menorSoma = menorSomaDeColunas(matrix);
      printf("\nMenor soma entre todas as colunas = %d\n", menorSoma);
   } else {
      printf("\nERRO: Essa coluna nao existe.\n");
   }

   free_int_Matrix(matrix);

// gravar matriz em arquivo
   //gravar_matriz ( "M2.txt", linhas, colunas, matriz );

   IO_pause("Apertar ENTER para continuar");
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
      IO_println ( "Exercicio_02 - v.0.0 - 09/11/2020\n"       );
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
