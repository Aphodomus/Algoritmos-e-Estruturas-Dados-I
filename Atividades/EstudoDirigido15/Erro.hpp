#include <string>

#ifndef _ERRO_H_
#define _ERRO_H_

class Erro {
    private:
        int erro;


    public:
        //Destrutor
        ~Erro() {

        };

        //Construtor
        Erro() {
            erro = 0;
        };

        //Constante de classe
        static const std::string NO_ERROR;

        //Funcao para obter o codigo de erro, retornar codigo de erro
        int getErro() {
            return(erro); //Valor provisorio
        }

    protected:
        void setErro(int codigo) {
            erro = codigo;
        }

};

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro."; // definir o valor da constante

#endif