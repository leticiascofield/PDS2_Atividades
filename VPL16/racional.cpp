#include "racional.h"

#include <cmath>
#include <iostream>

int mdc(int a, int b) {
    if (a < 0){
      a = -a;
    }
    if (b < 0){
     b = -b;
    }
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

void Racional::Simplificar() {
  if (this->denominador_ < 0){
    this->numerador_ = -this->numerador_;
    this->denominador_ = -this->denominador_;
  }
  int MaximoDivisorComum = mdc(this->numerador_, this->denominador_);
  this->numerador_ = this->numerador_/ MaximoDivisorComum;
  this->denominador_ = this->denominador_ / MaximoDivisorComum;
}

Racional::Racional() {
  this->numerador_ = 0;
  this->denominador_ = 1;
  Simplificar();
}

Racional::Racional(int n)  {
  this->numerador_ = n;
  this->denominador_ = 1;
  Simplificar();
}

Racional::Racional(int n, int d) {
  if(d == 0){
    ExcecaoDivisaoPorZero e;
    throw e;
  } 
  this->numerador_ = n;
  this->denominador_ = d;
  Simplificar();
}

int Racional::numerador() const {
  return this->numerador_;
}

int Racional::denominador() const {
  return this->denominador_;
}
Racional Racional::operator-() const{
  Racional r(-numerador_, denominador_);
  return r;
} 

Racional Racional::operator+(Racional k) const{
  int soma_numerador = (((this->numerador_) * (k.denominador_)) + ((k.numerador_) * (this->denominador_)));
  int soma_denominador = ((this->denominador_) * (k.denominador_));
  Racional soma(soma_numerador, soma_denominador);
  return soma;
}

Racional Racional::operator-(Racional k) const{
  int subtracao_numerador = (((this->numerador_) * (k.denominador_)) - ((k.numerador_) * (this->denominador_)));
  int subtracao_denominador = ((this->denominador_) * (k.denominador_));
  Racional subtracao(subtracao_numerador, subtracao_denominador);
  return subtracao;
}

Racional Racional::operator*(Racional k) const {
  int multiplicacao_numerador = ((this->numerador_) * (k.numerador_));
  int multiplicacao_denominador = ((this->denominador_) * (k.denominador_));
  Racional multiplicacao(multiplicacao_numerador, multiplicacao_denominador);
  return multiplicacao;
}

Racional Racional::operator/(Racional k) const {
  int divisao_numerador = ((this->numerador_) * (k.denominador_));
  int divisao_denominador = ((this->denominador_) * (k.numerador_));
  Racional divisao(divisao_numerador, divisao_denominador);
  return divisao;
}

Racional::operator float() const {
  float f = static_cast<float>(numerador_)/denominador_;
  return f;
}

Racional::operator string() const {
  string string_numerador = std::to_string(numerador_);
  string string_denominador = std::to_string(denominador_);
  string s = string_numerador + "/" + string_denominador;
  return s;
}

ostream& operator<<(ostream& out, Racional r){
  out << r.numerador_ << '/' << r.denominador_;
  return out; 
}

// Sobrecarrega o operador de extração de streams.
istream& operator>>(istream& in, Racional& r){
    in >> r.numerador_ >> r.denominador_;
    r.Simplificar();
    return in; 
}