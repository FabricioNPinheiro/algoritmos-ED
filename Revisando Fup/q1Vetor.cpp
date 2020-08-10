#include <iostream>

using namespace std;

#define TAM 3

int main(){

    int vetor[TAM], maior, posMaior, menor, posMenor;

    //Preenchendo vetor
    for (int i = 0; i < TAM; i++)
    {
        cin >> vetor[i];
    }

    // encontra o maior valor
    maior = vetor[0];
    posMaior = 0;
    for (int i = 1; i < TAM; i++)
    {
        if(vetor[i] > maior){
            maior    = vetor[i];
            posMaior = i;
        }
    }

    // encontra o menor valor
    menor = vetor[0];
    posMenor = 0;
    for (int i = 1; i < TAM; i++)
    {
        if(vetor[i] < menor){
            menor    = vetor[i];
            posMenor = i;
        }
    }

    // mostrar vetor
    cout << "Vetor: ";
    for (int i = 0; i < TAM; i++)
    {
        cout << " " << vetor[i];
    }

    cout << "\nMaior valor: " << maior  << " Posição: " << posMaior << endl;
    cout << "\nMenor valor: " << menor  << " Posição: " << posMenor << endl;
    
    return 0;
}