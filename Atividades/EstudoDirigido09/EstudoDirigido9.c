/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Ed09
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 22/10/2020
*/

#include "io.h"
#include "MyLib.h"

//Mostrar dados em uma matriz
void printIntMatrix (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;

    //mostrar valores na matriz
    printf("\n");
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            IO_printf("%3d\t", matrix[x][y]);
        }
        IO_printf("\n");
    }
}

//Ler e guardar dados em matriz
void readIntMatrix (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;
    int z = 0;
    chars text = IO_new_chars(STR_SIZE);

    //ler e guardar valores em arranjo
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            strcpy(text, STR_EMPTY);
            z = IO_readint(IO_concat (
                IO_concat (IO_concat (text, IO_toString_d (x)), ", "),
                IO_concat (IO_concat (text, IO_toString_d(y)), ": ")));
            //guardar valor
            matrix[x][y] = z;
        }
    }
}

//Gravar em arquivo dados da matriz.
void fprintIntMatrix (chars fileName, int lines, int columns, int matrix[][columns]) {
    FILE* arquivo = fopen(fileName, "wt");
    int x = 0;
    int y = 0;

    //gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", lines);
    IO_fprintf(arquivo, "%d\n", columns);

    //gravar valores no arquivo
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            //gravar valor
            IO_fprintf(arquivo, "%d\n", matrix[x][y]);
        }
    }
    fclose(arquivo);
}

//Ler tamanho das linhas da matriz com valores inteiros
int freadMatrixRows (chars fileName) {
    int n = 0;
    FILE* arquivo = fopen(fileName, "rt");

    //ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);

    if (n <= 0) {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }

    //retornar dado lido
    return(n);
}

//Ler tamanho das colunas da matriz com valores inteiros
int freadMatrixColumns (chars fileName) {
    int n = 0;
    FILE* arquivo = fopen(fileName, "rt");

    //ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);
    IO_fscanf(arquivo, "%d", &n);

    if (n <= 0) {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }
    return(n);
}

//Ler arranjo bidimensional com valores inteiros
void freadIntMatrix(chars fileName, int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;
    int z = 0;
    FILE* arquivo = fopen (fileName, "rt");

    //ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &x);
    IO_fscanf(arquivo, "%d", &y);

    if (lines <= 0 || lines > x || columns <= 0 || columns > y) {
        IO_println("ERRO: Valor invalido.");
    } else {
        //ler e guardar valores em arranjo
        x = 0;
        while (! feof(arquivo) && x < lines) {
            y = 0;
            while (! feof(arquivo) && y < columns) {
                //ler valor
                IO_fscanf(arquivo, "%d", &z);
                //guardar valor
                matrix [x][y] = z;
                //passar ao proximo
                y = y + 1;
            }
            x = x + 1;
        }
    }
}

//Copiar dados de uma matriz para outra.
void copyIntMatrix (int lines, int columns, int matrix2[][columns], int matrix1[][columns]) {
    int x = 0;
    int y = 0;

    if (lines <= 0 || columns <= 0) {
        IO_println("ERRO: Valor invalido.");
    } else {
        //copiar valores em matiz
        for (x = 0; x < lines; x = x + 1) {
            for (y = 0; y < columns; y = y + 1) {
                matrix2[x][y] = matrix1[x][y];
            }
        }
    }
}

//Fazer a transposição de uma matriz
void transposeIntMatrix (int lines, int columns, int matrix2[][lines], int matrix1[][columns]) {
    int x = 0;
    int y = 0;

    //percorrer a matriz
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            matrix2[y][x] = matrix1[x][y];
        }
    } 
}

//Dizer se uma matriz é identidade.
bool isIdentity (int lines, int columns, int matrix[][columns]) {
    bool result = true;
    int x = 0;
    int y = 0;

    if (lines <= 0 || columns <= 0 || lines != columns) {
        IO_println("ERRO: Valor invalido");
    } else {
        x = 0;
        while (x < lines && result) {
            y = 0;
            while (y < columns && result) {
                if (x == y) {
                    result = result && (matrix[x][y] == 1);
                } else {
                    result = result && (matrix[x][y] == 0);
                }
                y = y + 1;
            }
            x = x + 1;
        }
    }
    return(result);
}

