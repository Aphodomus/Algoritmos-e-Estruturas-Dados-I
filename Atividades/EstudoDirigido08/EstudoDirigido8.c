/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Ed08
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 15/10/2020
*/

#include "io.h"
#include "MyLib.h"

void printIntArray (int n, int array[]) {
    int x = 0;

    for (x = 0; x < n; x = x + 1 ) {
        IO_printf("%2d: %d\n", x, array[x]);
    }
}

void readIntArray (int n, int array[]) {
    int x = 0;
    int y = 0;
    chars text = IO_new_chars(STR_SIZE);

    for (x = 0; x < n; x = x + 1) {
        strcpy(text, STR_EMPTY);
        y = IO_readint(IO_concat(IO_concat(text, IO_toString_d(x)), ": "));
        array[x] = y;
    }
}

void fprintIntArray (chars fileName, int n, int array[]) {
    FILE* arquivo = fopen(fileName, "wt");
    int x = 0;

    IO_fprintf(arquivo, "%d\n", n);

    for (x = 0; x < n; x = x + 1) {
        IO_fprintf(arquivo, "%d\n", array[x]);
    }
    fclose(arquivo);
}

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

void freadIntArray (chars fileName, int n, int array[]) {
    int x = 0, y = 0;
    FILE* arquivo = fopen(fileName, "rt");

    IO_fscanf(arquivo, "%d", &x);

    if (n <= 0 || n > x) {
        IO_println("ERRO: Valor invalido.");
    } else {
        x = 0;
        while (! feof(arquivo) && x < n) {
            IO_fscanf(arquivo, "%d", &y);
            array[x] = y;
            x = x + 1;
        }
    }
}

void copyIntArray (int n, int copy[], int array[]) {
    int x = 0;
    int y = 0;

    if (n <= 0) {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } else {
        for (x = 0; x < n; x = x + 1) {
            copy[x] = array[x];
        }
    }
}

bool isAllZeros (int n, int array[]) {
    bool result = true;
    int x = 0;

    x = 0;
    while (x < n && result) {
        // testar valor
        result = result && (array[x] == 0);
        // passar ao proximo
        x = x + 1;
    }
    return(result);
}

int sumIntArray (int n, int array[]) {
    int soma = 0;
    int x = 0;

    for (x = 0; x < n; x = x + 1) {
        soma =  soma + array[x];
    }

    return(soma);
}

void addIntArray (int n, int array3[], int array1[], int k, int array2[]) {
    int x = 0;

    for (x = 0; x < n; x = x + 1) {
        array3[x] = array1[x] + k*array2[x];
    }
}

bool isEqual (int n, int array1[], int array2[]) {
    bool result = true;
    int x = 0;

    x = 0;
    while (x < n && result) {
        result = result && (array1[x] == array2[x]);
        x = x + 1;
    }

    return(result);
}

bool searchArray (int n, int array[], int value) {
    bool result = false;
    int x = 0;

    x = 0;
    while (x < n && ! result) {
        result = (value == array[x]);
        x = x + 1;
    }
    return(result);
}


int readANumberArray (int tamanho, int array[]) {
    int contador = 0;
    int digito = 0;
    chars text = IO_new_chars(STR_SIZE);
    FILE* resultado = fopen ("Dados0811.txt", "wt");

    for (contador = 0; contador < tamanho; contador = contador + 1) {
        strcpy(text, STR_EMPTY);
        digito = IO_readint(IO_concat(IO_concat(text, IO_toString_d(contador + 1)), ": Digito = "));
        if (digito%2 != 0 || digito < 0) {
            printf("ERRO: Valor invalido.\n");
            contador = contador - 1;
        } else {
            array[contador] = digito;
            fprintf(resultado, "%d\n", digito);
        }
    }
    fclose(resultado);
}

int readANumberArray2 (chars fileName, int tamanho, int array[]) {
    int contador = 0;
    int digito = 0;
    chars text = IO_new_chars(STR_SIZE);
    FILE* resultado = fopen (fileName, "wt");

    for (contador = 0; contador < tamanho; contador = contador + 1) {
        strcpy(text, STR_EMPTY);
        digito = IO_readint(IO_concat(IO_concat(text, IO_toString_d(contador + 1)), ": Digito = "));
        array[contador] = digito;
        fprintf(resultado, "%d\n", digito);
    }
    fclose(resultado);
}

