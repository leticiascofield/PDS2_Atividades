#include <map>
#include <string>
#include <iostream>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  estoque_[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  bool b = false;
  for(auto aux: estoque_){
    if(aux.first == mercadoria){
      b = true;
      if(aux.second < qtd){
        Insuficiente e;
        e.mercadoria_ = mercadoria;
        throw e;
      }
    }
  }
  if(b == false){
    Inexistente e;
    e.mercadoria_ = mercadoria;
    throw e;
  }
  estoque_[mercadoria] -= qtd;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  for(auto aux: estoque_){
    if(aux.first == mercadoria){
      return aux.second;
    }
  }
  return 0;
}

void Estoque::imprime_estoque() const {
  for(auto aux: estoque_){
    std::cout << aux.first << ", " << aux.second << std::endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  for(auto aux: rhs.estoque_){
    this->add_mercadoria(aux.first, aux.second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for(auto aux: rhs.estoque_){
    this->sub_mercadoria(aux.first, aux.second);
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  int mercadoriasIguais = 0;
  for(auto aux1: lhs.estoque_){
    for(auto aux2: rhs.estoque_){
      if(aux1.first == aux2.first){
        mercadoriasIguais++;
        if(aux1.second >= aux2.second){
          return false;
        }
      }
    }
  }
  if(mercadoriasIguais == lhs.estoque_.size()){
    return true;
  } else{
    return false;
  }
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  int mercadoriasIguais = 0;
  for(auto aux1: lhs.estoque_){
    for(auto aux2: rhs.estoque_){
      if(aux1.first == aux2.first){
        mercadoriasIguais++;
        if(aux1.second <= aux2.second){
          return false;
        }
      }
    }
  }
  if(mercadoriasIguais == rhs.estoque_.size()){
    return true;
  } else{
    return false;
  }
}