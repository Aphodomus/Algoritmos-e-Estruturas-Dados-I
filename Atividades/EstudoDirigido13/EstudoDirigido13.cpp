/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Ed10
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 27/10/2020
*/

#include "io.hpp"
#include "Contato.hpp"

#include <iostream> 
#include <limits> 
#include <string> 

using namespace std;

void method00() {

}

void method01() {
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato();

    cout << "\nExemplo1301 - Method01 - v0.0\n" << endl;

    pause("Apertar ENTER para continuar");
}

void method02() {
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato();

    cout << "\nExemplo1302 - Method02 - v0.0\n" << endl;

    pessoa1.setNome("Pessoa01");
    pessoa1.setFone("113");
    pessoa3->setNome("Pessoa3");
    pessoa3->setFone("333");

    cout << "pessoa1 - { " << pessoa1.getNome ( ) << ", " << pessoa1.getFone ( ) << " }" << endl;
    cout << "pessoa3 - { " << pessoa3->getNome ( ) << ", " << pessoa3->getFone ( ) << " }" << endl;

    pause("Apertar ENTER para continuar");
}

void method03() {
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato();

    cout << "\nExemplo1302 - Method02 - v0.0\n" << endl;

    pessoa1.setNome("Pessoa01");
    pessoa1.setFone("113");
    pessoa3->setNome("Pessoa3");
    pessoa3->setFone("333");

    cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
    cout << "pessoa3 - " << pessoa3->toString ( ) << endl;

    pause("Apertar ENTER para continuar");
}

void method04() {
    Contato pessoa1{.nome = "Pessoa 01", .fone = "312234"};
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("Pessoa 03", "345264");

    cout << "\nExemplo1304 - Method04 - v0.0\n" << endl;

    cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
    cout << "pessoa3 - " << pessoa3->toString ( ) << endl;

    pause("Apertar ENTER para continuar");
}

void method05() {
    Contato pessoa1{.nome = "Pessoa 01", .fone = "234515"};
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "345264");

    cout << "\nExemplo1305 - Method05 - v0.0\n" << endl;

    cout << "pessoa1 - " << pessoa1.toString ( ) << "Erro ? (" << pessoa1.getErro( ) << ")" << endl;
    cout << "pessoa3 - " << pessoa3->toString ( ) << "Erro ? (" << pessoa3->getErro( ) << ")" << endl;

    pause("Apertar ENTER para continuar");
}

void method06() {
    Contato pessoa1{.nome = "Pessoa 01", .fone = "234515"};
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "345264");

    cout << "\nExemplo1306 - Method06 - v0.0\n" << endl;

    if ( ! pessoa1.hasErro( ) )
      cout << "pessoa1 - " << pessoa1.toString( ) << endl;
    else
      cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
    if ( ! pessoa3->hasErro( ) )
      cout << "pessoa3 - " << pessoa3->toString( ) << endl;
    else
      cout << "pessoa3 tem erro (" << pessoa3->getErro( ) << ")" << endl;

    pause("Apertar ENTER para continuar");
}

void method07() {
    Contato pessoa1{.nome = "Pessoa 01", .fone = "234515"};
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "345264");

    cout << "\nExemplo1307 - Method07 - v0.0\n" << endl;

    pessoa2 = &pessoa1; // copiar endereco de objeto
    if ( ! pessoa2->hasErro( ) )
      cout << "pessoa1 - " << pessoa2->toString( ) << endl;
    else
      cout << "pessoa1 tem erro (" << pessoa2->getErro( ) << ")" << endl;
      pessoa2 = pessoa3; // vincular-se a outro objeto
    if ( ! pessoa2->hasErro( ) )
      cout << "pessoa3 - " << pessoa2->toString( ) << endl;
    else
      cout << "pessoa3 tem erro (" << pessoa2->getErro( ) << ")" << endl;

    pause("Apertar ENTER para continuar");
}