void readAFileArray (chars fileName, int n, int array[]) {
    int x = 0, y = 0;
    FILE* arquivo = fopen(fileName, "rt");

    IO_fscanf(arquivo, "%d", &x);

    if (n <= 0 || n > x) {
        IO_println("ERRO: Valor invalido.");
    } else {
        x = 0;
        while (! feof(arquivo) && x < n) {
            IO_fscanf(arquivo, "%d", &y);
            IO_printf("leu");
            array[x] = y;
            x = x + 1;
        }
    }
}

void randomNumber (int inferior, int superior, int quantidade) {
    int contador = 0, numero = 0;
    FILE* arquivo = fopen ("Dados0813.txt", "wt");
    
    srand(time(0));
    fprintf(arquivo, "%d\n", quantidade);
    for (contador = 0; contador < quantidade; contador = contador + 1) {
        numero = inferior + rand() % (superior - inferior + 1);
        printf("%d\n", numero);
        fprintf(arquivo, "%d\n", numero);
    }
    fclose(arquivo);
}

void readInts (chars fileName) {
    FILE* arquivo = fopen(fileName, "rt");
    int x = 0;

    fscanf(arquivo, "%d", &x);

    while (!feof(arquivo)) {
        printf("%d\n", x);
        fscanf(arquivo, "%d", &x);
    }

    fclose(arquivo);
}

void lowerNumberArray (chars fileName, int tamanho) {
    FILE* arquivo = fopen(fileName, "rt");
    int x = 0, y = 0, menorpar = 0, contador = 0, quantidade = 0;
    int array[tamanho];
    fscanf(arquivo, "%d", &y);

    while (!feof(arquivo) && x < tamanho) {
        array[x] = y;
        fscanf(arquivo, "%d", &y);
        x = x + 1;
    }

    menorpar = array[0];

    for (contador = 1; contador < tamanho; contador = contador + 1) {
        if (menorpar > array[contador] && array[contador]%2 == 0) {
            menorpar = array[contador];
        }
    }
    IO_printf("\nMenor valor par = %d\n", menorpar);

    fclose(arquivo);
}

void biggerNumberArray (chars fileName, int tamanho) {
    FILE* arquivo = fopen(fileName, "rt");
    int x = 0, y = 0, menorpar = 0, contador = 0, quantidade = 0;
    int array[tamanho];
    fscanf(arquivo, "%d", &y);

    while (!feof(arquivo) && x < tamanho) {
        array[x] = y;
        fscanf(arquivo, "%d", &y);
        x = x + 1;
    }

    menorpar = array[0];

    for (contador = 1; contador < tamanho; contador = contador + 1) {
        if (menorpar < array[contador] && array[contador]%2 != 0) {
            menorpar = array[contador];
        }
    }
    IO_printf("\nMaior valor impar = %d\n", menorpar);

    fclose(arquivo);
}

void averageArray (chars fileName, int tamanho) {
    FILE* arquivo = fopen(fileName, "rt");
    FILE* biggerAverage = fopen("BiggerThanAverageEven0816.txt", "wt");
    FILE* lowerAverage = fopen("LowerThanAverageOdd0816.txt", "wt");
    int array[tamanho], y = 0, contador = 0, contador2 = 0, soma = 0, contador3 = 0;
    double media = 0.0;

    fscanf(arquivo, "%d", &y);

    while (!feof(arquivo) && contador < tamanho) {
        array[contador] = y;
        fscanf(arquivo, "%d", &y);
        contador = contador + 1;
    }

    for (contador2 = 0; contador2 < tamanho; contador2 = contador2 + 1) {
        soma = soma + array[contador2];
    }
    
    media = (double) soma/tamanho;

    IO_printf("\bA media dos valores e: %.2lf\n", media);

    for (contador3 = 0; contador3 < tamanho; contador3 = contador3 + 1) {
        if (array[contador3]%2 == 0 && array[contador3] >= media) {
            fprintf(biggerAverage, "%d\n", array[contador3]);
            IO_printf("Valor par maior ou igual a media: %d\n", array[contador3]);
        } else {
            if (array[contador3]%2 != 0 && array[contador3] < media) {
                fprintf(lowerAverage, "%d\n", array[contador3]);
                IO_printf("Valor impar menor que a media: %d\n", array[contador3]);
            }
        }
    }

    fclose(arquivo);
    fclose(biggerAverage);
    fclose(lowerAverage);
}

