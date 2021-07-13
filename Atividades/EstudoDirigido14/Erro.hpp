#include <string>

#ifndef _ERRO_H_
#define _ERRO_H_

class Erro {
    /*

        * Tratamento de erro
        * Codigos de erro:
        * 0 - Nao existe erro.
        * 

    */

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
        //Metodo para estabelecer novo codigo de erro, parametro sera um codigo a ser guardado
        //Estabelecer novo codigo de erro
        void setErro(int codigo) {
            erro = codigo;
        }

};

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro."; // definir o valor da constante

#endif