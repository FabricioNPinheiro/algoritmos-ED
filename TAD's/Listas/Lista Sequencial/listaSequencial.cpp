#include <iostream>
#include <vector>

using namespace std;

class vector{
    private:
        int *vetor;
        unsigned int tamanho;
        unsigned int capacidade;

        public:

            vector(unsigned int capacidade){
                vetor = new int[capacidade];
                this->tamanho = 0;
                this->capacidade = capacidade;   
            }
        
            vector(unsigned int tamanho, int inicial){
                vetor = new int[tamanho];
                capacidade = tamanho;
                this->tamanho = tamanho;

                for(unsigned int i = 0; i < tamanho; i++){
                    vetor[i] = inicial;
                }
            }

        // OPERAÇÕES COLEÇÃO
        bool inserir(int elemento){
            if(tamanho < capacidade){
                tamanho++;
                vetor[tamanho] = elemento;
                return true;
            } else{
                vetor = (int *) realloc(vetor, sizeof(int)*capacidade);
                tamanho++;
                vetor[tamanho] = elemento;
                return true;
            }
            return false;
        }

        bool remover(unsigned int elemento){
            if(tamanho < 0){
                return false;
            }
            else {
                for (int i = 0; i < tamanho; i++) {
                if(vetor[i] == elemento){
                    for(unsigned int j = i+1; j < tamanho; j++){
                          vetor[j-1] = vetor[j];
                    }
                    tamanho--;
                    return true;
                } else {
                    return false;
                  }
                }
            }   
        }


        bool pertinencia(int elemento){
            if(tamanho < 0) {
                return false
            } else {
                for (int i = 0; i < tamanho; i++) {
                    if(vetor[i] == elemento){
                        return true;
                    } else {
                        return false;
                      }
                }
             }
        }

        int tamanho(){}

        //OPERAÇÕES LISTAS
        bool inserir_Indice(int elemento, int indice){}
        bool remover_Indice(int indice){}
        bool obter_Elemento(int indice){}
        bool obter_Indice(int elemento){}


};

int main()
{
    return 0;
}