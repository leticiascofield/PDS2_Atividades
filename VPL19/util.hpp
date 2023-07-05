#ifndef UTIL_H
#define UTIL_H

/**
 * Este arquivo contem testes para o VPL. Ele nao deve ser modificado em
 * hipotese alguma. Voce pode usa-lo para testar seu VPL localmente.
 */

#include "pedido.hpp"

void readPizza(Pedido* pedido);
void readHamburguer(Pedido* pedido);
void readJapaneseCuisine(Pedido* pedido);
void readAddress(Pedido* pedido);

#endif