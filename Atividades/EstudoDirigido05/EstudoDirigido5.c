/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Ed05
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 14/09/2020
*/

#include "io.h"
#include "MyLib.h"

void method00() {

}

void method01a (int x) {
    int y = 1;

    while (y <= x) {
        IO_printf("%s%d\n", "Valor = ", y);
        y = y + 1;
    }
}

void method02a (int x) {
    int y = 1, z = 2;

    while (y <= x) {
        IO_printf("%d: %d\n", y, z);
        z = z + 2;
        y = y + 1;
    }
}

void method03a (int x) {
    int y = 1, z = 0;

    while (y <= x) {
        z = 2*y;
        IO_printf("%d: %d\n", y, z);
        y = y + 1;
    }
}

void method04a (int x) {
    int y = x, z = 0;

    while (y > 0) {
        z = 2*y;
        IO_printf("%d: %d\n", y, z);
        y = y - 1;
    }
}

void method05a (int x) {
    int y = 0;

    for (y = x; y > 0; y = y - 1) {
        IO_printf("%d: %d\n", y, (2*y));
    }
}

int somarValores (int x) {
    int soma = 1, y = 0;

    for (y = x - 1; y > 0; y = y - 1) {
        IO_printf("%d: %d\n", y, (2*y));
        soma = soma + (2*y);
    }

    return(soma);
}

double somarFracao (int x) {
    double soma = 1.0, numerador = 0, denominador = 0;
    int y = 0;

    for (y = x-1; y > 0; y = y - 1) {
        numerador = 1.0;
        denominador = 2.0*y;
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y, numerador, denominador, (numerador/denominador));
        soma = soma + (1.0)/(2.0*y);
    }
    return(soma);
}

double somarFracao2 (int x) {
    double soma = 1.0;
    double numerador = 0;
    double denominador = 0;
    int y = 0;

    IO_printf("%d: %7.4lf/%7.4lf = %lf\n", 1, 1.0, 1.0, 1.0);

    for (y = 1; y <= (x-1); y = y + 1) {
        numerador = 2.0*y-1;
        denominador = 2.0*y;
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y + 1, numerador, denominador, (numerador/denominador));
        soma = soma + (2.0*y-1)/(2.0*y);
    }
    return(soma);
}

double somarFracao3 (int x) {
    double soma = 1.0;
    int y = 0;

    IO_printf("%d: %7.4lf/%7.4lf = %7.4lf\n", 1, 1.0, 1.0, 1.0);

    for (y = 1; y <= (x-1); y = y + 1) {
        IO_printf("%d: %7.4lf/%7.4lf = %7.4lf\n", y + 1, (2.0*y), (2.0*y+1), ((2.0*y)/(2.0*y+1)));

        soma = soma + (2.0*y)/(2.0*y+1);
    }
    return(soma);
}

int multiplicarValores (int x) {
    int produto = 1;
    int y = 0;

    for (y = 1; y <= x; y = y + 1) {
        IO_printf("%d: %d\n", y, (2*y-1));
        produto = produto*(2*y-1);
    }
    return(produto);
}

