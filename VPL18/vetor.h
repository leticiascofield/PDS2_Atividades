#ifndef VETOR_H_
#define VETOR_H_

#include <iostream>
using namespace std;

#include <string>

using std::string;

// Define um vetor cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <typename Tipo>
class Vetor
{
public:
  // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
  // O valor associado aos índices é indefinido.
  // PRECONDIÇÃO: fim >= inicio.
  Vetor(int inicio, int fim) : inicio_(inicio), fim_(fim)
  {
    elementos_ = new Tipo[fim - inicio + 1];
  }

  // Redimensiona o vetor de forma que os índices passam a variar
  // de 'inicio2' até 'fim2'.
  // O valor associado aos índices que estão na interseção de
  // [inicio_, fim_] e [inicio2, fim2], não se alteram.
  // Já o valor dos demais índices é indefinido.
  // PRECONDIÇÃO: fim2 >= inicio2.
  void Redimensionar(int inicio2, int fim2)
  {

    int intersecaoInicio = max(inicio_, inicio2);
    int intersecaoFim = min(fim_, fim2);
    int intersecaoTamanho = intersecaoFim - intersecaoInicio + 1;

    Tipo *aux = new Tipo[fim2 - inicio2 + 1];

    for (int i = intersecaoInicio; i <= intersecaoFim; i++)
    {
      aux[i - inicio2] = elementos_[i - inicio_];
    }

    elementos_ = aux;
    inicio_ = inicio2;
    fim_ = fim2;
  }

  void atribuir(int i, Tipo valor)
  {
    elementos_[i - inicio_] = valor;
  }

  // Retorna uma referência a variável correspondente ao índice i.
  // Pode ser utilizado tanto para atribuir quanto para acessar valores.
  // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
  Tipo &operator[](int i)
  {
    return elementos_[i - inicio_];
  }

  // Desaloca a memória reservada para os elementos do vetor.
  ~Vetor()
  {
    delete[] elementos_;
  }

private:
  int inicio_;      // Primeiro índice válido do vetor.
  int fim_;         // Último índice válido do vetor.
  Tipo *elementos_; // Elementos do vetor.
};

#endif