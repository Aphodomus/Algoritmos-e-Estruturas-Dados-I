#ifndef _CONTATO_H_
#define _CONTATO_H_

#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha

#include <iomanip>
using std::setw; // para definir espacamento

#include <string>
using std::string; // para cadeia de caracteres

#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo

void pause(std::string text) {
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
}

#include "Erro.hpp"

class Contato : public Erro {
    private:
        string nome;
        string fone;
        string fone2;
        string adressHome;
        string adressProfessional;
        string telefone;

    public:
        //Destrutor
        ~Contato() {

        }

        //Construtor padrao
        Contato() {
            setErro(0);
            nome = "";
            fone = "";
        }

        //Construto alternativo
        Contato (std::string nomeInicial, std::string foneInicial) {
            setErro(0);
            setNome(nomeInicial);//nome = nomeInicial;
            setFone(foneInicial);//fone = foneInicial;
        }

        //Construtor alternativo baseado em copia
        Contato (Contato const &another) {
            setErro(0);
            setNome(another.nome);
            setFone(another.fone);
        }

        //Construtor apenas com nome
        Contato (std::string nomeInicial) {
            setErro(0);
            setNome(nomeInicial);
        }

        Contato (std::string nomeInicial, std::string foneInicial, std::string foneAlternativo) {
            setErro(0);
            setNome(nomeInicial);//nome = nomeInicial;
            setFone(foneInicial);//fone = foneInicial;
            setFone2(foneAlternativo);
        }

        //Construtor de telefone
        Telefone (std::string telefone) {
            setFone(telefone);
        }

        //Atribuir nome
        void setNome(std::string nome) {
            if (nome.empty()) {
                setErro(1);
            } else{
                this->nome = nome;
            }
        }

        //Atribuir telefone
        void setFone(std::string fone) {
            if (fone.empty()) {
                setErro(2);
            } else {
                this->fone = fone;
            }
        }

        //Atribuir telefone alternativo
        void setFone2(std::string fone2) {
            if (fone2.empty()) {
                setErro(2);
            } else {
                this->fone2 = fone2;
            }
        }

        //Atribuir endereco residencial
        void setAdressHome(std::string adressHome) {
            if (adressHome.empty()) {
                setErro(2);
            } else {
                this->adressHome = adressHome;
            }
        }

        //Atribuir endereco profissional
        void setAdressProfessional(std::string adressProfessional) {
            if (adressProfessional.empty()) {
                setErro(2);
            } else {
                this->adressProfessional = adressProfessional;
            }
        }

        //Obter nome
        std::string getNome () {
            return(this->nome);
        }

        //Obter fone
        std::string getFone () {
            return(this->fone);
        }

        //Obter fone alternativo
        std::string getFone2 () {
            return(this->fone2);
        }

        //Obter dados de uma pessoa
        std::string toString() {
            return("{" + getNome() + ", " + getFone() + "}");
        }

        //Obter endereco residencial
        std::string getAdressHome() {
            return(this->adressHome);
        }

        //Obter endereco profissional
        std::string getAdressProfessional() {
            return(this->adressProfessional);
        }

        //Indica a existencia de erro
        bool hasErro() {
            return(getErro() != 0);
        }

        //Ler do teclado e atribuir um valor ao nome
        void readNome(std::string nome) {
            if (nome.empty()) {
                setErro(2);
            } else {
                this->nome = nome;
            }
        }

        //Ler do teclado e atribuir um valor ao fone
        void readFone(std::string fone) {
            if (fone.empty()) {
                setErro(2);
            } else {
                this->fone = fone;
            }
        }
        //Testar cada valor para ver se e um numero ou simbolo "-"
        bool numberAndSymbol(char digito) {
            bool result = false;
            if (('0' <= digito && digito <= '9') || digito == '-') {
                result = true;
            }
            return(result);
        }

        //Verificar se o fone e valido
        bool isFoneValid(std::string nome) {
            bool result = true;
            for (int x = 0; x < nome.length(); x = x + 1) {
                if(! numberAndSymbol(nome[x])) {
                    result = false;
                    break;
                }
            }
            return(result);
        }

        //Ler nome de um arquivo
        void readFromFile(chars fileName) {
            ifstream afile;
            string nome;
            string fone;

            afile.open(fileName);
            afile >> nome;
            afile >> fone;

            this->nome = nome;
            this->fone = fone;

            afile.close();
        }

        //Gravar dados de uma pessoa em um arquivo
        void writeToFile(chars fileName) {
            ofstream afile;

            afile.open(fileName);
            afile << 2 << endl;
            afile << this->nome << endl;
            afile << this->fone << endl;

            afile.close();
        }

        //Verificar quantos telefones tem em cada objeto
        int telefones() {
            if (this->fone.empty() == 0 && this->fone2.empty() == 0) {
                return (2);
            } else {
                if (this->fone.empty() == 0 || this->fone2.empty() == 0) {
                    return(1);
                } else {
                    return(0);
                }
            }
        }

        //Remover o segundo telefone
        void removeFone2() {
            if (this->fone2.empty() != 1) {
                this->fone2 = "";
            } else {
                cout << "Erro: Nao existe um segundo numero." << endl;
            }
        }
};

using ref_Contato = Contato*;

#endif