//Testar a igualdade de dados em duas matrizes, posição por posição.
bool isEqual (int lines, int columns, int matrix1[][columns], int matrix2[][columns]) {
    bool result = true;
    int x = 0;
    int y = 0;

    //mostrar valores na matriz
    x = 0;
    while (x < lines && result) {
        y = 0;
        while (y < columns && result) {
            //restar valor
            result = result && (matrix1[x][y] == matrix2[x][y]);
            y = y + 1;
        }
        x = x + 1;
    }
    return(result);
}

//Somar dados em duas matrizes, posição por posição.
void addIntMAtrix (int lines, int columns, int matrix3[][columns], int matrix1[][columns], int k, int matrix2[][columns]) {
    int x = 0;
    int y = 0;

    //mostrar valores na matriz
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            //somar valores
            matrix3[x][y] = matrix1[x][y] + k*matrix2[x][y];
        }
    }
}

//Calcular o produto de matrizes
void mulIntMatrix (int lines3, int columns3, int matrix3[][columns3], int lines1, int columns1, int matrix1[][columns1], int lines2, int columns2, int matrix2[][columns2]) {
    int x = 0;
    int y = 0;
    int z = 0;
    int soma = 0;

    if (lines1 <= 0 || columns1 == 0 ||
        lines2 <= 0 || columns2 == 0 ||
        lines3 <= 0 || columns3 == 0 ||
        columns1 != lines2 ||
        lines1 != lines3 ||
        columns2 != columns3) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        //percorer valores na matriz resultante
        for (x = 0; x < lines3; x = x + 1) {
            for (y = 0; y < columns3; y = y + 1) {
                //somar valores
                soma = 0;
                for (z = 0; z < columns1; z = z + 1) {
                    soma = soma + matrix1[x][z]* matrix2[z][y];
                }
                //guardar a soma
                matrix3[x][y] = soma;
            }
        }
    }
}

//Ler e guardar dados (positivos) em uma matriz
void readIntMatrixPositive (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;
    int z = 0;
    chars text = IO_new_chars(STR_SIZE);

    //ler e guardar valores em arranjo
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            strcpy(text, STR_EMPTY);
            z = IO_readint(IO_concat (
                IO_concat (IO_concat (text, IO_toString_d (x)), ", "),
                IO_concat (IO_concat (text, IO_toString_d(y)), ": ")));
            if (z < 0) {
                IO_printf("ERRO: O valor nao pode ser negativo, valor 0 atribuido.\n");
            } else {
                //guardar valor
                matrix[x][y] = z;
            }
        }
    }
}

//Mostrar se a matriz e quadrada ou nao
bool readAndShowIsQuadratic (int lines, int columns, int matrix[][columns]) {
    bool result = false;
    int contador1 = 0;
    int contador2 = 0;

    if (lines <= 0 || columns <= 0 || lines != columns || lines == 1 || columns == 1) {
        IO_println("ERRO: A matrix nao e identidade.");
        return(result);
    } else {
        IO_println("\nMatriz identidade.");
        result = true;
        return(result);
    }
}

//Mostrar os valores pares da diagonal principal de uma matriz
void printIntMatrixIdentityEven (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;

    printf("\n");
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            if (x == y && matrix[x][y]%2 == 0) {
                IO_printf("%3d\t", matrix[x][y]);
            } else {
                IO_printf("\t");
            }
        }
        IO_printf("\n");
    }
}

//Mostrar os valores impares da diagonal secundaria de uma matriz
void printIntMatrixSecundaryOdd (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;

    printf("\n");
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            if ((x + y == columns - 1) && (matrix[x][y]%2 != 0)) {
                IO_printf("%3d\t", matrix[x][y]);
            } else {
                IO_printf("\t");
            }
        }
        IO_printf("\n");
    }
}

