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

#include "mymatrix.hpp"
#include "io.hpp"
using namespace std;

void method00() {

}

void method01() {
    Matrix <int> int_matrix(2,2);

    int_matrix.set ( 0, 0, 1 ); int_matrix.set ( 0, 1, 2 );
    int_matrix.set ( 1, 0, 3 ); int_matrix.set ( 1, 1, 4 );

    cout << "\nExemplo1201 - method01 - v0.0\n" << endl;

    int_matrix.print();

    pause("Apertar ENTER para continuar");
}

void method02() {
    Matrix <int> matrix(2, 2);

    cout << "\nExemplo1202 - method02 - v0.0\n" << endl;

    matrix.read();

    matrix.print();

    pause("Apertar ENTER para continuar");
}

void method03() {
    Matrix <int> matrix(2, 2);

    cout << "\nExemplo1203 - method03 - v0.0\n" << endl;

    matrix.read();

    matrix.print();

    matrix.fprint("Matrix1.txt");

    pause("Apertar ENTER para continuar");
}

void method04() {
    Matrix <int> matrix(1, 1);

    cout << "\nExemplo1204 - method04 - v0.0\n" << endl;

    matrix.fread("Matrix1.txt");

    matrix.print();

    pause("Apertar ENTER para continuar");
}

void method05() {
    Matrix <int> matrix1(1, 1);
    Matrix <int> matrix2(1, 1);

    cout << "\nExemplo1205 - method05 - v0.0\n" << endl;

    matrix1.fread("Matrix1.txt");

    cout << "\nOriginal\n" << endl;
    matrix1.print();

    matrix2 = matrix1;

    cout << "\nCopia\n" << endl;
    matrix2.print();

    pause("Apertar ENTER para continuar");
}

void method06() {
    Matrix <int> matrix(2, 2);

    matrix.set(0, 0, 0);
    matrix.set(1, 0, 0);
    matrix.set(0, 1, 0);
    matrix.set(1, 1, 0);

    cout << "\nExemplo1206 - method06 - v0.0\n" << endl;

    matrix.print();

    cout << "Zeros = " << matrix.isZeros() << endl;

    matrix.fread("Matrix1.txt");

    matrix.print();

    cout << "Zeros = " << matrix.isZeros() << endl;

    pause("Apertar ENTER para continuar");
}

void method07() {
    Matrix <int> matrix1(1, 1);
    Matrix <int> matrix2(1, 1);

    cout << "\nExemplo1207 - method07 - v0.0\n" << endl;

    matrix1.fread("Matrix1.txt");

    cout << "\nMatrix 1:\n" << endl;
    matrix1.print();

    matrix2 = matrix1;

    cout << "\nMatrix 2:\n" << endl;
    matrix2.print();

    cout << "Diferentes = " << (matrix1 != matrix2) << endl;

    pause("Apertar ENTER para continuar");
}

//Ta dando erro
void method08() {
    Matrix <int> matrix1(1, 1);
    Matrix <int> matrix2(1, 1);
    Matrix <int> matrix3(1, 1);


    cout << "\nExemplo1208 - method08 - v0.0\n" << endl;

    matrix1.fread("Matrix1.txt");

    cout << "\nMatrix 1:\n" << endl;
    matrix1.print();

    matrix2 = matrix1;

    cout << "\nMatrix 2:\n" << endl;
    matrix2.print();

    matrix3 = matrix1 - matrix2;

    cout << "\nMatrix 3:\n" << endl;
    matrix3.print();

    pause("Apertar ENTER para continuar");
}

void method09() {
    Matrix <int> matrix1(2, 2);

    matrix1.set(0, 0, 1);
    matrix1.set(0, 1, 1);
    matrix1.set(1, 0, 1);
    matrix1.set(1, 1, 1);

    Matrix <int> matrix2(1, 1);
    Matrix <int> matrix3(1, 1);

    cout << "\nExemplo1209 - method09 - v0.0\n" << endl;

    matrix2.fread("Matrix1.txt");

    cout << "\nMatrix 1:\n" << endl;
    matrix1.print();

    cout << "\nMatrix 2:\n" << endl;
    matrix2.print();

    matrix3 = matrix1 * matrix2;

    cout << "\nMatrix 3:\n" << endl;
    matrix3.print();

    pause("Apertar ENTER para continuar");
}

void method10() {
    Matrix <int> matrix(3, 3);
    int x = 0;
    int y = 0;

    cout << "\nExemplo1210 - method10 - v0.0\n" << endl;

    matrix.fread("Matrix1.txt");

    cout << "\nMatrix\n" << endl;
    matrix.print();

    for (int x = 0; x < matrix.getRows(); x = x + 1) {
        for (int y = 0; y < matrix.getColumns(); x = x + 1) {
            matrix.set(x, y, matrix.get(x, y) * (-1));
        }
    }

    cout << "\nMatrix\n" << endl;
    matrix.print();

    pause("Apertar ENTER para continuar");
}

