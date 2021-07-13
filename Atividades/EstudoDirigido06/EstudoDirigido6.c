/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Ed06
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 29/09/2020
*/

#include "io.h"
#include "MyLib.h"

void method00 () {

}

void method01a (int x) {
    if (x > 0) {
        IO_printf("%s%d\n", "Valor = ", x);
        method01a(x - 1);
    }
}

void method02a (int x) {
    if (x > 0) {
        method02a(x - 1);
        IO_printf("%s%d\n", "Valor = ", x);
    }
}

void method03a (int x) {
    if (x > 1) {
        method03a (x - 1);
        IO_printf("%s%d\n", "Valor = ", x);
    } else {
        IO_printf("%s\n", "Valor = 1");
    }
}

void method04a (int x) {
    if (x > 1) {
        method04a(x - 1);
        IO_printf("%s%d\n", "Valor = ", 2*(x - 1));
    } else {
        IO_printf("%s\n", "Valor = 1");
    }
}

void method05a (int x) {
    if (x > 1) {
        method05a(x - 1);
        IO_printf("%d: %d/%d\n", x, (2*(x - 1)), (2*(x - 1) + 1));
    } else {
        IO_printf ("%d; %d\n", x, 1);
    }
}

double somarFracoes (int x) {
    double soma = 0.0;

    if (x > 1) {
        soma = (2.0*(x - 1)/(2.0*(x - 1) + 1) + somarFracoes(x - 1));
        IO_printf("%d: %lf/%lf\n", x, (2.0*(x - 1)), (2.0*(x - 1) + 1));
    } else {
        soma = 1.0;
        IO_printf("%d; %lf\n", x, 1.0);
    }
    return(soma);
}

double somarFracoes2b (int x, double soma, double numerador, double denominador) {
    if (x > 0) {
        IO_printf("%d: %lf/%lf\n", x, numerador, denominador);
        soma = somarFracoes2b(x - 1, soma + ((1.0*numerador) / denominador), numerador + 2.0, denominador + 2.0);
    }
    return(soma);
}

double somarFracoes2a (int x) {
    double soma = 0.0;

    if (x > 0) {
        IO_printf("%d: %lf\n", x, 1.0);
        soma = somarFracoes2b(x - 1, 1.0, 2.0, 3.0);
    }
    return(soma);
}

int contarDigitos (int x) {
    int resposta = 1;

    if (x >= 10) {
        resposta = 1 + contarDigitos(x/10);
    } else {
        if (x < 0) {
            resposta = contarDigitos(-x);
        }
    }
    return(resposta);
}

int fibonacci (int x) {
    int resposta = 0;

    if (x == 1 || x == 2) {
        resposta = 1;
    } else {
        if (x > 1) {
            resposta = fibonacci(x - 1) + fibonacci(x - 2);
        }
    }
    return(resposta);
}

int contarMinusculas (chars cadeia, int x) {
    int resposta = 0;

    if (0 <= x && x < strlen(cadeia)) {
        if (cadeia[x] >= 'a' && cadeia[x] <= 'z') {
            resposta = 1;
        }
        resposta = resposta + contarMinusculas (cadeia, x + 1);
    }
    return(resposta);
}

