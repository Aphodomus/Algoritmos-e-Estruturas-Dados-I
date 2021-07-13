/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Estudo Dirigido 14
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 25/11/2020
*/
#include "io.hpp"
#include "MyString.hpp"
#include "Erro.hpp"

#include <string>

using namespace std;

void method00() {

}

void method01() {
    MyString string1;
    int result = 0;

    cout << "\nExemplo1401 - Method01 - v0.0\n" << endl;

    string1.setString("123456789");

    result = string1.getInt();

    if (result != -1) {
        printf("\n\n");
        cout << "String original = " << string1.getString() << endl;
        cout << "Resultado da conversao de string para int = " << result << endl;
    } else {
        cout << "Nao foi possivel converter." << endl;
    }

    string1.getErroMsg();

    pause("Apertar ENTER para continuar");
}

//Tem um problema, eu nao estou conseguindo retornar o ultimo digito, sempre fica
//Faltando o ultimo digito, tentei resolver de varias formas mas ainda nao consegui
void method02() {
    MyString string1;
    double result = 0;

    cout << "\nExemplo1402 - Method02 - v0.0\n" << endl;

    string1.setString("2483.487");

    result = string1.getDouble();
    cout << "Valor em string = " << string1.getString() << endl;
    cout << "Resultado conversao de string para real = " << result << endl;

    string1.getErroMsg();

    pause("Apertar ENTER para continuar");
}

void method03() {
    MyString string1;
    int resultado = 0;

    cout << "\nExemplo1403 - Method03 - v0.0\n" << endl;

    string1.setString("true");

    resultado = string1.getBoolean();

    if (resultado != -1) {
        cout << "Valor em string = " << string1.getString() << endl;
        cout << "Resultado conversao de string para boolean = " << resultado << endl;
    }

    string1.getErroMsg();

    pause("Apertar ENTER para continuar");
}

//Incompleto
void method04() {
    MyString string1;
    bool result = false;

    cout << "\nExemplo1404 - Method04 - v0.0\n" << endl;

    string1.setString("Daniel");

    result = string1.contains("l");

    if (result == 1) {
        cout << "Valor em string = " << string1.getString() << endl;
        cout << "Resultado da procura = "  << result << endl;
    } else {
        cout << "Conteudo nao encontrado." << endl;
    }

    string1.getErroMsg();

    pause("Apertar ENTER para continuar");
}

void method05() {
    MyString string1;

    cout << "\nExemplo1405 - Method05 - v0.0\n" << endl;

    string1.setString("danielvitor");

    cout << "Valor de entrada = " << string1.getString() << endl;

    string1.toUpperCase();

    cout << "Valor de saida = " << string1.getString() << endl;

    string1.getErroMsg();

    pause("Apertar ENTER para continuar");
}

void method06() {
    MyString string1;

    cout << "\nExemplo1406 - Method06 - v0.0\n" << endl;

    string1.setString("DANIELVITOR");

    cout << "Valor de entrada = " << string1.getString() << endl;

    string1.toLowerCase();

    cout << "Valor de saida = " << string1.getString() << endl;

    string1.getErroMsg();

    pause("Apertar ENTER para continuar");
}

void method07() {
    MyString string1;

    cout << "\nExemplo1407 - Method07 - v0.0\n" << endl;

    string1.setString("aabbaaceddfaaa");

    cout << "Valor de entrada = " << string1.getString() << endl;

    cout << "Valor a ser trocado [a] por [z]." << endl;

    string1.replace('a', 'z');

    cout << "Valor de saida = " << string1.getString() << endl;

    string1.getErroMsg();

    pause("Apertar ENTER para continuar");
}

//Nao consegui desenvolver
void method08() {


    cout << "\nExemplo1408 - Method08 - v0.0\n" << endl;



    pause("Apertar ENTER para continuar");
}

void method09() {
    MyString string1;
    int chave = 0;
    std::string frase;
    //chars frase = IO_new_chars(STR_SIZE);
    int erro = 0;

    cout << "\nExemplo1409 - Method09 - v0.0\n" << endl;

    std::cout << "Digite uma string para ser criptografada: ";
    cin.get();
    std::getline(std::cin, frase);
    string1.setString(frase);
    std::cout << "Teste: " << string1.getString() << endl;
    

    /*
    string1.setString(frase);

    cout << "\n[A chave de criptografia precisa estar entre o intervalo -26 e 26]\n" << endl;
    chave = IO_readint("Digite uma chave de criptografia: ");

    string1.encrypt(chave);
    if (! string1.hasErro()) {
        cout << "String original = " << frase << endl;
        cout << "String criptografada = " << string1.getString() << endl;
    }
    string1.getErroMsg();
    */

    pause("Apertar ENTER para continuar");
}

//Para teste esse metodo use como parametro a frase
//Entrada: VshWyvmlzzvyAluohBtVaptvKph
//Chave: -19
void method10() {
    MyString string1;
    int chave = 0;
    string frase = "";

    cout << "\nExemplo1410 - Method10 - v0.0\n" << endl;

    frase = IO_readstring("Digite a string que voce deseja descriptografar: ");

    string1.setString(frase);

    cout << "\n[A chave de descriptografia precisa estar entre o intervalo -26 e 26]\n" << endl;
    chave = IO_readint("Digite uma chave de descriptografia: ");

    string1.decrypt(chave);

    cout << "String original = " << frase << endl;
    cout << "String descriptografada = " << string1.getString() << endl;

    pause("Apertar ENTER para continuar");
}

int main (int argc, char** argv) {
    int x = 0;

    do {
        cout << "Exemplo1400 - Programa - v0.0\n" << endl;
        cout << "Matricula: 716417\n" << endl;
        cout << "Nome: Daniel Vitor de Oliveira Santos\n" << endl;

        cout << "Opcoes" << endl;
        cout << "0 - parar" << endl;
        cout << "1 - converter string para int" << endl;
        cout << "2 - converter string para real" << endl;
        cout << "3 - converter string para valor logico" << endl;
        cout << "4 - verificar se um parametro esta contido no conteudo" << endl;
        cout << "5 - converter letras para maiusculas" << endl;
        cout << "6 - converter letras para minusculas" << endl;
        cout << "7 - trocar a ocorrencia de um certo caractere" << endl;
        cout << "8 - separa sequencias de caracteres" << endl;
        cout << "9 - codificar um conteudo segundo a cifra de cesar" << endl;
        cout << "10 - decodificar um conteudo segundo a cifra de cesar" << endl;

        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

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
            cout << endl << "Erro: Valor invalido." << endl;
        }
    } while (x != 0);

    pause("Apertar ENTER para terminar");
    return(0);
}