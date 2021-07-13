/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Ed10
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 27/10/2020
*/

#include "io.h"
#include "MyLib.h"

//Definicao de tipo arranjo com inteiros baseado em estrutura
typedef struct s_int_Array {
    int length;
    ints data;
    int ix;
} int_Array;

//Definicao de tipo arranjo bidimensional com inteiros baseados em estrutura
typedef struct s_int_Matrix {
    int lines;
    int columns;
    ints* data;
    int ix, iy;
} int_Matrix;

//Definicao de referencia para arranjo com inteiros baseado em estrutura
typedef int_Array* ref_int_Array;

//Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura
typedef int_Matrix* ref_int_Matrix;

//Funcao new_int_Array - Reserva espaco para arranjo com inteiros
ref_int_Array new_int_Array (int n) {
    //reserva de espaco
    ref_int_Array tmpArray = (ref_int_Array) malloc (sizeof(int_Array));

    //estabelecer valores padroes
    if (tmpArray == NULL) {
        IO_printf("\nERRO: Falta espaco.\n");
    } else {
        tmpArray -> length = 0;
        tmpArray -> data = NULL;
        tmpArray -> ix = -1;

        if (n > 0) {
            //guardar a quantidade de dados
            tmpArray -> length = n;
            //reservar espaco para os dados
            tmpArray -> data = (ints) malloc (n*sizeof(int));
            //definir indicador do primeiro elemento
            tmpArray -> ix = 0;
        }
    }
    return(tmpArray);
}

//Funcao new_int_matrix reserva espaco para arranjo bidimensional
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

//Dispensar espaco para arranjo com inteiros
void free_int_Array (ref_int_Array tmpArray) {
    //testar se existe dados
    if (tmpArray != NULL) {
        free (tmpArray -> data);
        free (tmpArray);
    }
}

//Dispensar espaco para arranjo com inteiros
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

//mostrar array com valores intieros
void printIntArray (int_Array array) {
    //mostrar valores no arranjo
    for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1) {
        //mostrar valor
        printf("%2d: %d\n", array.ix, array.data[array.ix]);
    }
}

//mostrar matrix com valores inteiros
void printIntMatrix (ref_int_Matrix matrix) {
    for (matrix -> ix = 0; (matrix -> ix) < (matrix -> lines); matrix -> ix = matrix -> ix + 1) {
        for (matrix -> iy = 0; (matrix -> iy) < (matrix -> columns); matrix -> iy = matrix -> iy + 1) {
            printf("%3d\t", matrix -> data[matrix -> ix][matrix -> iy]);
        }
        printf("\n");
    }
}

//ler e guardar dados em arranjo
int_Array IO_readintArray() {
    chars text = IO_new_chars(STR_SIZE);
    static int_Array array;

    //ler a quantidade de dados
    do {
        array.length = IO_readint("\nlength = ");
    } while (array.length <= 0);

    //reservar espaco para armazenar
    array.data = IO_new_ints(array.length);

    //testar se a espaço
    if (array.data == NULL) {
        array.length = 0;
    } else {
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1) {
            //ler valor
            strcpy(text, STR_EMPTY);
            array.data[array.ix] = IO_readint(IO_concat(IO_concat(text, IO_toString_d(array.ix)), ":"));
        }
    }
    return(array);
}

//gravar em arquivos dados do arranjo
void fprintIntArray (chars fileName, int_Array array) {
    FILE* arquivo = fopen (fileName, "wt");

    //gravar quantidade de dados que vao existir
    fprintf(arquivo, "%d\n", array.length);

    //gravar valores no arquivo
    for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1) {
        //gravar valor
        fprintf(arquivo, "%d\n", array.data[array.ix]);
    }
    fclose(arquivo);
}

//ler tamanho do arranjo com valores inteiros
int freadArraySize (chars fileName) {
    int n = 0;
    FILE* arquivo = fopen(fileName, "rt");

    //ler a quantidade de dados
    fscanf(arquivo, "%d", &n);

    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
        n = 0;
    }
    return(n);
}