void method08() {
    Contato pessoa1{.nome = "Pessoa 01", .fone = "234515"};
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato("", "345264");
    ref_Contato pessoa4 = nullptr;

    cout << "\nExemplo1308 - Method08 - v0.0\n" << endl;

    pessoa2 = new Contato ( pessoa1 );
    if ( pessoa2 )
      cout << "pessoa1 - " << pessoa2->toString( ) << endl;
    else
      cout << "pessoa1 tem erro (" << pessoa2->getErro( ) << ")" << endl;
    if ( pessoa3 ) // o teste de existencia deve ser feito previamente
    {
      pessoa2 = new Contato ( *pessoa3 );
    if ( pessoa2 )
      cout << "pessoa3 - " << pessoa2->toString( ) << endl;
    else
      cout << "pessoa3 tem erro (" << pessoa2->getErro( ) << ")" << endl;
    } // fim se
    if ( pessoa4 ) // o teste de existencia deve ser feito previamente
    {
      pessoa2 = new Contato ( *pessoa4 );
    if ( pessoa2 )
      cout << "pessoa4 - " << pessoa2->toString( ) << endl;
    else
      cout << "pessoa4 tem erro (" << pessoa2->getErro( ) << ")" << endl;
    } // fim se

    pause("Apertar ENTER para continuar");
}

void method09() {
    Contato pessoa[3];
    int x = 0;

    cout << "\nExemplo1309 - Method09 - v0.0\n" << endl;

    pessoa[0].setNome("Pessoa 1");
    pessoa[0].setFone("23562345");

    pessoa[1].setNome("Pessoa 2");
    pessoa[1].setFone("93248752");

    pessoa[2].setNome("Pessoa 3");
    pessoa[2].setFone("78747546");

    for (x = 0; x < 3; x = x + 1) {
      cout << x << " : " << pessoa[x].toString() << endl;
    }

    pause("Apertar ENTER para continuar");
}

void method10() {
    Contato *pessoa[3];
    int x = 0;

    cout << "\nExemplo1310 - Method10 - v0.0\n" << endl;

    pessoa[0] = new Contato("Pessoa 1", "1234");
    pessoa[1] = new Contato("Pessoa 2", "4567");
    pessoa[2] = new Contato("Pessoa 3", "8890");

    for (x = 0; x < 3; x = x + 1) {
      cout << x << " : " << pessoa[x]->toString() << endl;
    }

    pause("Apertar ENTER para continuar");
}

void method11() {
    Contato pessoa;
    string nome;

    cout << "\nExemplo1311 - Method11 - v0.0\n" << endl;

    nome = IO_readstring("Digite um nome para atribuir ao objeto: ");

    pessoa.readNome(nome);

    cout << pessoa.getNome() << endl;

    pause("Apertar ENTER para continuar");
}

void method12() {
  Contato pessoa;
  string fone;

  cout << "\nExemplo1312 - Method12 - v0.0\n" << endl;

  fone = IO_readstring("Digite um telefone para atribuir ao objeto: ");

  pessoa.readFone(fone);

  cout << pessoa.getFone() << endl;

  pause("Apertar ENTER para continuar");
}

void method13() {
  Contato pessoa;
  string fone;
  bool result = 0;

  cout << "\nExemplo1313 - Method13 - v0.0\n" << endl;

  fone = IO_readstring("Digite um telefone para atribuir ao objeto: ");

  result = pessoa.isFoneValid(fone);

  if (result != 0) {
    cout << "O fone e valido, corresponde ao padrao." << endl;
  } else {
    cout << "O fone NAO e valido, NAO corresponde ao padrao." << endl;
  }

  pause("Apertar ENTER para continuar");
}

void method14() {
  Contato pessoa;

  cout << "\nExemplo1314 - Method14 - v0.0\n" << endl;

  pessoa.readFromFile("Pessoa1.txt");

  cout << "Nome: " << pessoa.getNome() << endl;
  cout << "Fone: " << pessoa.getFone() << endl;

  pause("Apertar ENTER para continuar");
}

void method15() {
  Contato pessoa;
  string nome;
  string fone;

  cout << "\nExemplo1315 - Method15 - v0.0\n" << endl;

  nome = IO_readstring("Digite um nome para atribuir ao objeto: ");
  fone = IO_readstring("Digite um telefone para atribuir ao objeto: ");

  pessoa.readNome(nome);
  pessoa.readFone(fone);

  cout << "Nome: " << pessoa.getNome() << endl;
  cout << "Fone: " << pessoa.getFone() << endl;

  pessoa.writeToFile("Pessoa2.txt");

  pause("Apertar ENTER para continuar");
}

