#include <iostream> 
#include <limits> 
#include <string> 

void pause ( std::string text ) {
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
}

#include "myarray.hpp"
#include "io.hpp"
using namespace std;

void method00() {

}

void method01() {
    Array <int> int_array(5);

    int_array.set(0, 1);
    int_array.set(1, 2);
    int_array.set(2, 3);
    int_array.set(3, 4);
    int_array.set(4, 5);

    cout << "\nExemplo1101 - method01 - v0.0\n" << endl;

    int_array.print();

    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method02() {
    //definir dados
    Array <int> int_array(5);

    cout << endl << "Exemplo1101 - method02 - v0.0" << endl;

    //Ler dados
    int_array.read();

    //mostrar dados
    int_array.print();

    //reciclar espaco
    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method03() {
    Array <int> int_array(5);

    cout << endl << "Exemplo1101 - method03 - v0.0" << endl;

    //Ler dados
    int_array.read();

    //Mostrar dados
    int_array.fprint("Int_Array1.txt");

    //Reciclar espaco
    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method04() {
    Array <int> int_array(5);

    cout << endl << "Exemplo1101 - method04 - v0.0" << endl;

    int_array.fread("Int_Array1.txt");

    int_array.print();

    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method05() {
    int other[] = {1, 2, 3, 4, 5};
    Array <int> int_array (5, other);

    cout << endl << "Exemplo1101 - method05 - v0.0" << endl;

    //mostrar dados
    cout << "\nCopia\n" << endl;
    int_array.print();

    //reciclar espaco
    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method06() {
    Array <int> int_array1(1);

    cout << endl << "Exemplo1101 - method06 - v0.0" << endl;

    //ler dados
    int_array1.fread("Int_Array1.txt");

    //mostrar dados
    cout << "\nOriginal\n" << endl;
    int_array1.print();

    //criar copia
    Array <int> int_array2(int_array1);

    //mostrar dados
    cout << "\nCopia\n" << endl;
    int_array2.print();

    //reciclar espaco
    int_array1.free();
    int_array2.free();

    pause("Apertar ENTER para continuar");
}

void method07() {
    Array <int> int_array1(1);
    Array <int> int_array2(1);

    cout << endl << "Exemplo1101 - method07 - v0.0" << endl;

    //ler dados
    int_array1.fread("Int_Array1.txt");

    //mostrar dados
    cout << "\nOriginal\n" << endl;
    int_array1.print();

    //copiar dados
    int_array2 = int_array1;

    //mostrar dados
    cout << "\nCopia\n" << endl;
    int_array2.print();

    //reciclar espaco
    int_array1.free();
    int_array2.free();

    pause("Apertar ENTER para continuar");
}

void method08() {
    int other[] = {1, 2, 3};
    Array <int> int_array1(3, other);
    Array <int> int_array2(3, other);
    int x;

    cout << endl << "Exemplo1101 - method08 - v0.0" << endl;

    //mostrar dados
    cout << endl;
    cout << "Array_1";
    int_array1.print();

    //mostrar dados
    cout << "Array_2";
    int_array2.print();

    //mostrar comparacao
    cout << "Igualdade = " << (int_array1 == int_array2) << endl;

    //alterar dado
    int_array2.set(0, (-1));

    //mostrar dados
    cout << endl;
    cout << "Array_1" << endl;
    int_array1.print();

    //mostrar dados
    cout << "Array_2" << endl;
    int_array2.print();

    //mostrar comparacao
    cout << "Igualdade = " << (int_array1 == int_array2) << endl;

    //reciclar espaco
    int_array1.free();
    int_array2.free();

    pause("Apertar ENTER para continuar");
}

void method09() {
    Array <int> int_array1(1);
    Array <int> int_array2(1);
    Array <int> int_array3(1);

    cout << endl << "Exemplo1101 - method09 - v0.0" << endl;

    //ler dados
    int_array1.fread("Int_Array1.txt");

    //copiar dados
    int_array2 = int_array1;

    //somar dados
    int_array3 = int_array2 + int_array1;

    //mostrar dados
    cout << endl;
    cout << "Original" << endl;
    int_array1.print();

    //mostrar dados
    cout << "Copia" << endl;
    int_array2.print();

    //mostrar dados
    cout << "Soma" << endl;
    int_array3.print();

    //reciclar espaco
    int_array1.free();
    int_array2.free();
    int_array3.free();

    pause("Apertar ENTER para continuar");
}

void method10() {
    int other[] = {1, 2, 3, 4, 5};
    Array <int> int_array(5, other);
    int x;

    cout << endl << "Exemplo1101 - method10 - v0.0" << endl;

    //mostrar dados
    cout << "\nAcesso externo" << endl;
    for (x = 0; x < int_array.getLength(); x = x + 1) {
        cout << endl << setw(3) << x << " : " << int_array[x];
    }
    cout << endl << "\nFora dos limites:";
    cout << endl << "[-1]:" << int_array.get(-1) << endl;
    cout << endl << "[" << int_array.getLength() << "]:" << int_array[int_array.getLength()] << endl;

    //reciclar espaco
    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method11() {
    int quantidade = 0, inferior = 0, superior = 0, valor = 0;

    cout << endl << "Exemplo1101 - method11 - v0.0" << endl;

    do {
        quantidade = IO_readint("Digite a quantidade de elementos a serem gerados: ");
    } while (quantidade <= 0);

    inferior = IO_readint("Limite inferior: ");

    do {
        superior = IO_readint("Limite superior: ");
    } while (superior <= inferior);

    Array <int> array1(quantidade);

    for (int contador = 0; contador < quantidade; contador = contador + 1) {
        valor = array1.createIntRandom (inferior, superior);
        array1.set(contador, valor);
    }

    array1.print();

    array1.fprint("DadosExemplo1111.txt");

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method12() {
    int tamanho = 0, maiorValor = 0;
    Array <int> lerTamanho(1);

    cout << endl << "Exemplo1101 - method12 - v0.0" << endl;

    tamanho = lerTamanho.freadLength("DadosExemplo1112.txt");
    Array <int> array1(tamanho);

    array1.fread("DadosExemplo1112.txt");

    maiorValor = array1.searchBiggerEven();

    array1.print();

    if (maiorValor != 0) {
        cout << "\nMaior valor par do array = " << maiorValor << endl;
    } else {
        cout << "\nNao existe maior valor par no array.\n" << endl;
    }

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method13() {
    int tamanho = 0, menorValor = 0;
    Array <int> lerTamanho(1);

    cout << endl << "Exemplo1101 - method13 - v0.0" << endl;

    tamanho = lerTamanho.freadLength("DadosExemplo1113.txt");
    Array <int> array1(tamanho);

    array1.fread("DadosExemplo1113.txt");

    menorValor = array1.searchLowerOdd();

    array1.print();

    if (menorValor != 0) {
        cout << "\nMenor valor divisivel por 3 do array = " << menorValor << endl;
    } else {
        cout << "\nNao existe menor valor divisivel por 3 no array.\n" << endl;
    }

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method14() {
    int tamanho = 0, somaDosImpares = 0;
    Array <int> lerTamanho(1);

    cout << endl << "Exemplo1101 - method14 - v0.0" << endl;

    tamanho = lerTamanho.freadLength("DadosExemplo1114.txt");
    Array <int> array1(tamanho);

    array1.fread("DadosExemplo1114.txt");

    somaDosImpares = array1.sumOddNumbersArray();

    array1.print();

    if (somaDosImpares != 0) {
        cout << "\nA soma dos impares do array e = " << somaDosImpares << endl;
    } else {
        cout << "\nNao existe valores impares no array para serem somados. " << endl;
    }

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method15() {
    int tamanho = 0;
    double mediaDosPares = 0.0;
    Array <int> lerTamanho(1);

    cout << endl << "Exemplo1101 - method15 - v0.0" << endl;

    tamanho = lerTamanho.freadLength("DadosExemplo1115.txt");
    Array <int> array1(tamanho);

    array1.fread("DadosExemplo1115.txt");

    mediaDosPares = array1.averageEvenNumberArray();

    array1.print();

    if (mediaDosPares != 0) {
        cout << "\nA media dos pares do array e = " << mediaDosPares << endl;
    } else {
        cout << "\nNao existem valores pares no array para calcular a media." << endl;
    }

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method16() {
    int tamanho = 0, diferentesDeZero = 0;
    Array <int> lerTamanho(1);

    cout << endl << "Exemplo1101 - method16 - v0.0" << endl;

    tamanho = lerTamanho.freadLength("DadosExemplo1116.txt");
    Array <int> array1(tamanho);

    array1.fread("DadosExemplo1116.txt");

    diferentesDeZero = array1.allNumbersDifferentZero();

    array1.print();

    if (diferentesDeZero == tamanho) {
        cout << "\nTodos os valores sao iguais a zero." << endl;
    } else {
        if (diferentesDeZero > 1) {
            cout << "\nExistem valores iguais a zero = " << diferentesDeZero << endl;
        } else {
            if (diferentesDeZero == 0) {
                cout << "\nTodos os valores sao diferentes de zero." << endl;
            }
        }
    }

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method17() {
    int tamanho = 0;
    Array <int> lerTamanho(1);
    bool ordemCrescente = 0;

    cout << endl << "Exemplo1101 - method17 - v0.0" << endl;

    tamanho = lerTamanho.freadLength("DadosExemplo1117.txt");
    Array <int> array1(tamanho);

    array1.fread("DadosExemplo1117.txt");

    ordemCrescente = array1.isAscendingOrder();

    array1.print();

    if (ordemCrescente == 1) {
        cout << "\nEsta em ordem crescente." << endl;
    } else {
        cout << "\nNAO esta em ordem crescente." << endl;
    }

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method18() {
    int tamanho = 0, resultado = 0, inferior = 0, superior = 0, procurar = 0;
    Array <int> lerTamanho(1);

    cout << endl << "Exemplo1101 - method18 - v0.0" << endl;

    tamanho = lerTamanho.freadLength("DadosExemplo1118.txt");
    Array <int> array1(tamanho);

    procurar = IO_readint("Digite o valor que deseja procurar: ");

    do {
        inferior = IO_readint("Qual posicao voce deseja iniciar: ");
    } while (inferior < 0);
    
    do {
        superior = IO_readint("Ate qual posicao voce deseja procurar: ");
    } while (superior <= inferior || superior > tamanho);

    array1.fread("DadosExemplo1118.txt");

    resultado = array1.searchForThisNumber(procurar, inferior, superior);

    array1.print();

    if (resultado != 0) {
        cout << "O valor [" << procurar << "]" << " foi encontrado " << resultado << " vezes." << endl;
    } else {
        cout << "O valor [" << procurar << "]" << " nao foi encontrado." << endl;
    }

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method19() {
    int tamanho = 0, constante = 0;
    Array <int> lerTamanho (1);

    cout << endl << "Exemplo1101 - method19 - v0.0" << endl;

    constante = IO_readint("Qual o valor da constante que ira multificar o array: ");

    tamanho = lerTamanho.freadLength("DadosExemplo1119.txt");
    Array <int> array1(tamanho);
    Array <int> array2(tamanho);

    array1.fread("DadosExemplo1119.txt");

    cout << "\nOriginal" << endl;
    array1.print();

    array1.multArrayByConstant(constante);

    cout << "Resultado" << endl;
    array1.print();

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method20() {
    int tamanho = 0;
    Array <int> lerTamanho(1);

    cout << endl << "Exemplo1101 - method20 - v0.0" << endl;

    tamanho = lerTamanho.freadLength("DadosExemplo1120.txt");
    Array <int> array1(tamanho);

    array1.fread("DadosExemplo1120.txt");

    cout << "\nOriginal:" << endl;
    array1.print();

    array1.arrayAscendingOrder();

    cout << "\nResultado:" << endl;
    array1.print();

    array1.free();

    pause("Apertar ENTER para continuar");
}

void method21() {
    int tamanho1 = 0, tamanho2 = 0;
    Array <int> lerTamanho1(1);
    Array <int> lerTamanho2(1);
    bool resultado = 0;

    cout << endl << "Exemplo1101 - method21 - v0.0" << endl;

    tamanho1 = lerTamanho1.freadLength("DadosExtra21A.txt");
    Array <int> array1(tamanho1);
    tamanho2 = lerTamanho2.freadLength("DadosExtra21B.txt");
    Array <int> array2(tamanho2);

    array1.fread("DadosExtra21A.txt");
    array2.fread("DadosExtra21B.txt");

    cout << "\nArray1:" << endl;
    array1.print();
    cout << "Array2:" << endl;
    array2.print();

    cout << "Igualdade = " << (array1 != array2) << endl;

    if (resultado == 0) {
        cout << "Os dois arranjos NAO sao diferentes (iguais)." << endl;
    } else {
        cout << "Os dois arranjos sao diferentes." << endl;
    }

    array1.free();
    array2.free();

    pause("Apertar ENTER para continuar");
}

void method22() {
    int tamanho1 = 0, tamanho2 = 0;
    Array <int> lerTamanho1(1);
    Array <int> lerTamanho2(1);

    cout << endl << "Exemplo1101 - method22 - v0.0" << endl;

    tamanho1 = lerTamanho1.freadLength("DadosExtra22A.txt");
    Array <int> array1(tamanho1);
    tamanho1 = lerTamanho1.freadLength("DadosExtra22A.txt");
    Array <int> array2(tamanho2);

    array1.fread("DadosExtra22A.txt");
    array2.fread("DadosExtra22B.txt");

    cout << "\nArray1:" << endl;
    array1.print();
    cout << "Array2:" << endl;
    array2.print();

    Array <int> array3(tamanho1);
    array3 = array1 - array2;

    cout << "Resultado da diferenca:" << endl;
    array3.print();

    array1.free();
    array2.free();
    array3.free();

    pause("Apertar ENTER para continuar");
}


int main (int argc, char** argv) {
    int x = 0;

    do {

        cout << "Exemplo1100 - programa - v0.0" << endl;
        cout << "Nome: Daniel Vitor de Oliveira Santos" << endl;
        cout << "Matricula: 716417" << endl;

        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - mostrar dados inteiros em arranjo " << endl;
        cout << " 2 - ler dados e colocar em um arranjo" << endl;
        cout << " 3 - ler dados e grava-los em um arquivo" << endl;
        cout << " 4 - ler dados de um arquivo e grava-los em um array" << endl;
        cout << " 5 - copia um array para outro e mostra na tela" << endl;
        cout << " 6 - copiar dados de um array para outro e mostrar na tela" << endl;
        cout << " 7 - le dados de um arquivo, copia para um arranjo" << endl;
        cout << " 8 - fazer a comparacao de 2 arrays, para ver se sao iguais" << endl;
        cout << " 9 - fazer a soma de 2 array e colocar em outro array" << endl;
        cout << "10 - mostrar valores dentro e fora do limite" << endl;
        cout << "11 - guarde numeros aleatorios em um array" << endl;
        cout << "12 - procurar o maior valor par de um array" << endl;
        cout << "13 - procurar o menor divisor de 3 no array" << endl;
        cout << "14 - somar todos os valores impares do array" << endl;
        cout << "15 - media dos valores pares de um array" << endl;
        cout << "16 - verificar se todos os valores sao iguais a zero" << endl;
        cout << "17 - verificar se esta em ordem crescente" << endl;
        cout << "18 - dizer se um determinado valor esta no array" << endl;
        cout << "19 - escalar um array por uma constante" << endl;
        cout << "20 - colocar os valores de um array em ordem crescente" << endl;
        cout << "21 - Extra1" << endl;
        cout << "22 - Extra2" << endl;

        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        switch ( x ) {
            case 0:
            method00 ( );
            break;
            case 1:
            method01 ( );
            break;
            case 2:
            method02 ( );
            break;
            case 3:
            method03 ( );
            break;
            case 4:
            method04 ( );
            break;
            case 5:
            method05 ( );
            break;
            case 6:
            method06 ( );
            break;
            case 7:
            method07 ( );
            break;
            case 8:
            method08 ( );
            break;
            case 9:
            method09 ( );
            break;
            case 10:
            method10 ( );
            break;
            case 11:
            method11 ( );
            break;
            case 12:
            method12 ( );
            break;
            case 13:
            method13 ( );
            break;
            case 14:
            method14 ( );
            break;
            case 15:
            method15 ( );
            break;
            case 16:
            method16 ( );
            break;
            case 17:
            method17 ( );
            break;
            case 18:
            method18 ( );
            break;
            case 19:
            method19 ( );
            break;
            case 20:
            method20 ( );
            break;
            case 21:
            method21 ( );
            break;
            case 22:
            method22 ( );
            break;
            default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } 
    } while ( x != 0 );
    pause ( "Apertar ENTER para terminar" );
    return(0);
}