//Mostrar os valores multiplos de 3 abaixo da diagonal principal
void printIntMatrixIdentityTriangleLower (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;

    printf("\n");
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            if ((x > y) && (matrix[x][y]%3 == 0)) {
                IO_printf("%3d\t", matrix[x][y]);
            } else {
                IO_printf("\t");
            }
        }
        IO_printf("\n");
    }
}

//Mostrar os valores multiplos de 5 acima da diagonal principal
void printIntMatrixIndentityTriangleUpper (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;

    printf("\n");
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            if ((x < y) && (matrix[x][y]%5 == 0)) {
                IO_printf("%3d\t", matrix[x][y]);
            } else {
                IO_printf("\t");
            }
        }
        IO_printf("\n");
    }
}

//Mostrar os valores multiplos de 3 impares abaixo da diagonal secundaria
void printIntMatrixSecundaryTriangleLower (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;

    printf("\n");
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            if (((x + 1) + (y + 1) > columns + 1) && (matrix[x][y]%3 == 0) && (matrix[x][y]%2 != 0)) {
                IO_printf("%3d\t", matrix[x][y]);
            } else {
                IO_printf("\t");
            }
        }
        IO_printf("\n");
    }
}

//Mostrar os valores multiplos de 5 pares acima da diagonal secundaria
void printIntMatrixSecundaryTriangleUpper (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;

    printf("\n");
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            if (((x + 1) + (y + 1) < columns + 1) && (matrix[x][y]%5 == 0) && (matrix[x][y]%2 == 0)) {
                IO_printf("%3d\t", matrix[x][y]);
            } else {
                IO_printf("\t");
            }
        }
        IO_printf("\n");
    }
}

//Testar os valores sao todos zeros abaixo da diagonal principal
int printIntMatrixIdentityTriangleLowerTest (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;
    int contador = 0;

    printf("\n");
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            if ((x > y)) {
                if (matrix[x][y] == 0) {
                    contador = contador + 1;
                }
                IO_printf("%3d\t", matrix[x][y]);
            } else {
                IO_printf("\t");
            }
        }
        IO_printf("\n");
    }
    
    return(contador);
}

//Testar os valores sao todos zeros acima da diagonal principal
int printIntMatrixIdentityTriangleUpperTest (int lines, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;
    int contador = 0;

    printf("\n");
    for (x = 0; x < lines; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            if ((x < y)) {
                if (matrix[x][y] == 0) {
                    contador = contador + 1;
                }
                IO_printf("%3d\t", matrix[x][y]);
            } else {
                IO_printf("\t");
            }
        }
        IO_printf("\n");
    }
    
    return(contador);
}

void method00 () {

}

//Mostrar dados em uma matriz
void method01 () {
    int matrix [][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

    IO_id("Exemplo0901 - Method01 - v0.0");

    printIntMatrix(3, 3, matrix);

    IO_pause("Apertar ENTER para continuar");
}

//Ler e guardar dados em matriz
void method02 () {
    int n = 2;
    int matrix [n][n];

    IO_id("Exemplo0902 - Method02 - v0.0");

    //ler dados
    readIntMatrix(n, n, matrix);

    //mostrar dados
    IO_printf("\n");
    printIntMatrix(n, n, matrix);

    IO_pause("Apertar ENTER para continuar");
}

//Gravar em arquivo dados da matriz.
void method03 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0903 - Method03 - v0.0");

    lines = IO_readint("\nlines = ");
    columns = IO_readint("\ncolumns = ");
    IO_printf("\n");

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        //reservar espaco
        int matrix [lines][columns];
        //ler dados
        readIntMatrix(lines, columns, matrix);
        //mostrar dados
        IO_printf("\n");
        printIntMatrix(lines, columns, matrix);
        //gravar dados
        IO_printf("\n");
        fprintIntMatrix("Matrix1.txt", lines, columns, matrix);
    }

    IO_pause("Apertar ENTER para continuar");
}

