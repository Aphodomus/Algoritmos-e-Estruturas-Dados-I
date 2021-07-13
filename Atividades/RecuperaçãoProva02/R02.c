/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Recuperacao 02
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 22/11/2020
*/

#include "io.h"

//Definicao de tipo arranjo com inteiros baseado em estrutura
typedef struct s_int_Array {
    int length;
    ints data;
    int ix;
} int_Array;

//Definicao de tipo de arranjo com inteiros baseados em estrutura supermercado
typedef struct market_int_Array {
    chars nome;
    int codigo;
    double precoProduto;
} intArrayMarket;

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

//ler arquivo e guardar dados em arranjo, ate o ultimo digito ser 0
int_Array readFile (chars fileName) {
    int x = 0;
    int y = 0;
    FILE* arquivo = fopen (fileName, "rt");
    static int_Array array;
    int valor = 0;
    int tamanho = 0;

    while (!feof (arquivo)) {
        fscanf(arquivo, "%d", &valor);
        if (valor == 0) {
            break;
        }
        //passar ao proximo
        tamanho = tamanho + 1;
    }

    FILE* arquivo2 = fopen (fileName, "rt");

    array.length = tamanho;
    array.data = IO_new_ints(array.length);
    array.ix = 0;

    while ( array.ix < tamanho) {
        //ler valor
        fscanf(arquivo2, "%d", &(array.data[array.ix]));
        //passar ao proximo
        array.ix = array.ix + 1;
    }

    return(array);
}

//mostrar array com valores intieros
void printIntArray (int_Array array) {
    //mostrar valores no arranjo
    for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1) {
        //mostrar valor
        printf("%2d: %d\n", array.ix, array.data[array.ix]);
    }
}

//Resolucao do exercicio 1
int_Array resolucaoExercicio01(int_Array array) {
    int_Array result;
    result.length = array.length;
    result.data = IO_new_ints(result.length);

    int numero = 0, contador = 0, x = 0;

    for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1) {
        numero = array.data[array.ix];
        contador = 0;
        for (x = 1; x <= numero; x = x + 1) {
            if (numero%x == 0) {
                contador = contador + 1;
            }
        }
        result.data[array.ix] = contador;
    }
    return(result);
}

//Transformar um array binario em um numero decimal
int BinaryToDecimal(int_Array array) {
    int resultado = 0, decimal = 0, elevar = 0;

    elevar = array.length - 1;

    for (int x = 0 ; x < array.length; x = x + 1) {
        decimal = array.data[x] * pow(2, elevar);
        elevar = elevar - 1;
        resultado = resultado + decimal;
    }

    return(resultado);
}


//Ler N valores de um arquivo e guardar em um array
int_Array readNValues(chars fileName, int quantidade) {
    FILE* arquivo = fopen(fileName, "rt");
    static int_Array array;
    int tamanho = 0;

    array.length = quantidade;
    array.data = IO_new_ints(array.length);
    array.ix = 0;
    fscanf(arquivo, "%d", &tamanho);

    if (quantidade != 0) {
        while(array.ix <= quantidade) {
            fscanf(arquivo, "%d", &(array.data[array.ix]));
            array.ix = array.ix + 1;
        }
    } else {
        printf("Erro: Tamanho do arquivo invalido.");
    }
    fclose(arquivo);

    return(array);
}

//Gravar resultados do exercicio1
void GravarResultado(chars fileName, int tamanho, int Maior, int Menor) {
    FILE* arquivo = fopen(fileName, "wt");

    fprintf(arquivo, "%d\n", tamanho);
    fprintf(arquivo, "%d\n", Maior);
    fprintf(arquivo, "%d\n", Menor);

    fclose(arquivo);
}

//Calcular a soma dos divisores de um numero qualquer
int somaDosDivisores(int numero) {
    int x = 0, somaDosDivisores;

    for (x = 1; x <= numero; x = x + 1) {
        if (numero%x == 0) {
            somaDosDivisores = somaDosDivisores + x;
        }
    }
    return(somaDosDivisores);
}

//Verificar se um valor inteiro e perfeito
bool isPerfectNumber(int numero, int somaDosDivisores) {
    bool result = false;
    int somaDivisoresProprios = 0;

    somaDivisoresProprios = somaDosDivisores - numero;
    if (numero == somaDivisoresProprios) {
        result = true;
    }
    return(result);
}

