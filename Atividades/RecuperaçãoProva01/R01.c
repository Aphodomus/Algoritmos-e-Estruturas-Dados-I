/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Recuperação 01
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 02/11/2020
*/

#include "io.h"

//Resolucao da questao 2
void resolverExercicio02(int tamanho) {
    int array[tamanho];
    int contador = 0, valor = 0, negativos = 0, positivos = 0,
        nulos = 0, pares = 0, impares = 0, maiorValor = 0;

    array[0] = IO_readint("\n- Digite um numero: ");

    maiorValor = array[0];
    //Verificar se e positivo, negativo ou igual a zero
    if (maiorValor < 0) {
        negativos = negativos + 1;
    } else {
        if (maiorValor > 0) {
            positivos = positivos + 1;
        } else {
            nulos = nulos + 1;
        }
    }
    //Verificar se e par ou impar
    if (maiorValor %2 == 0) {
        pares = pares + 1;
    } else {
        impares = impares + 1;
    }

    for (contador = 1; contador < tamanho; contador = contador + 1) {
        array[contador] = IO_readint("\n- Digite um numero: ");
        //Verificar se e positivo, negativo ou igual a zero
        if (array[contador] < 0) {
            negativos = negativos + 1;
        } else {
            if (array[contador] > 0) {
                positivos = positivos + 1;
            } else {
                nulos = nulos + 1;
            }
        }
        //Verificar se e par ou impar
        if (array[contador] %2 == 0) {
            pares = pares + 1;
        } else {
            impares = impares + 1;
        }
        //Maior valor
        if (array[contador] > maiorValor) {
            maiorValor = array[contador];
        }
    }
    printf("\nResultado:\n");
    printf("Maior valor = %d\n", maiorValor);
    printf("Quantidade de pares = %d\n", pares);
    printf("Quantidade de impares = %d\n", impares);
    printf("Quantidade de positivos = %d\n", positivos);
    printf("Quantidade de negativos = %d\n", negativos);
    printf("Quantidade de nulos = %d\n", nulos);
}

//Verificar se e um operador logico
bool isLogic (char x) {
    bool result = false;
    if (x == '&' || x == '|' || x == '!') {
        result = true;
    }
    return(result);
}

//Verificar se e um operador aritmetico
bool isArithmetic (char x) {
    bool result = false;
    if (x == '+' || x == '-' || x == '*' || x == '%' || x == '/') {
        result = true;
    }
    return(result);
}

//Verificar se e um operador relacional
bool isRelational (char x) {
    bool result = false;
    if (x == '<' || x == '>' || x == '=') {
        result = true;
    }
    return(result);
}

//Verificar se e um separador
bool isSeparator (char x) {
    bool result = false;
    if (x == ' ' || x == '.' || x == ',' || x == ';' || x == ':' || x == '_') {
        result = true;
    }
    return(result);
}

//Verificar se e uma letra
bool isUpperCase (char x) {
    bool result = false;
    if ('A' <= x && x <= 'Z') {
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

bool isWord (char x) {
    bool result = false;
    if (isUpperCase(x) || isLowerCase(x)) {
        result = true;
    }
    return(result);
}

//Verificar se e um numero
bool isNumber (char x) {
    bool result = false;
    if (x >= '1' || x <= '9') {
        result = true;
    }
    return(result);
}

//Resolucao exercicio 3
void resolucaoExercicio3 (chars string, int tamanho) {
    int posicao = 0;
    char simbolo = '_';


    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];

        if (isLogic(simbolo)) {
            printf("%c = operador logico\n", simbolo);
        } else {
            if (isArithmetic(simbolo)) {
                printf("%c = operador aritmetico\n", simbolo);
            } else {
                if (isRelational(simbolo)) {
                    printf("%c = operador relacional\n", simbolo);
                } else {
                    if (isSeparator(simbolo)) {
                        printf("%c = separador\n", simbolo);
                    } else {
                        if (isWord(simbolo)) {
                            printf("%c = letra\n", simbolo);
                        } else {
                            if (isNumber(simbolo)) {
                                printf("%c = numero\n", simbolo);
                            } else {
                                printf("ERRO: Nao identificado pelo sistema");
                            }
                        }
                    }
                }
            }
        }
    }
}