//ler arranjo com valores inteiros
int_Array fIO_readIntArray (chars fileName) {
    int x = 0;
    int y = 0;
    FILE* arquivo = fopen (fileName, "rt");
    static int_Array array;

    //ler a quantidade de dados
    fscanf(arquivo, "%d", &array.length);

    //testar se existe dados
    if (array.length <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
        array.length = 0;
    } else {
        //reservar espaco
        array.data = IO_new_ints(array.length);

        //ler e guardar valores em arranjo
        array.ix = 0;
        while (!feof (arquivo) && array.ix < array.length) {
            //ler valor
            fscanf(arquivo, "%d", &(array.data[array.ix]));
            //passar ao proximo
            array.ix = array.ix + 1;
        }
    }
    return(array);
}

//Copiar dados de um arranjo para outro
int_Array copyIntArray (int_Array array) {
    int x = 0;
    int y = 0;
    static int_Array copy;

    if (array.length <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
        array.length = 0;
    } else {
        //reservar area
        copy.length = array.length;
        copy.data = IO_new_ints(copy.length);

        //testar se existe espaco e dados
        if (copy.data == NULL || array.data == NULL) {
            printf("\nERRO: Falta espaco ou dados.");
        } else {
            //ler e copiar valores
            for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1) {
                //copiar valor
                copy.data[array.ix] = array.data[array.ix];
            }
        }
    }
    return(copy);
}

//ler e armazenar dados em matriz
ref_int_Matrix IO_readintMatrix () {
    int lines = 0;
    int columns = 0;
    int z = 0;
    chars text = IO_new_chars(STR_SIZE);

    //ler a quantidade de dados
    do {
        lines = IO_readint("\nlines = ");
    } while (lines <= 0);

    do {
        columns = IO_readint("\ncolumns = ");
    } while (columns <= 0);

    //reservar espaco para armazenar valores
    ref_int_Matrix matrix = new_int_Matrix(lines, columns);

    //testar se a espaco
    if (matrix -> data == NULL) {
        //nao existe espaco
        matrix -> lines = 0;
        matrix -> columns = 0;
        matrix -> ix = 0;
        matrix -> iy = 0;
    } else {
        for (matrix -> ix = 0; (matrix -> ix) < (matrix -> lines); matrix -> ix = matrix -> ix + 1) {
            for (matrix -> iy = 0; (matrix -> iy) < (matrix -> columns); matrix -> iy = matrix -> iy + 1) {
                //ler e guardar valor
                strcpy(text, STR_EMPTY);
                matrix -> data[matrix -> ix][matrix -> iy] = IO_readint( IO_concat (
                IO_concat ( IO_concat ( text, IO_toString_d ( matrix->ix ) ), ", " ),
                IO_concat ( IO_concat ( text, IO_toString_d ( matrix->iy ) ), " : " ) ));
            }
            printf("\n");
        }
    }
    return(matrix);
}

//gravar dados em matriz, posicao por posicao
void fprintIntMatrix (chars fileName, ref_int_Matrix matrix) {
    FILE* arquivo = fopen(fileName, "wt");

    //testar se a dados
    if (matrix == NULL) {
        printf("\nERRO: Nao existe dados.");
    } else {
        //gravar quantidade de linhas e colunas
        fprintf(arquivo, "%d\n", matrix -> lines);
        fprintf(arquivo, "%d\n", matrix -> columns);

        //gravar valores no arquivo
        for (matrix -> ix = 0; (matrix -> ix) < (matrix -> lines); matrix -> ix = matrix -> ix + 1) {
            for (matrix -> iy = 0; (matrix -> iy) < (matrix -> columns); matrix -> iy = matrix -> iy + 1) {
                fprintf(arquivo, "%d\n", matrix -> data[matrix -> ix][matrix -> iy]);
            }
        }
        fclose(arquivo);
    }
}

//ler dados de um arquivo para armazenar em matriz
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