//Calcular e gravar numeros perfeitos em arquivo
void calcularEgravarPerfeitos() {
    int numero = 0, somaDosD = 0, resultPerfectN = 0, quantidade = 0, T = 0;
    bool result = false;
    int_Array array;
    array.length = 1;
    array.data = IO_new_ints(array.length);

    for (numero = 1000; numero < 10000; numero = numero + 1) {
        somaDosD = 0;
        resultPerfectN = 0;

        somaDosD = somaDosDivisores(numero);
        resultPerfectN = isPerfectNumber(numero, somaDosD);
        result = resultPerfectN;

        printf("bool = %d\n", result);

        if (result == 1) {
            quantidade = quantidade + 1;
            array.data[T] = numero;
            T = T + 1;
        }
    }
    printf("\nPerfeitos entre 1000 e 9999:\n");
    printIntArray(array);
    gravarNumerosPerfeitos("Perfeitos.txt", array);
}

//Gravar os numeros perfeitos em arquivo
void gravarNumerosPerfeitos(chars fileName, int_Array array) {
    FILE* arquivo = fopen(fileName, "wt");

    fprintf(arquivo, "%d\n", array.length);

    array.ix = 0;
    while (array.ix < array.length) {
        fprintf(arquivo, "%d\n", array.data[array.ix]);
        array.ix = array.ix + 1;
    }
    fclose(arquivo);
}

//Calcular o MDC de 2 numeros 
int calcularMDC(int x, int y) {
    int restoDaDivisao = 0;

    while (y != 0) {
        restoDaDivisao = x % y;
        x = y;
        y = restoDaDivisao;
    }
    return(x);
}

//Ler arquivo com e armazenar em arranjo
int_Array lerArquivoEGravar(chars fileName) {
    FILE* arquivo = fopen(fileName, "rt");
    int tamanho = 0;
    static int_Array array;
    array.length = 2;
    array.data = IO_new_ints(array.length);

    fscanf(arquivo, "%d", &tamanho);

    if (tamanho == 2) {
        while(! feof(arquivo) && array.ix < array.length) {
            fscanf(arquivo, "%d", &array.data[array.ix]);
            array.ix = array.ix + 1;
        }
    } else {
        printf("Erro: Tamanho do arquivo invalido.");
    }

    fclose(arquivo);

    return(array);
}

//Calcular o MMC de 2 numeros
int calcularMMC(int x, int y) {
    for (int contador = 1; contador < (x * y); contador = contador + 1) {
        if (contador%x == 0 && contador%y == 0) {
            return(contador);
        }
    }
}

//Inverter array e devolver o array invertido como resposta
int_Array inverterArray(int_Array array) {
    static int_Array result;
    result.length = array.length;
    result.data = IO_new_ints(result.length);
    int contador = 1;

    for (int x = 0; x < array.length; x = x + 1) {
        result.data[x] = array.data[(array.length - contador)];
        contador = contador + 1;
    }

    return(result);
}

