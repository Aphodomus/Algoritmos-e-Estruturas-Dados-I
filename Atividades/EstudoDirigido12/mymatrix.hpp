#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

template <typename T>
class Matrix {
    private:
        int rows;
        int columns;
        T** data;
    public:
        Matrix() {
            this->rows = 0;
            this->columns = 0;
            data = NULL;
        }

        Matrix(int rows, int columns) {
            bool OK = true;
            this->rows = rows;
            this->columns = columns;
            data = new T*[rows];
            if (data != NULL) {
                for (int x = 0; x < rows; x = x + 1) {
                    data[x] = new T[columns];
                    OK = OK && (data[x] != NULL);
                }
                if (! OK) {
                    data = NULL;
                }
            }
        }

        ~Matrix() {
            if (data != NULL) {
                for (int x = 0; x < rows; x = x + 1) {
                    delete(data[x]);
                }
                delete(data);
                data = NULL;
            }
        }

        //Operador para copiar uma matriz para outra, posicao por posicao
        Matrix& operator = (const Matrix <T> other) {
            if (other.rows == 0 || other.columns == 0) {
                cout << "\nERRO: Missing data.\n" << endl;
            } else {
                this->rows = other.rows;
                this->columns = other.columns;
                this->data = new T*[rows];
                for (int x = 0; x < rows; x = x + 1) {
                    this->data[x] = new T[columns];
                }
                for (int x = 0; x < this->rows; x = x + 1) {
                    for (int y = 0; y < this->columns; y = y + 1) {
                        data[x][y] = other.data[x][y];
                    }
                }
            }
            return(*this);
        }

        //Operador para testar se matrizes sao diferentes
        bool operator != (const Matrix <T> other) {
            bool result = false;
            int x = 0;
            int y = 0;

            if (other.rows == 0 || rows != other.rows || other.columns == 0 || columns != other.columns) {
                cout << "\nERROR: Missing data.\n" << endl;
            } else {
                x = 0;
                while (x < rows && !result) {
                    y = 0;
                    while (y < columns && !result) {
                        result = (data[x][y] != other.data[x][y]);
                        y = y + 1;
                    }
                    x = x + 1;
                }
            }
            return(result);
        }

        //Operador para subtrair dados em matrizes, posicao por posicao
        Matrix& operator - (const Matrix <T> other) {
            static Matrix <T> result(1, 1);
            int x = 0;
            int y = 0;

            result = other;

            if (other.rows == 0 || rows != other.rows || other.columns == 0 || columns != other.columns) {
                cout << "\nERROR: Missing data.\n" << endl;
            } else {
                for (int x = 0; x < result.rows; x = x + 1) {
                    for (int y = 0; y < result.columns; y = y + 1) {
                        result.data[x][y] = data[x][y] - other.data[x][y];
                    }
                }
            }
            return(result);
        }

        //Operador para calcular o produto de matrizes
        Matrix& operator * (const Matrix <T> other) {
            static Matrix <T> result(1, 1);
            int x = 0;
            int y = 0;
            int z = 0;
            int sum = 0;

            if (rows <= 0 || columns == 0 || other.rows <= 0 || other.columns == 0 || columns != other.rows) {
                cout << endl << "ERROR: Invalid data." << endl;
                result.data[0][0] = 0;
            } else {
                result.rows = rows;
                result.columns = other.columns;
                result.data = new T*[result.rows];
                for (int x = 0; x < result.rows; x = x + 1) {
                    result.data[x] = new T[result.columns];
                }
                for (x = 0; x < result.rows; x = x + 1) {
                    for (y = 0; y < result.columns; y = y + 1) {
                        sum = 0;
                        for (z = 0; z < columns; z = z + 1) {
                            sum = sum + data[x][z] * other.data[z][y];
                        }
                        result.data[x][y] = sum;
                    }
                }
            }
            return(result);
        }

        //Verificar se as matrizes sao identicas
        bool operator == (const Matrix <T> other) {
            bool result = true;
            int x = 0;
            int y = 0;

            if (other.rows == 0 || rows != other.rows) {
                cout << "\nERRO: Missing data.\n" << endl;
            } else {
                x = 0;
                while (x < rows) {
                    y = 0;
                    while (y < columns) {
                        if (data[x][y] != other.data[x][y]) {
                            result = false;
                            return(result);
                            break;
                        }
                        y = y + 1;
                    }
                    x = x + 1;
                }
            }
            return(result);
        }

