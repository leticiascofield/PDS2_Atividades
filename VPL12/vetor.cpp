#include "vetor.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdbool.h>

// Cria um vetor cujos índices variam de 'inicio' até 'fim'.
// PRECONDIÇÃO: fim >= inicio.
Vetor::Vetor(int inicio, int fim)
{
    if (inicio > fim)
    {
        IntervaloVazio e;
        e.inicio = inicio;
        e.fim = fim;
        throw e;
    }
    int tamanho = fim - inicio + 1;
    this->inicio_ = inicio;
    this->fim_ = fim;
    this->elementos_ = new string[tamanho];
    b.resize(fim_ - inicio_ + 1, false);
}

// Altera o valor do índice i.
// PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
void Vetor::atribuir(int i, std::string valor)
{
    if ((i < inicio_) || (i > fim_))
    {
        IndiceInvalido e;
        e.inicio = inicio_;
        e.fim = fim_;
        e.indice = i;
        throw e;
    }
    else
    {
        b[i - inicio_] = true;
        elementos_[i - inicio_] = valor;
    }
}

// Retorna o valor do índice i.
// PRECONDIÇÕES:
// (1) i está dentro do intervalo de índices do vetor.
// (2) i foi inicializando anteriormente.
string Vetor::valor(int i) const
{
    if ((i < inicio_) || (i > fim_))
    {
        IndiceInvalido e;
        e.inicio = inicio_;
        e.fim = fim_;
        e.indice = i;
        throw e;
    }
    else if (b[i - inicio_] == false)
    {
        IndiceNaoInicializado e;
        e.indice = i;
        throw e;
    }
    else
    {
        return elementos_[i - inicio_];
    }
}

// Desaloca a memória reservada para os elementos do vetor.
Vetor::~Vetor()
{
    delete[] elementos_;
}
