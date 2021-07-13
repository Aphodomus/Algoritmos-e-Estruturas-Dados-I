/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Ed07
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 05/10/2020
*/

#include "io.h"
#include "MyLib.h"

void writeInts (chars fileName, int x) {
    FILE* arquivo = fopen(fileName, "wt");
    int y = 0;

    for (y = 1; y <= x; y = y + 1) {
        fprintf(arquivo, "%d\n", y);
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

void writeDoubles (chars fileName, int x) {
    FILE* arquivo = fopen(fileName, "wt");
    int y = 0;

    IO_fprintf(arquivo, "%d\n", x);

    for (y = 1; y <= x; y = y + 1) {
        IO_fprintf(arquivo, "%lf\n", (0.1*y));
    }
    fclose(arquivo);
}

void readDoubles (chars fileName) {
    FILE* arquivo = fopen(fileName, "rt");
    int x = 1, y = 1;
    double z = 0.0;

    fscanf(arquivo, "%d", &x);

    while (!feof(arquivo) && y <= x) {
        fscanf(arquivo, "%lf", &z);
        y = y + 1;
    }
    fclose(arquivo);
}

void writeText (chars fileName) {
    FILE* arquivo = fopen(fileName, "wt");
    chars linha = IO_new_chars(STR_SIZE);

    IO_println("Gravar linhas(para terminar, entrar com \"PARAR\":\n");

    do {
        strcpy(linha, IO_readln(""));
        IO_fprintf(arquivo, "%s\n", linha);
    } while (strcmp("PARAR", linha) != 0);
    fclose(arquivo);
}

//Ler dados de um arquivo
void readText (chars fileName) {
    FILE* arquivo = fopen (fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);

    strcpy(linha, IO_freadln(arquivo));

    while (!feof(arquivo) && strcmp("PARAR", linha) != 0) {
        printf("%s\n", linha);
        strcpy(linha, IO_freadln(arquivo));
    }
    fclose(arquivo);
}

void copyText (chars fileOut, chars fileln) {
    FILE* saida = fopen(fileOut, "wt");
    FILE* entrada = fopen(fileln, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    int contador = 0;

    strcpy(linha, IO_freadln(entrada));

    while (!feof(entrada)) {
        contador = contador + 1;

        if (strcmp("PARAR", linha) != 0) {
            IO_fprintln(saida, linha);
        }
        strcpy(linha, IO_freadln(entrada));
    }
    IO_printf("Lines read = %d\n", contador);
    fclose(saida);
    fclose(entrada);
}

void appendText (chars fileName) {
    FILE* arquivo = fopen(fileName, "at");
    chars linha = IO_new_chars(STR_SIZE);

    IO_println("Gravar linhas(para terminar, entrar com \"PARAR\":\n");

    do {
        strcpy(linha, IO_readln(""));
        IO_fprintln(arquivo, linha);
    } while (strcmp("PARAR", linha) != 0);
    fclose(arquivo);
}


void readWords(chars fileName) {
    FILE* arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);

    strcpy(linha, IO_fread(arquivo));

    while(! feof(arquivo) && strcmp("PARAR", linha) != 0) {
        printf("%s\n", linha);
        strcpy(linha, IO_fread(arquivo));
    }
    fclose(arquivo);
}

bool searchWord(chars fileName, chars word) {
    FILE* arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);

    strcpy(linha, IO_fread(arquivo));

    while (! feof(arquivo) && strcmp(word, linha) != 0) {
        strcpy(linha, IO_fread(arquivo));
    }
    fclose(arquivo);
    return(strcmp(word, linha) == 0);
}

void readANumberAndWriteInFileMultThreeEven (int quantidade) {
    int contador = 0, x = 2, multiplo = 0;
    FILE* arquivo = fopen("Exemplo0711.txt", "wt");

    for (contador = 0; contador <  quantidade; contador = contador + 1) {
        multiplo = 3*x;
        if ((multiplo%3 == 0) && (multiplo%2 == 0)) {
            fprintf(arquivo, "%d\n", multiplo);
            IO_printf("%d", multiplo);
        } else {
            contador = contador - 1;
        }
        x = x + 1;
    }
    fclose(arquivo);
}

void readANumberAndWriteInFileMulitThreeOdd (int quantidade) {
    int contador = 0, numero = 0;
    FILE* arquivo = fopen("Exemplo0712.txt", "wt");

    numero = quantidade*6;
    for (contador = quantidade; contador > 0; contador = contador - 1) {
        if (numero%2 != 0) {
            fprintf(arquivo, "%d\n", numero);
            IO_printf("%d\n", numero);
        } else {
            contador = contador + 1;
        }
        numero = numero - 3;
    }
    fclose(arquivo);
}

void readANumberAndWriteInFileSequence (int quantidade) {
    int contador = 0, numero = 1;
    FILE* arquivo = fopen("Exemplo0713.txt", "wt");

    for (contador = 0; contador < quantidade; contador = contador + 1) {
        if(contador == 0) {
            fprintf(arquivo, "%d\n", numero);
            IO_printf("%d\n", numero);
        } else {
            if (contador == 1) {
                numero = numero + 4;
                fprintf(arquivo, "%d\n", numero);
                IO_printf("%d\n", numero);
            } else {
                numero = numero + 10;
                fprintf(arquivo, "%d\n", numero);
                IO_printf("%d\n", numero);
            }
        }
    }
    fclose(arquivo);
}

void readANumberAndWriteInFileSequence2 (int quantidade) {
    int contador = 0, expoente = 0, numero = 0;
    FILE* arquivo = fopen("Exemplo0714.txt", "wt");

    expoente = quantidade - 1;
    for (contador = 0; contador < quantidade; contador = contador + 1) {
        if (expoente != 0) {
            numero = pow(7, expoente);
            fprintf(arquivo, "%lf\n", pow(numero, -1));
            expoente = expoente - 1;
            IO_printf("%lf\n", pow(numero, -1));
        } else {
            numero = pow(7, expoente);
            fprintf(arquivo, "%lf\n", pow(numero, -1));
            expoente = expoente - 1;
            IO_printf("%lf\n", pow(numero, -1));
        }
    }
    fclose(arquivo);
}

void readANumberAndWriteInFileSequence3 (int quantidade, double valor) {
    int contador = 0, expoente = 0;
    double numero = 0.0;
    FILE* arquivo = fopen("Exemplo0715.txt", "wt");

    for (contador = 0; contador < quantidade; contador = contador + 1) {
        if (contador == 0) {
            numero = pow(valor, expoente);
            fprintf(arquivo, "%0.lf\n", pow(numero, -1));
            expoente = expoente + 1;
            IO_printf("%0.lf\n", pow(numero, -1));
        } else {
            numero = pow(valor, expoente);
            fprintf(arquivo, "%lf\n", pow(numero, -1));
            expoente = expoente + 2;
            IO_printf("%lf\n", pow(numero, -1));
        }
    }
    fclose(arquivo);
}

void readANumberAndReadAndWriteSum (chars fileName, int quantidade) {
    FILE* arquivo = fopen(fileName, "rt");
    FILE* resultado = fopen("Resultado0716.txt", "wt");
    double x = 0.0, soma = 0.0;
    int valor = 0;
    valor = quantidade;

    fscanf(arquivo, "%lf", &x);

    while (!feof(arquivo)) {
        printf("%lf\n", (x + valor));
        fscanf(arquivo, "%lf", &x);
        soma = x + valor;
        fprintf(resultado, "%lf\n", soma);
    }

    fclose(arquivo);
    fclose(resultado);
}

void readANumberAndReadAndWriteSumReverseSeven (chars fileName, int quantidade) {
    FILE* arquivo = fopen(fileName, "rt");
    FILE* resultado = fopen("Resultado0717.txt", "wt");
    double x = 0.0, soma = 0.0;
    int valor = 0;
    valor = quantidade;

    fscanf(arquivo, "%lf", &x);

    while(!feof(arquivo)) {
        printf("%lf\n", pow((x + valor), -7));
        fscanf(arquivo, "%lf", &x);
        soma = pow((x + valor), -7);
        fprintf(resultado, "%lf\n", soma);
    }

    fclose(arquivo);
    fclose(resultado);
}

void recursiveReadANumberandWriteFibonacciEven (int quantidade) {
    FILE* resultado = fopen("Resultado0718.txt", "wt");
    int numero = 0, fiboResult = 0, contador = 1;
    numero = quantidade;

    for (contador = 1; contador <= numero; contador = contador + 1) {
        fiboResult = fibonacci2(contador);
        if (fiboResult == 0) {
            numero = numero + 1;
        } else {
            if (even(fiboResult) == true) {
                printf("%d\n", fiboResult);
                fprintf(resultado, "%d\n", fiboResult);
            } else {
                numero = numero + 1;
            }
        }
    }
    fclose(resultado);
}
//Incompleto, nao encontrei uma maneira de ler cada uma das strings e ver quais digitos nela sao
//menores que 'N' e conta-los.
void readAStringAndWriteLessN (chars fileName) {
    FILE* arquivo = fopen(fileName, "rt");
    FILE* resultado = fopen("Resultado0719.txt", "wt");
    chars palavra = IO_new_chars(STR_SIZE);

    strcpy(palavra, IO_fread(arquivo));


    
    fclose(arquivo);
}

void method00 () {
    
}

void method01 () {
    IO_id("Exemplo701 - Method01 - v0.1");

    writeInts("DADOS1.TXT", 10);

    IO_pause("Apertar ENTER para continuar");
}

void method02 () {


    IO_id("Exemplo702 - Method02 - v0.1");

    readInts("DADOS1.TXT");

    IO_pause("Apertar ENTER para continuar");
}

void method03 () {

    
    IO_id("Exemplo703 - Method03 - v0.1");

    writeDoubles("DADOS2.TXT", 10);

    IO_pause("Apertar ENTER para continuar");
}

void method04 () {

    
    IO_id("Exemplo704 - Method04 - v0.1");

    readDoubles("DADOS2.TXT");

    IO_pause("Apertar ENTER para continuar");
}

void method05 () {

    
    IO_id("Exemplo705 - Method05 - v0.1");

    writeText("DADOS3.TXT");

    IO_pause("Apertar ENTER para continuar");
}

void method06 () {

    
    IO_id("Exemplo706 - Method06 - v0.1");

    readText("DADOS3.TXT");

    IO_pause("Apertar ENTER para continuar");
}

void method07 () {

    
    IO_id("Exemplo707 - Method07 - v0.1");

    copyText("DADOS4.TXT","DADOS3.TXT");

    IO_pause("Apertar ENTER para continuar");
}

void method08 () {

    
    IO_id("Exemplo708 - Method08 - v0.1");

    appendText("DADOS4.TXT");

    IO_pause("Apertar ENTER para continuar");
}

void method09 () {

    
    IO_id("Exemplo709 - Method09 - v0.1");

    readWords("DADOS4.TXT");

    IO_pause("Apertar ENTER para continuar");
}

void method10 () {

    
    IO_id("Exemplo710 - Method10 - v0.1");

    IO_printf("Procurar (\"%s\") = %d\n", "bbp", searchWord("DADOS4.TXT", "z"));
    IO_printf("Procurar (\"%s\") = %d\n", "pqsdef", searchWord("DADOS4.TXT", "x"));

    IO_pause("Apertar ENTER para continuar");
}

void method11 () {
    int quantidade = 0;
    
    IO_id("Exemplo711 - Method11 - v0.1");

    quantidade = IO_readint("Quantidade de valores multiplos de 3 pares que deseja gravar: ");

    readANumberAndWriteInFileMultThreeEven(quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method12 () {
    int quantidade = 0;
    
    IO_id("Exemplo712 - Method12 - v0.1");

    quantidade = IO_readint("Quantidade de valores multiplos de 3 e impar que deseja gravar: ");

    readANumberAndWriteInFileMulitThreeOdd(quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method13 () {
    int quantidade = 0;
    
    IO_id("Exemplo713 - Method13 - v0.1");

    quantidade = IO_readint("Quantidade de valores da sequencia que deseja gravar: ");

    readANumberAndWriteInFileSequence(quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method14 () {
    int quantidade = 0;
    
    IO_id("Exemplo714 - Method14 - v0.1");

    quantidade = IO_readint("Quantidade de valores da sequencia que deseja gravar: ");

    readANumberAndWriteInFileSequence2(quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method15 () {
    int quantidade = 0;
    double valor = 0.0;
    
    IO_id("Exemplo715 - Method15 - v0.1");

    quantidade = IO_readint("Digite uma quantidade: ");
    valor = IO_readdouble("Digite um valor real: ");

    readANumberAndWriteInFileSequence3(quantidade, valor);

    IO_pause("Apertar ENTER para continuar");
}

void method16 () {
    int quantidade = 0;
    
    IO_id("Exemplo716 - Method16 - v0.1");

    quantidade = IO_readint("Valor a ser somado aos valores do exemplo 15: ");

    readANumberAndReadAndWriteSum("Exemplo0715.txt", quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method17 () {
    int quantidade = 0;
    
    IO_id("Exemplo717 - Method17 - v0.1");

    quantidade = IO_readint("Digite um valor: ");

    readANumberAndReadAndWriteSumReverseSeven("Exemplo0714.txt", quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method18 () {
    int quantidade = 0;
    
    IO_id("Exemplo718 - Method18 - v0.1");

    quantidade = IO_readint("Digite um valor: ");

    recursiveReadANumberandWriteFibonacciEven(quantidade);

    IO_pause("Apertar ENTER para continuar");
}
//Incompleto, nao encontrei uma maneira de ler cada uma das strings e ver quais digitos nela sao
//menores que 'N' e conta-los.
void method19 () {
    int quantidade = 0, contador = 0;
    FILE* arquivo = fopen("Dados0719.txt", "wt");
    chars palavra = IO_new_chars(STR_SIZE);
    
    IO_id("Exemplo719 - Method19 - v0.1");

    quantidade = IO_readint("Quantas palavras voce deseja verificar: ");

    for (contador = 0; contador < quantidade; contador = contador + 1) {
        strcpy(palavra, IO_readln("Digite a palavra:"));
        IO_fprintf(arquivo, "%s\n", palavra);
    }
    fclose(arquivo);

    readAStringAndWriteLessN("Dados0719.txt");

    IO_pause("Apertar ENTER para continuar");
}

void method20 () {

    
    IO_id("Exemplo720 - Method20 - v0.1");

    

    IO_pause("Apertar ENTER para continuar");
}

int main () {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "Ed07 - v.1 - 05/10/2020\n"       );
        IO_println ( "Estudo Dirigido 07\n"          );
        IO_println ( "Matricula: 716417\nNome: Daniel Vitor de Oliveira Santos\n" );
        IO_println ( "" ); 

        IO_println ( "Opcoes" );
        IO_println ( " 0 - parar" );
        IO_println ( " 1 - metho01" );
        IO_println ( " 2 - metho02" );
        IO_println ( " 3 - metho03" );
        IO_println ( " 4 - metho04" );
        IO_println ( " 5 - metho05" );
        IO_println ( " 6 - metho06" );
        IO_println ( " 7 - metho07" );
        IO_println ( " 8 - metho08" );
        IO_println ( " 9 - metho09" );
        IO_println ( "10 - metho10" );
        IO_println ( "11 - metho11" );
        IO_println ( "12 - metho12" );
        IO_println ( "13 - metho13" );
        IO_println ( "14 - metho14" );
        IO_println ( "15 - metho15" );
        IO_println ( "16 - metho16" );
        IO_println ( "17 - metho17" );
        IO_println ( "18 - metho18" );
        IO_println ( "19 - incompleto" );
        IO_println ( "20 - incompleto" );
        IO_println ( "21 - incompleto" );
        IO_println ( "22 - incompleto" );
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
            break;
            default:
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
 0.1 05/10 esboco
---------------------------------------------- testes
Algoritmo           entrada             saida

method11               8                6, 12 , 18, 24, 30, 36, 42, 48
method12               6                33, 27, 21, 15, 9, 3
method13               6                1, 5, 15, 25, 35, 45
method14               5                0.000416, 0.002915, 0.0204, 0.1428, 1
method15              5,2.4             1, 0.4166, 0.0723, 0.0125, 0.0021
method16               4                5, 4.333, 4.037, 4.004, 4.0004, 4.00005
method17               3                0.000457, 0.000454, 0.000436, 0.000330, 0.000061
method18               7                2, 8, 34, 144, 610, 2584, 10946
*/