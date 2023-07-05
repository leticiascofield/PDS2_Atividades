#include "japonesa.hpp"

using std::string;
using std::to_string;
std::string Japonesa::descricao() const
{

  string descricao = to_string(m_qtd) + "X Comida Japonesa - " + this->combinado_ + ", " +
                     to_string(sushis_) + " sushis, " + to_string(temakis_) + " temakis e " + to_string(hots_) +
                     " hots.";
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */

  return descricao;
}

Japonesa::Japonesa(const std::string &combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) : combinado_(combinado)
{
  this->sushis_ = sushis;
  this->temakis_ = temakis;
  this->hots_ = hots;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}