void method11() {
    int linhas = 0;
    int colunas = 0;
    int quantidade = 0;
    int valor = 0;
    int inferior = 0;
    int superior = 0;

    cout << "\nExemplo1211 - method11 - v0.0\n" << endl;

    linhas = IO_readint("Numero de linhas: ");
    colunas = IO_readint("Numero de colunas: ");
    inferior = IO_readint("Limite inferior dos numeros a serem gerados: ");
    do {
        superior = IO_readint("Limite superior dos numeros a serem gerados: ");
    } while (superior <= inferior);

    Matrix <int> matrix1(linhas, colunas);

    quantidade = linhas*colunas;

    for (int x = 0; x < linhas; x = x + 1) {
        for (int y = 0; y < colunas; y = y + 1) {
            valor = matrix1.gerarIntRandom(inferior, superior);
            matrix1.set(x, y, valor);
        }
    }

    cout << "\nMatrix 1:\n" << endl;
    matrix1.print();

    matrix1.fprint("DadosExemplo1211.txt");

    pause("Apertar ENTER para continuar");
}

void method12() {
    Matrix <int> matrix1(1,1); 
    Matrix <int> matrix2(1,1);
    int k = 0;

    cout << "\nExemplo1212 - method12 - v0.0\n" << endl;

    k = IO_readint("Qual o valor da constante: ");

    matrix1.fread("DadosExemplo1211.txt");

    cout << "\nOriginal:\n" << endl;
    matrix1.print();

    matrix1.scale(k);

    cout << "\nResultado:\n" << endl;
    matrix1.print();

    pause("Apertar ENTER para continuar");
}

void method13() {
    Matrix <int> matrix1(3, 3);
    bool result = false;

    cout << "\nExemplo1213 - method13 - v0.0\n" << endl;

    matrix1.fread("DadosExemplo1213.txt");

    if (matrix1.isQuadratic() == 1) {
        result = matrix1.isIdentity();

        if (result == 1) {
            cout << "A matriz e identidade." << endl;
        } else {
            cout << "A matriz nao e identidade." << endl;
        }
    } else {
        cout << "\nA operacao nao pode continuar, erro na matrix." << endl;
    }
    
    cout << "\nResultado: " << endl;
    matrix1.print();

    pause("Apertar ENTER para continuar");
}

void method14() {
    Matrix <int> matrix1(1,1);
    Matrix <int> matrix2(1,1);

    cout << "\nExemplo1214 - method14 - v0.0\n" << endl;
    
    matrix1.fread("DadosExemplo1214A.txt");
    matrix2.fread("DadosExemplo1214B.txt");

    cout << "\nMatriz 1:" << endl;
    matrix1.print();
    cout << "\nMatriz 2:" << endl;
    matrix2.print();

    cout << "\nResultado:" << endl;
    if ((matrix1 == matrix2) == 1) {
        cout << "\nAs matrizes sao iguais." << endl;
    } else {
        cout << "\nAs matrizes sao diferentes." << endl;
    }



    pause("Apertar ENTER para continuar");
}

void method15() {
    Matrix <int> matrix1(1,1);
    Matrix <int> matrix2(1,1);
    Matrix <int> matrix3(1,1);

    cout << "\nExemplo1215 - method15 - v0.0\n" << endl;

    matrix1.fread("DadosExemplo1214A.txt");
    matrix2.fread("DadosExemplo1214B.txt");

    cout << "\nMatriz 1:" << endl;
    matrix1.print();
    cout << "\nMatriz 2:" << endl;
    matrix2.print();

    matrix3 = matrix1 + matrix2;

    cout << "\nResultado da soma:" << endl;
    matrix3.print();

    pause("Apertar ENTER para continuar");
}

void method16() {
    Matrix <int> matrix1(1,1);
    int k = 0;

    cout << "\nExemplo1216 - method16 - v0.0\n" << endl;

    matrix1.fread("DadosExemplo1216.txt");

    k = IO_readint("Digite o valor da constante: ");
    
    cout << "Original" << endl;
    matrix1.print();

    matrix1.addRows(0, 1, k);

    cout << "Modificada pela constante: " << endl;
    matrix1.print();

    pause("Apertar ENTER para continuar");
}

void method17() {
    Matrix <int> matrix1(1,1);
    int k = 0;

    cout << "\nExemplo1217 - method17 - v0.0\n" << endl;

    matrix1.fread("DadosExemplo1217.txt");

    k = IO_readint("Digite o valor da constante: ");
    
    cout << "Original" << endl;
    matrix1.print();

    matrix1.subColumns(0, 1, k);

    cout << "Modificada pela constante: " << endl;
    matrix1.print();

    pause("Apertar ENTER para continuar");
}