//Resolucao exercicio 4 
void resolucaoExercicio4 (chars string, int tamanho) {
    int posicao = 0, logico = 0, aritmetico = 0, relacional = 0, separador = 0, letras = 0, numeros = 0;
    char simbolo = '_';

    for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
        simbolo = string[posicao];

        if (isLogic(simbolo)) {
            logico = logico + 1;
        } else {
            if (isArithmetic(simbolo)) {
                aritmetico = aritmetico + 1;
            } else {
                if (isRelational(simbolo)) {
                    relacional = relacional + 1;
                } else {
                    if (isSeparator(simbolo)) {
                        separador = separador + 1;
                    } else {
                        if (isWord(simbolo)) {
                            letras = letras + 1;
                        } else {
                            if (isNumber(simbolo)) {
                                numeros = numeros + 1;
                            } else {
                                printf("ERRO: Nao identificado pelo sistema");
                            }
                        }
                    }
                }
            }
        }
    }

    printf("\nResultado:\n");
    printf("Quantidade de operadores logicos = %d\n", logico);
    printf("Quantidade de operadores aritmeticos = %d\n", aritmetico);
    printf("Quantidade de operadores relacionais = %d\n", relacional);
    printf("Quantidade de separadores = %d\n", separador);
    printf("Quantidade de letras = %d\n", letras);
    printf("Quantidade de numeros = %d\n", numeros);
}

//Resolucao exercicio 5
void resolucaoExercicio5 (int quantidade) {
    int contador = 0, contador1 = 0, contador2 = 0, contador3 = 0, posicao = 0;
    double valor = 0.0, soma1 = 0.0, soma2 = 0.0, soma3 = 0.0, media1 = 0.0, media2 = 0.0, media3 = 0.0, menorValor = 0.0;
    
    for (contador = 0; contador < quantidade; contador = contador + 1) {
        valor = IO_readdouble("Digite um numero real: ");
        if (valor < -27.25) {
            soma1 = soma1 + valor;
            contador1 = contador1 + 1;
        } else {
            if (valor >= -27.25 && valor <= 47.25) {
                soma2 = soma2 + valor;
                contador2 = contador2 + 1;
            } else {
                soma3 = soma3 + valor;
                contador3 = contador3 + 1;
            }
        }
    }

    if (contador1 == 0) {
        media1 = 0;
    } else {
        media1 = soma1/contador1;
    }
   
    if (contador2 == 0) {
        media2 = 0;
    } else {
        media2 = soma2/contador2;
    }
    
    if (contador3 == 0) {
        media3 = 0;
    } else {
        media3 = soma3/contador3;
    }

    printf("\n");
    printf("Media dos valores menores que -27.25 = %.2lf\n", media1);
    printf("Media dos valores entre -27.25 e 47.25 = %.2lf\n", media2);
    printf("Media dos valores maiores que 47.25 = %.2lf\n", media3);

    if (media1 < media2 && media1 < media3) {
        printf("\nA menor media e = %.2lf\n", media1);
    } else {
        if (media2 < media1 && media2 < media3) {
            printf("\nA menor media e = %.2lf\n", media2);
        } else {
            if (media3 < media1 && media3 < media2) {
                printf("\nA menor media e = %.2lf\n", media3);
            }
        }
    }
    
}

//Resolucao exercicio 6
void resolucaoExercicio6 (int inferior, int superior) {
    int contador = 0, valor = 0;
    double soma = 0.0, cuboDoInverso = 0.0;

    printf("\n");
    do {
        valor = IO_readint("\nDigite um valor (se quiser parar, digite -1): ");
        contador = contador + 1;
        if (valor != 0) {
            if (valor > inferior && valor < superior) {
                cuboDoInverso = pow(pow(valor, 3), -1);
                printf("%d/%.0lf = %.4lf\n", 1, pow(valor, 3), cuboDoInverso);
                soma = soma + cuboDoInverso; 
            } else {
                printf("ERRO: Valor invalido.");
            }
        }
    } while (valor != -1);

    printf("\nSoma dos cubos dos inversos = %lf\n", soma);
}