//copiar dados de uma matriz para outra
ref_int_Matrix copyIntMatrix (ref_int_Matrix matrix) {
    ref_int_Matrix copy = NULL;

    if (matrix == NULL || matrix -> data == NULL) {
        IO_printf("\nERRO: Falta dados.\n");
    } else {
        if ((matrix -> lines) <= 0 || (matrix -> columns) <= 0) {
            IO_printf("\nERRO: Valor invalido.\n");
        } else {
            //reservar espaco
            copy = new_int_Matrix (matrix -> lines, matrix -> columns);

            //testar se a espaco e dados
            if (copy == NULL || copy -> data == NULL) {
                printf("\nEROO: Falta espaco.");
            } else {
                //copiar valores
                for (copy -> ix = 0; (copy -> ix) < (copy -> lines); copy -> ix = copy -> ix + 1) {
                    for (copy -> iy = 0; (copy -> iy) < (copy -> columns); copy -> iy = copy -> iy  + 1) {
                        copy -> data[copy -> ix][copy -> iy] = matrix -> data[copy -> ix][copy -> iy];
                    }
                }
            }
        }
    }
    return(copy);
}

//Ler dados e guardar em um arranjo
int_Array My_lib_readintArray (int inferior, int superior, int quantidade) {
    int contador = 0, numero = 0;
    FILE* arquivo = fopen ("Dados.txt", "wt");
    static int_Array array;

    array.length = quantidade;
    array.data = IO_new_ints(array.length);

    if (array.data == NULL) {
        array.length = 0;
    } else {
        srand(time(0));
        fprintf(arquivo, "%d\n", quantidade);
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1) {
            numero = inferior + rand() % (superior - inferior + 1);
            array.data[array.ix] = numero;
            fprintf(arquivo, "%d\n", numero);
        }
        fclose(arquivo);
    }

    return(array);
}

//Procurar o menor valor em um array
int searchLowerValue (int_Array array, int search) {
    int menor = 0, contador = 0;

    for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1) {
        if (search == array.data[array.ix]) {
            printf("O valor %d foi encontrado na posicao [%d]\n", search, array.data[array.ix]);
            contador = contador + 1;
        }
    }
    return(contador);
}

//Comparar 2 arrays
bool compareTwoArrays (int_Array array1, int_Array array2) {
    bool result = false;
    int contador = 0;

    if (array1.length != array2.length) {
        printf("\nERRO: Os arrays possuem tamanhos diferentes.");
    } else {
        for (array1.ix = 0; array1.ix < array1.length; array1.ix = array1.ix + 1) {
            if (array1.data[array1.ix] == array2.data[array1.ix]) {
                contador = contador + 1;
            }
        }
    }
    if (contador == array1.length) {
        result = true;
        return(result);
    } else {
        return (result);
    }
}

//Somar 2 arrays com uma constante multiplicando o segundo array
int_Array sumTwoArraysWithConstant (int_Array array1, int_Array array2, int k) {
    static int_Array result;

    result.length = array1.length;
    result.data = IO_new_ints(result.length);

    if (result.data == NULL) {
        result.length = 0;
    } else {
        if (array1.length != array2.length) {
        printf("\nERRO: Os arrays possuem tamanhos diferentes.");
        } else {
            result.length = array1.length;
            for (array1.ix = 0; array1.ix < array1.length; array1.ix = array1.ix + 1) {
                result.data[array1.ix] = array1.data[array1.ix] + (k * array2.data[array1.ix]);
                printf("Array1 [%d] + Array2 [%d*%d] = %d\n", array1.data[array1.ix], array2.data[array1.ix], k, result.data[array1.ix]);
            }
        }
    }

    return(result);
}

//Verificar se está ordenado
int isOrdered (int_Array array) {
    int contador = 0;

    for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1) {
        if (array.data[array.ix] <= (array.data[array.ix + 1])) {
            contador = contador + 1;
        }
    }
    return(contador);
}

//Transpor uma matriz
ref_int_Matrix transposedMatrix (ref_int_Matrix matrix) {
    ref_int_Matrix transposed = NULL;

    if (matrix == NULL || matrix->data == NULL) {
        printf("\nERRO: Faltam dados.\n");
    } else {
        if ((matrix->lines) <= 0 || (matrix->columns) <= 0) {
            printf("ERRO: Valor das linhas ou colunas invalido.\n");
        } else {
            transposed = new_int_Matrix(matrix->columns, matrix->lines);
            
            if (transposed == NULL || (transposed->data) == NULL) {
                printf("\nERRO: Falta espaco.\n");
            } else {

                for (matrix->ix = 0; (matrix->ix) < (matrix->lines); matrix->ix = matrix->ix + 1) {
                    for (matrix->iy = 0; (matrix->iy) < (matrix->columns); matrix->iy = matrix->iy + 1) {
                        transposed->data[matrix->iy][matrix->ix] = matrix->data[matrix->ix][matrix->iy];
                    }
                }
            }
        }
    }
    return(transposed);
}

