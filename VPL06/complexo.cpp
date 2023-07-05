// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>
#include <math.h>
#include <iostream>

// conferir funções que retornam modulo e argumento, tem que retornar real e imaginario

Complexo::Complexo() {
    this->modulo_ = 0; 
    this->argumento_ = 0;
    
}

Complexo::Complexo(double a, double b) {
    this->modulo_ = sqrt(a*a + b*b); // a; mudei na aula
    this->argumento_ = atan2(b, a); // b;
}

double Complexo::real() {
    return (this->modulo_*cos(this->argumento_));
}

double Complexo::imag() {
    return (this->modulo_*sin(this->argumento_));
}

bool Complexo::igual(Complexo x) {
    if ((this->modulo_ == x.modulo_) && (cos(this->argumento_) == cos(x.argumento_)) && 
    (sin(this->argumento_) == sin(x.argumento_))){ 
        return true;
      }
    else {
        return false;
    }
}

void Complexo::Atribuir(Complexo x) {
    this->modulo_ = x.modulo_;
    this->argumento_ = x.argumento_;
}

double Complexo::modulo() {
  return (this->modulo_);
}

Complexo Complexo::conjugado() { 
    double conjugado_real = this->modulo_ *(cos(this->argumento_));
    double conjugado_imag = -(this->modulo_ *(sin(this->argumento_)));
    Complexo c(conjugado_real, conjugado_imag);
    return c;
}

Complexo Complexo::simetrico() { // errado
  //double simetrico_real = -(this->modulo_ *(cos(this->argumento_)));
  //double simetrico_imag = this->modulo_ *(sin(this->argumento_));
  //Complexo c(simetrico_real, simetrico_imag);
  Complexo c(-this->modulo_, this->argumento_);
  return c;
}

Complexo Complexo::inverso() { // errado
  double inverso_modulo = (1/this->modulo_);
  double inverso_argumento = (-this->argumento_);
  Complexo i(inverso_modulo, inverso_argumento);
  return i;
}

Complexo Complexo::somar(Complexo y) { // possivelmente errado
  double soma_modulo = sqrt(pow((this->modulo_*cos(this->argumento_) + y.modulo_*cos(y.argumento_)), 2) + 
                      pow((this->modulo_*sin(this->argumento_) + y.modulo_*sin(y.argumento_)), 2));
  double soma_argumento = atan2((this->modulo_*sin(this->argumento_) + y.modulo_*sin(y.argumento_)), 
                      (this->modulo_*cos(this->argumento_) + y.modulo_*cos(y.argumento_)));

  while (soma_argumento > M_PI) soma_argumento -= 2*M_PI;
  while (soma_argumento <= -M_PI) soma_argumento += 2*M_PI;                    
  Complexo s(soma_modulo, soma_argumento);
  return s;
}

Complexo Complexo::subtrair(Complexo y) { // possivelmente errado
  double subtracao_modulo = sqrt(pow(this->modulo_, 2) + pow(y.modulo_, 2) - 
                            2*this->modulo_*y.modulo_*cos(this->argumento_ - y.argumento_));
  double subtracao_argumento = atan2(this->modulo_*sin(this->argumento_) - y.modulo_*sin(y.argumento_), 
                               this->modulo_*cos(this->argumento_) - y.modulo_*cos(y.argumento_));
  Complexo s(subtracao_modulo, subtracao_argumento);
  return s;
}

Complexo Complexo::multiplicar(Complexo y) { // possivelmente errado
  double multiplicacao_modulo = (this->modulo_*y.modulo_);
  double multiplicacao_argumento = (this->argumento_ + y.argumento_);
  Complexo p(multiplicacao_modulo, multiplicacao_argumento);
  return p;
}

Complexo Complexo::dividir(Complexo y) { // possivelmente errado
  double divisao_modulo = (this->modulo_/y.modulo_);
  double divisao_argumento = (this->argumento_ - y.argumento_);
  Complexo d(divisao_modulo, divisao_argumento);
  return d;
}