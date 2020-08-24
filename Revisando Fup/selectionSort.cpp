#include<iostream>

using namespace std;

void selectionSort(int vet[], int qtd){

    int Menor, aux;

    for (int i = 0; i < qtd; i++) {
        Menor=i;
        for (int j = 0; j < qtd; j++) {
            if (vet[Menor] < vet[j]) {
                Menor=j;
            }
                aux=vet[i];
                vet[i] = vet[Menor];
                vet[Menor]=aux;      
        }
    }
}

void insertionSort(int vetor[], int tam) {

    for (int i = 1; i < tam; i++) {
		int escolhido = vetor[i];
		int j = i - 1;
		
		while ((j >= 0) && (vetor[j] > escolhido)) {
			vetor[j + 1] = vetor[j];
			j--;
		}
		
		vetor[j + 1] = escolhido;
	}
}

int main(){

    int n = 15;
    int vetor[] = {4, 1, 3, 0, 2, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};

    // selectionSort(vetor, n);
    insertionSort(vetor, n);

    cout << "\n\n";

    for (int i = 0; i < n; i++) {
        cout << vetor[i] << endl;
    }

    cout << "\n\n";

    return 0;
}