//Verificar se todos os valores da matriz sao iguais a zero
int isAllEqualZeroMatrix (ref_int_Matrix matrix) {
    int contador = 0;

    if (matrix == NULL || matrix->data == NULL) {
        printf("\nERRO: Faltam dados.\n");
    } else {
        if ((matrix->lines) <= 0 || (matrix->columns) <= 0) {
            printf("\nERRO: Valor das linhas ou colunas invalido.\n");
        } else {
            for (matrix->ix = 0; (matrix->ix) < (matrix->lines); matrix->ix = matrix->ix + 1) {
                for (matrix->iy = 0; (matrix->iy) < (matrix->columns); matrix->iy = matrix->iy + 1) {
                    if (matrix->data[matrix->ix][matrix->iy] == 0) {
                        contador = contador + 1;
                    }
                }
            }
        }
    }
    return(contador);
}

//Comparar 2 matrizes e ver se elas sao iguais
int CompareTwoMatrix (ref_int_Matrix matrix1, ref_int_Matrix matrix2) {
    int contador = 0;

    if ((matrix1->columns) <= 0 || (matrix1->lines) <= 0 || (matrix2->columns) <= 0 || (matrix2->lines) <= 0) {
        printf("\nERRO: Tamanho das matrizes invalido.\n");
    } else {
        if (matrix1->lines != matrix2->lines || matrix1->columns != matrix2->columns) {
            printf("\nERRO: As matrizes tem tamanhos de linhas ou colunas diferentes.\n");
        } else {
            for (matrix1->ix = 0; (matrix1->ix) < (matrix1->lines); matrix1->ix = matrix1->ix + 1) {
                for (matrix1->iy = 0; (matrix1->iy) < (matrix1->columns); matrix1->iy = matrix1->iy + 1) {
                    if (matrix1->data[matrix1->ix][matrix1->iy] == matrix2->data[matrix1->ix][matrix1->iy]) {
                        contador = contador + 1;
                    }
                }
            }
        }
    }
    return(contador);
}

//Somar os valores de 2 matrizes, com a segunda escalada por uma constante
ref_int_Matrix sumTwoMatrixsWithConstant (ref_int_Matrix matrix1, ref_int_Matrix matrix2, int k) {
    ref_int_Matrix result = NULL;

    if ((matrix1->columns) <= 0 || (matrix1->lines) <= 0 || (matrix2->columns) <= 0 || (matrix2->lines) <= 0) {
        printf("\nERRO: Tamanho das matrizes invalido.\n");
    } else {
        if ((matrix1->lines) != (matrix2->lines) || (matrix1->columns) != (matrix2->columns)) {
            printf("\nERRO: As matrizes tem tamanhos de linhas ou colunas diferentes.\n");
        } else {
            result = new_int_Matrix(matrix1->lines, matrix1->columns);
            if (result == NULL || result->data == NULL) {
                printf("\nERRO: Falta espaco.\n");
            } else {
                for (matrix1->ix = 0; (matrix1->ix) < (matrix1->lines); matrix1->ix = matrix1->ix + 1) {
                    for (matrix1->iy = 0; (matrix1->iy) < (matrix1->columns); matrix1->iy = matrix1->iy + 1) {
                        result->data[matrix1->ix][matrix1->iy] = matrix1->data[matrix1->ix][matrix1->iy] + (k * matrix2->data[matrix1->ix][matrix1->iy]);
                        printf("Matrix1 [%d] + Matrix2 [%d*%d] = %d\n", matrix1->data[matrix1->ix][matrix1->iy], matrix2->data[matrix1->ix][matrix1->iy], k, result->data[matrix1->ix][matrix1->iy]);
                    }
                }
            }
        }
    }
    return(result);
}

