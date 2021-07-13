/*
  * ---------------------------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Refação Prova 01
  *
  * Nome: Daniel Vitor de Oliveira Santos   
  * Matricula: 716417
  * Versao:  1.0                Data: 04/11/2020
*/
// ---------------------------------------------- classes nativas
//                                                ou auxiliares

#include "io.h"     // se na mesma pasta

//Questao 1
int resolucaoMetodo1 (int valor) {
   int numero = 0;

   srand(time(0));

   numero = 1 + rand() % (100 - 1);

   return(numero);
}

//Questao 2
double resolucaoMetodo2 (int quantidade) {
   int contador = 0, numerador = 0, proximo = 0, expoente = 0;
   double denominador = 0.0, soma = 0.0, fracao = 0.0;

   printf("%d/%.0lf = %.2lf\n", 1, 1.0, 1.0);
   soma = soma + 1;

   for (contador = 1; contador < quantidade; contador = contador + 1) {
      proximo = proximo + 1;
      expoente = expoente + 1;
      denominador = pow(2, expoente);
      numerador = numerador + proximo;
      fracao = (double)numerador/denominador;
      //Tanto o numerador quanto o contador tem que ser divisivel por 3
      if (numerador%3 == 0 && contador%3 == 0) {
         soma = soma - fracao; 
      } else {
         soma = soma + fracao; 
      }
      printf("%d/%.0lf = %.2lf\n", numerador, denominador, fracao);
   }

   return(soma);
}

//Verificar se e uma palavra
bool isWord (char x) {
    bool result = false;
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) {
        result = true;
    }
    return(result);
}

//Verificar se e um digito
bool isDigit (char x) {
    bool result = false;
    if ('0' <= x && x <= '9') {
        result = true;
    }
    return(result);
}

//Resolucao questao 3
bool verificarPlaca(chars string, int tamanho) {
   int contador = 0;
   bool result = false;

   if (isWord(string[0]) == 1) {
      contador = contador + 1;
   }
   if (isWord(string[1]) == 1) {
      contador = contador + 1;
   }
   if (isWord(string[2]) == 1) {
      contador = contador + 1;
   }
   if (isDigit(string[3]) == 1) {
      contador = contador + 1;
   }
   if (isWord(string[4]) == 1) {
      contador = contador + 1;
   }
   if (isDigit(string[5]) == 1) {
      contador = contador + 1;
   }
   if (isDigit(string[6]) == 1) {
      contador = contador + 1;
   }
   
   if (contador == 7) {
      result = true;
   }

   return(result);
}



void method00 () {

}

void metodo01 () {
   int resultado = 0, valor = 0, contador = 0;

   IO_println ("\nMetodo01");

   for (contador = 0; contador < 7; contador = contador + 1) {
      valor = IO_readint("\nDigite um numero para verificar: ");

      resultado = resolucaoMetodo1(valor);
      printf("\nNumero gerado = %d\n", resultado);
      if (valor >= 1 && valor < 100) {
         if (valor == resultado) {
         printf("OK\n");
         } else {
            if (valor < resultado) {
               printf("UP\n");
            } else {
               printf("DOWN\n");
            }
         }
      } else {
         printf("ERRO: Valor fora do inverfalo [1:100).");
      }
   }

   IO_pause("Apertar ENTER para continuar");
}

void metodo02 () {
   int quantidade = 0;
   double resultado = 0.0;

   IO_println ("\nMetodo02");

   quantidade = IO_readint("Digite uma quantidade: ");

   if (quantidade > 0) {
      resultado = resolucaoMetodo2(quantidade);
      printf("\nA soma dos termos = %.2lf\n", resultado);
   } else {
      printf("ERRO: A quantidade precisa ser maior que 0.");
   }

   IO_pause("Apertar ENTER para continuar");
}

void metodo03 ()  {
   int contador = 0, quantidade = 0, tamanho = 0, placaTotal = 0, placaAceita = 0, placaRejeitada = 0;
   chars placa = IO_new_chars(STR_SIZE);
   bool result = 0;

   IO_println ("\nMetodo03");

   quantidade = IO_readint("Digite quantas placas deseja verificar: ");

   for (contador = 0; contador < quantidade; contador = contador + 1) {
      placa = IO_readstring("\nDigite a placa a ser verificada: ");
      tamanho = strlen(placa);
      if (tamanho > 7 || tamanho < 7) {
         printf("\nERRO: A placa nao atende ao minimo de caracteres ou numeros [7].\n");
      } else {
         result = verificarPlaca(placa, tamanho);
         placaTotal = placaTotal + 1;
         if (result == 1) {
            printf("Sua placa atende aos requisitos [AAA0A00].");
            placaAceita = placaAceita + 1;
         } else {
            printf("Sua placa NAO atende aos requisitos [AAA0A00].");
            placaRejeitada = placaRejeitada + 1;
         }
      }
   }
   printf("\n");
   printf("Quantidade de placas testadas = %d\n", placaTotal);
   printf("Quantidade de placas aceitas = %d\n", placaAceita);
   printf("Porcentagem de placas rejeitadas = %.0lf\n", 100*((double)placaRejeitada/placaTotal));


   IO_pause("Apertar ENTER para continuar");
}


// ---------------------------------------------- definicao do metodo principal

int main ( void )
{
// definir dados
   int opcao = 0;

// repetir ate' desejar parar
   do
   {
   // identificar
      IO_printf  ( "\n" );   // para saltar linha
      IO_println ( "Refacao da prova 01 - v.0.0 - 04/11/2020\n"       );
      IO_println ( "Matricula: 716417 Nome: Daniel Vitor de Oliveira Santos\n" );
      IO_println ( "" );     // para saltar linha
   
   // mostrar opcoes

      IO_println ( "Opcoes:"       );
      IO_println ( "0 - parar"     );
      IO_println ( "1 - metodo 01" );
      IO_println ( "2 - metodo 02" );
      IO_println ( "3 - metodo 03" );
      IO_println ( "" );     // para saltar linha

   // ler opcao
      opcao = IO_readint ( "Qual a sua opcao? " );

   // escolher acao
      switch ( opcao )
      {
         case 0:
            break;
         case 1:
            metodo01 ( );
            break;
         case 2:
            metodo02 ( );
            break;
         case 3:
            metodo03 ( );
            break;
         default:
            IO_printf ( "\nERRO: Opcao invalida.\n" );
            break;
      } // fim escolher
   }
   while ( opcao != 0 );
   IO_pause("Apertar ENTER para terminar");

   return(0);

} // end main ( )


/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes


---------------------------------------------- testes

*/