void method16() {
  ref_Contato pessoa = new Contato("Gabriel", "2345-2342", "6753-4352");

  cout << "\nExemplo1316 - Method16 - v0.0\n" << endl;

  cout << "Nome: " << pessoa->getNome() << endl;
  cout << "Fone 1: " << pessoa->getFone() << endl;
  cout << "Fone 2: " << pessoa-> getFone2() << endl;

  pause("Apertar ENTER para continuar");
}

void method17() {
  ref_Contato pessoa = new Contato("Gabriel", "2345-2342", "4563-4356");
  int resultado = 0;

  cout << "\nExemplo1317 - Method17 - v0.0\n" << endl;

  resultado = pessoa->telefones();

  cout << "Quantidade de telefones: " << resultado << endl;

  pause("Apertar ENTER para continuar");
}

void method18() {
  ref_Contato pessoa = new Contato("Gabriel", "2345-3245");
  int numero = 0, resultado = 0, resp = 0;
  string fone2;

  cout << "\nExemplo1318 - Method18 - v0.0\n" << endl;

  resultado = pessoa->telefones();

  if (resultado == 1) {
    cout << "Possui apenas 1 numero." << endl;
    do {
      numero = IO_readint("Deseja adicionar um segundo numero para contato ? [1]|[0] : ");
    } while (numero != 0 && numero != 1);
    if (numero == 1) {
      fone2 = IO_readstring("Digite o segundo numero: ");
      resp = pessoa->isFoneValid(fone2); 
      if (resp != 0) {
        pessoa->setFone2(fone2);

        cout << "Nome: " << pessoa->getNome() << endl;
        cout << "Telefone 1: " << pessoa->getFone() << endl;
        cout << "Telefone 2: " << pessoa->getFone2() << endl;
      } else {
        cout << "Erro: O numero nao atende ao padrao xxxx-xxxx." << endl;
      }
    } else {
      cout << "Nome: " << pessoa->getNome() << endl;
      cout << "Telefone1: " << pessoa->getFone() << endl;
    }
  }

  pause("Apertar ENTER para continuar");
}

void method19() {
  ref_Contato pessoa = new Contato("Gabriel", "2345-6534");
  int numero = 0, resultado = 0, resp = 0, resultado2 = 0;
  string fone2;

  cout << "\nExemplo1319 - Method19 - v0.0\n" << endl;

  resultado = pessoa->telefones();

  if (resultado == 1) {
    cout << "Possui apenas 1 numero." << endl;
    do {
      numero = IO_readint("Deseja adicionar um segundo numero para contato ? [1]|[0] : ");
    } while (numero != 0 && numero != 1);
    if (numero == 1) {
      fone2 = IO_readstring("Digite o segundo numero: ");
      resp = pessoa->isFoneValid(fone2); 
      if (resp != 0) {
        pessoa->setFone2(fone2);

        cout << "Nome: " << pessoa->getNome() << endl;
        cout << "Telefone 1: " << pessoa->getFone() << endl;
        cout << "Telefone 2: " << pessoa->getFone2() << endl;
        resultado2 = pessoa->telefones();
        cout << "Quantidade de numeros: " << resultado2 << endl;
      } else {
        cout << "Erro: O numero nao atende ao padrao xxxx-xxxx." << endl;
      }
    } else {
      cout << "Nome: " << pessoa->getNome() << endl;
      cout << "Telefone1: " << pessoa->getFone() << endl;
    }
  } else {
    if (resultado == 2) {
      cout << "Ja existem 2 numeros." << endl;
    } else {
      pessoa->hasErro();
      cout << "Erro: Nao existem fones." << endl;
    }
  }

  pause("Apertar ENTER para continuar");
}

