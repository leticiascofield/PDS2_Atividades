#include "hamburguer.hpp"

#include <iostream>
#include <string>

using std::string;
using std::to_string;

std::string Hamburguer::descricao() const
{
  string artesanalOuSimples;
  if (this->artesanal_ == true)
  {
    artesanalOuSimples = "artesanal";
  }
  else
  {
    artesanalOuSimples = "simples";
  }

  string descricao = to_string(m_qtd) + "X Hamburguer " + this->tipo_ + " " + artesanalOuSimples + ".";
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
  return descricao;
}

Hamburguer::Hamburguer(const std::string &tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) : tipo_(tipo)
{
  this->artesanal_ = artesanal;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}