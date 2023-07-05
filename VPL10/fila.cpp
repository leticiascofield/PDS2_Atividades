#include "fila.h"
#include <iostream>
#include <string>

using std::string;

   // Cria uma fila vazia;
  Fila::Fila(){
    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
  }

  // Retorna o primeiro elemento da fila.
  // Precondição: a fila *não* pode estar vazia.  
  string Fila::primeiro(){
    return this->primeiro_->chave;
  }

  // Retorna o último elemento da fila.
  // Precondição: a fila *não* pode estar vazia.  
  string Fila::ultimo(){
    return this->ultimo_->chave;
  }

  // Informa se a fila está vazia.
  bool Fila::vazia(){
    if(this->primeiro_ == nullptr){
        return true;
    } else{
        return false;
    }
  }

  // Insere um elemento no fim da fila.
  void Fila::Inserir(string k){
    No* aux = new No{k,nullptr};
    if(primeiro_ == nullptr){
        primeiro_ = aux;
        ultimo_ = aux; 
    } else{
        ultimo_->proximo = aux; //(*ultimo_).proximo
        ultimo_ = aux;
    }
  }

  // Remove o elemento no início da fila. 
  // Precondição: a fila *não* pode estar vazia.
  void Fila::Remover(){
    No* aux = primeiro_;
    primeiro_ = primeiro_->proximo;
    if (primeiro_ == nullptr){
        ultimo_ = nullptr;
    }
    delete aux;
  }

  // Retorna o número de elementos na fila.
  int Fila::tamanho(){
    No* aux = primeiro_;
    int count = 0;
    while(aux != nullptr){
        aux = aux->proximo;
        count++;
    }
    delete aux;
    return count;
  }

  // Libera toda a memória alocada para a fila.
  Fila::~Fila(){
    for (int i = 0; i < this->tamanho(); i++){
        this->Remover();
    }
    delete primeiro_;
    delete ultimo_;
  }
