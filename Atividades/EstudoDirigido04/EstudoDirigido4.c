/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Ed03
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 14/09/2020
*/

#include "io.h"

bool positive (int x) {
    bool result = false;
    if (x > 0) {
        result = true;
    }
    return(result);
}

bool belongsTo (int x, int inferior, int superior) {
    bool result = false;
    if (inferior < x && x < superior) {
        result = true;
    }
    return(result);
}

bool even (int x) {
    bool result = false;
    if (x%2 == 0) {
        result = true;
    }
    return(result);
}

bool odd (int x) {
    bool result = false;
    if (x%2 != 0) {
        result = true;
    }
    return(result);
}

bool isLowerCase (char x) {
    bool result = false;
    if ('a' <= x && x <= 'z') {
        result = true;
    }
    return(result);
}

bool isUpperCase (char x) {
    bool result = false;
    if ('A' <= x && x <= 'Z') {
        result = true;
    }
    return(result);
}

bool isUpperCaseLessN (char x) {
    bool result = false;
    if (isUpperCase(x) && x < 'N') {
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

bool isADigit (char x) {
    return ('0' <= x && x <= '9');
}

bool isWord (char x) {
    bool result = false;
    if (isUpperCase(x) || isLowerCase(x)) {
        result = true;
    }
    return(result);
}

bool isBiggerThanN (char x) {
    bool result = false;
    if (isLowerCase(x)) {
        if (x > 'n') {
            result = true;
        }
    } else {
        if (isUpperCase(x)) {
            if (x > 'N') {
                result = true;
            }
        }
    }
    return(result);
}

bool isAlphanumeric (char x) {
    bool result = false;
    if (isDigit(x) || isWord(x)) {
        result = true;
    }
    return(result);
}

chars concatADigit (chars string, char digit) {
    return(IO_concat(string, IO_toString_c(digit)));
}

chars readStringAndCountLessN (chars string, int tamanho) {
    int posicao = 0, contador = 0;
    char simbolo = "_";

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if (isUpperCaseLessN(simbolo)) {
            contador = contador + 1;
        }
    }
    return(contador);
}

chars readStringAndShowLessN (chars string, int tamanho) {
    int posicao = 0;
    char simbolo = '_';
    chars frase = IO_new_chars(STR_SIZE);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if (isUpperCaseLessN(simbolo)) {
            frase = IO_concat(frase, IO_toString_c(simbolo));
        }
    }
    return(frase);
}

chars readStringAndCountUpper (chars string, int tamanho) {
    int posicao = 0, maiusculas = 0;
    char simbolo = '_';
    
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if (isUpperCase(simbolo) && simbolo > 'N') {
            maiusculas = maiusculas + 1;
        }
    }

    return(maiusculas);
}

chars readStringAndCountLower (chars string, int tamanho) {
    int posicao = 0, minusculas = 0;
    char simbolo = '_';
    
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if (isLowerCase(simbolo) && simbolo > 'n') {
            minusculas = minusculas + 1;
        }
    }

    return(minusculas);
}

chars readStringAndShowUpperLowerN (chars string, int tamanho) {
    int posicao = 0;
    char simbolo = '_';
    chars frase = IO_new_chars(STR_SIZE);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if (isBiggerThanN(simbolo)) {
            frase = IO_concat(frase, IO_toString_c(simbolo));
        }
    }

    return(frase);
}

chars readStringAndShowOddDigits (chars string, int tamanho) {
    int posicao = 0;
    char simbolo = '_';
    chars frase = IO_new_chars(STR_SIZE);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if (isADigit(simbolo) && odd(simbolo)) {
            frase = concatADigit(frase, simbolo);
        }
    }

    return(frase);
}

chars readStringAndShowNoAlphanumeric(chars string, int tamanho) {
    int posicao = 0;
    char simbolo = '_';
    chars frase = IO_new_chars(STR_SIZE);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if (!(isAlphanumeric(simbolo))) {
            frase = IO_concat(frase, IO_toString_c(simbolo));
        }
    }

    return(frase);
}

chars readStringAndShowAlphanumeric(chars string, int tamanho) {
    int posicao = 0;
    char simbolo = '_';
    chars frase = IO_new_chars(STR_SIZE);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if ((isAlphanumeric(simbolo))) {
            frase = IO_concat(frase, IO_toString_c(simbolo));
        }
    }

    return(frase);
}

chars readStringsAndShow (chars string) {
    int tamanho = 0, posicao = 0;
    char simbolo = '_';

    chars frase = IO_new_chars(STR_SIZE);

    tamanho = strlen(string);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if (! (isAlphanumeric(simbolo))) {
            frase = IO_concat(frase, IO_toString_c(simbolo));
        }
    }

    return(frase);
}