//Ler arquivo e guardar dados em matriz.
void method04 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0904 - Method04 - v0.0");

    lines = freadMatrixRows("Matrix1.txt");
    columns = freadMatrixColumns("Matrix1.txt");

    if (lines <= 0 || columns <= 0) {
        IO_println("ERRO: Valor invalido.");
    } else {
        //definir armazenador
        int matrix [lines][columns];
        //ler dados
        freadIntMatrix("Matrix1.txt", lines, columns, matrix);
        //mostrar dados
        IO_printf("\n");
        printIntMatrix(lines, columns, matrix);
    }

    IO_pause("Apertar ENTER para continuar");
}

//Copiar dados de uma matriz para outra.
void method05 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0905 - Method05 - v0.0");

    lines = freadMatrixRows("Matrix1.txt");
    columns = freadMatrixColumns("Matrix1.txt");

    if (lines <= 0 || columns <= 0) {
        IO_println("ERRO: Valor invalido.");
    } else {
        int matrix[lines][columns];
        int other[lines][columns];

        //ler dados
        freadIntMatrix("Matrix1.txt", lines, columns, matrix);
        //copiar dados
        copyIntMatrix(lines, columns, other, matrix);
        //mostrar dados
        IO_printf("\nOriginal\n");
        printIntMatrix(lines, columns, matrix);
        //mostrar dados
        IO_printf("\nCopia\n");
        printIntMatrix(lines, columns, other);
    }

    IO_pause("Apertar ENTER para continuar");
}

//Fazer a transposição de uma matriz
//As quantidades de linha e colunas estarão trocadas na matriz transposta.
void method06 () {
    int matrix1[][2] = { {1,0}, {0,1} };
    int matrix2[][2] = { {0,0}, {0,0} };
    int matrix3[][3] = { {1,2,3}, {4,5,6} };
    int matrix4[][3] = { {1,2,3}, {4,5,6} };

    IO_id("Exemplo0906 - Method06 - v0.0");

    //testar dados
    IO_println("\nMatrix1");
    printIntMatrix(2, 2, matrix1);

    transposeIntMatrix(2, 2, matrix2, matrix1);

    IO_println("\nMatrix2");
    printIntMatrix(2, 2, matrix2);

    IO_println("\nMatrix3");
    printIntMatrix(2, 3, matrix3);

    transposeIntMatrix(2, 3, matrix4, matrix3);

    IO_println("\nMatrix4");
    printIntMatrix(3, 2, matrix4);

    IO_pause("Apertar ENTER para continuar");
}

void method07 () {
    int matrix1[][2] = { {0,0}, {0,0} };
    int matrix2[][3] = { {1,2,3}, {4,5,6} };
    int matrix3[][2] = { {1,0}, {0,1} };

    IO_id("Exemplo0907 - Method07 - v0.0");

    //testar dados
    IO_println("\nMatrix1");
    printIntMatrix(2, 2, matrix1);
    IO_printf("isIdentity(matrix1) = %d", isIdentity(2, 2, matrix1));

    IO_println("\nMatrix2");
    printIntMatrix(2, 3, matrix2);
    IO_printf("isIdentity(matrix2) = %d", isIdentity(2, 3, matrix2));

    IO_println("\nMatrix3");
    printIntMatrix(2, 2, matrix3);
    IO_printf("isIdentity(matrix3) = %d", isIdentity(2, 2, matrix3));

    IO_pause("Apertar ENTER para continuar");
}

