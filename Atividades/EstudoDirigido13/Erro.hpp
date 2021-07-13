#ifndef _ERRO_H_
#define _ERRO_H_

class Erro {
    private:
        int erro;

    public:
        ~Erro() {

        }

        Erro() {
            erro = 0;
        }

        int getErro() {
            return(erro);
        }

    protected:
        //Estabelecer novo codigo de erro
        void setErro(int codigo) {
            erro = codigo;
        }
};

#endif