chars readStringsAndCount (chars string) {
    int tamanho = 0, posicao = 0, noAlphanumeric = 0;
    char simbolo = '_';

    tamanho = strlen(string);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];
        if (! (isAlphanumeric(simbolo))) {
            noAlphanumeric = noAlphanumeric + 1;
        }
    }

    return(noAlphanumeric);
}

void method00() {

}

void method01() {
    int quantidade = 0, valor = 0, controle = 0;

    IO_id("Exemplo0401 - Method01 - v0.1");

    quantidade = IO_readint("Entrar com uma quantidade: ");

    controle = 1;
    while (controle <= quantidade) {
        valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
        controle = controle + 1;
    }

    IO_pause("Apertar ENTER para continuar");
}

void method02() {
    int quantidade = 0, valor = 0, controle = 0, contador = 0;

    IO_id("Exemplo0402 -  Method02 - v0.1");

    quantidade = IO_readint("Entrar com uma quantidade: ");

    controle = 1;
    while (controle <= quantidade) {
        valor = IO_readint( IO_concat (IO_concat ( "", IO_toString_d ( controle ) ),": " ) );
        if (positive (valor)) {
            contador = contador + 1;
        }
        controle = controle + 1;
    }
    IO_printf("%s%d\n", "Positivos = ", contador);

    IO_pause("Apertar ENTER para continuar");
}

void method03() {
    int quantidade = 0, valor = 0, controle = 0, contador = 0;

    IO_id("Exemplo0403 -  Method03 - v0.1");

    quantidade = IO_readint("Entrar com uma quantidade: ");

    controle = 1;
    while (controle <= quantidade) {
        valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
        if (belongsTo(valor, 0, 100)) {
            contador = contador + 1;
        }
        controle = controle + 1;
    }
    IO_printf("%s%d\n", "Positivos menores que 100 = ", contador);

    IO_pause("Apertar ENTER para continuar");
}

void method04() {
    int quantidade = 0, valor = 0, controle = 0, contador = 0;

    IO_id("Exemplo0404 -  Method04 - v0.1");

    quantidade = IO_readint("Entrar com uma quantidade: ");

    controle = 1;
    while (controle <= quantidade) {
        valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
        if (belongsTo (valor, 0, 100) && even (valor)) {
            contador = contador + 1;
        }
        controle = controle + 1;
    }
    IO_printf("%s%d\n", "Positivos menores que 100 e pares = ", contador);

    IO_pause("Apertar ENTER para continuar");
}

void method05() {
    int quantidade = 0, valor = 0, controle = 0, contador = 0;
    bool ok = false;

    IO_id("Exemplo0405 -  Method05 - v0.1");

    quantidade = IO_readint("Entrar com uma quantidade: ");

    controle = 1;
    while (controle <= quantidade) {
        valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
        ok = belongsTo(valor, 0, 100);
        ok = ok && even(valor);
        if (ok) {
            contador = contador + 1;
        }
        controle = controle + 1;
    }
    IO_printf("%s%d\n", "Positivos menores que 100 e pares = ", contador);

    IO_pause("Apertar ENTER para continuar");
}

void method06() {
    int tamanho = 0, posicao = 0, contador = 0;
    char simbolo = '_';
    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0406 -  Method06 - v0.1");

    palavra = IO_readstring("Entrar com uma palavra: ");
    tamanho = strlen(palavra);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = palavra[posicao];
        if (isLowerCase(simbolo)) {
            contador = contador + 1;
        }
    }
    IO_printf("%s%d\n", "Minusculas = ", contador);

    IO_pause("Apertar ENTER para continuar");
}

void method07() {
    int tamanho = 0, posicao = 0, contador = 0;
    char simbolo = '_';
    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0407 -  Method07 - v0.1");

    palavra = IO_readstring("Entrar com uma palavra: ");
    tamanho = strlen(palavra);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = palavra[posicao];
        if (isLowerCase(simbolo)) {
            IO_printf("%c", simbolo);
            contador = contador + 1;
        }
    }
    IO_printf("\n%s%d\n", "Minusculas = ", contador);

    IO_pause("Apertar ENTER para continuar");
}

void method08() {
    int tamanho = 0, posicao = 0, contador = 0;
    char simbolo = '_';
    chars palavra = IO_new_chars(STR_SIZE);
    chars minusculas = IO_new_chars(STR_SIZE);

    strcpy(minusculas, STR_EMPTY);

    IO_id("Exemplo0408 -  Method08 - v0.1");

    palavra = IO_readstring("Entrar com uma palavra : ");
    tamanho = strlen(palavra);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = palavra[posicao];
        if (isLowerCase(simbolo)) {
            minusculas = IO_concat(minusculas, IO_toString_c(simbolo));
            contador = contador + 1;
        }
    }
    IO_printf("\n%s%d [%s]\n", "Minusculas = ", contador, minusculas);

    IO_pause("Apertar ENTER para continuar");
}