void method01() {
    IO_id("Exemplo0501 - Method01 - v0.1");

    method01a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method02() {
    IO_id("Exemplo0502 - Method02 - v0.1");

    method02a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method03() {
    IO_id("Exemplo0503 - Method03 - v0.1");

    method03a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method04() {
    IO_id("Exemplo0504 - Method04 - v0.1");

    method04a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method05() {
    IO_id("Exemplo0505 - Method05 - v0.1");

    method05a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method06() {
    int soma = 0;

    IO_id("Exemplo0506 - Method06 - v0.1");

    soma = somarValores(5);

    IO_printf("Soma de pares = %d\n", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method07() {
    double soma = 0.0;

    IO_id("Exemplo0507 - Method07 - v0.1");

    soma = somarFracao(5);

    IO_printf("Soma de fracoes = %lf\n", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method08() {
    double soma = 0.0;

    IO_id("Exemplo0508 - Method08 - v0.1");

    soma = somarFracao2(5);

    IO_printf("soma de fracoes = %lf\n", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method09() {
    double soma = 0.0;

    IO_id("Exemplo0509 - Method09 - v0.1");

    soma = somarFracao3(5);

    IO_printf("Soma de fracoes = %lf\n", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method10() {
    int multiplicacao = 0;

    IO_id("Exemplo0510 - Method10 - v0.1");

    multiplicacao = multiplicarValores(5);

    IO_printf("%s%d\n", "Produto = ", multiplicacao);

    IO_pause("Apertar ENTER para continuar");
}

void method11() {
    int valor = 0;

    IO_id("Exemplo0511 - Method11 - v0.1");

    valor = IO_readint("Digite uma quantidade: ");

    readNumberShowMultTwoThreeCres(valor);

    IO_pause("Apertar ENTER para continuar");
}

void method12() {
    int valor = 0;

    IO_id("Exemplo0512 - Method12 - v0.1");

    valor = IO_readint("Digite uma quantidade: ");

    readNumberShowMultThreeCres(valor);

    IO_pause("Apertar ENTER para continuar");
}

void method13() {
    int valor = 0;

    IO_id("Exemplo0513 - Method13 - v0.1");

    valor = IO_readint("Digite uma quantidade: ");

    readNumberShowMultThreeDecres(valor);

    IO_pause("Apertar ENTER para continuar");
}

void method14() {
    int valor = 0;

    IO_id("Exemplo0514 - Method14 - v0.1");

    valor = IO_readint("Digite uma quantidade: ");

    readNumberShowReverseMultFourCresc(valor);

    IO_pause("Apertar ENTER para continuar");
}

void method15() {
    int inteiro = 0;
    double real = 0.0;

    IO_id("Exemplo0515 - Method15 - v0.1");

    real = IO_readdouble("Digite um valor real: ");
    inteiro = IO_readint("Digite uma quantidade de valores inteiros: ");

    readNumberShow(inteiro, real);

    IO_pause("Apertar ENTER para continuar");
}

void method16() {
    int valor = 0, soma = 0;

    IO_id("Exemplo0516 - Method16 - v0.1");

    valor = IO_readint("Digite uma quantidade de valores inteiros: ");

    soma = readNumberShowOddNoMultSeven(valor);

    IO_printf("\nA soma dos valores e : [%d]\n", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method17() {
    int valor = 0;
    double soma = 0.0;

    IO_id("Exemplo0517 - Method17 - v0.1");

    valor = IO_readint("Digite uma quantidade de valores inteiros: ");

    soma = readNumberShowEvenNoMultFive(valor);

    IO_printf("\nA soma dos inversos dos valores e: [%lf]", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method18() {
    int valor = 0, somar = 0;

    IO_id("Exemplo0518 - Method18 - v0.1");

    valor = IO_readint("Digite uma quantidade: ");

    somar = readNumberShowAndAdd(valor);

    IO_printf("\nA soma dos numeros e: [%d]\n", somar);

    IO_pause("Apertar ENTER para continuar");
}

void method19() {
    int valor = 0, soma = 0;

    IO_id("Exemplo0519 - Method19 - v0.1");

    valor = IO_readint("Digite uma quantidade: ");

    soma = readNumberShowAndAddQuadratic(valor);

    IO_printf("\nA soma dos quadrados dos numeros e: [%d]\n", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method20() {
    int valor = 0;
    double soma = 0.0;

    IO_id("Exemplo0520 - Method20 - v0.1");

    valor = IO_readint("Digite uma quantidade: ");

    soma = readNumberShowReverseAndAdd(valor);

    IO_printf("\nA soma dos inversos dos numeros e: [%lf]", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method21() {
    int valor = 0, resultado = 0;

    IO_id("Exemplo0519 - Method19 - v0.1");

    valor = IO_readint("Digite um numero: ");

    resultado = fatorial(valor);

    IO_printf("\nO fatorial do numero %d e: [%d]\n", valor, resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method22() {
    int valor = 0;
    double resultado = 0.0;

    IO_id("Exemplo0519 - Method19 - v0.1");

    valor = IO_readint("Digite um numero: ");

    resultado = readAndShowFraction(valor);

    IO_printf("\nA multiplicacao das fracoes e: [%lf]\n", resultado);

    IO_pause("Apertar ENTER para continuar");
}

int main () {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "Ed05 - v.1 - 19/09/2020\n"       );
        IO_println ( "Estudo Dirigido 05\n"          );
        IO_println ( "Matricula: 716417\nNome: Daniel Vitor de Oliveira Santos\n" );
        IO_println ( "" ); 

        IO_println ( "Opcoes" );
        IO_println ( " 0 - parar" );
        IO_println ( " 1 - mostrar certa quantidade de valores" );
        IO_println ( " 2 - mostrar certa quantidade de valores pares" );
        IO_println ( " 3 - mostrar certa quantidade de valores multiplicados por 2 crescente" );
        IO_println ( " 4 - mostrar certa quantidade de valores multiplicados por 2 decrescente" );
        IO_println ( " 5 - mostrar certa quantidade de valores multiplicados por 2 e decrescente" );
        IO_println ( " 6 - mostrar a soma de certa quantidade de valores pares" );
        IO_println ( " 7 - somar certa quantidade de fracoes" );
        IO_println ( " 8 - somar certa quantidade de fracoes" );
        IO_println ( " 9 - somar certa quantidade de fracoes" );
        IO_println ( "10 - multiplicar valores" );
        IO_println ( "11 - digite uma quantidade de numeros multiplos de 2 e 3 que deseja ver" );
        IO_println ( "12 - digite uma quantidade de numeros multiplos de 3 e par que deseja ver crescente" );
        IO_println ( "13 - digite uma quantidade de numeros multiplos de 3 e impar que deseja ver decrescente" );
        IO_println ( "14 - digite uma quantidade e numeros inversos aos multiplos de 4 que deseja ver" );
        IO_println ( "15 - digite um real e uma quantidade de numeros que deseja ver em forma de fracao" );
        IO_println ( "16 - mostrar a quantidade de valores impares e nao multiplos de 7" );
        IO_println ( "17 - mostrar a soma dos inversos dos numeros pares nao multiplos de 5" );
        IO_println ( "18 - mostrar e somar os primeiros numeros naturais" );
        IO_println ( "19 - mostrar a soma dos quadrados dos primeiros numeros naturais" );
        IO_println ( "20 - mostrar a soma dos inversos dos primeiros numeros naturais" );
        IO_println ( "21 - calcular o fatorial de um numero" );
        IO_println ( "22 - calcular e mostrar o resultado de uma fracao especifica" );
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
            case 22:
                method22();
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
 0.1 14/09 esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
*/