void method18() {
    Matrix <int> matrix1(1, 1);
    int search = 0, result = 0;

    cout << "\nExemplo1218 - method18 - v0.0\n" << endl;

    matrix1.fread("DadosExemplo1218.txt");

    search = IO_readint("Procurar pelo valor: ");

    cout << "\nMatriz:\n" << endl;
    matrix1.print();

    result = matrix1.searchRows(search);

    if (result != -1) {
        cout << "O valor " << search << " foi encontrado na linha " << result << "." << endl;
    } else {
        cout << "Valor " << search << " nao encontrado." << endl;
    }

    pause("Apertar ENTER para continuar");
}

void method19() {
    Matrix <int> matrix1(1, 1);
    int search = 0, result = 0;

    cout << "\nExemplo1219 - method19 - v0.0\n" << endl;

    matrix1.fread("DadosExemplo1218.txt");

    search = IO_readint("Procurar pelo valor: ");

    cout << "\nMatriz:\n" << endl;
    matrix1.print();

    result = matrix1.searchColumns(search);

    if (result != -1) {
        cout << "O valor " << search << " foi encontrado na coluna " << result << "." << endl;
    } else {
        cout << "Valor " << search << " nao encontrado." << endl;
    }

    pause("Apertar ENTER para continuar");
}

void method20() {
    Matrix <int> matrix1(1, 1);
    Matrix <int> matrix2(1, 1);

    cout << "\nExemplo1220 - method20 - v0.0\n" << endl;

    matrix1.fread("DadosExemplo1220.txt");

    cout << "\nMatriz original:\n" << endl;
    matrix1.print();

    matrix2 = matrix1.transposedMatrix(matrix1);

    cout << "\nMatriz transposta:\n" << endl;
    matrix2.print();

    pause("Apertar ENTER para continuar");
}

void method21() {
    int contador1 = 0, contador2 = 0, colunas = 0, linhas = 0;

    cout << "\nExemplo1221 - method21 - v0.0\n" << endl;

    linhas = IO_readint("Digite a quantidade de linhas: ");
    colunas = IO_readint("Digite a quantidade de colunas: ");

    Matrix <int> matrix1(linhas, colunas);

    matrix1.putValuesInMatrix(linhas, colunas);

    cout << "\nResultado:\n" << endl;
    matrix1.print();

    pause("Apertar ENTER para continuar");
}

void method22() {
    int contador1 = 0, contador2 = 0, colunas = 0, linhas = 0;

    cout << "\nExemplo1222 - method22 - v0.0\n" << endl;

    linhas = IO_readint("Digite a quantidade de linhas: ");
    colunas = IO_readint("Digite a quantidade de colunas: ");

    Matrix <int> matrix1(linhas, colunas);

    matrix1.putValuesInMatrix2(linhas, colunas);

    cout << "\nResultado:\n" << endl;
    matrix1.print();

    pause("Apertar ENTER para continuar");
}

int main (int argc, char** argv) {
    int x = 0;

    do {

        cout << "Exemplo1200 - programa - v0.0" << endl;
        cout << "Nome: Daniel Vitor de Oliveira Santos" << endl;
        cout << "Matricula: 716417" << endl;

        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - mostrar dados em matrix" << endl;
        cout << " 2 - metodo para ler dados e armazena-los na matrix" << endl;
        cout << " 3 - gravar valores de uma matrix em um arquivo" << endl;
        cout << " 4 - ler dados de um arquivo" << endl;
        cout << " 5 - copiar dados de uma matrix para outra" << endl;
        cout << " 6 - verificar se a matriz e toda igual a zero" << endl;
        cout << " 7 - testar se matrizes sao diferentes" << endl;
        cout << " 8 - subtrair dados de uma matriz" << endl;
        cout << " 9 - calcular o produto de duas matrizes" << endl;
        cout << "10 - acesso externo aos valores da matriz" << endl;
        cout << "11 - criar uma matriz e preencher com valores aleatorios" << endl;
        cout << "12 - faer uma constante multiplicar todos os valores da matriz" << endl;
        cout << "13 - verificar se uma matriz e identidade" << endl;
        cout << "14 - verificar se as matrizes sao iguais ou diferentes" << endl;
        cout << "15 - somar 2 matrix, posicao por posicao" << endl;
        cout << "16 - operar duas linhas de matrizes, com uma constante que multiplica a segunda" << endl;
        cout << "17 - operar duas colunas de matrizes, com uma constante que multiplica a segunda" << endl;
        cout << "18 - dizer em qual linha da matriz se encontra certo valor" << endl;
        cout << "19 - dizer em qual coluna da matriz se encontra certo valor" << endl;
        cout << "20 - transpor uma matriz" << endl;
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