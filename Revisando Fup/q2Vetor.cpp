#include <iostream>

using namespace std;
// imprimir pares do vetor de 1 a 10
void Exercicio(){
    int vetor[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "Informe o valor do Indice " << i << " ";
        cin >> vetor[i];
    }

    for (int i = 0; i < 10; i+=2)
    {
        cout << "" << i << " - "<< vetor[i] << endl;
    }
}

int main(){
    Exercicio();
    return 0;
}