//Gravar dados em um arquivo
void gravarDadosEmArquivo(chars fileName, int_Array array) {
    FILE* arquivo = fopen(fileName, "wt");

    fprintf(arquivo, "%d\n", array.length);
    array.ix = 0;
    while (array.ix < array.length) {
        fprintf(arquivo, "%d\n", array.data[array.ix]);
        array.ix = array.ix + 1;
    }
    fclose(arquivo);
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

//Verificar quais sao os valores comuns a ambos os arranjos e voltar eles em um arranjo
int_Array commomToBoth(int_Array array1, int_Array array2) {
    static int_Array result;
    static int_Array result2;
    int tamanho = 0;
    int k = 0;

    if (array1.length > array2.length) {
        result.length = array1.length;
    } else {
        if (array2.length > array1.length) {
            result.length = array2.length;
        } else {
            result.length = array1.length;
        }
    }

    result.data = IO_new_ints(result.length);

    for (array1.ix = 0; array1.ix < array1.length; array1.ix = array1.ix + 1) {
        for (array2.ix = 0; array2.ix < array2.length; array2.ix = array2.ix + 1) {
            if (array1.data[array1.ix] == array2.data[array2.ix]) {
                result.data[k++] = array1.data[array1.ix];
                tamanho = tamanho + 1;
            }
        }
    }
    
    result2.length = tamanho;
    result2.data = IO_new_ints(result2.length);

    for (result2.ix = 0; result2.ix < tamanho; result2.ix = result2.ix + 1) {
        result2.data[result2.ix] = result.data[result2.ix];
    }

    return(result2);
}

//ler dados de um arquivo para armazenar em matriz
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

/*
if (matrix->ix == 0) {
                if (matrix->data[matrix->ix][matrix->iy] != pow(matrix->data[matrix->ix][matrix->iy], matrix->ix)) {
                    contador = contador + 1;
                }
            } else {
                if (matrix->iy == 0) {
                    if (matrix->data[matrix->ix][matrix->iy] != pow(matrix->data[matrix->ix][matrix->iy], matrix->iy)) {
                        contador = contador + 1;
                    }
                }
            }

            if (matrix->ix == 0 || matrix->iy == 0) {
                if (matrix->data[matrix.ix][matrix.iy] != pow(matrix->data[matrix.ix][matrix.iy], matrix->columns)) {
                    contador = contador + 1;
                } else {
                    if (matrix->data[matrix.ix][matrix.iy] != pow(matrix->data[matrix.ix][matrix.iy], matrix->columns)) {

                    }
                }
            }
*/

//Verificar se a matrix possui as caracteristicas exigidas pelo enunciado da questao 8
bool checkMatrix(ref_int_Matrix matrix) {
    bool result = false;
    int contador = 0;

    for (matrix->ix = 0; (matrix->ix) < (matrix->lines); matrix->ix = matrix->ix + 1) {
        for (matrix->iy = 0; (matrix->iy) < (matrix->columns); matrix->iy = matrix->iy + 1 ) {
            if (matrix->ix == 0) {
                if (matrix->data[matrix->ix][matrix->iy] != pow(matrix->data[matrix->ix][matrix->iy], matrix->ix)) {
                    contador = contador + 1;
                }
            } else {
                if (matrix->iy == 0) {
                    if (matrix->data[matrix->ix][matrix->iy] != pow(matrix->data[matrix->ix][matrix->iy], matrix->iy)) {
                        contador = contador + 1;
                    }
                } else {
                    if (matrix->data[matrix->ix][matrix->iy] != pow(matrix->data[matrix->ix][matrix->iy], matrix->iy)) {
                        contador = contador + 1;
                    }
                }
            }
        }
    }
    printf("\nContador = %d\n", contador);
    
    if (contador == 0) {
        result = true;
        return(result);
    } else {
        return(result);
    }
}

//Aplicar as caracteristicas da matriz desejada no exercicio 8
ref_int_Matrix applyMatrix(ref_int_Matrix matrix) {
    ref_int_Matrix result;

    result = new_int_Matrix(matrix->lines, matrix->columns);

    for (matrix->ix = 0; (matrix->ix) < (matrix->lines); matrix->ix = matrix->ix + 1) {
        for (matrix->iy = 0; (matrix->iy) < (matrix->columns); matrix->iy = matrix->iy + 1 ) {
            if (matrix->ix == 0) {
                result->data[matrix->ix][matrix->iy] = pow(matrix->data[matrix->ix][matrix->iy], matrix->ix);
            } else {
                if (matrix->iy == 0) {
                    result->data[matrix->ix][matrix->iy] = pow(matrix->data[matrix->ix][matrix->iy], matrix->iy);
                } else {
                    result->data[matrix->ix][matrix->iy] = pow(matrix->data[matrix->ix][matrix->iy], matrix->iy);
                }
            }
        }
    }

    return(result);
}

//Mostrar matrix com valores inteiros
void printIntMatrix (ref_int_Matrix matrix) {
    for (matrix -> ix = 0; (matrix -> ix) < (matrix -> lines); matrix -> ix = matrix -> ix + 1) {
        for (matrix -> iy = 0; (matrix -> iy) < (matrix -> columns); matrix -> iy = matrix -> iy + 1) {
            printf("%3d\t", matrix -> data[matrix -> ix][matrix -> iy]);
        }
        printf("\n");
    }
}

//Comparar 2 matrizes e ver se elas sao iguais
int CompareTwoMatrix (ref_int_Matrix matrix1, ref_int_Matrix matrix2) {
    int contador = 0;
    int numeroDiferente1 = 0, numeroDiferente2, result = 0;

    if ((matrix1->columns) <= 0 || (matrix1->lines) <= 0 || (matrix2->columns) <= 0 || (matrix2->lines) <= 0) {
        printf("\nERRO: Tamanho das matrizes invalido.\n");
    } else {
        if (matrix1->lines != matrix2->lines || matrix1->columns != matrix2->columns) {
            printf("\nERRO: As matrizes tem tamanhos de linhas ou colunas diferentes.\n");
        } else {
            for (matrix1->ix = 0; (matrix1->ix) < (matrix1->lines); matrix1->ix = matrix1->ix + 1) {
                for (matrix1->iy = 0; (matrix1->iy) < (matrix1->columns); matrix1->iy = matrix1->iy + 1) {
                    if (contador == 0) {
                        if (matrix1->data[matrix1->ix][matrix1->iy] != matrix2->data[matrix1->ix][matrix1->iy]) {
                            numeroDiferente1 = matrix1->data[matrix1->ix][matrix1->iy];
                            numeroDiferente2 = matrix2->data[matrix1->ix][matrix1->iy];
                            contador = contador + 1;
                        }
                    }
                }
            }
        }
    }

    if (contador != 0) {
        if (numeroDiferente1 > numeroDiferente2) {
            result = 1;
            printf("\nPrimeiro elemento diferente encontrado da Matriz 1 = [%d]\n", numeroDiferente1);
            printf("Primeiro elemento diferente encontrado da Matriz 2 = [%d]\n", numeroDiferente2);
            return(result);
        } else {
            if (numeroDiferente1 < numeroDiferente2) {
                result = -1;
                printf("\nPrimeiro elemento diferente encontrado da Matriz 1 = [%d]\n", numeroDiferente1);
                printf("Primeiro elemento diferente encontrado da Matriz 2 = [%d]\n", numeroDiferente2);
                return(result);
            }
        }
    } else {
        return(contador);
    }
}

void method00() {

}

void method01() {
    int_Array array;
    int_Array resultado;
    int maior = 0, menor = 0, menosDivisor = 0, maisDivisor = 0;
    int indiceMaior = 0, indiceMenor;

    IO_id("Exercicio01 - Method01 - v0.0");

    array = readFile("Dados.txt");

    printf("\nArray: \n");
    printIntArray(array);

    resultado = resolucaoExercicio01(array);
    
    maior = resultado.data[0];
    for (int x = 0; x < resultado.length; x = x + 1) {
        if (resultado.data[x] > maior) {
            maior = resultado.data[x];
            indiceMaior = x;
        }
    }
    
    menor = resultado.data[0];
    for (int y = 0; y < resultado.length; y = y + 1) {
        if (resultado.data[y] < menor) {
            menor = resultado.data[y];
            indiceMenor = y;
        }
    }

    printf("\nQuantidade de divisores: \n");
    printIntArray(resultado);
    printf("\nNumero com o maior numero de divisores: %d\n", array.data[indiceMaior]);
    printf("Numero com o menor numero de divisores: %d\n", array.data[indiceMenor]);

    GravarResultado("Resultado.txt", 2, array.data[indiceMaior], array.data[indiceMenor]);

    IO_pause("Apertar ENTER para continuar");
}

void method02() {
    int numero = 0, somaDosD = 0, resultPerfectN = 0;

    IO_id("Exercicio02 - Method02 - v0.0");
    
    calcularEgravarPerfeitos();

    IO_pause("Apertar ENTER para continuar");
}

void method03() {
    int_Array array;
    int x = 0, y = 0, resultado = 0;

    IO_id("Exercicio03 - Method03 - v0.0");

    array = lerArquivoEGravar("Numeros.txt");
    x = array.data[0];
    y = array.data[1];
    printf("Numeros:\n");
    printIntArray(array);

    resultado = calcularMDC(x, y);

    printf("Resultado do MDC entre [%d , %d] = %d\n", x, y, resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method04() {
    int_Array array;
    int x = 0, y = 0, resultado = 0;

    IO_id("Exercicio04 - Method04 - v0.0");

    array = lerArquivoEGravar("Numeros.txt");

    x = array.data[0];
    y = array.data[1];
    printf("Numeros:\n");
    printIntArray(array);

    resultado = calcularMMC(x, y);

    printf("Resultado do MDC entre [%d , %d] = %d\n", x, y, resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method05() {
    int_Array array;
    int quantidade = 0;
    int resultado = 0;

    IO_id("Exercicio05 - Method05 - v0.0");

    quantidade = IO_readint("Qual o tamanho do digito binario: ");

    array.length = quantidade;
    array.data = IO_new_ints(array.length);    

    for (int contador = 0; contador < quantidade; contador = contador + 1) {
        do {
            array.data[contador] = IO_readint("Digite 0 ou 1: ");
        } while (array.data[contador] != 0 && array.data[contador] != 1);
    }

    resultado = BinaryToDecimal(array);

    printf("\nEm Binario:\n");
    for (int x = 0; x < array.length; x = x + 1) {
        printf("%d ", array.data[x]);
    }
    printf("\n");

    printf("\nEm Decimal:\n");
    printf("%d", resultado);
    printf("\n");

    IO_pause("Apertar ENTER para continuar");
}

void method06() {
    int_Array array;
    int_Array array2;
    int tamanho = 0;

    IO_id("Exercicio06 - Method06 - v0.0");

    tamanho = IO_readint("Tamanho do array: ");
    array.length = tamanho;
    array.data = IO_new_ints(array.length);

    array = readNValues("Crescentes.txt", tamanho);
    printf("\nOriginal:\n");
    printIntArray(array);

    array2.length = array.length;
    array2.data = IO_new_ints(array2.length);

    array2 = inverterArray(array);
    printf("\nResultado:\n");
    printIntArray(array2);

    gravarDadosEmArquivo("Invertidos.txt", array2);

    //printIntArray(array);

    IO_pause("Apertar ENTER para continuar");
}

void method07() {
    int_Array array1;
    int_Array array2;
    int_Array array3;

    IO_id("Exercicio07 - Method07 - v0.0");

    array1 = fIO_readIntArray("Dados1.txt");
    printf("\nDados1:\n");
    printIntArray(array1);

    array2 = fIO_readIntArray("Dados2.txt");
    printf("\nDados2:\n");
    printIntArray(array2);

    array3 = commomToBoth(array1, array2);

    printf("\nResultado da intersecao:\n");
    printIntArray(array3);

    gravarDadosEmArquivo("Filtrados.txt", array3);

    IO_pause("Apertar ENTER para continuar");
}

void method08() {
    ref_int_Matrix matrix;
    ref_int_Matrix matrix2;
    int result = 0;

    IO_id("Exercicio08 - Method08 - v0.0");

    matrix = freadIntMatrix("Matriz1.txt");
    printf("\nMatriz Original:\n");
    printIntMatrix(matrix);

    matrix2 = applyMatrix(matrix);
    printf("\nResultado:\n");
    printIntMatrix(matrix2);

    IO_pause("Apertar ENTER para continuar");
}

void method09() {
    ref_int_Matrix matrix1;
    ref_int_Matrix matrix2;
    int result = 0;

    IO_id("Exercicio09 - Method09 - v0.0");

    matrix1 = freadIntMatrix("Matriz1.txt");
    matrix2 = freadIntMatrix("Matriz2.txt");

    printf("\nMatriz 1:\n");
    printIntMatrix(matrix1);
    printf("\nMatriz 2:\n");
    printIntMatrix(matrix2);

    result = CompareTwoMatrix(matrix1, matrix2);

    if (result ==  0) {
        printf("\nAs matrizes sao IGUAIS.\n");
    } else {
        if (result == 1) {
            printf("\nAs matrizes sao diferentes e o elemento da primeira e MAIOR que o elemento da segunda.\n");
        } else {
            if (result == -1) {
                printf("\nAs matrizes sao diferentes e o elemento da primeira e MENOR que o elemento da segunda.\n");
            }
        }
    }
    
    IO_pause("Apertar ENTER para continuar");
}

void method10() {
    int quantidade = 0;
    double somaDosProdutos = 0.0, media = 0.0;

    IO_id("Exercicio10 - Method10 - v0.0");

    quantidade = IO_readint("Quantidade de supermercados: ");
    intArrayMarket mercado[quantidade];

    for (int x = 0; x < quantidade; x = x + 1) {
        mercado[x].nome = IO_readstring("Nome do supermercado: ");
        mercado[x].codigo = IO_readint("Codigo do supermercado: ");
        mercado[x].precoProduto = IO_readdouble("Preco de um produto X: ");
    }

    for (int y = 0; y < quantidade; y = y + 1) {
        somaDosProdutos = somaDosProdutos + mercado[y].precoProduto;
    }

    media = (double)somaDosProdutos/quantidade;
    printf("\n");
    printf("Resultado:");
    printf("\n");
    for (int z = 0; z < quantidade; z = z + 1) {
        if (mercado[z].precoProduto < media) {
            printf("O supermercado %s possui o preco do produto X[%.2lf] abaixo da media [%.2lf]\n", mercado[z].nome, mercado[z].precoProduto, media);
        }
    }
    printf("\n");
    IO_pause("Apertar ENTER para continuar");
}


int main () {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "Ed10 - v.1 - 22/11/2020\n"       );
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
            default:
            break;
            IO_pause ( "ERRO: Valor invalido." );
        }
    } while (x != 0);

    IO_pause("Apertar ENTER para terminar");
    return(0);
}