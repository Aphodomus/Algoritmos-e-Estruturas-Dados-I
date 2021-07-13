#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>
using std::cin ;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include "Erro.hpp"

class Produto : public Erro {
    private:
        int codigo;
        string nome;
        int quantidade;
        double preco;

    public:
        ~Produto() {

        }

        Produto() {

        }

        Produto(int codigoInicial, string nomeInicial, int quantidadeInicial, double precoInicial) {

        }

        //Set codigo
        void setCodigo(int codigo) {
            if (codigo.empty()) {
                setErro(1); //Codigo esta vazio
            } else {
                this->codigo = codigo;
            }
        }

        //Set codigo
        void setNome(std::string nome) {
            if (nome.empty()) {
                setErro(2); //Nome esta vazio
            } else {
                this->nome = nome;
            }
        }

        //Set codigo
        void setQuantidade(int quantidade) {
            if (quantidade.empty()) {
                setErro(3); //Quantidade esta vazia
            } else {
                this->quantidade = quantidade;
            }
        }

        //Set codigo
        void setPreco(int preco) {
            if (preco.empty()) {
                setErro(4); //Preco esta vazio
            } else {
                this->preco = preco;
            }
        }

        //Pegar o codigo
        int getCodigo() {
            return(this->codigo);
        }

        //Pegar o nome
        std::string getNome() {
            return(this->nome);
        }

        //Pegar o codigo
        int getQuantidade() {
            return(this->quantidade);
        }

        //Pegar o codigo
        double getPreco() {
            return(this->preco);
        }
}