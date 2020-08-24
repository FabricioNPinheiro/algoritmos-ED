#include "list.hpp"
#include <limits>

// Construir lista vazia
list::list() {
    this->primeiro = nullptr;
    this->tamanho = 0;
}

// Construir lista com "tamanho" cópias do valor "inicial".
list::list(unsigned int tamanho, int inicial) {
  this->tamanho = tamanho;
  this->primeiro = nullptr;
  for (unsigned int i = 0; i < this->tamanho; i++) {
    no_encadeado* novo_no = new no_encadeado(inicial, this->primeiro);
    this->primeiro = novo_no;
  }
}

// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção. Sempre deve executar a inserção.
void list::inserir(int elemento) {
    inserir_em(obter_indice_de(tamanho), elemento);
    tamanho++;
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
// NOTE Necessário preservar a ordem relativa dos que restarem.
bool list::remover(int elemento) {
    if((pertence(elemento))){
        for (int i = 0; i < tamanho; i++) {
            if(obter_elemento_em(i) == elemento) {
                remover_de(i);
                return true;
            }
        }
        return true;
    } else {
         return false;
    }
}

// Determinar se "elemento" é um dos elementos ainda na coleção.
bool list::pertence(int elemento) {
    for (int i = 0; i < tamanho; i++){
        if (obter_elemento_em(i) == elemento) {
            return true;
        }
    }
    return false;
}

// --- Métodos de "Lista" ---

// Inserir "elemento" na lista de forma que ele passe a constar no índice "indice".
// NOTE Necessário preservar a ordem relativa dos demais elementos.
bool list::inserir_em(unsigned int indice, int elemento) {
    if(indice == 0) {
        no_encadeado* novo_no = new no_encadeado(elemento, this->primeiro);
        this->primeiro = novo_no;

        this->tamanho++;

        return true;
    } else {
        no_encadeado* anterior = obter_no_em(indice - 1);

        if(anterior != nullptr) {
            no_encadeado* novo_no = new no_encadeado(elemento);
            novo_no->proximo = anterior->proximo;
            anterior->proximo = novo_no;

            this->tamanho++;

            return true;
        } else {
            return false;
        }
    }
}

// Remover o elemento associado a "indice".
// Retornar indicativo de sucesso da remoção.
bool list::remover_de(unsigned int indice) {
    if(!(obter_elemento_em(indice))){
        return false;
    } else{
        no_encadeado* anterior = obter_no_em(indice - 1);
        no_encadeado* elem = obter_no_em(indice);
        if (anterior != nullptr) {
            anterior->proximo = elem->proximo;
            elem->proximo = nullptr;
            this->tamanho = tamanho--;
        }
        return true;
    }
    return false;
}

// Retornar o valor associado ao índice "indice".
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<int>::max()`
//      (forma de obter o maior valor representável).
int list::obter_elemento_em(unsigned int indice) {
        if(!(this->tamanho > 0)){
            return std::numeric_limits<int>::max();
        } else {
            if(indice >= this->tamanho){
                return std::numeric_limits<int>::max();
            } else {
                no_encadeado* temp = this->primeiro;
                for (int i = 0; i < indice; i++){
                   temp = temp->proximo;
                }
                return temp->proximo->valor;
            }
         }
}

// Retornar o índice associado a "elemento".
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<unsigned int>::max()`
//      (forma de obter o maior valor representável).
unsigned int list::obter_indice_de(int elemento) {
    unsigned int indice = 0;
    no_encadeado* no = this->primeiro;

    while(no != nullptr) {
        if(no->valor == elemento) {
            return indice;
        }
        indice++;
        no = no->proximo;
    }
    return std::numeric_limits<unsigned int>::max();
}

// --- Métodos Auxiliares ---

// Construtor de um nó, onde a informação do próximo, no momento construção, é opcional
list::no_encadeado::no_encadeado(int valor, no_encadeado* proximo) {
    this->valor = valor;
    this->proximo = proximo;
}

// Desejamos obter o próprio nó que esteja no índice informado.
// Deve retornar `nullptr` quando tal nó não existe.
// Auxilia processos que dependem de encontrar nós baseado em um índice.
list::no_encadeado* list::obter_no_em(unsigned int indice) {
    if(!(indice > 0) || indice > this->tamanho){
        return nullptr;
    } else {
        no_encadeado* no = this->primeiro;
        for (int i = 0; i < indice; i++) {
            no = no->proximo;
        }
        return no->proximo;
    }

    return nullptr;
}

// Desejamos obter o próprio nó que veja **antes** de algum com o valor informado.
// (ou seja, `anterior.proximo.valor == valor`)
// Auxilia processos que dependem de encontrar nós baseado em um valor.
// Deve retornar `nullptr` quando tal nó não existe.
list::no_encadeado* list::obter_no_anterior_a(int valor) {
    no_encadeado* procura = this->primeiro;
    for (int i = 0; i < tamanho; i++){
            if(procura->valor == valor){
                return obter_no_em(i-1);
            } else {
                return nullptr;
            }
    }
    return nullptr;
}
