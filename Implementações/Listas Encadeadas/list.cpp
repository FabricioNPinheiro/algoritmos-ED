#include "list.hpp"

#include <limits>

using namespace std;

// Construir lista vazia.
list::list() {
  this->primeiro = nullptr;
  this->tamanho = 0;
}

// Construtor de um nó, onde a informação do próximo, no momento construção, é
// opcional
list::no_encadeado::no_encadeado(int valor, no_encadeado* proximo) {
  this->valor = valor;
  this->proximo = proximo;
}
// Construir lista com "tamanho" cópias do valor "inicial".
list::list(unsigned int tamanho, int inicial) {
  this->tamanho = tamanho;
  this->primeiro = nullptr;
  for (unsigned int i = 0; i < this->tamanho; i++) {
    no_encadeado* new_no = new no_encadeado(inicial, this->primeiro);
    this->primeiro = new_no;
  }
}

// --- Métodos de "Coleção" ---

// Inserir "elemento" na coleção. Sempre deve executar a inserção.
void list::inserir(int elemento) {
  if (this->tamanho == 0) {
    no_encadeado* new_no = new no_encadeado(elemento);
    this->primeiro = new_no;
    this->tamanho++;
  } else {
    no_encadeado* ant = obter_no_em(tamanho - 1);
    no_encadeado* new_no = new no_encadeado(elemento);
    ant->proximo = new_no;
    this->tamanho++;
  }
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
// NOTE Necessário preservar a ordem relativa dos que restarem.
bool list::remover(int elemento) {
  if (!(this->tamanho > 0)) {
    return false;
  } else {
    if (!pertence(elemento)) {
      return false;
    }
    unsigned int aux = obter_indice_de(elemento);
    no_encadeado* remove = obter_no_em(aux);
    if (aux == 0) {
        this->primeiro = remove->proximo;
        delete[] remove;
        this->tamanho--;
        return true;
    } else {
        no_encadeado* anterior = obter_no_em(aux - 1);
        anterior->proximo = remove->proximo;
        delete[] remove;
        this->tamanho--;
        return true;
    }
  }
  return false;
}
// Determinar se "elemento" é um dos elementos ainda na coleção.
bool list::pertence(int elemento) {
  if (!(this->tamanho > 0)) {
    return false;
  } else {
    no_encadeado* temp = this->primeiro;
    while (temp != nullptr) {
      if (temp->valor == elemento) {
        return true;
      }
      temp = temp->proximo;
    }
  }
  return false;
}

// --- Métodos de "Lista" ---

// Inserir "elemento" na lista de forma que ele passe a constar no índice
// "indice". NOTE Necessário preservar a ordem relativa dos demais
// elementos.
bool list::inserir_em(unsigned int indice, int elemento) {
  if (indice == 0) {
    no_encadeado* temp = new no_encadeado(elemento, this->primeiro);
    this->primeiro = temp;
    this->tamanho++;
    return true;
  } else {
    no_encadeado* anterior = obter_no_em(indice - 1);
    if (anterior != nullptr) {
        no_encadeado* temp = new no_encadeado(elemento);
        temp->proximo = anterior->proximo;
        anterior->proximo = temp;
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
  if (!(this->tamanho > 0)) {
    return false;
  }
  if (indice >= this->tamanho) {
    return false;
  } else {
    no_encadeado* remove = obter_no_em(indice);
    bool exc = remover(remove->valor);
    if (exc)
      return true;
    else
      return false;
  }
  return false;
}

// Retornar o valor associado ao índice "indice".
// NOTE Quando o índice for inválido, retornar
// `std::numeric_limits<int>::max()`
//      (forma de obter o maior valor representável).
int list::obter_elemento_em(unsigned int indice) {
  if (!(this->tamanho > 0)) {
    return std::numeric_limits<int>::max();
  } else {
    if (indice >= this->tamanho) {
      return std::numeric_limits<int>::max();
    } else {
      no_encadeado* temp = obter_no_em(indice);
      if (temp == nullptr) {
        return std::numeric_limits<int>::max();
      }
      return temp->valor;
    }
  }
  return std::numeric_limits<int>::max();
}

// Retornar o índice associado a "elemento".
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<unsigned
// int>::max()`
//      (forma de obter o maior valor representável).
unsigned int list::obter_indice_de(int elemento) {
  if (!(this->tamanho > 0)) {
    return std::numeric_limits<unsigned int>::max();
  } else {
    unsigned int index = 0;
    no_encadeado* temp = this->primeiro;
    while (temp != nullptr) {
      if (temp->valor == elemento) {
        return index;
      }
      index++;
      temp = temp->proximo;
    }
  }
  return std::numeric_limits<unsigned int>::max();
}

// --- Métodos Auxiliares ---

// Desejamos obter o próprio nó que esteja no índice informado.
// Deve retornar `nullptr` quando tal nó não existe.
// Auxilia processos que dependem de encontrar nós baseado em um índice.
list::no_encadeado* list::obter_no_em(unsigned int indice) {
  if (!(this->tamanho > 0)) {
    return nullptr;
  } else {
    no_encadeado* temp = this->primeiro;
    for (unsigned int i = 0; i < indice; i++) {
      temp = temp->proximo;
    }
    return temp;
  }
  return nullptr;
}

// Desejamos obter o próprio nó que veja **antes** de algum com o valor
// informado. (ou seja, `anterior.proximo.valor == valor`) Auxilia processos
// que dependem de encontrar nós baseado em um valor. Deve retornar
// `nullptr` quando tal nó não existe.
list::no_encadeado* list::obter_no_anterior_a(int valor) {
  int aux = 0;
  if (!(this->tamanho > 0)) {
    return nullptr;
  } else {
    no_encadeado* temp = this->primeiro;
    while (temp != nullptr) {
      aux = temp->proximo->valor;
      if (aux == valor) {
        return temp;
      }
      temp = temp->proximo;
    }
  }
  return nullptr;
}