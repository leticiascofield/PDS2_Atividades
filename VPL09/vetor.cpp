#include "vetor.h"
#include <iostream>
#include <string>

    // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
       // PRECONDIÇÃO: fim >= inicio.
    Vetor::Vetor(int inicio, int fim){
        if(inicio <= fim){
        int tamanho = fim - inicio + 1;
        this->inicio_ = inicio;
        this->fim_ = fim;
        this->elementos_ = new string[tamanho];
        } 
    }

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void Vetor::atribuir(int i, std::string valor){
        if ((i >= inicio_) && (i <= fim_)){
            elementos_[i-inicio_] = valor;
        }
    }

    // Retorna o valor do índice i.
    // PRECONDIÇÕES: 
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    string Vetor::valor(int i) const{
        if ((i >= inicio_) && (i <= fim_)){
            return elementos_[i-inicio_];
        } 
        else{
            return "";
        }
    }

    // Desaloca a memória reservada para os elementos do vetor.
    Vetor::~Vetor(){
        delete[] elementos_;
    }
  
