#include <iostream>

class vector {
    private:
        // Ponteiro para o vetor que usaremos para armazenar os elementos.
        int *vetor;
        // Contagem da quantidade de elementos efetivamente presentes na lista.
        unsigned int tamanho; // FIXME Veja que a correspondência desse valor e do último índice ocupado está incorreta em alguns lugares do código.
        // Contagem do número de índices alocados no vetor "vetor".
        unsigned int capacidade;

    public:
        // Construir lista vazia, mas com capacidade máxima informada.
        vector(unsigned int capacidade) {
            vetor = new int[capacidade];
            tamanho = 0;
            this->capacidade = capacidade;
        }
        
        // Construir lista com "tamanho" cópias do valor "inicial".
        vector(unsigned int tamanho, int inicial) {
            vetor = new int[tamanho];
            capacidade = tamanho;
            this->tamanho = tamanho;

            for(unsigned int i = 0; i < tamanho; i++) {
                vetor[i] = inicial;
            }
        }

        // Inserir "elemento" na coleção. Sempre deve executar a inserção.
        // FIXME Alterar tipo de retorno para `void` e fazer realocação quando não houver espaço.
        bool inserir(int elemento) {
            // TODO Reorganizar o código
            if(tamanho < capacidade) {
                tamanho++;
                vetor[tamanho] = elemento;
                return true;
            } else {
                // TODO Realocar o vetor e inserir "elemento"
                return false;
            }
        }

        // Remover o elemento associado a "indice". Deve falhar apenas quando "índice" não for válido ou quando a lista estiver vazia.
        bool remover(unsigned int indice) {
            if(indice >= tamanho) {
                return false;
            }

            for(unsigned int i = indice+1; i < tamanho; i++) {
                vetor[i-1] = vetor[i];
            }
            tamanho--;
        }

        // TODO Implementar todos os outros métodos correspondentes aos necessários para "Lista" e para "Coleção".
};

int main() {

    return 0;
}