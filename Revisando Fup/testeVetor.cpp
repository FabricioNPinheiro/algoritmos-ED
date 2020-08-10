#include <iostream>

using namespace std;

#define TAM 5

int main(){

    int vetor[TAM], maior, posMaior, menor, posMenor;

    // preechendo
    for (int i = 0; i < TAM; i++)
    {
        cin >> vetor[i];
    }

    // encontrando o maior
    maior = vetor[0];
    posMaior = 0;
    for (int i = 1; i < TAM; i++)
    {
        if(vetor[i] > maior){
            maior = vetor[i];
            posMaior = i;
        }
    }

    // encotrando o menor
    menor = vetor[0];
    posMenor = 0;
    for (int i = 1; i < TAM; i++)
    {
        if(vetor[i] < menor){
            menor = vetor[i];
            posMenor = i;
        }
    }

    // Mostra vetor;

    cout << "Vetor: " << endl;
    for (int i = 0; i < TAM; i++)
    {
        cout << " " << vetor[i];
    }

    cout << "\nMaior: " << maior << " Posição do maior: " << posMaior << endl;
     cout << "\nMenor: " << menor << " Posição do menor: " << posMenor << endl;
        
    

    





    return 0;
}