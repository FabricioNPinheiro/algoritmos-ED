#include<iostream>

// g++ programa.cpp -o programa -> gera o executavel (compila o programa)
// ./programa -> executa o programa

using namespace std;

int main(){
    int inteiro = 2;
    string palavra = "numero";
    cout << inteiro << endl;
    cout << palavra << endl;

    cout << "\nExemplo2\n";

    cout << "Informe um número: ";
    int num1;
    cin >> num1;

    cout << "\n\nDigite outro número: ";
    int num2;
    cin >> num2;

    int soma = num1 + num2;
    cout << "\n\nSoma: " << soma << endl;

    cout << "\n\n";

    float valor = 10 + 0.7;
    cout << valor << endl;

    double get = 34.56 + 45.777;
    cout << get << endl;

    char variavel = 'fg';
    cout << variavel << endl;

    int var1, var2, varSoma;

    var1 = 2;
    var2 = 4;
    varSoma = var1 + var2;

    int idade = 25;
    idade = 30;
    cout << idade << endl;

    return 0;
}

