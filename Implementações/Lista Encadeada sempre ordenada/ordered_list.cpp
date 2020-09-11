#include "ordered_list.hpp"
#include <limits>

// Construir lista vazia, mas com capacidade máxima informada.
ordered_list::ordered_list() {
    this->primeiro = nullptr;
    this->tamanho = 0;
}

// Construir lista com "tamanho" cópias do valor "inicial".
ordered_list::ordered_list(unsigned int tamanho, int inicial) {
    this->tamanho = tamanho;
    this->primeiro = nullptr;
    for (unsigned int i = 0; i < this->tamanho; i++) {
        no_encadeado* new_no = new no_encadeado(inicial, this->primeiro);
        this->primeiro = new_no;
  }
}


// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção. Sempre deve executar a inserção.
void ordered_list::inserir(int elemento) {
 if (tamanho == 0) {
    no_encadeado* novo_no = new no_encadeado(elemento);
    this->primeiro = novo_no;
    this->tamanho++;
  } else {
    no_encadeado* anterior = obter_no_em(this->tamanho - 1);
    no_encadeado* novo_no = new no_encadeado(elemento);
    anterior->proximo = novo_no;
    tamanho++;
  } 
    for (unsigned int i = 0; i < this->tamanho - 1; i++) {
        for (unsigned int k = 0; k < (this->tamanho - 1) - i; k++) {
            no_encadeado* no = obter_no_em(k);
              no_encadeado* no_aux = obter_no_em(k + 1);
              if (no_aux->valor < no->valor) {
                if (obter_indice_de(no->valor) == 0) {
                  this->primeiro = no_aux;
                  no->proximo = no_aux->proximo;
                  this->primeiro->proximo = no;
                } else {
                  no_encadeado* no_aux_2 = obter_no_anterior_a(no->valor);
                  no->proximo = no_aux->proximo;
                  no_aux->proximo = no;
                  no_aux_2->proximo = no_aux;
                }
      }
    }
  }
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
bool ordered_list::remover(int elemento) {
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
bool ordered_list::pertence(int elemento) {
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

// Remover o elemento associado a "indice".
// Retornar indicativo de sucesso da remoção.
bool ordered_list::remover_de(unsigned int indice) {
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
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<int>::max()`
//      (forma de obter o maior valor representável).
int ordered_list::obter_elemento_em(unsigned int indice) {
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
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<unsigned int>::max()`
//      (forma de obter o maior valor representável).
unsigned int ordered_list::obter_indice_de(int elemento) {
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

// Construtor de um nó, onde a informação do próximo, no momento construção, é opcional
ordered_list::no_encadeado::no_encadeado(int valor, no_encadeado* proximo) {
    this->valor = valor;
    this->proximo = proximo;
}

// Desejamos obter o próprio nó que esteja no índice informado.
// Deve retornar `nullptr` quando tal nó não existe.
// Auxilia processos que dependem de encontrar nós baseado em um índice.
ordered_list::no_encadeado* ordered_list::obter_no_em(unsigned int indice) {
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

// Desejamos obter o próprio nó que veja **antes** de algum com o valor informado.
// (ou seja, `anterior.proximo.valor == valor`)
// Auxilia processos que dependem de encontrar nós baseado em um valor.
// Deve retornar `nullptr` quando tal nó não existe.
ordered_list::no_encadeado* ordered_list::obter_no_anterior_a(int valor) {
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