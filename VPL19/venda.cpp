#include "venda.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

Venda::~Venda()
{
  for (auto aux : m_pedidos)
  {
    delete aux;
  }
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
}

void Venda::adicionaPedido(Pedido *p)
{
  m_pedidos.push_back(p);
  // TODO: Implemente este metodo
}

void Venda::imprimeRelatorio() const
{
  float valorVendas;
  int count = 0;
  for (auto aux : m_pedidos)
  {
    count++;
    valorVendas += aux->calculaTotal();
    cout << "Pedido " << count << endl;
    cout << aux->resumo();
  }
  float valorVendasArredondado = round(valorVendas * 100) / 100;
  cout << "Relatorio de Vendas" << endl;
  cout << "Total de vendas: R$ " << std::fixed << std::setprecision(2) << valorVendasArredondado << endl;
  cout << "Total de pedidos: " << count << endl;
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
}