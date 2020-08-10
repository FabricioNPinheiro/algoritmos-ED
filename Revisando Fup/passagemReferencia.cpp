#include<iostream>

using namespace std;

/*
void altera(int &x, int &y){
    x = 5;
    y = 7;
}

int main(){
     
     int a;
     int b;

     a = 10;
     b = 20;
     altera(a, b);

     cout << a << endl;
     cout << b << endl;
    return 0;
}

*/

int main(void){

    void testeVariavel(int x);
    void testePonteiro(int *pX);
    int teste = 1;
    int *pTeste = &teste;

    testeVariavel(teste);
    testePonteiro(pTeste);

    cout << teste << endl;
    cout << pTeste << endl;

    getchar();
    return 0;
}

void testeVariavel(int x){
    ++x;
}
void testePonteiro(int *pX){
    ++pX;
}