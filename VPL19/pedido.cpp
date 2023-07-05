#include "pedido.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Pedido::~Pedido()
{
  for (auto aux : m_produtos)
  {
    delete aux;
  }
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
}

void Pedido::setEndereco(const std::string &endereco)
{
  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const
{
  float valorTotal = 0;
  for (auto aux : m_produtos)
  {
    valorTotal += (aux->getValor() * aux->getQtd());
  }
  return valorTotal;
}

void Pedido::adicionaProduto(Produto *p)
{
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const
{
  string resumo;
  for (auto aux : m_produtos)
  {
    resumo += aux->descricao();
    cout << aux->descricao() << endl;
  }
  resumo += "Endereco: " + m_endereco;
  cout << "Endereco: " << m_endereco << endl;
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  return "";
}