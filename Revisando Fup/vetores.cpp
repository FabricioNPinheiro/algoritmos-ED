#include<iostream>

using namespace std;

int main(){

    int nota[3];

    nota[0] = 3;
    nota[1] = 4;
    nota[2] = 5;

    // cout << nota[2] << endl;

//////////////////////////////////////////////////////////////////////////////
    //cout << "\n\n" << endl;

    int vetor[5] = {1, 2, 3, 4};

    //vetor[1] = 7;

    for (int i = 0; i < 5; i++)
    {
      //cout << vetor[i] << endl;
    }

//////////////////////////////////////////////////////////////////////////////
   // cout << "\n\n" << endl;

    float notas[3];
    float total = 0;
    float media = 0;

    //cout << "Insira 5 notas:\n";

    for (int i = 0; i < 3; i++)
    {
        //cin >> notas[i];
    }

    for (int i = 0; i < 3; i++)
    {
        total += notas[i];
    }
    
    media =  total / 3;

    cout << fixed;
    cout.precision(1);

    //cout << media << endl;
    
//////////////////////////////////////////////////////////////////////////////
    cout << "\n\n" << endl;

    int numeros[4];

    cout << "Insira os números: " << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "Informe o numero da posição " << i << endl;
        cin >> numeros[i];
    }
    
    for (int i = 0; i < 4; i++)
    {
        cout << "O numero da posição " << i << "eh: " << numeros[i] << endl;
    }
    
    return 0;
}