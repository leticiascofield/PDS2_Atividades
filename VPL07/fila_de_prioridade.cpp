#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
  lista_.push_back(p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  string nome;
  vector<string> ordem = this->listar();
  nome = ordem.front();
  this->Remover(nome);
  return nome;
}

void FilaDePrioridade::Remover(string nome) {
  vector<Pessoa> vetorPessoa;
  for (Pessoa const &c: lista_) {
      vetorPessoa.push_back(c);
  }
  for(int i = 0; i < vetorPessoa.size(); i++){
    if(vetorPessoa[i].nome == nome){
      vetorPessoa.erase(vetorPessoa.begin() + i);
    }
  }

  this->lista_.clear();
  for(int i = 0; i < vetorPessoa.size(); i++){
    this->lista_.push_back(vetorPessoa[i]);
  }

}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v;
  for (int i=3; i>=0; i--) {
    for (auto it = lista_.begin(); it != lista_.end(); it++) {
      if (it->prioridade == i) {
        v.push_back(it->nome);
      }
    }
  }
  return v; 
}