void method09() {
    int tamanho = 0, posicao = 0, contador = 0;
    char simbolo = '_';
    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0409 -  Method09 - v0.1");

    palavra = IO_readstring("Entrar com caracteres: ");
    tamanho = strlen(palavra);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = palavra[posicao];
        if (isDigit(simbolo)) {
            IO_printf("%c", simbolo);
            contador = contador + 1;
        }
    }
    IO_printf("\n%s%d\n", "Algarismos = ", contador);

    IO_pause("Apertar ENTER para continuar");
}

void method10() {
    int tamanho = 0, posicao = 0;
    char simbolo = '_';
    chars palavra = IO_new_chars(STR_SIZE);
    chars digitos = IO_new_chars(STR_SIZE);

    strcpy(digitos, STR_EMPTY);

    IO_id("Exemplo0410 -  Method10 - v0.1");

    palavra = IO_readstring("Entrar com uma palavra: ");
    tamanho = strlen(palavra);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = palavra[posicao];
        if (isADigit (simbolo)) {
            digitos = concatADigit(digitos, simbolo);
        }
    }
    IO_printf("\n%s%d [%s]\n", "Algarismos = ", strlen(digitos), digitos);

    IO_pause("Apertar ENTER para continuar");
}

void method11() {
    double inferior = 0.0, superior = 0.0, x = 0.0;
    int numeroDeReais = 0, contador = 0, dentro = 0, fora = 0;

    IO_id ( "Exemplo411 - Method11 - v0.1" );

    inferior = IO_readdouble ( "Limite inferior do intervalo: " );
    
    do {
        superior = IO_readdouble("Limite superior do intervalo: ");
    } while (inferior > superior);

    numeroDeReais = IO_readint("Quantidade de Reais a verificar: ");
    
    for (contador = 0; contador < numeroDeReais; contador = contador + 1) {
        x = IO_readdouble("Digite o Real que vai ser verificado: ");

        if (even(x)) {
            if ((inferior <= x && x <= superior)) {
                dentro = dentro + 1;
            } else {
                fora = fora + 1;
            }
        } else {
            if (!(inferior <= x && x <= superior)) {
                fora = fora + 1;
            }
        }
    }
    IO_printf("Existem [%d] valores que sao pares e estao dentro do intervalo [%2.lf:%2.lf]\n", dentro, inferior, superior);
    IO_printf("Existem [%d] valores que estao fora do intervalo [%2.lf:%2.lf]\n", fora, inferior, superior);
    
    IO_pause ( "Apertar ENTER para continuar" );
}

void method12() {
    int tamanho = 0, posicao = 0, contador = 0;
    char simbolo = '_';
    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0412 -  Method12 - v0.1");

    palavra = IO_readstring("Entrar com uma sequencia de caracteres: ");
    tamanho = strlen(palavra);

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = palavra[posicao];
        if (isUpperCase(simbolo)) {
            contador = contador + 1;
        }
    }
    IO_printf("Quantidade de letras maiusculas -> [%d]", contador);

    IO_pause("Apertar ENTER para continuar");
}