//Multiplicar os valores de 2 matrizes
ref_int_Matrix multiplyTwoMatrix (ref_int_Matrix matrix1, ref_int_Matrix matrix2) {
    ref_int_Matrix result = NULL;

    if ((matrix1->columns) <= 0 || (matrix1->lines) <= 0 || (matrix2->columns) <= 0 || (matrix2->lines) <= 0) {
        printf("\nERRO: Tamanho das matrizes invalido.\n");
    } else {
        if ((matrix1->lines) != (matrix2->lines) || (matrix1->columns) != (matrix2->columns)) {
            printf("\nERRO: As matrizes tem tamanhos de linhas ou colunas diferentes.\n");
        } else {
            result = new_int_Matrix(matrix1->lines, matrix1->columns);
            if (result == NULL || result->data == NULL) {
                printf("\nERRO: Falta espaco.\n");
            } else {
                for (matrix1->ix = 0; (matrix1->ix) < (matrix1->lines); matrix1->ix = matrix1->ix + 1) {
                    for (matrix1->iy = 0; (matrix1->iy) < (matrix1->columns); matrix1->iy = matrix1->iy + 1) {
                        result->data[matrix1->ix][matrix1->iy] = (matrix1->data[matrix1->ix][matrix1->iy]) * (matrix2->data[matrix1->ix][matrix1->iy]);
                        printf("Matrix1 [%d] * Matrix2 [%d] = %d\n", matrix1->data[matrix1->ix][matrix1->iy], matrix2->data[matrix1->ix][matrix1->iy], result->data[matrix1->ix][matrix1->iy]);
                    }
                }
            }
        }
    }
    return(result);
}

//Ordenar valores em um array, tanto em crescente como decrescente
int_Array OrdernarArray (int_Array array, int valor) {
    int_Array aux;
    int x = 0, y = 0;

    aux.length = array.length;

    if (valor == 0) {
        for (x = 0; x < array.length - 1; x = x + 1) { 
            for (y = 0; y < array.length - 1; y = y + 1) {
                if (array.data[y] > array.data[y + 1]) {
                    aux.data[y] = array.data[y];
                    array.data[y] = array.data[y + 1];
                    array.data[y + 1] = aux.data[y];
                }
            }
        }
    } else {
        if (valor == 1) {
            for (x = 1; x < array.length; x = x + 1) { 
                for (y = x; y < array.length; y = y + 1) {
                    if (array.data[x] < array.data[y]) {
                        aux.data[x] = array.data[x];
                        array.data[x] = array.data[y];
                        array.data[y] = aux.data[x];
                    }
                }
            }
        } else {
            printf("ERRO: Valor invalido.");
        }
    }

}

void method00 () {

}

void method01 () {
    //definir dado
    int_Array array;

    //montar arranjo em estrutura
    array.length = 5;
    array.data = (ints) malloc (array.length*sizeof(int));
    array.data[0] = 1;
    array.data[1] = 2;
    array.data[2] = 3;
    array.data[3] = 4;
    array.data[4] = 5;

    IO_id("Exemplo1010 - Method01 - v0.0");

    //executar o metodo auxiliar
    printIntArray(array);

    IO_pause("Apertar ENTER para continuar");
}

//ler e guardar dados em arranjo
void method02 () {
    int_Array array;

    IO_id("Exemplo1020 - Method02 - v0.0");

    array = IO_readintArray();

    IO_printf("\n");
    printIntArray(array);

    IO_pause("Apertar ENTER para continuar");
}

//gravar em um arquivo dados do arranjo
void method03 () {
    int_Array array;

    IO_id("Exemplo1030 - Method03 - v0.0");

    array = IO_readintArray();

    //mostrar dados
    IO_print("\n");
    fprintIntArray("Array1.txt", array);

    IO_pause("Apertar ENTER para continuar");
}

//ler arquivo e guardar dados em arranjo
void method04 () {
    int_Array array;

    IO_id("Exemplo1040 - Method04 - v0.0");

    array = fIO_readIntArray("Array1.txt");

    IO_printf("\n");
    printIntArray(array);

    IO_pause("Apertar ENTER para continuar");
}

