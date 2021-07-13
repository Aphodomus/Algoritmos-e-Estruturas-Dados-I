#include <iostream>
using std::cin ; 
using std::cout; 
using std::endl;

#include <iomanip>
using std::setw;

#include <string>

#include <sstream>

#include <fstream>
using std::ofstream;
using std::ifstream;

std::string str;

void pause ( std::string text ) {
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
}

#include "Erro.hpp"

using namespace std;

class MyString : public Erro {
    private:
        string string;

    public:
        //Construtor padrao
        Contato() {
            setErro(0);
            string = "";
        }

        //Construtor com string
        Contato(std::string string) {
            setErro(0);
            setString(string);
        }

        //Funcao para obter mensagem relativa ao codigo de erro
        void getErroMsg() {
            switch(getErro()) {
                case 0:
                    cout << "\nNao existem erros." << endl;
                break;
                case 1:
                    cout << "\nERRO: Tamanho da string igual a zero." << endl;
                break;
                case 2:
                    cout << "\nERRO: A string possui caracter que nao e numero." << endl;
                break;
                case 3:
                    cout << "\nERRO: Booleano possui caracter invalidos." << endl;
                break;
                case 4:
                    cout << "\nERRO: Possui algum caractere que nao e letra." << endl;
                break;
                default:
                    cout << endl << "Erro: Valor invalido." << endl;
            }
        }

        //Indica a existencia de erro
        bool hasErro() {
            return(getErro() != 0);
        }

        //Atribuir valor a string
        void setString(std::string string) {
            if (string.empty()) {
                setErro(1);
            } else{
                setErro(0);
                this->string = string;
            }
        }

        //Pegar o valor da string
        std::string getString() {
            return(this->string);
        }

        //Metodo para verificar se e um numero
        bool isNumber(char x) {
            bool result = false;

            if (x >= '0' && x <= '9' || x == '.') {
                result = true;
            }
            return(result);
        }