void method13() {
    int tamanho = 0, resultado = 0;
    char simbolo = '_';
    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0413 -  Method13 - v0.1");

    palavra = IO_readstring("Entrar com uma sequencia de caracteres: ");
    tamanho = strlen(palavra);

    resultado = readStringAndCountLessN(palavra, tamanho);

    IO_printf("Quantidade de letras maiusculas menores que N -> [%d]", resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method14() {
    int tamanho = 0;

    chars palavra = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0414 -  Method14 - v0.1");

    palavra = IO_readstring("Entrar com uma sequencia de caracteres: ");
    tamanho = strlen(palavra);

    resultado = readStringAndShowLessN(palavra, tamanho);

    IO_printf("Letras maiusculas menores que N -> [%s]\n", resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method15() {
    int tamanho = 0, maiusculas = 0, minusculas = 0;

    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0415 -  Method15 - v0.1");

    palavra = IO_readstring("Entrar com uma sequencia de caracteres: ");
    tamanho = strlen(palavra);

    maiusculas = readStringAndCountUpper(palavra, tamanho);
    minusculas = readStringAndCountLower(palavra, tamanho);

    IO_printf("\nQuantidade de letras maiusculas [%d] e minusculas [%d] maiores que N\n", maiusculas, minusculas);

    IO_pause("Apertar ENTER para continuar");
}

void method16() {
    int tamanho = 0;

    chars palavra = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0416 -  Method16 - v0.1");

    palavra = IO_readstring("Entrar com uma sequencia de caracteres: ");
    tamanho = strlen(palavra);

    resultado = readStringAndShowUpperLowerN(palavra, tamanho);

    IO_printf("\nLetras maiusculas e minusculas maiores que N -> [%s]\n", resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method17() {
    int tamanho = 0;

    chars palavra = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0417 -  Method17 - v0.1");

    palavra = IO_readstring("Entrar com uma sequencia de caracteres: ");
    tamanho = strlen(palavra);

    resultado = readStringAndShowOddDigits(palavra, tamanho);

    IO_printf("\nDigitos impares -> [%s]\n", resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method18() {
    int tamanho = 0;

    chars palavra = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0418 -  Method18 - v0.1");

    palavra = IO_readstring("Entrar com uma sequencia de caracteres: ");
    tamanho = strlen(palavra);

    resultado = readStringAndShowNoAlphanumeric(palavra, tamanho);

    IO_printf("\nCinco primeiros simbolos nao alfanumericos -> [%.5s]\n", resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method19() {
    int tamanho = 0;

    chars palavra = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0419 -  Method19 - v0.1");

    palavra = IO_readstring("Entrar com uma sequencia de caracteres: ");
    tamanho = strlen(palavra);

    resultado = readStringAndShowAlphanumeric(palavra, tamanho);

    IO_printf("\nCinco primeiros simbolos alfanumericos -> [%.5s]\n", resultado);

    IO_pause("Apertar ENTER para continuar");
}

void method20() {
    int quantidade = 0, tamanho = 0, posicao = 0, posicao1 = 0, noAlphanumeric = 0;
    char simbolo = '_';

    chars palavra = IO_new_chars(STR_SIZE);
    chars frase = IO_new_chars(STR_SIZE);
    chars strings = IO_new_chars(STR_SIZE);

    IO_id("Exemplo0420 -  Method20 - v0.1");

    quantidade = IO_readint("Quantidade de cadeias de caracteres que deseja verificar: ");

    for (posicao = 0; posicao < quantidade; posicao = posicao + 1) {
        palavra = IO_readstring("Entrar com uma sequencia de caracteres: ");
        tamanho = strlen(palavra);
        for (posicao1 = 0; posicao1 < tamanho; posicao1 = posicao1 + 1) {
            simbolo = palavra[posicao1];
            strings = IO_concat(strings, IO_toString_c(simbolo));
        }
    }

    noAlphanumeric = readStringsAndCount(strings);
    frase = readStringsAndShow(strings);

    IO_printf("\nSimbolos nao alfanumericos das frases -> [%s] e quantidade -> [%d]\n", frase, noAlphanumeric);

    IO_pause("Apertar ENTER para continuar");
}

int main () {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "Ed04 - v.1 - 14/09/2020\n"       );
        IO_println ( "Estudo Dirigido 04\n"          );
        IO_println ( "Matricula: 716417\nNome: Daniel Vitor de Oliveira Santos\n" );
        IO_println ( "" ); 

        IO_println ( "Opcoes" );
        IO_println ( " 0 - parar" );
        IO_println ( " 1 - ler certa quantidade de valores" );
        IO_println ( " 2 - ler e contar valores positivos" );
        IO_println ( " 3 - ler e contar positivos menores que 100" );
        IO_println ( " 4 - ler e contar positivos menores que 100 e pares" );
        IO_println ( " 5 - ler e contar positivos menores que 100 e pares" );
        IO_println ( " 6 - ler uma palavra e mostrar a quantidade de letras minusculas" );
        IO_println ( " 7 - ler uma palavra e mostrar a quantidade e as letras minusculas" );
        IO_println ( " 8 - ler uma palavra e mostras as letras minusculas e a quantidade" );
        IO_println ( " 9 - ler uma cadeia de caracteres e verificar se tem numeros" );
        IO_println ( "10 - ler uma cadeia de caracteres e verificar a quantidade de digitos" );
        IO_println ( "11 - ler e mostrar a quantidade de digitos" );
        IO_println ( "12 - ler e mostrar a quantidade de letras maiusculas" );
        IO_println ( "13 - ler e mostrar a quantidade de letras maiusculas menores que N" );
        IO_println ( "14 - ler e mostrar as letras maiusculas menores que N" );
        IO_println ( "15 - ler e mostrar a quantidade de maiusculas e minusculas" );
        IO_println ( "16 - ler e mostrar as letras maiusculas e minusculas maiores que N" );
        IO_println ( "17 - ler e mostrar os digitos impares de uma cadeia de caracteres" );
        IO_println ( "18 - ler e mostrar os cinco primeiros simbolos nao alfanumericos" );
        IO_println ( "19 - ler e mostrar os cinco primeiros simbolos alfanumericos" );
        IO_println ( "20 - ler e contar a quantidade de simbolos nao alfanumericos em cada palavra" );
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
a.) -1
b.) 0
c.) 5 e { 1, 2, 3, 4, 5 }
---------------------------------------------- historico
Versao Data Modificacao
 0.1 14/09 esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
*/
