/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * 
  * MyLibrary - v0.1 - 25/09/2020
  * 
  * Author: Daniel Vitor de Oliveira Santos
  * Matricula: 716417
  * 
*/

#include "io.h"

//Estudo Dirigido 04----------------------------------------

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

int readStringAndCountLessN (chars string, int tamanho) {
    int posicao = 0, contador = 0;
    char simbolo = '_';

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

int readStringAndCountUpper (chars string, int tamanho) {
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

int readStringAndCountLower (chars string, int tamanho) {
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

int readStringsAndCount (chars string) {
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

//Estudo Dirigido 05----------------------------------------

int readNumberShowMultTwoThreeCres (int x) {
    int contador = 0, numero = 0;
    
    for (contador = 0; x > contador; contador = contador + 1) {
        numero = numero + 6;
        IO_printf("Multiplo de 2 e 3: [%d]\n", numero);
    }
}

int readNumberShowMultThreeCres (int x) {
    int contador = 0, numero = 0;

    for (contador = 0; x > contador; contador = contador + 1) {
        numero = numero + 3;

        if (numero%2 == 0) {
            IO_printf("Multiplo de 3 e par: [%d]\n", numero);
        } else {
            contador = contador - 1;
        }
    } 
}

int readNumberShowMultThreeDecres (int x) {
    int contador = 0, numero = 0;

    numero = x*6;
    for (contador = x; contador > 0; contador = contador - 1) {
        if (numero%2 != 0) {
            IO_printf("Multiplo de 3 e impar: [%d]\n", numero);
            numero = numero - 3;
        } else {
            numero = numero - 3;
            contador = contador + 1;
        }
    } 
}

int readNumberShowReverseMultFourCresc (int x) {
    int contador = 0, numero = 0;
    
    for (contador = 0; x > contador; contador = contador + 1) {
        numero = numero + 4;

        if (numero%4 == 0) {
            IO_printf("Inverso do multiplo de 4: 1/%d = %lf\n",numero, pow(numero,-1));
        } else {
            contador = contador - 1;
        }
    } 
}

double readNumberShow (int inteiro, double real) {
    int contador = 0, elevar = 0;
    double fracao, denominador = 0.0;
    
    denominador = real;
    
    for (contador = 0; inteiro > contador; contador = contador + 1) {
        if (contador == 0 ) {
            fracao = pow(denominador, elevar);
            IO_printf("Valor: %.0lf = [%.0lf]\n", fracao, pow(fracao, -1));
        } else {
            fracao = pow(denominador, elevar);
            IO_printf("Valor: 1/%lf = [%lf]\n", fracao, pow(fracao, -1));
        }
        if (contador < 1) {
            elevar = elevar + 1;
        } else {
            elevar = elevar + 2;
        }
    } 
}

int readNumberShowOddNoMultSeven (int x) {
    int contador = 0, numero = 3, soma = 0;
    
    for (contador = 0; x > contador; contador = contador + 1) {
        if (numero%2 != 0 && numero%7 != 0) {
            IO_printf("Impar e nao multiplo de 7: [%d]\n", numero);
            soma = soma + numero;
        } else {
            contador = contador - 1;
        }
        numero = numero + 1;
    }
    return(soma);
}

double readNumberShowEvenNoMultFive (int x) {
    int contador = 0, numero = 4;
    double soma = 0.0;
    
    for (contador = 0; x > contador; contador = contador + 1) {
        if (numero%2 == 0 && numero%5 != 0) {
            IO_printf("Par e nao multiplo de 5: [%d]\n", numero);
            soma = soma + pow(numero, -1);
        } else {
            contador = contador - 1;
        }
        numero = numero + 2;
    }
    return(soma);
}

int readNumberShowAndAdd (int x) {
    int contador = 0, numero = 1, somar = 0;

    for (contador = 0; x > contador; contador = contador + 1) {
        if (contador == 0) {
            somar = somar + numero;
            IO_printf("Valor %d\n", numero);
        } else {
            numero = numero + 1;
            somar = somar + numero;
            IO_printf("Valor %d\n", numero);
        }
    }
    return(somar);
}

int readNumberShowAndAddQuadratic (int x) {
    int contador = 0, numero = 1, somar = 0, quadrado = 0;

    for (contador = 0; x > contador; contador = contador + 1) {
        if (contador == 0) {
            somar = somar + pow(numero, 2);
            quadrado = pow(numero, 2);
            IO_printf("Valor %d^2 = [%d]\n", numero, quadrado);
        } else {
            numero = numero + 1;
            somar = somar + pow(numero, 2);
            quadrado = pow(numero, 2);
            IO_printf("Valor %d^2 = [%d]\n", numero, quadrado);
        }
    }
    return(somar); 
}

double readNumberShowReverseAndAdd (int x) {
    int contador = 0, numero = 1;
    double reverse = 0.0, somar = 0.0;

    for (contador = 0; x > contador; contador = contador + 1) {
        if (contador == 0) {
            somar = somar + pow(numero, -1);
            reverse = pow(numero, -1);
            IO_printf("Valor %d^-1 = [%lf]\n", numero, reverse);
        } else {
            numero = numero + 1;
            somar = somar + pow(numero, -1);
            reverse = pow(numero, -1);
            IO_printf("Valor %d^-1 = [%lf]\n", numero, reverse);
        }
    }
    return(somar); 
}

int fatorial (int x) {
    int resultado = 0, numero = 0;

    numero = x;
    if(numero == 0) {
        resultado = 1;
    } else {
        resultado = numero*fatorial(numero-1);
    }
    return(resultado);
}

double readAndShowFraction (int x) {
    int contador = 0;
    double multiplicar = 1.0, fracao = 0.0, denominador = 4.0, numerador = 3.0;
    
    for (contador = 0; x > contador; contador = contador + 1) {
        if (contador == 0) {
            fracao = (1 + (numerador/fatorial(denominador)));
            multiplicar = multiplicar*fracao;
            IO_printf("Fracao: 1 + %.0lf/%.0lf! = [%lf]\n", numerador, denominador, fracao);
        } else {
            numerador = numerador + 2;
            denominador = denominador + 2;
            fracao = (1 + (numerador/fatorial(denominador)));
            multiplicar = multiplicar*fracao;
            IO_printf("Fracao: 1 + %.0lf/%.0lf! = [%lf]\n", numerador, denominador, fracao);
        }
    }
    return(multiplicar); 
}

//Estudo Dirigido 06 ------------------------------

void recursionOddBiggerThreeGrowing (int quantidade, int impar) {

    if (quantidade > 0) {
        IO_printf("%s%d\n", "Valor = ", impar);
        recursionOddBiggerThreeGrowing(quantidade - 1, impar + 2);
    }
}

void recursionMultiFiveDecreasing (int quantidade, int multiploMaior) {
    multiploMaior = quantidade*5;

    if (quantidade > 0) {
        IO_printf("%s%d\n", "Valor = ", multiploMaior);
        recursionMultiFiveDecreasing(quantidade - 1, multiploMaior -5);
    }
}

void recursionSequenceGrowing (int quantidade) {

    if (quantidade > 1) {
        recursionSequenceGrowing(quantidade - 1);
        IO_printf("%s%d\n", "Valor = ", 4*(quantidade - 1));
    } else {
        IO_printf("%s\n", "Valor = 1");
    }
}

void recursionSequence2Decreasing (int quantidade, int expoente) {

    if (quantidade > 0) {
        recursionSequence2Decreasing(quantidade - 1, expoente + 1);
        IO_printf("%s%.0lf\n", "Valor = 1/", pow(4, expoente));
    }
}

void recursionReadStringDecreasing (chars palavra, int quantidade) {
    if (quantidade > 0) {
        IO_printf("Palavra = %c\n", palavra[quantidade - 1]);
        recursionReadStringDecreasing(palavra, quantidade - 1);
    }
}

int recursionSumEven (int quantidade, int par) {
    double soma = 0;

    if (quantidade > 0) {
        IO_printf("Valor = %d\n", par);
        soma = par + recursionSumEven(quantidade - 1, par + 2);
    }
    return(soma);
}

double recursionSumEvenReverse (int quantidade, int par) {
    double soma = 0.0, inverso = 0.0;

    if (quantidade > 0) {
        inverso = pow(par, -1);
        IO_printf("Valor: 1/%d = [%lf]\n", par, inverso);
        soma = inverso + recursionSumEvenReverse(quantidade - 1, par + 2);
    }
    return(soma);
}

int fibonacci2 (int quantidade) {

   if (quantidade == 1) {
       return 0;
   } else {
       if (quantidade == 2 || quantidade == 3) {
            return 1;
        } else {
            if (quantidade > 3) {
                return (fibonacci2(quantidade - 1) + fibonacci2(quantidade - 2));
            }
        }
   }
}

bool divisibleByThree(int valor) {
    bool result;
    result = false;

    if (valor%3 == 0) {
        result = true;
    }

    return(result);
}

int recursiveCountDigitsOdd (chars cadeia, int tamanho) {
    char simbolo = '_';
    int resultado = 0;

    if (tamanho > 0) {
        simbolo = cadeia[tamanho - 1];
        if (isADigit(simbolo) && odd(simbolo)) {
            IO_printf("Valor = %c\n", simbolo);
            resultado = 1;
        }
        resultado = resultado + recursiveCountDigitsOdd(cadeia, tamanho - 1);
    }

    return(resultado);
}

int recursiveCountDigitsBiggerThanN (chars cadeia, int tamanho) {
    char simbolo = '_';
    int resultado = 0;

    if (tamanho > 0) {
        simbolo = cadeia[tamanho - 1];
        if (isUpperCaseLessN(simbolo)) {
            IO_printf("Valor = %c\n", simbolo);
            resultado = 1;
        }
        resultado = resultado + recursiveCountDigitsBiggerThanN(cadeia, tamanho - 1);
    }

    return(resultado);
}

void recursiveSumSequence (int valor, int quantidade, int potencia) {
    int resultado = 0;

    if (quantidade > 0) {
        IO_printf("Valor = %0.lf\n", pow(valor, (pow(2, potencia))));
        recursiveSumSequence(valor, quantidade - 1, potencia + 1); 
    }
}