void method01 () {
    int quantidade = 0, valor = 0, controle = 0;

    IO_id ( "Exemplo0601 - Method01 - v0.0" );

    method01a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method02 () {


    IO_id ( "Exemplo0602 - Method02 - v0.0" );

    method02a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method03 () {


    IO_id ( "Exemplo0603 - Method03 - v0.0" );

    method03a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method04 () {


    IO_id ( "Exemplo0604 - Method04 - v0.0" );

    method04a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method05 () {


    IO_id ( "Exemplo0605 - Method05 - v0.0" );

    method05a(5);

    IO_pause("Apertar ENTER para continuar");
}

void method06 () {
    double soma = 0.0;

    IO_id ( "Exemplo0606 - Method06 - v0.0" );

    soma = somarFracoes(5);

    IO_printf("Soma = %lf\n", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method07 () {
    double soma = 0.0;

    IO_id ( "Exemplo0607 - Method07 - v0.0" );

    soma = somarFracoes2a(5);

    IO_printf("soma = %lf\n", soma);

    IO_pause("Apertar ENTER para continuar");
}

void method08 () {


    IO_id ( "Exemplo0608 - Method08 - v0.0" );

    IO_printf ( "digitos (%3d) = %d\n", 123, contarDigitos (123) );
    IO_printf ( "digitos (%3d) = %d\n", 1 , contarDigitos ( 1 ) );
    IO_printf ( "digitos (%3d) = %d\n", -10, contarDigitos ( -10 ) );

    IO_pause("Apertar ENTER para continuar");
}

void method09 () {


    IO_id ( "Exemplo0609 - Method09 - v0.0" );

    IO_printf ( "fibonacci (%d) = %d\n", 1, fibonacci ( 1 ) );
    IO_printf ( "fibonacci (%d) = %d\n", 2, fibonacci ( 2 ) );
    IO_printf ( "fibonacci (%d) = %d\n", 3, fibonacci ( 3 ) );
    IO_printf ( "fibonacci (%d) = %d\n", 4, fibonacci ( 4 ) );
    IO_printf ( "fibonacci (%d) = %d\n", 5, fibonacci ( 5 ) );

    IO_pause("Apertar ENTER para continuar");
}

void method10 () {


    IO_id ( "Exemplo0610 - Method10 - v0.0" );

    IO_printf ( "Minusculas (\"abc\",0) = %d\n", contarMinusculas ( "abc", 0 ) );
    IO_printf ( "Minusculas (\"aBc\",0) = %d\n", contarMinusculas ( "aBc", 0 ) );
    IO_printf ( "Minusculas (\"AbC\",0) = %d\n", contarMinusculas ( "AbC", 0 ) );

    IO_pause("Apertar ENTER para continuar");
}

void method11 () {
    int quantidade = 0;
    int impar = 3;

    IO_id ( "Exemplo0611 - Method11 - v0.0" );

    quantidade = IO_readint("Digite quantos valores impares voce deseja ver [>= 3]: ");

    recursionOddBiggerThreeGrowing(quantidade, impar);

    IO_pause("Apertar ENTER para continuar");
}

void method12 () {
    int quantidade = 0;
    int multiploMaior = 0;

    IO_id ( "Exemplo0612 - Method12 - v0.0" );

    quantidade = IO_readint("Digite quantos multiplos de 5 voce deseja ver: ");

    recursionMultiFiveDecreasing(quantidade, multiploMaior);

    IO_pause("Apertar ENTER para continuar");
}

void method13 () {
    int quantidade = 0;

    IO_id ( "Exemplo0613 - Method13 - v0.0" );

    quantidade = IO_readint("Digite quantos numeros da sequencia voce deseja ver: ");

    recursionSequenceGrowing(quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method14 () {
    int quantidade = 0;
    int expoente = 0;

    IO_id ( "Exemplo0614 - Method14 - v0.0" );

    quantidade = IO_readint("Digite quantos numeros da sequencia voce deseja ver: ");

    recursionSequence2Decreasing(quantidade, expoente);

    IO_pause("Apertar ENTER para continuar");
}

void method15 () {
    int tamanho = 0;
    chars caracteres = IO_new_chars(STR_SIZE);

    IO_id ( "Exemplo0615 - Method15 - v0.0" );

    caracteres = IO_readstring("Entrar com uma palavra: ");

    tamanho = strlen(caracteres);

    recursionReadStringDecreasing(caracteres, tamanho);

    IO_pause("Apertar ENTER para continuar");
}

void method16 () {
    int quantidade = 0, par = 2, resultado = 0;

    IO_id ( "Exemplo0616 - Method16 - v0.0" );

    quantidade = IO_readint("Digite um valor: ");

    resultado = recursionSumEven(quantidade, par);

    IO_printf("\nSoma dos %d numeros pares positivos = [%d]\n", quantidade, resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method17 () {
    int quantidade = 0, par = 2;
    double resultado = 0.0;

    IO_id ( "Exemplo0617 - Method17 - v0.0" );

    quantidade = IO_readint("Digite um valor: ");

    resultado = recursionSumEvenReverse(quantidade, par);

    IO_printf("\nSoma dos inversos dos %d numeros pares positivos = [%lf]\n", quantidade, resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method18 () {
    int quantidade = 0, resultado = 0, contador = 1;
    
    IO_id ( "Exemplo0618 - Method18 - v0.0" );

    quantidade = IO_readint("Quantidade de valores divisiveis por 3 na Fibonacci: ");

    for (contador = 1; contador <= quantidade; contador = contador + 1) {
        resultado = fibonacci2(contador);
        if (resultado == 0) {
            quantidade = quantidade + 1;
        } else {
            if (divisibleByThree(resultado) == true) {
                IO_printf("Valor = %d\n", resultado);
            } else {
                quantidade = quantidade + 1;
            }
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void method19 () {
    int tamanho = 0, resultado = 0;
    chars caracteres = IO_new_chars(STR_SIZE);

    IO_id ( "Exemplo0619 - Method19 - v0.0" );

    caracteres = IO_readstring("Entrar com uma cadeia de caracteres: ");

    tamanho = strlen(caracteres);

    resultado = recursiveCountDigitsOdd(caracteres, tamanho);

    IO_printf("Quantidade de valores impares: %d\n", resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method20 () {
    int tamanho = 0, resultado = 0;
    chars caracteres = IO_new_chars(STR_SIZE);

    IO_id ( "Exemplo0620 - Method20 - v0.0" );

    caracteres = IO_readstring("Entrar com uma cadeia de caracteres: ");

    tamanho = strlen(caracteres);

    resultado = recursiveCountDigitsBiggerThanN(caracteres, tamanho);

    IO_printf("Quantidade de maiusculas menores que N: %d\n", resultado);

    IO_pause("Apertar ENTER para continuar");
}

//Incompleto, acho que eu estava no caminho correto porem nao tive tempo de finalizar
//Tive dificuldade em começar contando em 1 e depois seguir a sequencia normalmente
void method21 () {
    int valor = 0, potencia = 0, quantidade = 0;

    IO_id ( "Exemplo0621 - Method21 - v0.0" );

    valor = IO_readint("Digite um valor: ");
    quantidade = IO_readint("Digite uma quantidade: ");

    recursiveSumSequence(valor, quantidade, potencia);

    IO_pause("Apertar ENTER para continuar");
}

void method22 () {


    IO_id ( "Exemplo0622 - Method22 - v0.0" );



    IO_pause("Apertar ENTER para continuar");
}

int main () {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "Ed06 - v.1 - 29/09/2020\n"       );
        IO_println ( "Estudo Dirigido 06\n"          );
        IO_println ( "Matricula: 716417\nNome: Daniel Vitor de Oliveira Santos\n" );
        IO_println ( "" ); 

        IO_println ( "Opcoes" );
        IO_println ( " 0 - parar" );
        IO_println ( " 1 - mostrar uma certa quantidade de valores em ordem decrescente" );
        IO_println ( " 2 - mostrar uma certa quantidade de valores em ordem crescente" );
        IO_println ( " 3 - mostrar uma certa quantidade de valores multiplicados por 2 em ordem crescente" );
        IO_println ( " 4 - mostrar certa quantidade de valores multiplicados por 2 decrescente" );
        IO_println ( " 5 - mostrar certa quantidade de valores em uma fracao crescente" );
        IO_println ( " 6 - somar uma certa quantidade de fracoes ja definidas" );
        IO_println ( " 7 - somar uma certa quantidade de fracoes ja definidas" );
        IO_println ( " 8 - contar digitos" );
        IO_println ( " 9 - sequencia de fibonacci" );
        IO_println ( "10 - contar minusculas" );
        IO_println ( "11 - digite quantos valores impares maiores ou iguais a 3 deseja ver" );
        IO_println ( "12 - digite quantos multiplos de 5 voce deseja ver" );
        IO_println ( "13 - digite quantos numeros da sequencia voce deseja ver" );
        IO_println ( "14 - digite quantos numeros da sequencia voce deseja ver" );
        IO_println ( "15 - digite uma cadeia de caracteres e veja ela ao contrario" );
        IO_println ( "16 - veja a soma dos n primeiros numeros pares comecando por 2" );
        IO_println ( "17 - veja a soma dos inversos dos n primeiros numeros pares comecando por 2" );
        IO_println ( "18 - quantidade de valores divisiveis por 3 na Fibonacci" );
        IO_println ( "19 - entrar com uma string e ver quantos sao impares" );
        IO_println ( "20 - entrar com uma string e ver quantos sao maiusculos e menores que N" );
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
 0.1 29/09 esboco
---------------------------------------------- testes
Algoritmo         Dados             Resultados

method01            5               5,4,3,2,1         
method02            5               1,2,3,4,5
method03            5               1,2,3,4,5
method04            5               1,2,4,6,8
method05            5               1,2/3,4/5,6/7,8/9
method06            5               4.212698
method07            5               4.212698
method08        123,1,-10           3,1,2
method09        1,2,3,4,5           1,1,2,3,5
method10        abc,aBc,AbC         3,2,1
method11            8               3,5,7,9,11,13,15,17
method12            4               20,15,10,5
method13            6               1,4,8,12,16,20
method14            4               1/64,1/16,1/4,1/1
method15         abc55&&            &&55cba
method16            9               90
method17            6               1.1225000
method18            4               3,21,144,987
method19        abc12345            3
method20        ABCyy223            3
*/