//Testar a igualdade de dados em duas matrizes, posição por posição.
void method08 () {
    int matrix1[][2] = { {0,0}, {0,0} };
    int matrix2[][2] = { {1,2}, {3,4} };
    int matrix3[][2] = { {1,0}, {0,1} };

    IO_id("Exemplo0908 - Method08 - v0.0");

    //testar dados
    IO_println("\nMatrix1");
    printIntMatrix(2, 2, matrix1);

    IO_println("\nMatrix2");
    printIntMatrix(2, 2, matrix2);

    IO_printf("isEqual(matrix1, matrix2) = %d", isEqual(2, 2, matrix1, matrix2));

    copyIntMatrix (2, 2, matrix1, matrix3);
    copyIntMatrix (2, 2, matrix2, matrix3);

    IO_println("\nMatrix1");
    printIntMatrix(2, 2, matrix1);

    IO_println("\nMatrix3");
    printIntMatrix(2, 2, matrix2);

    IO_printf("isEqual(matrix1, matrix2) = %d", isEqual(2, 2, matrix1, matrix2));

    IO_pause("Apertar ENTER para continuar");
}

//Somar dados em duas matrizes, posição por posição.
void method09 () {
    int matrix1[][2] = { {1,2}, {3,4} };
    int matrix2[][2] = { {1,0}, {0,1} };
    int matrix3[][2] = { {0,0}, {0,0} };


    IO_id("Exemplo0909 - Method09 - v0.0");

    //testar dados
    IO_println("\nMatrix1");
    printIntMatrix(2, 2, matrix1);

    IO_println("\nMatrix2");
    printIntMatrix(2, 2, matrix2);

    //somar matrizes
    addIntMAtrix(2, 2, matrix3, matrix1, (-2), matrix2);

    IO_println("\nMatrix3");
    printIntMatrix(2, 2, matrix3);

    IO_pause("Apertar ENTER para continuar");
}

void method10 () {
    int matrix1[][2] = { {1,2}, {3,4} };
    int matrix2[][2] = { {1,0}, {0,1} };
    int matrix3[][2] = { {0,0}, {0,0} };

    IO_id("Exemplo0910 - Method10 - v0.0");

    //testar produto
    IO_println("\nMatrix1");
    printIntMatrix(2, 2, matrix1);
    IO_println("\nMatrix2");
    printIntMatrix(2, 2, matrix2);

    //multiplicar matrizes
    mulIntMatrix(2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2);
    IO_println("\nMatrix3 = Matrix1 * matrix2");
    printIntMatrix(2, 2, matrix3);

    //outro teste
    IO_println("\nMatrix2");
    printIntMatrix(2, 2, matrix2);
    IO_println("\nMatrix1");
    printIntMatrix(2, 2, matrix1);

    //multiplicar matrizes
    mulIntMatrix(2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1);
    IO_println("\nMatrix3 = Matrix2 * Matrix1");
    printIntMatrix(2, 2, matrix3);

    IO_pause("Apertar ENTER para continuar");
}