        //Metodo para verificar se sao letras
        bool isLetter(char x) {
            bool result = false;

            if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) {
                result = true;
            }
            return(result);
        }

        //Metodo para verificar se existe ponto
        bool hasPoint(char x) {
            bool result = false;

            if (x == '.') {
                result = true;
            }
            return(result);
        }

        //Metodo para verificar se a string e boolean
        bool isBoolean() {
            bool result = false;
            if (this->string == "true" || this->string == "T" || this->string == "1" || this->string == "false" || this->string == "F" || this->string == "0" ||
                this->string == "f" || this->string == "v" || this->string == "t") {
                result = true;
            }
            return(result);
        }
        
        //Metodo para verificar qual valor booleano ele corresponde
        bool whichBoolean() {
            bool result = false;
            if (this->string == "true" || this->string == "T" || this->string == "1" || this->string == "v" || this->string == "t") {
                result = true;
            }
            return(result);
        }

        //Funcao para testar se e uma string de numeros, e se for, transformar em inteiro
        int getInt() {
            int contador = 0;

            if (this->string.length() != 0) {
                for (int i = 0; i < this->string.length(); i = i + 1) {
                    if (isNumber(this->string.at(i)) != 1) {
                        contador = contador + 1;
                    }
                }

                if (contador == 0) {
                    int x = 0;
                    int y = 0;
                    int pot = 1;

                    for (y = this->string.length() - 1; y >= 0 ; y = y - 1) {
                        x = x + ((int) this->string.at(y) - 48) * pot;
                        pot = pot * 10;
                    }

                    return(x);
                } else {
                    setErro(2); //Nao e um numero
                    return(-1);
                }
            } else {
                setErro(1); // Tamanho da string igual a zero.
            }
        }

        //Funcao para transformar uma string em um valor real
        double getDouble() {
            double x = 0.0;
            int ponto = 0;
            int pot = 10;
            int contador0 = 0;
            int contador1 = 0;
            int contador2 = 0;
            int exp1 = 0;
            int exp2 = 1;
            int i = 0;
            double valor = 0.0;
            double result = 0.0;

            if (this->string.length() != 0) {
                for (int i = 0; i < this->string.length(); i = i + 1) {
                    if (isNumber(this->string.at(i)) != 1) {
                        contador0 = contador0 + 1;
                    }
                }

                if (contador0 == 0) {
                    for (int y = 0; y < this->string.length(); y = y + 1) {
                        if (this->string.at(y) != '.') {
                            contador1 = contador1 + 1;
                        } else {
                            for (int j = y + 1; j < this->string.length(); j = j + 1) {
                                contador2 = contador2 + 1;
                            }
                            break;
                        }
                    }

                    exp1 = contador1 - 1;
                    for (i = 0; i < contador1; i = i + 1) {
                        x = x + ((double) this->string.at(i) - 48) * pow(pot, exp1);
                        exp1 = exp1 - 1;
                    }

                    exp2 = 1;
                    for (int k = i + 1; k < this->string.length() - 1; k = k + 1) {
                        valor = ((double) this->string.at(k) - 48);
                        result = valor * pow(pot, - (exp2));
                        x = x + result;
                        exp2 = exp2 + 1;
                    }
                } else {
                    setErro(3); //Booleano possui caracter ou numero de pontos decimais invalidos
                }
            } else {
                setErro(1); // Tamanho da string igual a zero.
            }
            
            return(x);
        }

        //Funcao para transformar uma string em valor booleano, se possivel
        int getBoolean () {
            int result = -1;
            
            if (this->string.length() != 0) {
                if (isBoolean() == 1) {
                    if (whichBoolean() == 1) {
                        result = 1;
                    } else {
                        result = 0;
                    }
                } else {
                    return(result);
                }
            } else {
                setErro(1);
            }
        }

        //Funcao para procurar um valor passado como parametro dentro de uma string
        bool contains(std::string texto) {
            int x = 0;
            bool result = false;

            if (this->string.length() != 0) {
                for (int y = 0; y < this->string.length(); y = y + 1) {
                    for (int z = 0; z < texto.length(); z = z + 1) {
                        if (this->string.at(y) == texto.at(z)) {
                            x = x + 1;
                        }
                    }
                }

                if (x == texto.length()) {
                    result = true;
                    return(result);
                }
            } else {
                setErro(1);
            }

        }

        //Funcao para transformar letras minusculas em maiusculas
        std::string toUpperCase() {
            if (this->string.length() != 0) {
                for (int y = 0; y < this->string.length(); y = y + 1) {
                    if (this->string.at(y) >= 'a' && this->string.at(y) <= 'z') {
                        this->string.at(y) = ((char) this->string.at(y) - 32);
                    }
                }
            } else {
                setErro(1);
            }
            return(this->string);
        }

        //Funcao para transformar letras maiusculas em minusculas
        std::string toLowerCase() {
            if (this->string.length() != 0) {
                for (int y = 0; y < this->string.length(); y = y + 1) {
                    if (this->string.at(y) >= 'A' && this->string.at(y) <= 'Z') {
                        this->string.at(y) = ((char) this->string.at(y) + 32);
                    }
                }
            } else {
                setErro(1);
            }
            return(this->string);
        }

        //Funcao para trocar todas as ocorrencias de certo caractere por outro
        std::string replace (char original, char novo) {
            if (this->string.length() != 0) {
                for (int y = 0; y < this->string.length(); y = y + 1) {
                    if (this->string.at(y) == original) {
                        this->string.at(y) = novo;
                    }
                }
            } else {
                setErro(1);
            }
    
            return(this->string);
        }

        //Funcao para criptografar uma determinada frase
        std::string encrypt(int chave) {
            int numLetras = 26;
            int erro = 0;

            if (this->string.length() != 0) {
                for (int p = 0; p < this->string.length(); p = p + 1) {
                    if (isLetter(this->string.at(p)) == 0) {
                        erro = 1;
                    }
                }

                if (erro == 0) {
                    if (chave >= 0 && chave <= 26) {
                        for (int y = 0; y < this->string.length(); y = y + 1) {
                            if (this->string.at(y) >= 'A' && this->string.at(y) <= 'Z') {
                                if (((char) this->string.at(y) + chave) > 90 ) {
                                    this->string.at(y) = (char) this->string.at(y) - (numLetras - chave);
                                } else {
                                    this->string.at(y) = (char) this->string.at(y) + chave;
                                }
                            } else {
                                if (((char) this->string.at(y) + chave) > 122 ) {
                                    this->string.at(y) = (char) this->string.at(y) - (numLetras - chave);
                                } else {
                                    this->string.at(y) = (char) this->string.at(y) + chave;
                                }
                            }
                        }
                    } else {
                        if (chave >= -26 && chave < 0) {
                            for (int z = 0; z < this->string.length(); z = z + 1) {
                                if (this->string.at(z) >= 'A' && this->string.at(z) <= 'Z') {
                                    if (((char) this->string.at(z) + chave) < 65) {
                                        this->string.at(z) = (char) this->string.at(z) + (numLetras + chave);
                                    } else {
                                        this->string.at(z) = this->string.at(z) + chave;
                                    }
                                } else {
                                    if (((char) this->string.at(z) + chave) < 97) {
                                        this->string.at(z) = (char) this->string.at(z) + (numLetras + chave);
                                    } else {
                                        this->string.at(z) = this->string.at(z) + chave;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    setErro(4);
                }
            } else {
                setErro(1);
            }
            return(this->string);
        }

        //Funcao para descriptografar uma determinada frase
        std::string decrypt(int chave) {
            int numLetras = 26;
            int erro = 0;

            if (this->string.length() != 0) {
                for (int p = 0; p < this->string.length(); p = p + 1) {
                    if (isLetter(this->string.at(p)) == 0) {
                        erro = 1;
                    }
                }

                if (erro == 0) {
                    if (chave >= 0 && chave <= 26) {
                        for (int y = 0; y < this->string.length(); y = y + 1) {
                            if (this->string.at(y) >= 'A' && this->string.at(y) <= 'Z') {
                                if (((char) this->string.at(y) - chave) < 65 ) {
                                    this->string.at(y) = (char) this->string.at(y) + (numLetras - chave);
                                } else {
                                    this->string.at(y) = (char) this->string.at(y) - chave;
                                }
                            } else {
                                if (((char) this->string.at(y) - chave) < 97 ) {
                                    this->string.at(y) = (char) this->string.at(y) + (numLetras - chave);
                                } else {
                                    this->string.at(y) = (char) this->string.at(y) - chave;
                                }
                            }
                        }
                    } else {
                        if (chave >= -26 && chave < 0) {
                            for (int z = 0; z < this->string.length(); z = z + 1) {
                                if (this->string.at(z) >= 'A' && this->string.at(z) <= 'Z') {
                                    if (((char) this->string.at(z) - chave) > 90) {
                                        this->string.at(z) = this->string.at(z) - (numLetras + chave);
                                    } else {
                                        this->string.at(z) = this->string.at(z) - chave;
                                    }
                                } else {
                                    if (((char) this->string.at(z) - chave) > 122) {
                                        this->string.at(z) = this->string.at(z) - (numLetras + chave);
                                    } else {
                                        this->string.at(z) = this->string.at(z) - chave;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    setErro(4);
                }
            } else {
                setErro(1);
            }

            return(this->string);
        }
};