//copiar dados de um arranjo para outro
void method05 () {
    int_Array array;
    int_Array other;

    IO_id("Exemplo1050 - Method05 - v0.0");

    //ler dados
    array = fIO_readIntArray("Array1.txt");

    //copiar dados
    other = copyIntArray(array);

    //mostrar dados
    IO_printf("\nOriginal\n");
    printIntArray(array);

    //mostrar dados
    IO_printf("\nCopia\n");
    printIntArray(other);

    IO_pause("Apertar ENTER para continuar");
}

//mostrar dados em matriz
void method06 () {
    ref_int_Matrix matrix = new_int_Matrix(3,3);

    matrix -> data [0][0] = 1;
    matrix -> data [0][1] = 2;
    matrix -> data [0][2] = 3;
    matrix -> data [1][0] = 4;
    matrix -> data [1][1] = 5;
    matrix -> data [1][2] = 6;
    matrix -> data [2][0] = 7;
    matrix -> data [2][1] = 8;
    matrix -> data [2][2] = 9;

    IO_id("Exemplo1060 - Method06 - v0.0");

    //executar o metodod auxiliar
    printIntMatrix(matrix);

    //reciclar espaco
    free_int_Matrix(matrix);

    IO_pause("Apertar ENTER para continuar");
}

//ler e armazenar dados em uma matriz
void method07 () {
    ref_int_Matrix matrix = NULL;

    IO_id("Exemplo1070 - Method07 - v0.0");

    //ler dados
    matrix = IO_readintMatrix();

    //mostrar dados
    IO_printf("\n");
    printIntMatrix(matrix);

    //reciclar espaco
    free_int_Matrix(matrix);

    IO_pause("Apertar ENTER para continuar");
}

//gravar dados de uma matriz em um arquivo
void method08 () {
    ref_int_Matrix matrix = NULL;

    IO_id("Exemplo1080 - Method08 - v0.0");

    //ler dados
    matrix = IO_readintMatrix();

    //gravar dados
    fprintIntMatrix("Matrix1.txt", matrix);

    //reciclar espaco
    free_int_Matrix(matrix);

    IO_pause("Apertar ENTER para continuar");
}

//ler uma matrix de um arquivo
void method09 () {

    IO_id("Exemplo1090 - Method09 - v0.0");

    //ler dados
    ref_int_Matrix matrix = freadIntMatrix("Matrix1.txt");

    //mostrar dados
    IO_printf("\n");
    printIntMatrix(matrix);

    //reciclar espaco
    free_int_Matrix(matrix);

    IO_pause("Apertar ENTER para continuar");
}

//copiar dados de uma matriz para outra
void method10 () {
    ref_int_Matrix matrix = NULL;
    ref_int_Matrix other = NULL;

    IO_id("Exemplo1100 - Method10 - v0.0");

    //ler dados
    matrix = freadIntMatrix("Matrix1.txt");

    //copiar dados
    other = copyIntMatrix(matrix);

    //mostrar dados
    IO_printf("\nOriginal\n");
    printIntMatrix(matrix);

    //mostrar dados
    IO_printf("\nCopia\n");
    printIntMatrix(other);

    //reciclar espaco
    free_int_Matrix(matrix);
    free_int_Matrix(other);

    IO_pause("Apertar ENTER para continuar");
}

void method11 () {
    int_Array array;
    int inferior = 0, superior = 0, quantidade = 0, valor = 0;

    IO_id("Exemplo1110 - Method11 - v0.0");

    inferior = IO_readint("Limite inferior: ");

    do {
        superior = IO_readint("Limite superior: ");
    } while (superior <= inferior);

    do {
        quantidade = IO_readint("Quantidade de valores a serem gerados: ");
    } while (quantidade <= 0);

    array = My_lib_readintArray(inferior, superior, quantidade);

    printIntArray(array);

    IO_pause("Apertar ENTER para continuar");
}