void method11 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0911 - Method11 - v0.0");

    lines = IO_readint("\nlinhas = ");
    columns = IO_readint("\ncolunas = ");
    IO_printf("\n");

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        IO_printf("\n");
        printIntMatrix(lines, columns, matrix);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method12 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0912 - Method12 - v0.0");

    lines = IO_readint("\nlinhas = ");
    columns = IO_readint("\ncolunas = ");
    IO_printf("\n");

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        fprintIntMatrix("Matrix0912.txt", lines, columns, matrix);
        IO_printf("\n");
        freadIntMatrix("Matrix0912.txt", lines, columns, matrix);
        printIntMatrix(lines, columns, matrix);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method13 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0913 - Method13 - v0.0");

    lines = IO_readint("\nlinhas = ");
    columns = IO_readint("\ncolunas = ");
    IO_printf("\n");

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        if (readAndShowIsQuadratic(lines, columns, matrix) == 1) {
            printIntMatrixIdentityEven(lines, columns, matrix);
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void method14 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0914 - Method14 - v0.0");

    lines = IO_readint("\nLinhas = ");
    columns = IO_readint("\nColunas = ");

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        if (readAndShowIsQuadratic(lines, columns, matrix) == 1) {
            printIntMatrixSecundaryOdd(lines, columns, matrix);
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void method15 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0915 - Method15 - v0.0");

    lines = IO_readint("\nLinhas = ");
    columns = IO_readint("\nColunas = ");

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        if (readAndShowIsQuadratic(lines, columns, matrix) == 1) {
            printIntMatrixIdentityTriangleLower(lines, columns, matrix);
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void method16 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0916 - Method16 - v0.0");

    lines = IO_readint("\nLinhas = ");
    columns = IO_readint("\nColunas = ");

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        if (readAndShowIsQuadratic(lines, columns, matrix) == 1) {
            printIntMatrixIndentityTriangleUpper(lines, columns, matrix);
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void method17 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0917 - Method17 - v0.0");

    lines = IO_readint("\nLinhas = ");
    columns = IO_readint("\nColunas = ");

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        if (readAndShowIsQuadratic(lines, columns, matrix) == 1) {
            printIntMatrixSecundaryTriangleLower(lines, columns, matrix);
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void method18 () {
    int lines = 0;
    int columns = 0;

    IO_id("Exemplo0918 - Method18 - v0.0");

    lines = IO_readint("\nLinhas = ");
    columns = IO_readint("\nColunas = ");

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        if (readAndShowIsQuadratic(lines, columns, matrix) == 1) {
            printIntMatrixSecundaryTriangleUpper(lines, columns, matrix);
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void method19 () {
    int lines = 0;
    int columns = 0;
    int resultado = 0;
    int NumeroMax = 0;

    IO_id("Exemplo0919 - Method19 - v0.0");

    lines = IO_readint("\nLinhas = ");
    columns = IO_readint("\nColunas = ");

    NumeroMax = ((lines*columns) - columns)/2;

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        if (readAndShowIsQuadratic(lines, columns, matrix) == 1) {
            resultado = printIntMatrixIdentityTriangleLowerTest(lines, columns, matrix);
            if (resultado == NumeroMax) {
                printf("Todos os valores do triangulo inferior da diagonal principal sao iguais a zero.\n");
                printf("Numero maximo de valores do triangulo inferior = %d\n", NumeroMax);
                printf("Quantidade de digitos iguais a zero = %d\n", resultado);
            } else {
                printf("Os valores do triangulo inferior da diagonal principal NAO sao todos iguais a zero.\n");
                printf("Numero maximo de valores do triangulo inferior = %d\n", NumeroMax);
                printf("Quantidade de digitos iguais a zero = %d\n", resultado);
            }
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void method20 () {
    int lines = 0;
    int columns = 0;
    int resultado = 0;
    int NumeroMax = 0;
    

    IO_id("Exemplo0920 - Method20 - v0.0");

    lines = IO_readint("\nLinhas = ");
    columns = IO_readint("\nColunas = ");

    NumeroMax = ((lines*columns) - columns)/2;

    if (lines <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix [lines][columns];
        readIntMatrixPositive(lines, columns, matrix);
        if (readAndShowIsQuadratic(lines, columns, matrix) == 1) {
            resultado = printIntMatrixIdentityTriangleUpperTest(lines, columns, matrix);
            if (resultado == NumeroMax) {
                printf("Todos os valores do triangulo inferior da diagonal principal sao iguais a zero.\n");
                printf("Numero maximo de valores do triangulo inferior = %d\n", NumeroMax);
                printf("Quantidade de digitos iguais a zero = %d\n", resultado);
            } else {
                printf("Os valores do triangulo inferior da diagonal principal NAO sao todos iguais a zero.\n");
                printf("Numero maximo de valores do triangulo inferior = %d\n", NumeroMax);
                printf("Quantidade de digitos iguais a zero = %d\n", resultado);
            }
        }
    }

    IO_pause("Apertar ENTER para continuar");
}


int main () {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "Ed09 - v.1 - 22/10/2020\n"       );
        IO_println ( "Estudo Dirigido 09\n"          );
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
 0.1 22/10 esboco
---------------------------------------------- testes
Algoritmo           entrada             saida

*/