//Resolucao exercicio 7
void resolucaoExercicio7 (double inferior, double superior) {
    int contador = -1, contador1 = 0, contador2 = 0, contador3 = 0;
    double valor = 0.0, porcentagemAbaixo = 0.0, porcentagemAcima = 0.0, porcentagemDentro = 0.0;

    printf("\n");
    do {
        valor = IO_readdouble("\nDigite um valor (se quiser parar, digite 0): ");
        contador = contador + 1;

        if (valor != 0) {
            if (valor > inferior && valor < superior) {
                contador1 = contador1 + 1;
            } else {
                if (valor < inferior) {
                    contador2 = contador2 + 1;
                } else {
                    contador3 = contador3 + 1;
                }
            }
        }

    } while (valor != 0);

    porcentagemDentro = (double)contador1/contador;
    porcentagemAbaixo = (double)contador2/contador;
    porcentagemAcima = (double)contador3/contador;

    printf("\n");
    printf("Resultados:");
    printf("\n");
    printf("Valores dentro do intervalo ]%.2lf:%.2lf[ = %d\n", inferior, superior, contador1);
    printf("Porcentagem de valores dentro do intervalo %.2lf\n", porcentagemDentro*100);
    printf("Porcentagem de valores abaixo do intervalo %.2lf\n", porcentagemAbaixo*100);
    printf("Porcentagem de valores acima do intervalo %.2lf\n", porcentagemAcima*100);

}

//Verificar se e crescente
bool testarCrescente (double x, double y, double z) {
    bool result = false;

    if ((x < y) && (x < z) && (y < z)) {
        result = true;
    }
    return(result);
}

//Verificar se e decrescente
bool testarDecrescente (double x, double y, double z) {
    bool result = false;

    if ((x > y) && (x > z) && (y > z)) {
        result = true;
    }
    return(result);
}

//Verificar qual e o maior valor
double testarMaiorValor (double x, double y, double z) {
    double result = 0.0;

    if (x > z && x > y) {
        result = x;
    }
    if (y > x && y > z) {
        result = y;
    }
    if (z > x && z > y) {
        result = z;
    }
    return(result);
}

//Verificar qual e o menor valor
double testarMenorValor (double x, double y, double z) {
    double result = 0.0;

    if (x < z && x < y) {
        result = x;
    }
    if (y < x && y < z) {
        result = y;
    }
    if (z < x && z < y) {
        result = z;
    }
    return(result);
}

//Verificar se a letra esta em ordem crescente
bool letraTestarCrescente (char x, char y, char z) {
    bool result = false;

    if ((x < y) && (x < z) && (y < z)) {
        result = true;
    }
    return(result);
}

//Verificar se a letra esta em ordem decrescente
bool letraTestarDecrescente (char x, char y, char z) {
    bool result = false;

    if ((x > y) && (x > z) && (y > z)) {
        result = true;
    }
    return(result);
}

//Verificar se a cadeia de caracteres esta em ordem crescente
bool caracteresTestarCrescente (chars x, chars y, chars z) {
    int comparacao1 = 0, comparacao2 = 0, comparacao3 = 0;
    bool result = false;

    comparacao1 = strcmp(x, y);
    comparacao2 = strcmp(x, z);
    comparacao3 = strcmp(y, z);

    if (comparacao1 == -1 && comparacao2 == -1 && comparacao3 == -1) {
        result = true;
    }

    return(result);
}

//Verificar se a cadeia de caracteres esta em ordem decrescente
bool caracteresTestarDecrescente (chars x, chars y, chars z) {
    int comparacao1 = 0, comparacao2 = 0, comparacao3 = 0;
    bool result = false;

    comparacao1 = strcmp(x, y);
    comparacao2 = strcmp(x, z);
    comparacao3 = strcmp(y, z);

    if (comparacao1 == 1 && comparacao2 == 1 && comparacao3 == 1) {
        result = true;
    }

    return(result);
}