void method12 () {
    int_Array array;
    int resultado = 0, search = 0;

    IO_id("Exemplo1120 - Method12 - v0.0");

    search = IO_readint("Qual numero voce deseja procurar: ");

    array = fIO_readIntArray("Dados.txt");

    IO_printf("\n");
    resultado = searchLowerValue(array, search);

    if (resultado == 0) {
        printf("O valor %d nao foi encontrado no array.\n", search);
    } else {
        printf("\nO valor %d foi encontrado %d vez no array.\n", search, resultado);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method13 () {
    int_Array array1;
    int_Array array2;
    bool resultado = 0;

    IO_id("Exemplo1130 - Method13 - v0.0");

    array1 = fIO_readIntArray("Dados1.txt");
    array2 = fIO_readIntArray("Dados2.txt");

    resultado = compareTwoArrays(array1, array2);

    printf("\nArray1\n");
    printIntArray(array1);
    printf("\nArray2\n");
    printIntArray(array2);

    if (resultado == 1) {
        printf("\nOs arranjos sao identicos.\n");
    } else {
        printf("Os arranjos sao diferentes.\n");
    }

    IO_pause("Apertar ENTER para continuar");
}

void method14 () {
    int_Array array1;
    int_Array array2;
    int_Array resultado;
    int k = 0;

    IO_id("Exemplo1140 - Method14 - v0.0");

    array1 = fIO_readIntArray("Dados1.txt");
    array2 = fIO_readIntArray("Dados2.txt");

    k = IO_readint("Qual o valor da constante: ");
    printf("\n");

    resultado = sumTwoArraysWithConstant(array1, array2, k);

    printf("\n");
    printf("Resultado\n");
    printIntArray(resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method15 () {
    int_Array array;
    int resultado = 0;

    IO_id("Exemplo1150 - Method15 - v0.0");

    array = fIO_readIntArray("Dados1.txt");
    resultado = isOrdered(array);

    if (resultado == array.length) {
        printf("Crescente\n");
    } else {
        if (resultado == 0) {
            printf("Decrescente\n");
        } else {
            printf("Desordenado\n");
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void method16 () {
    ref_int_Matrix matrix1;
    ref_int_Matrix matrix2;

    IO_id("Exemplo1160 - Method16 - v0.0");

    matrix1 = freadIntMatrix("DadosMatriz1.txt");
    printf("\nOriginal\n");
    printIntMatrix(matrix1);

    printf("\n");

    matrix2 = transposedMatrix(matrix1);
    printf("\nTransposta\n");
    printIntMatrix(matrix2);

    free_int_Matrix(matrix1);
    free_int_Matrix(matrix2);

    IO_pause("Apertar ENTER para continuar");
}

void method17 () {
    ref_int_Matrix matrix1;
    int resultado = 0;

    IO_id("Exemplo1170 - Method17 - v0.0");

    matrix1 = freadIntMatrix("DadosMatriz1.txt");
    resultado = isAllEqualZeroMatrix(matrix1);

    if (resultado == matrix1->columns * matrix1->lines) {
        printf("A matriz contem apenas valores iguais a zero.\n");
    } else {
        printf("A matriz nao contem todos os valores iguais a zero.\n");
    }

    IO_pause("Apertar ENTER para continuar");
}

void method18 () {
    ref_int_Matrix matrix1;
    ref_int_Matrix matrix2;
    int resultado = 0;

    IO_id("Exemplo1180 - Method18 - v0.0");

    matrix1 = freadIntMatrix("DadosMatriz3.txt");
    matrix2 = freadIntMatrix("DadosMatriz4.txt");

    resultado = CompareTwoMatrix(matrix1, matrix2);

    if (resultado == matrix1->columns * matrix1->lines) {
        printf("\nAs matrizes sao identicas\n");
    } else {
        printf("\nAs matrizes sao diferentes.\n");
    }

    IO_pause("Apertar ENTER para continuar");
}

void method19 () {
    ref_int_Matrix matrix1;
    ref_int_Matrix matrix2;
    ref_int_Matrix resultado;
    int k = 0;

    IO_id("Exemplo1190 - Method19 - v0.0");

    matrix1 = freadIntMatrix("DadosMatriz3.txt");
    matrix2 = freadIntMatrix("DadosMatriz4.txt");
    k = IO_readint("Qual sera o valor da constante: ");
    printf("\n");

    resultado = sumTwoMatrixsWithConstant(matrix1, matrix2, k);
    printf("\n");
    printf("Resultado da soma das matrizes:\n");
    printf("\n");
    printIntMatrix(resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method20 () {
    ref_int_Matrix matrix1;
    ref_int_Matrix matrix2;
    ref_int_Matrix resultado;

    IO_id("Exemplo1200 - Method20 - v0.0");

    matrix1 = freadIntMatrix("DadosMatriz3.txt");
    matrix2 = freadIntMatrix("DadosMatriz4.txt");
    resultado = multiplyTwoMatrix(matrix1, matrix2);

    printf("\n");
    printf("Resultado da multiplicacao das matrizes:\n");
    printIntMatrix(resultado);

    IO_pause("Apertar ENTER para continuar");
}

//Esse metodo nao esta funcionando direito, ele esta entrando em loop
//quando chega no ultimo elemento, ou seja, ele ordena ate o penultimo elemento
//mas o ultimo ele coloca 0 e simplesmente nao funciona mais, nao consegui
//entender onde estava o problema
void method21 () {
    int_Array array;
    int_Array resultado;
    int valor = 0;

    IO_id("Exemplo1210 - Method21 - v0.0");

    array = fIO_readIntArray("DadosQuestao21.txt");

    do {
        valor = IO_readint("Ordenar por crescente(0) ou decrescente(1): ");
    } while (valor != 0 && valor != 1);

    resultado = OrdernarArray(array, valor);

    printf("\nOriginal\n");
    printIntArray(array);
    printf("\nModificado\n");
    printIntArray(resultado);

    IO_pause("Apertar ENTER para continuar");
}


int main () {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "Ed10 - v.1 - 27/10/2020\n"       );
        IO_println ( "Estudo Dirigido 10\n"          );
        IO_println ( "Matricula: 716417\nNome: Daniel Vitor de Oliveira Santos\n" );
        IO_println ( "" ); 

        IO_println ( "Opcoes" );
        IO_println ( " 0 - parar" );
        IO_println ( " 1 - method01" );
        IO_println ( " 2 - method02" );
        IO_println ( " 3 - method03" );
        IO_println ( " 4 - method04" );
        IO_println ( " 5 - method05" );
        IO_println ( " 6 - method06" );
        IO_println ( " 7 - method07" );
        IO_println ( " 8 - method08" );
        IO_println ( " 9 - method09" );
        IO_println ( "10 - method10" );
        IO_println ( "11 - method11" );
        IO_println ( "12 - method12" );
        IO_println ( "13 - method13" );
        IO_println ( "14 - method14" );
        IO_println ( "15 - method15" );
        IO_println ( "16 - method16" );
        IO_println ( "17 - method17" );
        IO_println ( "18 - method18" );
        IO_println ( "19 - method19" );
        IO_println ( "20 - method20" );
        IO_println ( "21 - method21" );
        IO_println ( "" );

        x = IO_readint("Entrar com uma opcao: ");

        switch(x) {
            case 0:
                method00();
            break;
            case 1:
                method01();
            break;
            case 2:
                method02();
            break;
            case 3:
                method03();
            break;
            case 4:
                method04();
            break;
            case 5:
                method05();
            break;
            case 6:
                method06();
            break;
            case 7:
                method07();
            break;
            case 8:
                method08();
            break;
            case 9:
                method09();
            break;
            case 10:
                method10();
            break;
            case 11:
                method11();
            break;
            case 12:
                method12();
            break;
            case 13:
                method13();
            break;
            case 14:
                method14();
            break;
            case 15:
                method15();
            break;
            case 16:
                method16();
            break;
            case 17:
                method17();
            break;
            case 18:
                method18();
            break;
            case 19:
                method19();
            break;
            case 20:
                method20();
            break;
            case 21:
                method21();
            break;
            default:
            break;
            IO_pause ( "ERRO: Valor invalido." );
        }
    } while (x != 0);

    IO_pause("Apertar ENTER para terminar");
    return(0);
}
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 27/10 esboco
---------------------------------------------- testes
Algoritmo           entrada             saida

*/

