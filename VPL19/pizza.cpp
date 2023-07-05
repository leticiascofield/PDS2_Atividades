#include "pizza.hpp"

using std::string;
using std::to_string;

std::string Pizza::descricao() const
{
  string bordaRecheadaOuNao;
  if (this->borda_recheada_ == true)
  {
    bordaRecheadaOuNao = "e borda recheada.";
  }
  else
  {
    bordaRecheadaOuNao = "e sem borda recheada.";
  }

  string descricao = to_string(m_qtd) + "X Pizza " + this->sabor_ + ", " + to_string(pedacos_) + " pedacos " +
                     bordaRecheadaOuNao;

  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */

  return descricao;
}

Pizza::Pizza(const std::string &sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) : sabor_(sabor)
{
  this->pedacos_ = pedacos;
  this->borda_recheada_ = borda_recheada;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}