//Verificar qual e a menor letra de uma string
char testarMenorLetra (chars x, chars y, chars z) {
    int posicao = 0, tamanho = 0;;
    char menorLetra = '_', simbolo = '_';
    chars frase = IO_new_chars(STR_SIZE);

    frase = strcat(x, y);
    frase = strcat(frase, z);

    tamanho = strlen(frase);

    menorLetra = frase[0];

    for (posicao = 1; posicao < tamanho; posicao = posicao + 1) {
        simbolo = x[posicao];
        if (simbolo < menorLetra) {
            menorLetra = simbolo;
        }
    }
    
    return(menorLetra);
}

//Verificar qual e a maior letra de uma string
char testarMaiorLetra (chars x, chars y, chars z) {
    int posicao = 0, tamanho = 0;;
    char maiorLetra = '_', simbolo = '_';
    chars frase = IO_new_chars(STR_SIZE);

    frase = strcat(x, y);
    frase = strcat(frase, z);

    tamanho = strlen(frase);

    maiorLetra = frase[0];

    for (posicao = 1; posicao < tamanho; posicao = posicao + 1) {
        simbolo = x[posicao];
        if (simbolo > maiorLetra) {
            maiorLetra = simbolo;
        }
    }
    
    return(maiorLetra);
}

void method00 () {

}

void method01() {
    int quantidade = 0, contador = 0, valor = 0;

    IO_id("Exercicio01 - Method01 - v0.0");

    quantidade = IO_readint("Digite uma quantidade: ");

    for (contador = 0; contador < quantidade; contador = contador + 1) {
        valor = IO_readint("\n- Digite um numero: ");
        //Verificar se e positivo ou negativo ou igual a zero
        if (valor > 0) {
            printf("\nO valor e positivo\n");
        } else {
            if (valor < 0) {
                printf("\nO valor e negativo\n");
            } else {
                printf("\nO valor e igual a zero\n");
            }
        }
        //Verificar se e par ou impar
        if (valor%2 == 0) {
            printf("O valor e par\n");
        } else {
            printf("O valor e impar\n");
        }

    }

    IO_pause("Apertar ENTER para continuar");
}