        //Fazer a soma de duas matrizes
        Matrix& operator + (const Matrix <T> other) {
            static Matrix <T> result(1, 1);
            int x = 0;
            int y = 0;

            if (rows <= 0 || columns == 0 || other.rows <= 0 || other.columns == 0 || columns != other.rows) {
                cout << "\nERROR: Missing data.\n" << endl;
            } else {
                result.rows = rows;
                result.columns = other.columns;
                result.data = new T*[result.rows];
                for (int x = 0; x < result.rows; x = x + 1) {
                    result.data[x] = new T[result.columns];
                }
                for (x = 0; x < result.rows; x = x + 1) {
                    for (y = 0; y < result.columns; y = y + 1) {
                        result.data[x][y] = data[x][y] + other.data[x][y];
                    }
                }
            }
            return(result);
        }

        void set(int row, int column, T value) {
            if (row < 0 || row >= rows || column < 0 || column >= columns) {
                cout << "\nERRO: Invalid position.\n";
            } else {
                data[row][column] = value;
            }
        }

        T get (int row, int column) {
            T value = 0;

            if (row < 0 || row >= rows || column < 0 || column >= columns) {
                cout << "\nERROR: Invalid position.\n";
            } else {
                value = data[row][column];
            }
        }

        //Ler dados de uma matriz e mostrar
        void print() {
            for (int x = 0; x < rows; x = x + 1) {
                for (int y = 0; y < columns; y = y + 1) {
                    cout << data[x][y] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }

        //Ler e guardar dados em matriz
        void read() {
            cout << endl;
            for (int x = 0; x < rows; x = x + 1) {
                for (int y = 0; y < columns; y = y + 1) {
                    cout << setw(2) << x << ", " << setw(2) << y << ": ";
                    cin >> data[x][y];
                }
            }
            cout << endl;
        }

        //Gravar em arquivo dados da matriz
        void fprint(string fileName) {
            ofstream afile;

            afile.open(fileName);
            afile << rows << endl;
            afile << columns << endl;
            for (int x = 0; x < rows; x = x + 1) {
                for (int y = 0; y < columns; y = y + 1) {
                    afile << data[x][y] << endl;
                }
            }
            afile.close();
        }

        //Ler arquivo e guardar dados em matriz
        void fread(string fileName) {
            ifstream afile;
            int m = 0;
            int n = 0;

            afile.open(fileName);
            afile >> m;
            afile >> n;
            if (m <= 0 || n <= 0) {
                cout << "\nERRO: Invalid dimension for matrix.\n";
            } else {
                rows = m;
                columns = n;
                //reservar area
                data = new T*[rows];
                for (int x = 0; x < rows; x = x + 1) {
                    data[x] = new T[columns];
                }

                for (int x = 0; x < rows; x = x + 1) {
                    for (int y = 0; y < columns; y = y + 1) {
                        afile >> data[x][y];
                    }
                }
            }
            afile.close();
        }

        //Testar se a matriz so contem zeros
        bool isZeros() {
            bool result = true;
            int x = 0;
            int y = 0;
            while (x < rows && result) {
                y = 0;
                while (y < columns && result) {
                    result = result && (data[x][y] == 0);
                    y = y + 1;
                }
                x = x + 1;
            }
            return(result);
        }

        //Acesso externos aos valores da matriz
        const int getRows() {
            return(rows);
        }
        const int getColumns() {
            return(columns);
        }

        //Gerar um numero aleatorio para colocar na matriz
        int gerarIntRandom(int inferior, int superior) {
            int number = 0;

            number = inferior + rand() % (superior - inferior + 1);

            return(number);
        }

        //Metodo para fazer uma constate multiplicar todo um array
        void scale(int k) {
            for (int x = 0; x < columns; x = x + 1) {
                for (int y = 0; y < rows; y = y + 1) {
                    data[x][y] = data[x][y] * k;
                }
            }
        }

        //Verificar se e uma matrix quadrada
        bool isQuadratic() {
            bool result = false;

            if (rows <= 0 || columns <= 0 || rows != columns || rows == 1 || columns == 1) {
                cout << "Erro: A matriz nao e quadrada." << endl;
                return(result);
            } else {
                result = true;
                return(result);
            }
        }

        //Verificar se uma matrix e identidade
        bool isIdentity() {
            int countNumberOne = 0, countNumberZero = 0, contadorOne = 0, contadorZero = 0;
            bool result = false;

            countNumberOne = rows;
            countNumberZero = (rows*columns) - rows;
            
            for (int x = 0; x < rows; x = x + 1) {
                for (int y = 0; y < columns; y = y + 1) {
                    if (x == y && data[x][y] == 1) {
                        contadorOne = contadorOne + 1;
                    } else {
                        if (data[x][y] == 0) {
                            contadorZero = contadorZero + 1;
                        }
                    }
                }
            }

            if (countNumberOne == contadorOne && countNumberZero == contadorZero) {
                result = true;
                return(result);
            } else {
                return(result);
            }
        }

        //Operar duas matrizes, guardar na primeira linha o valor da soma da primeira mais a segunda multiplicada por uma constante
        void addRows(int row, int column, int k) {
            if (row < 0 || row >= rows || column < 0 || column >= columns) {
                cout << "\nERRO: Invalid position.\n";
            } else {
                data[row][column] = data[row][column] + (data[row + 1][column] * k);
            }
        }

        //Operar duas matrizes, guardar na primeira linha o valor da diferenca da primeira com a segunda multiplicada por uma constante
        void subColumns(int row, int column, int k) {
            if (row < 0 || row >= rows || column < 0 || column >= columns) {
                cout << "\nERRO: Invalid position.\n";
            } else {
                data[row][column] = data[row][column] - (data[row][column + 1] * k);
            }
        }

        //Procurar por um valor e informar em qual linha ele se encontra
        int searchRows(int valor) {
            int result = -1;

            for (int x = 0; x < rows; x = x + 1) {
                for (int y = 0; y < columns; y = y + 1) {
                    if (data[x][y] == valor) {
                        return(x);
                        break;
                    }
                }
            }

            return(result);
        }

        //Procurar por um valor e informar em qual coluna ele se encontra
        int searchColumns(int valor) {
            int result = -1;

            for (int x = 0; x < rows; x = x + 1) {
                for (int y = 0; y < columns; y = y + 1) {
                    if (data[x][y] == valor) {
                        return(y);
                        break;
                    }
                }
            }

            return(result);
        }

        //Transpor uma matriz
        Matrix& transposedMatrix (const Matrix <T> other) {
            static Matrix <T> result(1, 1);
            int x = 0;
            int y = 0;

            if (rows <= 0 || columns == 0) {
                cout << endl << "ERROR: Invalid data." << endl;
                result.data[0][0] = 0;
            } else {
                result.rows = other.columns;
                result.columns = other.rows;
                result.data = new T*[result.rows];
                for (int x = 0; x < result.rows; x = x + 1) {
                    result.data[x] = new T[result.columns];
                }
                for (x = 0; x < result.rows; x = x + 1) {
                    for (y = 0; y < result.columns; y = y + 1) {
                        result.data[x][y] = other.data[y][x];
                    }
                }
            }
            return(result);
        }

        //Ler valores do teclado e colocar dentro da matrix
        void putValuesInMatrix(int linhas, int colunas) {
            for (int contador1 = 0; contador1 < linhas; contador1 = contador1 + 1) {
                for (int contador2 = 0; contador2 < colunas; contador2 = contador2 + 1) {
                    cout << setw(2) << contador1 << ", " << setw(2) << contador2 << ": ";
                    cin >> data[contador1][contador2];
                }
            }
        }

        //Ler valores do teclado e colocar dentro da matrix
        void putValuesInMatrix2(int linhas, int colunas) {
            for (int contador1 = 0; contador1 < linhas; contador1 = contador1 + 1) {
                for (int contador2 = 0; contador2 < colunas; contador2 = contador2 + 1) {
                    cout << setw(2) << contador1 << ", " << setw(2) << contador2 << ": ";
                    cin >> data[contador2][contador1];
                }
            }
        }

};

#endif