#include "dicionario.h"

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::list;
using std::string;

// Implementa um dicionário que mapeia uma chave (do tipo string)
// a um valor (também do tipo string).
// As chaves são únicas, e estão dispostas em qualquer ordem na lista. 
  // Cria um dicionário vazio.
  Dicionario::Dicionario(){
  }

  // Retorna quantos pares chave/valor estão no dicionário.
  int Dicionario::tamanho(){
    return elementos_.size();
  }

  // Testa se uma chave pertence ao dicionário.
  bool Dicionario::pertence(string chave){
    auto aux = std::find_if(elementos_.begin(), elementos_.end(),
      [chave](const Elemento& elem) {
        return elem.chave == chave;
      }
    );

    return aux != elementos_.end();
  }

  // Retorna a *menor* chave do dicionário.
  // Pré-condição: o dicionário não está vazio.
  string Dicionario::menor(){
    if(this->tamanho() == 0){
      DicionarioVazio e;
      throw e;
    }
    string menor = elementos_.front().chave;
    for (auto i = elementos_.begin(); i != elementos_.end(); i++) {
        if(i->chave < menor){
            menor = i->chave;
        }
    }
    return menor;
  }

  // Retorna o valor associado a chave.
  // Pré-condição: a chave *necessariamente* está no dicionário.
  string Dicionario::valor(string chave){
    if(this->pertence(chave) == false){
      ChaveInexistente e;
      e.chave = chave;
      throw e;
    }
    string valor = "";
    for (auto i = elementos_.begin(); i != elementos_.end(); i++) {
        if(i->chave == chave){
            valor = i->valor;
        }
    }  
    return valor;
  }

  // Insere um par chave/valor no dicionário.
  // Pré-condição: a chave *não* está no dicionário.
  void Dicionario::Inserir(string chave, string valor){
    if(this->pertence(chave)){
      ChaveRepetida e;
      e.chave = chave;
      throw e;
    }
    Elemento elemento1 = {chave, valor};
    bool b = false;
    if (elementos_.empty() || elementos_.back().chave < chave) {
    elementos_.push_back(elemento1);
    } else {
        for (auto i = elementos_.begin(); i != elementos_.end(); i++) {
            if((i->chave > elemento1.chave) && (b == false)){
                elementos_.insert(i, elemento1);
                b = true; 
            }
        }  
    } 
  }

  // Remove um par chave/valor do dicionário.
  // Pré-condição: a chave *necessariamente* está no dicionário.
  void Dicionario::Remover(string chave){
    if(this->pertence(chave) == false){
      ChaveInexistente e;
      e.chave = chave;
      throw e;
    }
    auto aux = std::find_if(elementos_.begin(), elementos_.end(),
      [chave](const Elemento& elem) {
        return elem.chave == chave;
      }
    );

    if (aux != elementos_.end()) {
      elementos_.erase(aux);
    }
  }

  // Altera o valor associado a uma chave do dicionário.
  // Pré-condição: a chave *necessariamente* está no dicionário.
  void Dicionario::Alterar(string chave, string valor){
    if(this->pertence(chave) == false){
      ChaveInexistente e;
      e.chave = chave;
      throw e;
    }
    auto aux = std::find_if(elementos_.begin(), elementos_.end(),
      [chave](const Elemento& elem) {
        return elem.chave == chave;
      }
    );

    if (aux != elementos_.end()) {
      aux->valor = valor;
    }
  }

  // Libera toda a memória alocada para armazenar os dados no
  // dicionário.
  Dicionario::~Dicionario(){
    elementos_.clear();
  }