void method02() {
    int quantidade = 0;

    IO_id("Exercicio02 - Method02 - v0.0");

    quantidade = IO_readint("Digite uma quantidade: ");

    resolverExercicio02(quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method03() {
    int tamanho = 0;

    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exercicio03 - Method03 - v0.0");

    palavra = IO_readstring("Entrar com uma cadeia de caracteres: ");
    tamanho = strlen(palavra);

    resolucaoExercicio3(palavra, tamanho);

    IO_pause("Apertar ENTER para continuar");
}

void method04() {
    int tamanho = 0;

    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exercicio04 - Method04 - v0.0");

    palavra = IO_readstring("Entrar com uma cadeia de caracteres: ");
    tamanho = strlen(palavra);

    resolucaoExercicio4(palavra, tamanho);

    IO_pause("Apertar ENTER para continuar");
}

void method05() {
    int quantidade = 0;

    IO_id("Exercicio05 - Method05 - v0.0");

    quantidade = IO_readint("Digite uma quantidade: ");

    resolucaoExercicio5(quantidade);

    IO_pause("Apertar ENTER para continuar");
}

void method06() {
    int inferior = 0, superior = 0;

    IO_id("Exercicio06 - Method06 - v0.0");

    inferior = IO_readint("Digite o intervalo inferior: ");

    do {
        superior = IO_readint("Digite o intervalo superior: ");
    } while (superior <= inferior);

    resolucaoExercicio6(inferior, superior);

    IO_pause("Apertar ENTER para continuar");
}

void method07() {
    double inferior = 0.0, superior = 0.0;

    IO_id("Exercicio07 - Method07 - v0.0");

    inferior = IO_readdouble("Digite o intervalo inferior (real): ");

    do {
        superior = IO_readdouble("Digite o intervalo superior(real): ");
    } while (superior <= inferior);

    resolucaoExercicio7(inferior, superior);

    IO_pause("Apertar ENTER para continuar");
}

void method08() {
    double x = 0.0, y = 0.0, z = 0.0, maiorValor = 0.0, menorValor = 0.0;
    bool result1 = 0, result2 = 0;

    IO_id("Exercicio08 - Method08 - v0.0");

    x = IO_readdouble("Primeiro valor: ");
    y = IO_readdouble("Segundo valor: ");
    z = IO_readdouble("Terceiro valor: ");

    result1 = testarCrescente(x, y, z);
    result2 = testarDecrescente(x, y, z);

    maiorValor = testarMaiorValor(x, y, z);
    menorValor = testarMenorValor(x, y, z);

    if (result1 == 1) {
        printf("\nOs digitos estao em ordem crescente = [%.2lf  %.2lf  %.2lf]\n", x, y, z);
    }
    if (result2 == 1) {
        printf("\nOs digitos estao em ordem decrescente = [%.2lf  %.2lf  %.2lf]\n", x, y, z);
    }
    if (result1 == 0 && result2 == 0) {
        printf("\nOs digitos estao em ordem aleatoria = [%.2lf  %.2lf  %.2lf]\n", x, y, z);
    }
    printf("\n");
    printf("Maior valor digitado = %.2lf\n", maiorValor);
    printf("Menor valor digitado = %.2lf\n", menorValor);
    printf("\n");
    
    IO_pause("Apertar ENTER para continuar");
}

void method09() {
    char x = '_', y = '_', z = '_';
    bool result1 = 0, result2 = 0;

    IO_id("Exercicio09 - Method09 - v0.0");

    x = IO_readchar("Digite uma letra: ");
    y = IO_readchar("Digite uma letra: ");
    z = IO_readchar("Digite uma letra: ");

    result1 = letraTestarCrescente(x, y, z);
    result2 = letraTestarDecrescente(x, y, z);

    if (result1 == 1) {
        printf("\nAs letras estao em ordem crescente = [%c  %c  %c]\n", x, y, z);
    }
    if (result2 == 1) {
        printf("\nAs letras estao em ordem decrescente = [%c  %c  %c]\n", x, y, z);
    }
    if (result1 == 0 && result2 == 0) {
        printf("\nAs letras estao em ordem aleatoria = [%c  %c  %c]\n", x, y, z);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method10() {
    chars x = IO_new_chars(STR_SIZE);
    chars y = IO_new_chars(STR_SIZE);
    chars z = IO_new_chars(STR_SIZE);
    bool result1 = 0, result2 = 0;
    char menorLetra = '_', maiorLetra = '_';

    IO_id("Exercicio10 - Method10 - v0.0");

    x = IO_readstring("Digite uma cadeia de caracteres: ");
    y = IO_readstring("Digite uma cadeia de caracteres: ");
    z = IO_readstring("Digite uma cadeia de caracteres: ");

    result1 = caracteresTestarCrescente(x, y, z);
    result2 = caracteresTestarDecrescente(x, y, z);

    menorLetra = testarMenorLetra(x, y, z);
    maiorLetra = testarMaiorLetra(x, y, z);

    if (result1 == 1) {
        printf("\nOs caracteres estao em ordem crescente\n");
    }
    if (result2 == 1) {
        printf("\nOs caracteres estao em ordem decrescente\n");
    }
    if (result1 == 0 && result2 == 0) {
        printf("\nOs caracteres estao em ordem aleatoria\n");
    }

    printf("\n");
    printf("Maior letra encontrada = %c\n", maiorLetra);
    printf("Menor letra encontrada = %c\n", menorLetra);

    IO_pause("Apertar ENTER para continuar");
}


int main () {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "R01 - v.1 - 02/11/2020\n"       );
        IO_println ( "Recuperacao 01\n"          );
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