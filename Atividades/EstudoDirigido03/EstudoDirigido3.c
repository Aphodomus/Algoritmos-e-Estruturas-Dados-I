/**
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Ed03
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 10/09/2020
  */

#include "io.h"

void method00() {

}

void method01() {
    int x = 0;

    IO_id ( "Exemplo01 - Method01 - v0.1" );

    x = IO_readint ("Entrar com uma quantidade: ");

    while (x > 0) {
        IO_println ( IO_toString_d ( x ) );
        x = x - 1;
    }

    IO_pause   ( "Apertar ENTER para continuar." );
} 

void method02() {
    int x = 0, y = 0;

    IO_id ( "Exemplo02 - Method02 - v0.1" );

    x = IO_readint("Entrar com uma quantidade: ");

    y = x;
    while (y > 0) {
        IO_println(IO_toString_d(x));
        y = y - 1;
    }

    IO_pause   ( "Apertar ENTER para continuar." );
}

void method03() {
    int x = 0, y = 0;

    IO_id ( "Exemplo03 - Method03 - v0.1" );

    x = IO_readint("Entrar com uma quantidade: ");

    y = 1;
    while (y <= x) {
        IO_printf("%d\n", y);
        y = y + 1;
    }

    IO_pause   ( "Apertar ENTER para continuar." );
}

void method04() {
    int x = 0, y = 0;

    IO_id ( "Exemplo04 - Method04 - v0.1" );

    x = IO_readint("Entrar com uma quantidade: ");

    for (y = 1; y <= x; y = y + 1) {
        IO_printf("%d\n", y);
    }

    IO_pause   ( "Apertar ENTER para continuar." );
}

void method05() {
    int x = 0, y = 0;

    IO_id ( "Exemplo05 - Method05 - v0.1" );

    x = IO_readint("Entrar com uma quantidade: ");

    for (y = x; y >= 1; y = y - 1) {
        IO_printf ( "%d\n", y );
    }

    IO_pause   ( "Apertar ENTER para continuar." );
}

void method06() {
    int x = 0, y = 0;

    chars palavra = IO_new_chars ( STR_SIZE );
    int tamanho = 0;

    IO_id ( "Exemplo06 - Method06 - v0.1" );

    palavra = IO_readstring ( "Entrar com uma palavra: " );

    tamanho = strlen (palavra) - 1;

    for (y = tamanho; y >= 0; y = y - 1) {
        IO_printf ( "%d: [%c]\n", y, palavra [y] );
    }

    IO_pause   ( "Apertar ENTER para continuar." );
}

void method07() {
    int x = 0, y = 0;

    char palavra [STR_SIZE];
    int tamanho = 0;

    IO_id ( "Exemplo07 - Method07 - v0.1" );

    IO_printf ( "Entrar com uma palavra: " );
    scanf ( "%s", palavra );

    tamanho = strlen ( palavra );

    for (y = 0; y < tamanho; y = y + 1) {
        IO_printf ( "%d: [%c]\n", y, palavra [y] );
    }

    IO_pause   ( "Apertar ENTER para continuar." );
}

void method08() {
    int inferior = 0, superior = 0, x = 0;

    IO_id ( "Exemplo08 - Method08 - v0.1" );

    inferior = IO_readint ( "Limite inferior do intervalo: " );
    superior = IO_readint ( "Limite superior do intervalo : " );

    for (x = inferior; x <= superior; x = x + 1) {
        IO_printf ( "%d\n", x );
    }

    IO_pause ( "Apertar ENTER para continuar" );
}

void method09() {
    double inferior = 0, superior = 0, passo = 0, x = 0;

    IO_id ( "Exemplo09 - Method09 - v0.1" );

    inferior = IO_readdouble ( "Limite inferior do intervalo : " );
    superior = IO_readdouble ( "Limite superior do intervalo : " );
    passo = IO_readdouble ( "Variacao no intervalo (passo): " );

    for (x = superior; x >= inferior; x = x - passo) {
        IO_printf ( "%lf\n", x );
    }

    IO_pause ( "Apertar ENTER para continuar" );
}

