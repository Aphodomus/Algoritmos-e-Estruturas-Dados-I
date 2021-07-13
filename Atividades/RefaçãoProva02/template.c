/**
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Refacao 02
  *
  * Autor    : Daniel Vitor de Oliveira Santos
  * Matricula: 716417
  *
*/
#include "io.h"

typedef struct s_int_Matrix {
    int lines;
    int columns;
    ints* data;
    int ix, iy;
} int_Matrix;

typedef int_Matrix* ref_int_Matrix;

ref_int_Matrix new_int_Matrix (int lines, int columns) {
    ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));

    if (tmpMatrix != NULL) {
        tmpMatrix -> lines = 0;
        tmpMatrix -> columns = 0;
        tmpMatrix -> data = NULL;
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

    fscanf(arquivo, "%d", &lines);
    fscanf(arquivo, "%d", &columns);

    if (lines <= 0 || columns <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        matrix = new_int_Matrix(lines, columns);

        if (matrix -> data == NULL) {
            matrix -> lines = 0;
            matrix -> columns= 0;
            matrix -> ix = 0;
            matrix -> iy = 0;
        } else {
            matrix -> ix = 0;
            while (! feof(arquivo) && ((matrix -> ix) < (matrix -> lines))) {
                matrix -> iy = 0;
                while (! feof(arquivo) && ((matrix -> iy) < (matrix -> columns))) {
                    fscanf(arquivo, "%d", &(matrix -> data[matrix -> ix][matrix -> iy]));
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
   printf("Coluna com a menor soma = %d\n", colunaMenorSoma);

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

//Trocar uma coluna de lugar com a outra, vai ser passada como parametro
ref_int_Matrix trocarColunas(ref_int_Matrix matrix, int coluna) {
   int aux = 0;

   for (matrix->ix = 0; (matrix->ix) < matrix->lines; matrix->ix = matrix->ix + 1) {
      for (matrix->iy = 0; (matrix->iy) < matrix->columns; matrix->iy = matrix->iy + 1) {
         if (matrix->iy == 0) {
            aux = matrix->data[matrix->ix][matrix->iy];
            matrix->data[matrix->ix][matrix->iy] = matrix->data[matrix->ix][coluna];
            matrix->data[matrix->ix][coluna] = aux;
         }
      }
   }

   return(matrix);
}

//gravar dados em matriz, posicao por posicao
void fprintIntMatrix (chars fileName, ref_int_Matrix matrix) {
    FILE* arquivo = fopen(fileName, "wt");

    if (matrix == NULL) {
        printf("\nERRO: Nao existe dados.");
    } else {
        fprintf(arquivo, "%d\n", matrix -> lines);
        fprintf(arquivo, "%d\n", matrix -> columns);

        for (matrix -> ix = 0; (matrix -> ix) < (matrix -> lines); matrix -> ix = matrix -> ix + 1) {
            for (matrix -> iy = 0; (matrix -> iy) < (matrix -> columns); matrix -> iy = matrix -> iy + 1) {
                fprintf(arquivo, "%d\n", matrix -> data[matrix -> ix][matrix -> iy]);
            }
        }
        fclose(arquivo);
    }
}

void metodo01() {
   int tamanho1 = 0, tamanho2 = 0, tamanho3 = 0;
   double arranjo1 [ STR_SIZE ];
   double arranjo2 [ STR_SIZE ];
   double arranjo3 [ STR_SIZE ];

   IO_println ( "\nMetodo01" );

   tamanho1 = freadArraySize("A1.txt");
   tamanho2 = freadArraySize("A2.txt");

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

}

void separarNomes ( char *prenomes, char *sobrenomes, char *fileName ) {
   FILE* arquivo = fopen(fileName, "rt");
   FILE* arquivoPrenome = fopen(prenomes, "wt");
   FILE* arquivoSobrenome = fopen(sobrenomes, "wt");
   int tamanho = 0, x = 0;
   chars testar = IO_new_chars(STR_SIZE);
   chars prenome = IO_new_chars(STR_SIZE);
   chars sobrenome = IO_new_chars(STR_SIZE);

   fscanf(arquivo, "%d", &tamanho);

   while (! feof(arquivo) && x < tamanho) {
      fscanf(arquivo, "%s\n", prenome);
      fprintf(arquivoPrenome, "%s\n", prenome);
      printf("Prenome: %s\n", prenome);

      fgets(sobrenome, 100, arquivo);
      fprintf(arquivoSobrenome, "%s", sobrenome);
      printf("Sobrenome: %s\n", sobrenome);

      x = x + 1;
   }

   fclose(arquivo);
   fclose(arquivoPrenome);
   fclose(arquivoSobrenome);
}

void metodo02 () {

   IO_println ( "\nMetodo02" );

   separarNomes ( "PRENOMES.TXT", "SOBRENOMES.TXT", "NOMES.TXT" );

   IO_pause("Apertar ENTER para continuar");
}

void metodo03() {
   ref_int_Matrix matrix;
   ref_int_Matrix result;
   int linhas  = 0;
   int colunas = 0;
   int valor = 0;
   int soma = 0;
   int menorSoma = 0;

   IO_println ( "\nMetodo03" );

   linhas = freadIntMatrix_lines("M1.txt");
   colunas = freadIntMatrix_columns("M1.txt");

   matrix = freadIntMatrix("M1.txt");

   printf("\nMatriz inicial:\n");
   printf("\n");
   printIntMatrix(matrix);

   valor = IO_readint("\nQual coluna voce deseja somar: ");

   if (valor <= colunas - 1) {
      soma = somaDaColuna(matrix, valor);
      printf("\nSoma da coluna %d = %d\n", valor, soma);
      menorSoma = menorSomaDeColunas(matrix);
      printf("Menor soma entre todas as colunas = %d\n", menorSoma);
   } else {
      printf("\nERRO: Essa coluna nao existe.\n");
   }

   result = trocarColunas(matrix, valor);

   printf("\nMatriz resultado:\n");
   printf("\n");
   printIntMatrix(result);

   fprintIntMatrix("M2.txt", result);

   free_int_Matrix(matrix);

   IO_pause("Apertar ENTER para continuar");
}

int main (void) {

   int opcao = 0;

   do {
      IO_printf  ( "\n" );
      IO_println ( "Exercicio_02 - v.0.0 - 22/11/2020\n"       );
      IO_println ( "Matricula: 716417 Nome: Daniel Vitor de Oliveira Santos\n" );
      IO_println ( "" ); 

      IO_println ( "Opcoes:"       );
      IO_println ( "0 - parar"     );
      IO_println ( "1 - metodo 01" );
      IO_println ( "2 - metodo 02" );
      IO_println ( "3 - metodo 03" );
      IO_println ( "" );

      printf("Digite uma opcao: ");
      scanf ( "%d", &opcao );

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
      }
   }
   while ( opcao != 0 );

}

