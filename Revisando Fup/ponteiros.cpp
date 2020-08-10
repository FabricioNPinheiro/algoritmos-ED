#include <iostream>

using namespace std;

int main(){
/*
    int valor;
    int *PontValor;

    valor = 20;
    PontValor = &valor;


    cout << "Valor: " << valor << endl;
    cout << "Endereço de valor: " <<&valor << endl;
    cout << "Pra onde o ponteiro aponta: " << *PontValor << endl;
    cout << "O que o ponteiro armazena: " << PontValor << endl;
*/

///////////////////////////////////////////////////////////////

    int vetor[3] = {1, 2, 3};
    // int *ponteiro = vetor; --> Aponta para posição inicial do vetor, o primeiro membro, no caso o valor 1
    // int *ponteiro = &vetor[2]; // forço meu ponteiro a apontar para a posição que eu desejar no vetor
    // cout << *ponteiro << endl;

    int *ponteiro = &vetor[0];
    ++ponteiro;
    ++ponteiro;
    cout << *ponteiro << endl;

    // Alterando valor de ponteiro
    // int *ponteiro = vetor;
    // *(ponteiro + 1) = 10;
    // cout << vetor[1] << endl;

/*
    ponteiro = &vetor[1];
    cout << ponteiro << endl;

    ponteiro = &vetor[2];
    cout << ponteiro << endl;
*/


    return 0;
}