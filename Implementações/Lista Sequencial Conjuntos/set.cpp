#include "set.hpp"
#include <limits>
#include <iostream>

// Construir lista vazia, mas com capacidade máxima informada.
set::set(unsigned int capacidade) {
    vetor = new int[capacidade];
    tamanho = 0;
    this->capacidade = capacidade;
}

// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção.
// Retornar indicativo de sucesso da inserção.
// NOTE Deve aumentar a capacidade caso necessário.
// NOTE Observe que aumentar em apenas uma unidade não nos alivia da pressão que tínhamos antes...
bool set::inserir(int elemento) {
    if(pertence(elemento)){
        return false;
    } else {
        if(tamanho < capacidade){
        vetor[tamanho] = elemento;
         tamanho++;
         capacidade++;
         return true;
        } else {
            vetor = (int *) realloc(vetor, sizeof(int)*capacidade);
            tamanho++;
            vetor[tamanho] = elemento;
            return true;
            }
    }
    return false;
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
// NOTE Necessário preservar a ordem relativa dos que restarem.
bool set::remover(int elemento) {
   if(pertence(elemento)){
        for (int i = 0; i < tamanho; i++) {
              if(vetor[i] == elemento){
                  for(unsigned int j = i+1; j < tamanho; j++){
                      vetor[j-1] = vetor[j];
                  }
                  tamanho--;
                  return true;
                } 
            }
            return false;
        } else {
            return false;
          }          
}

// Determinar se "elemento" é um dos elementos ainda na coleção.
bool set::pertence(int elemento) const {
    for(unsigned int i = 0; i < tamanho; i++) {
        if(vetor[i] == elemento) {
            return true;
        }  
    }
    return false;  
}


// --- Métodos de "Conjunto" ---

// Tornar o próprio conjunto (`this`) o resultado de sua união com o outro informado.
void set::uniao_com(set const &conjunto) {
        for (int j = 0; j < conjunto.tamanho; j++) {
            if(!(pertence(conjunto.vetor[j]))){
                inserir(conjunto.vetor[j]);
            }
        }
}

// Tornar o próprio conjunto (`this`) o resultado de sua intersecção com o outro informado.
void set::intersecao_com(set const &conjunto) {
  int *temp = new int[tamanho];
  for (unsigned l = 0; l < tamanho; l++) {
       temp[l] = 0;
  }
  
  if (conjunto.tamanho == 0) {
        this->tamanho = 0;
  }
  
  for (unsigned int i = 0; i < tamanho; i++) {
    if ((conjunto.pertence(vetor[i]))) {
      temp[i] = vetor[i];
    }
  }
  
  for (unsigned int i = 0; i < tamanho; i++) {
    vetor[i] = temp[i];
  }
}

// Testar se este conjunto (`this`) está contido no outro informado.
bool set::esta_contido_em(set const &conjunto) const {
    // TODO Implementação.
        if(tamanho == 0) {
            return true;
        } else {
            for(unsigned int i = 0; i < tamanho; i++) {
                if(!(conjunto.pertence(vetor[i]))) {
                    return false;
                }
            }
            return true;
        }
    return false;
}