bool organizedArrayDecreasing (chars fileName, int tamanho) {
    FILE* arquivo = fopen(fileName, "rt");
    int y = 0, contador = 0, contador2 = 0, quantidade = 1;
    int array[tamanho];
    bool result = false;

    fscanf(arquivo, "%d", &y);

    while (!feof(arquivo) && contador < tamanho) {
        array[contador] = y;
        fscanf(arquivo, "%d", &y);
        contador = contador + 1;
    }

    if (tamanho > 1) {
        for (contador2 = 1; contador2 < tamanho; contador2 = contador2 + 1) {
            if(array[contador2] > (array[contador2 - 1])) {
                quantidade = quantidade + 1;
            }
        }
    }

    if (quantidade == tamanho) {
        printf("\nCrescente\n");
    } else {
        if (quantidade == 1) {
            printf("\nDecrescente\n");
        } else {
            printf("\nDesordenado\n");
        }
    }

    fclose(arquivo);
}

/*Como a questao 8 e 9 eram bem parecidas e com a mesma logica
  eu achei melhor fazer uma unica funcao para atender a ambas
  as questoes, espero que não haja problema.
  A funcao lê e procura um numero desejado em uma posicao
  especificada, e caso encontre o numero ela diz se ele
  esta em uma posicao impar ou par.
*/
void searchANumberInArray (chars fileName, int tamanho, int valor, int posicao) {
    FILE* arquivo = fopen(fileName, "rt");
    int y = 0, contador = 0, contador2 = 0, quantidade = 0;
    int array[tamanho];

    fscanf(arquivo, "%d", &y);

    while (!feof(arquivo) && contador < tamanho) {
        array[contador] = y;
        fscanf(arquivo, "%d", &y);
        contador = contador + 1;
    }

    for (contador2 = posicao; contador2 < tamanho; contador2 = contador2 + 1) {
        if (array[contador2] == valor && array[contador2]%2 == 0) {
            IO_printf("\nValor %d encontrado na posicao par [%d]\n", valor, contador2 + 1);
            quantidade = quantidade + 1;
        } else {
            if (array[contador2] == valor && array[contador2]%2 != 0) {
                IO_printf("\nValor %d encontrado na posicao impar [%d]\n", valor, contador2 + 1);
                quantidade = quantidade + 1;
            }
            
        }
    }

    if (quantidade == 0) {
        IO_printf("\nValor %d nao encontrado a partir da posicao [%d]\n", valor, posicao);
    }
}

void searchANumberInArrayAndCount (chars fileName, int tamanho, int valor, int posicao) {
    FILE* arquivo = fopen(fileName, "rt");
    int y = 0, contador = 0, contador2 = 0, quantidade = 0;
    int array[tamanho];

    fscanf(arquivo, "%d", &y);

    while (!feof(arquivo) && contador < tamanho) {
        array[contador] = y;
        fscanf(arquivo, "%d", &y);
        contador = contador + 1;
    }

    for (contador2 = posicao; contador2 < tamanho; contador2 = contador2 + 1) {
        if (array[contador2] == valor) {
            IO_printf("Valor %d encontrado na posicao [%d]\n", valor, contador2 + 1);
            quantidade = quantidade + 1;
        }
    }

    if (quantidade > 5) {
        IO_printf("\nQuantidade de vezes em que o valor apareceu = %d", quantidade);
        IO_printf("\nQuantidade maior que 5 ? Sim\n");
    } else {
        IO_printf("\nQuantidade de vezes em que o valor apareceu = %d", quantidade);
        IO_printf("\nQuantidade maior que 5 ? Nao\n");
    }
}

void method00 () {
    
}

void method01 () {
    int array[] = {1, 2, 3, 4, 5};
    IO_id("Exemplo0801 - Method01 - v0.0");
    printIntArray(5, array);
    IO_pause("Apertar ENTER para continuar");
}

void method02 () {
    int n = 5;
    int array[n];

    IO_id("Exemplo0802 - Method02 - v0.0");

    readIntArray(n, array);

    IO_printf("\n");
    printIntArray(n, array);

    IO_pause("Apertar ENTER para continuar");
}

void method03 () {
    int n = 5;
    int array [n];

    IO_id("Exemplo0803 - Method03 - v0.0");

    readIntArray(n, array);

    IO_printf("\n");
    fprintIntArray("Array1.txt", n, array);

    IO_pause("Apertar ENTER para continuar");
}