void method10() {
    double inferior = 0, superior = 0, passo = 0, x = 0;

    IO_id ( "Exemplo10 - Method10 - v0.1" );

    inferior = IO_readdouble ( "Limite inferior do intervalo : " );

    do {
        superior = IO_readint ( "Limite superior do intervalo: " );
    } while (inferior >= superior);

    do {
        passo = IO_readdouble ( "Variacao no intervalo (passo): " );
    } while (passo <= 0.0);

    for (x = inferior; x <= superior; x = x + passo) {
        IO_printf("%f\n", x);
    }

    IO_pause ( "Apertar ENTER para continuar" );
}

void method11() {
    int tamanho = 0, x = 0;

    chars palavra = IO_new_chars ( STR_SIZE );

    IO_id ( "Exemplo11 - Method11 - v0.1" );

    palavra = IO_readstring ( "Entrar com uma palavra: " );
    tamanho = strlen (palavra);

    for (x = 0; x < tamanho; x = x + 1) {
        if (palavra [x] >= 'A' && palavra [x] <= 'Z') {
            if (palavra [x] >= 'A' && palavra [x] < 'N') {
                IO_printf("A letra digitada e maiuscula e menor que N -> [%c]\n", palavra [x]);
            } else {
                if(palavra [x] == 'N') {
                    IO_printf("A letra digitada e maiuscula e igual a N -> [%c]\n", palavra [x]);
                } else {
                    IO_printf("A letra digitada e maiuscula e maior que N -> [%c]\n", palavra [x]);
                }
            }
        } else {
            if (palavra [x] >= 'a' && palavra [x] < 'n') {
                IO_printf("A letra digitada e minuscula e menor que n -> [%c]\n", palavra [x]);
            } else {
                if(palavra [x] == 'n') {
                    IO_printf("A letra digitada e minuscula e igual a N -> [%c]\n", palavra [x]);
                } else {
                    if (palavra [x] > 'n') {
                        IO_printf("A letra digitada e minuscula e maior que N -> [%c]\n", palavra [x]);
                    } else {
                        IO_printf("Isso nao e uma letra -> [%c]\n", palavra [x]);
                    }
                }
            }
        }
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

void method12() {
    int tamanho = 0, x = 0;

    chars palavra = IO_new_chars ( STR_SIZE );

    IO_id ( "Exemplo12 - Method12 - v0.1" );

    palavra = IO_readstring ( "Entrar com uma palavra: " );
    tamanho = strlen (palavra);

    for (x = tamanho; x >= 0; x = x - 1) {
        if (palavra [x] >= 'A' && palavra [x] <= 'Z') {
            if (palavra [x] >= 'A' && palavra [x] < 'N') {
                IO_printf("%d: A letra digitada e maiuscula e menor que N -> [%c]\n", x, palavra [x]);
            } else {
                if(palavra [x] == 'N') {
                    IO_printf("%d: A letra digitada e maiuscula e igual a N -> [%c]\n", x, palavra [x]);
                } else {
                    IO_printf("%d: A letra digitada e maiuscula e maior que N -> [%c]\n", x, palavra [x]);
                }
            }
        } else {
            if (palavra [x] >= 'a' && palavra [x] < 'n') {
                IO_printf("%d: A letra digitada e minuscula e menor que n -> [%c]\n", x, palavra [x]);
            } else {
                if(palavra [x] == 'n') {
                    IO_printf("%d: A letra digitada e minuscula e igual a N -> [%c]\n", x, palavra [x]);
                } else {
                    IO_printf("%d: A letra digitada e minuscula e maior que N -> [%c]\n", x, palavra [x]);
                }
            }
        }
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

void method13() {
    int tamanho = 0, x = 0;

    chars palavra = IO_new_chars ( STR_SIZE );

    IO_id ( "Exemplo13 - Method13 - v0.1" );

    palavra = IO_readstring ( "Entrar com uma palavra: " );
    tamanho = strlen (palavra);

    for (x = tamanho; x >= 0; x = x - 1) {
        if (palavra [x] >= 'A' && palavra [x] <= 'Z') {
            if (palavra [x] >= 'A' && palavra [x] < 'N') {
                IO_printf("%d: A letra digitada e maiuscula e menor que N -> [%c]\n", x, palavra [x]);
            } else {
                if(palavra [x] == 'N') {
                    IO_printf("%d: A letra digitada e maiuscula e igual a N -> [%c]\n", x, palavra [x]);
                } else {
                    IO_printf("%d: A letra digitada e maiuscula e maior que N -> [%c]\n", x, palavra [x]);
                }
            }
        } else {
            if (palavra [x] >= 'a' && palavra [x] < 'n') {
                IO_printf("%d: A letra digitada e minuscula e menor que n -> [%c]\n", x, palavra [x]);
            } else {
                if(palavra [x] == 'n') {
                    IO_printf("%d: A letra digitada e minuscula e igual a N -> [%c]\n", x, palavra [x]);
                } else {
                    IO_printf("%d: A letra digitada e minuscula e maior que N -> [%c]\n", x, palavra [x]);
                }
            }
        }
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

void method14() {
    int tamanho = 0, x = 0;

    chars palavra = IO_new_chars ( STR_SIZE );

    IO_id ( "Exemplo14 - Method14 - v0.1" );

    palavra = IO_readstring ( "Entrar com uma palavra: " );
    tamanho = strlen (palavra);

    for (x = 0; x < tamanho; x = x + 1) {
        if (palavra [x] >= 'A' && palavra [x] <= 'Z') {
            IO_printf("%d: A letra digitada e maiuscula -> [%c]\n", x, palavra [x]);
        } else {
            if (palavra [x] >= 'a' && palavra [x] <= 'z') {
                IO_printf("%d: A letra digitada e minuscula -> [%c]\n", x, palavra [x]);
            } else {
                IO_printf("%d: Nao e uma letra -> [%c]\n", x, palavra [x]);
            }
        }
    }

    IO_pause ( "Apertar ENTER para continuar" );
}

void method15() {
    int tamanho = 0, x = 0;

    chars palavra = IO_new_chars ( STR_SIZE );

    IO_id ( "Exemplo15 - Method15 - v0.1" );

    palavra = IO_readstring ( "Entrar com uma cadeia de caracteres: " );
    tamanho = strlen (palavra) -1;

    for (x = tamanho; x >= 0; x = x - 1) {
        if (palavra[x] >= '0' && palavra[x] <= '9') {
            IO_printf("%d: O digito e -> [%c]\n", x, palavra [x]);
        } else {
            IO_printf("%d: Nao e um digito -> [%c]\n",x , palavra [x]);
        }
    }

    IO_pause ( "Apertar ENTER para continuar" );
}

void method16() {
    int tamanho = 0, x = 0;

    chars palavra = IO_new_chars ( STR_SIZE );

    IO_id ( "Exemplo16 - Method16 - v0.1" );

    palavra = IO_readstring ( "Entrar com uma cadeia de caracteres: " );
    tamanho = strlen (palavra);

    for (x = 0; x < tamanho; x = x + 1) {
        if (!(palavra[x] >= '0' && palavra[x] <= '9') && !(palavra [x] >= 'a' && palavra [x] <= 'z')) {
            IO_printf("%d: Nao e um digito ou nao e uma letra minuscula -> [%c]\n",x , palavra [x]);
        }
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

void method17(){
    int inferior = 0, superior = 0, x = 0, numeroDeInteiros = 0, contador = 0;

    IO_id ( "Exemplo17 - Method17 - v0.1" );

    inferior = IO_readint ( "Limite inferior do intervalo: " );
    superior = IO_readint ( "Limite superior do intervalo: " );

    numeroDeInteiros = IO_readint("Quantidade de inteiros a verificar: ");
    
    for (contador = 0; contador < numeroDeInteiros; contador = contador + 1) {
        x = IO_readint("Digite o inteiro que vai ser verificado: ");

        if (x%2 == 0 && x%3 == 0) {
            if (x >= inferior && x <= superior) {
                IO_printf("[%d]: O numero [%d] esta no intervalo [%d:%d] e tambem e multiplo de 2 e 3\n", contador, x, inferior, superior);
            } else {
                IO_printf("[%d]: O numero [%d] nao esta no intervalo [%d:%d]\n", contador, x, inferior, superior);
            }
        } else {
            IO_printf("[%d]: O numero [%d] nao e multiplo de 2 e 3\n", contador, x);
        }
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

void method18() {
    int inferior = 0, superior = 0, x = 0, numeroDeInteiros = 0, contador = 0;

    IO_id ( "Exemplo18 - Method18 - v0.1" );

    inferior = IO_readint ( "Limite inferior do intervalo: " );
    superior = IO_readint ( "Limite superior do intervalo: " );

    numeroDeInteiros = IO_readint("Quantidade de inteiros a verificar: ");
    
    for (contador = 0; contador < numeroDeInteiros; contador = contador + 1) {
        x = IO_readint("Digite o inteiro que vai ser verificado: ");

        if (!(x%5 == 0) && x%3 == 0) {
            if (x >= inferior && x <= superior) {
                IO_printf("[%d]: O numero [%d] esta no intervalo [%d:%d] e tambem e multiplo de 3 e nao multiplo de 5\n", contador, x, inferior, superior);
            } else {
                IO_printf("[%d]: O numero [%d] nao esta no intervalo [%d:%d]\n", contador, x, inferior, superior);
            }
        } else {
            IO_printf("[%d]: O numero [%d] nao atende aos requisitos = ser multiplo de 3 ou nao multiplo de 5\n", contador, x);
        }
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

void  method19() {
    double inferior = 0.0, superior = 0.0, x = 0.0;
    int numeroDeReais = 0, contador = 0;

    IO_id ( "Exemplo19 - Method19 - v0.1" );

    inferior = IO_readdouble ( "Limite inferior do intervalo: " );

    do {
        superior = IO_readdouble("Limite superior do intervalo: ");
    } while (superior < inferior);

    numeroDeReais = IO_readint("Quantidade de Reais a verificar: ");
    
    for (contador = 0; contador < numeroDeReais; contador = contador + 1) {
        x = IO_readdouble("Digite o Real que vai ser verificado: ");

        if ((int)x% 2 != 0) {
            if (x >= inferior && x <= superior) {
                IO_printf("[%d]: A parte inteira do numero [%.2f] esta no intervalo [%.2f:%.2f] e tambem tem a parte inteira impar\n", contador, x, inferior, superior);
            } else {
                IO_printf("[%d]: A parte inteira do numero [%.2f] nao esta no intervalo [%.2f:%.2f]\n", contador, x, inferior, superior);
            }
        } else {
            IO_printf("[%d]: O numero [%.2f] nao atende aos requisitos = ter a parte inteira impar\n", contador, x);
        }
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

void method20() {
    double inferior = 0.0, superior = 0.0, x = 0.0;
    int numeroDeReais = 0, contador = 0;

    IO_id ( "Exemplo20 - Method20 - v0.1" );

    do {
        inferior = IO_readdouble ( "Limite inferior do intervalo: " );
    } while (!(inferior > 0 && inferior < 1));
    
    do {
        superior = IO_readdouble("Limite superior do intervalo: ");
    } while (!(superior > inferior && superior < 1) );

    numeroDeReais = IO_readint("Quantidade de Reais a verificar: ");
    
    for (contador = 0; contador < numeroDeReais; contador = contador + 1) {
        x = IO_readdouble("Digite o Real que vai ser verificado: ");

        if ((x-(int)x) > inferior && (x-(int)x) < superior) {
            IO_printf("[%d]: A parte fracionaria do numero [%.3f] esta no intervalo [%.3f : %.3f]\n",contador , x, inferior, superior);
        } else {
            IO_printf("[%d]: A parte fracionaria do numero [%.3f] nao esta entre o intervalo [%.3f : %.3f] \n",contador , x, inferior, superior);
        }
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

/*Nao sabia como colocar os caracteres nao alfanumericos em outra cadeia de caracteres e mostrar*/
void method21() {
    int tamanho = 0, x = 0;

    chars palavra = IO_new_chars ( STR_SIZE );

    IO_id ( "Exemplo21 - Method21 - v0.1" );

    palavra = IO_readstring ( "Entrar com uma cadeia de caracteres: " );
    tamanho = strlen (palavra);

    for (x = 0; x < tamanho; x = x + 1) {
        if (!(palavra[x] >= '0' && palavra[x] <= '9') && !(palavra [x] >= 'a' && palavra [x] <= 'z') && !(palavra [x] >= 'A' && palavra [x] <= 'Z')) {
            IO_printf("%d: Nao e um simbolo alfanumerico -> [%c]\n",x , palavra [x]);
        } else {
            IO_printf("%d: E um simbolo alfanumerico -> [%c]\n",x , palavra [x]);
        }
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

/*Nao consegui desenvolver corretamente*/
void method22() {
    int tamanho = 0, x = 0;

    chars palavra = IO_new_chars ( STR_SIZE );

    IO_id ( "Exemplo21 - Method21 - v0.1" );

    palavra = IO_readstring ( "Entrar com uma cadeia de caracteres: " );
    tamanho = strlen (palavra);
    
    IO_pause ( "Apertar ENTER para continuar" );
}

int main (void) {
    int x = 0;

    do {
        IO_clrscr ( );
        IO_printf  ( "\n" );   
        IO_println ( "Ed03 - v.1 - 10/09/2020\n"       );
        IO_println ( "Estudo Dirigido 03\n"          );
        IO_println ( "Matricula: 716417\nNome: Daniel Vitor de Oliveira Santos\n" );
        IO_println ( "" ); 

        IO_println ( "Opcoes:"       );
        IO_println ( "0 - Parar"     );
        IO_println ( "1 - Repeticao com teste no inicio (decrescente)" );
        IO_println ( "2 - Repeticao com teste no inicio (alternativo)" );
        IO_println ( "3 - Repeticao com teste no inicio (crescente)" );
        IO_println ( "4 - Repeticao com teste no inicio e variacao (crescente)" );
        IO_println ( "5 - Repeticao com teste no inicio e variacao (decrescente)" );
        IO_println ( "6 - Repeticao sobre cadeia de caracteres (decrescente)" );
        IO_println ( "7 - Repeticao sobre cadeia de caracteres (crescente)" );
        IO_println ( "8 - Repeticao com intervalos (crescente)" );
        IO_println ( "9 - Repeticao com intervalos (decrescente)" );
        IO_println ( "10 - Repeticao com confirmacao " );
        IO_println ( "11 - Ver se uma letra e menor que N e maiuscula (crescente) " );
        IO_println ( "12 - Ver se uma letra e maior que N e maiuscula e contar (decrescente)" );
        IO_println ( "13 - Ver se uma letra e maior que N e maiuscula e do fim ao inicio " );
        IO_println ( "14 - Ver se uma letra maiuscula ou minuscula e contar" );
        IO_println ( "15 - Ver se um digito qualquer e contar" );
        IO_println ( "16 - Ver se nao e um digito ou nao e uma letra minuscula e contar" );
        IO_println ( "17 - Ver se e divisivel por 2 e 3 e pertence ao intervalo" );
        IO_println ( "18 - Ver se e divisivel por 3 e nao divisivel 5 e pertence ao intervalo" );
        IO_println ( "19 - Ver se e impar e pertence ao intervalo" );
        IO_println ( "20 - Ver se a parte fracionaria esta no intervalo" );
        IO_println ( "21 - Ver se e ou nao um simbolo alfanumerico" );
        IO_println ( "22 - Ver e dizer se contem apenas simbolos que nao sao letras ou digitos" );
        IO_println ( "" ); 

        x = IO_readint ( "Entrar com uma opcao: " );

        switch (x) {
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
                IO_pause( IO_concat ( "Valor diferente das opcoes [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22] (",
                IO_concat ( IO_toString_d ( x ), ")" ) ) );
            break;
        }
    }
    while (x != 0);

    IO_pause ( "\nApertar ENTER para terminar.\n" );
    return(0);
}


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes


---------------------------------------------- historico

Versao	Data		    Modificacao
  0.1	__/__		    esboco

 ---------------------------------------------- testes

Versao	Teste
  0.1	01. ( OK )		identificacao de programa

*/