void method20() {
  ref_Contato pessoa = new Contato("Gabriel", "2345-3453", "3456-4563");
  int result1 = 0, result2 = 0, resp = 0;

  cout << "\nExemplo1320 - Method20 - v0.0\n" << endl;

  result1 = pessoa->telefones();

  if (result1 != 0 && result1 != 1) {
    cout << "Quantidade de telefones: " << result1 << endl;
    cout << "Telefone 1: " << pessoa->getFone() << endl;
    cout << "Telefone 2: " << pessoa->getFone2() << endl;

    resp = IO_readint("Deseja remover o telefone 2 ? [1]|[0] : ");

    if (resp == 1) {
      pessoa->removeFone2();

      result2 = pessoa->telefones();
      cout << "Quantidade de telefones: " << result2 << endl;
      cout << "Telefone 1: " << pessoa->getFone() << endl;
      cout << "Telefone 2: " << pessoa->getFone2() << endl;
    }
  } else {
    pessoa->hasErro();
    cout << "Nao existem um segundo telefone para ser retirado." <<  endl;
  }

  pause("Apertar ENTER para continuar");
}

//Nao consegui fazer
void method21() {


  cout << "\nExemplo1321 - Method21 - v0.0\n" << endl;
  

  pause("Apertar ENTER para continuar");
}

//Acho que esta incompleto, mas e porque eu nao entendi muito bem o que era para
//fazer nessa questao, entao resolvi parcialmente da maneira que entendi.
void method22() {
  Contato pessoa;
  string nome;
  string fone;
  string fone2;
  string adressHome;
  string adressProfessional;

  cout << "\nExemplo1322 - Method22 - v0.0\n" << endl;

  nome = IO_readstring("Digite um nome: ");
  fone = IO_readstring("Digite o telefone 1: ");
  fone2 = IO_readstring("Digite o telefone 2: ");
  adressHome = IO_readstring("Digite o endereco residencial: ");
  adressProfessional = IO_readstring("Digite o endereco profissional: ");

  pessoa.setNome(nome);
  pessoa.setFone(fone);
  pessoa.setFone2(fone2);
  pessoa.setAdressHome(adressHome);
  pessoa.setAdressProfessional(adressProfessional);

  cout << "Nome: " << pessoa.getNome() << endl;
  cout << "Telefone 1: " << pessoa.getFone() << endl;
  cout << "Telefone 2: " << pessoa.getFone2() << endl;
  cout << "Endereco residencial: " << pessoa.getAdressHome() << endl;
  cout << "Endereco comercial: " << pessoa.getAdressProfessional() << endl;

  pause("Apertar ENTER para continuar");
}


int main (int argc, char** argv) {
    int x = 0;

    do {
        cout << "Exemplo1300 - Programa - v0.0\n" << endl;
        cout << "Matricula: 716417\n" << endl;
        cout << "Nome: Daniel Vitor de Oliveira Santos\n" << endl;

        cout << "Opcoes" << endl;
        cout << "0 - parar" << endl;
        cout << "1 - testar definicao de contatos(objeto)" << endl;
        cout << "2 - testar getNome e getFone" << endl;
        cout << "3 - testar toString" << endl;
        cout << "4 - testar Contato alternativo" << endl;
        cout << "5 - testar Erro" << endl;
        cout << "6 - testar hasErro" << endl;
        cout << "7 - testar tratamento de erro" << endl;
        cout << "8 - testar a copia de um objeto para outro" << endl;
        cout << "9 - testar arranjo de objetos" << endl;
        cout << "10 - testar arranjo de objetos(2)" << endl;
        cout << "11 - metodo para atribuir nome a um objeto" << endl;
        cout << "12 - ler do teclado e atribuir valor ao telefone" << endl;
        cout << "13 - testar se o valor do telefone e valido" << endl;
        cout << "14 - ler dados de arquivo e armazenar em objeto" << endl;
        cout << "15 - gravar dados de uma pessoa em arquivo" << endl;
        cout << "16 - atributo para adicionar um segundo telefone" << endl;
        cout << "17 - indicar quantos telefones estao associados a um objeto" << endl;
        cout << "18 - atribuir valor ao segundo telefone" << endl;
        cout << "19 - alterar o valor apenas do segundo telefone" << endl;
        cout << "20 - remover apenas o valor do segundo telefone" << endl;
        cout << "21 - Incompleto" << endl;
        cout << "22 - adicionar endereco residencial e profissional" << endl;

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
          cout << endl << "Erro: Valor invalido." << endl;
        }
    } while (x != 0);
    pause("Apertar ENTER para terminar");
    return(0);
}