void method04 () {
    int n = 0;

    IO_id("Exemplo0804 - Method04 - v0.0");

    n = freadArraySize("Array1.txt");

    if (n <= 0) {
        IO_printf('\nERRO: Valor invalido.');
    } else {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("Array1.txt", n, array);
        // mostrar dados
        IO_printf("\n");
        printIntArray(n, array);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method05 () {
    int n = 0;

    IO_id("Exemplo0805 - Method05 - v0.0");

    n = freadArraySize("Array1.txt");

    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        // definir armazenador
        int array[n];
        int other[n];
        // ler dados
        freadIntArray("Array1.txt", n, array);
        // copiar dados
        copyIntArray(n, other, array);

        //mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        //mostrar dadods
        IO_printf("\nCopia\n");
        printIntArray(n, other);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method06 () {
    int n = 0;

    IO_id("Exemplo0806 - Method06 - v0.0");

    n = freadArraySize("Array1.txt");

    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray ("Array1.txt", n, array);
        // mostrar a soma dos valores no arranjo
        IO_printf("\nSoma = %d\n", sumIntArray(n, array));
    }

    IO_pause("Apertar ENTER para continuar");
}

void method07 () {
    int n = 5;
    int array1[] = {0, 0, 0, 0, 0};
    int array2[] = {1, 2, 3, 4, 5};
    int array3[] = {1, 2, 0, 4, 5};

    IO_id("Exemplo0807 - Method07 - v0.0");

    // testar dados
    IO_println("\nArray1");
    printIntArray(n, array1);
    IO_printf("isAllZeros(array1) = %d", isAllZeros(n, array1));

    IO_println("\nArray2");
    printIntArray(n, array2);
    IO_printf("isAllZeros(array2) = %d", isAllZeros(n, array2));

    IO_println("\nArray3");
    printIntArray(n, array3);
    IO_printf("isAllZeros(array3) = %d", isAllZeros(n, array3));

    IO_pause("Apertar ENTER para continuar");
}

void method08 () {
    int n = 0;

    IO_id("Exemplo0808 - Method08 - v0.0");

    n = freadArraySize("Array1.txt");

    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        // definir armazenador
        int array[n];
        int other[n];
        int sum [n];
        // ler dados
        freadIntArray("Array1.txt", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);
        // operar soma de arranjos
        addIntArray(n, sum, array, (-2), other);
        // mostrar resultados
        IO_printf("\nSoma\n");
        printIntArray(n, sum);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method09 () {
    int n = 0;

    IO_id("Exemplo0809 - Method09 - v0.0");

    n = freadArraySize ("Array1.txt");

    if ( n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        // definir armazenador
        int array[n];
        int other[n];
        // ler dados
        freadIntArray("Array1.txt", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);
        // mostrar resultado da comparacao
        IO_printf("\nIguais = %d\n", isEqual(n, array, other));
        // modificar um valor
        other[0] = (-1)*other[0];
        // mostrar dados
        IO_printf("\nCopia alterada\n");
        printIntArray(n, other);
        // mostrar resultado da comparacao
        IO_printf("\nIguais = %d\n", isEqual(n, array, other));
    }

    IO_pause("Apertar ENTER para continuar");
}

void method10 () {
    int n = 0;
    int value = 0;

    IO_id("Exemplo0810 - Method10 - v0.0");

    n = freadArraySize("Array1.txt");

    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("Array1.txt", n, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar resultados de procuras
        value = array[0];
        IO_printf ("\nProcurar por (%d) = %d\n", value, searchArray ( n, array, value ));

        value = array [ n / 2 ];
        IO_printf ("\nProcurar por (%d) = %d\n", value, searchArray ( n, array, value ));

        value = array [ n - 1 ];
        IO_printf ("\nProcurar por (%d) = %d\n", value, searchArray ( n, array, value ));
    
        value = (-1);
        IO_printf ("\nProcurar por (%d) = %d\n", value, searchArray ( n, array, value ));
    }

    IO_pause("Apertar ENTER para continuar");
}

void method11 () {
    int x = 0;

    IO_id("Exemplo0811 - Method11 - v0.0");

    x = IO_readint("Qual sera o tamanho do array: ");
    if (x >= 0) {
        int tamanho = x;
        int array[x];
        
        readANumberArray(tamanho, array);
    } else {
        IO_printf("ERRO: o Array nao pode ser negativo.");
    }

    IO_pause("Apertar ENTER para continuar");

}

void method12 () {
    int tamanho = 5;
    int array[tamanho];

    IO_id("Exemplo0812 - Method12 - v0.0");

    readAFileArray("Dados0812.txt", tamanho, array );

    IO_printf("\n");
    printIntArray(tamanho, array);

    IO_pause("Apertar ENTER para continuar");
}

void method13 () {
    int inferior = 0, superior = 0, quantidade = 0;

    IO_id("Exemplo0813 - Method13 - v0.0");

    inferior = IO_readint("Qual o intervalo inferior: ");
    do {
        superior = IO_readint("Qual o intervalo superior: ");
    } while (superior <= inferior);
    
    quantidade = IO_readint("Quantidade de elementos a serem gerados: ");

    randomNumber(inferior, superior, quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method14 () {
    int x = 0;

    IO_id("Exemplo0814 - Method14 - v0.0");

    x = IO_readint("Qual sera o tamanho do array: ");
    if (x >= 0) {
        int tamanho = x;
        int array[x];
        
        readANumberArray2("Dados0814.txt", tamanho, array);
        lowerNumberArray("Dados0814.txt", tamanho);
    } else {
        IO_printf("ERRO: o Array nao pode ser negativo.");
    }

    IO_pause("Apertar ENTER para continuar");
}

void method15 () {
    int x = 0;

    IO_id("Exemplo0815 - Method15 - v0.0");

    x = IO_readint("Qual sera o tamanho do array: ");
    if (x >= 0) {
        int tamanho = x;
        int array[x];
        
        readANumberArray2("Dados0815.txt", tamanho, array);
        biggerNumberArray("Dados0815.txt", tamanho);
    } else {
        IO_printf("ERRO: o Array nao pode ser negativo.");
    }

    IO_pause("Apertar ENTER para continuar");
}

void method16 () {
    int x = 0;

    IO_id("Exemplo0816 - Method16 - v0.0");

    x = IO_readint("Qual sera o tamanho do array: ");
    if (x >= 0) {
        int tamanho = x;
        int array[x];
        
        readANumberArray2("Dados0816.txt", tamanho, array);
        averageArray("Dados0816.txt", tamanho);
    } else {
        IO_printf("ERRO: o Array nao pode ser negativo.");
    }

    IO_pause("Apertar ENTER para continuar");
}

void method17 () {
    int x = 0;

    IO_id("Exemplo0817 - Method17 - v0.0");

    x = IO_readint("Qual sera o tamanho do array: ");
    if (x >= 0) {
        int tamanho = x;
        int array[x];
        
        readANumberArray2("Dados0817.txt", tamanho, array);
        organizedArrayDecreasing("Dados0817.txt", tamanho);
    } else {
        IO_printf("ERRO: o Array nao pode ser negativo.");
    }

    IO_pause("Apertar ENTER para continuar");
}

void method18 () {
    int x = 0, posicao = 0, valor = 0;

    IO_id("Exemplo0818 - Method18 - v0.0");

    x = IO_readint("Qual sera o tamanho do array: ");
    valor = IO_readint("Qual o numero que deseja procurar: ");
    posicao = IO_readint("Qual posicao voce deseja iniciar: ");
    if (x >= 0) {
        int tamanho = x;
        int array[x];
        
        readANumberArray2("Dados0818.txt", tamanho, array);
        searchANumberInArray("Dados0818.txt", tamanho, valor, posicao);
    } else {
        IO_printf("ERRO: o Array nao pode ser negativo.");
    }

    IO_pause("Apertar ENTER para continuar");
}

void method19 () {
    int x = 0, posicao = 0, valor = 0;

    IO_id("Exemplo0819 - Method19 - v0.0");

    x = IO_readint("Qual sera o tamanho do array: ");
    valor = IO_readint("Qual o numero que deseja procurar: ");
    posicao = IO_readint("Qual posicao voce deseja iniciar: ");
    if (x >= 0) {
        int tamanho = x;
        int array[x];
        
        readANumberArray2("Dados0819.txt", tamanho, array);
        searchANumberInArray("Dados0819.txt", tamanho, valor, posicao);
    } else {
        IO_printf("ERRO: o Array nao pode ser negativo.");
    }

    IO_pause("Apertar ENTER para continuar");
}

void method20 () {
    int x = 0, posicao = 0, valor = 0;

    IO_id("Exemplo0820 - Method20 - v0.0");

    x = IO_readint("Qual sera o tamanho do array: ");
    valor = IO_readint("Qual o numero que deseja procurar: ");
    posicao = IO_readint("Qual posicao voce deseja iniciar: ");
    if (x >= 0) {
        int tamanho = x;
        int array[x];
        
        readANumberArray2("Dados0820.txt", tamanho, array);
        searchANumberInArrayAndCount("Dados0820.txt", tamanho, valor, posicao);
    } else {
        IO_printf("ERRO: o Array nao pode ser negativo.");
    }

    IO_pause("Apertar ENTER para continuar");
}

int main () {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "Ed08 - v.1 - 15/10/2020\n"       );
        IO_println ( "Estudo Dirigido 08\n"          );
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
 0.1 15/10 esboco
---------------------------------------------- testes
Algoritmo           entrada             saida

*/