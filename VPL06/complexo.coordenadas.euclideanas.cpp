// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>
#include <math.h>

Complexo::Complexo() {
    this->real_ = 0;
    this->imag_ = 0;
}

Complexo::Complexo(double a, double b) {
    this->real_ = a;
    this->imag_ = b;
}

double Complexo::real() {
     return (this->real_);
}

double Complexo::imag() {
    return (this->imag_);
}

bool Complexo::igual(Complexo x) {
    if ((this->real_ == x.real_) && (this->imag_ == x.imag_)){
        return true;
    }
    else {
        return false;
    }
}

void Complexo::Atribuir(Complexo x) {
    this->real_ = x.real_;
    this-> imag_ = x.imag_;
}

double Complexo::modulo() {
    auto m = sqrt((this->real_)*(this->real_) + (this->imag_)*(this->imag_));
    return m;
}

Complexo Complexo::conjugado() {
    Complexo c(this->real_, -this->imag_);
    return c;
}

Complexo Complexo::simetrico() {
    Complexo c(-this->real_, -this->imag_);
    return c;
}

Complexo Complexo::inverso() { // ? a/(a^2 + b^2) - b/(a^2 + b^2)i
    auto inverso_real = ((this->real_) / (((this->real_)*(this->real_)) + ((this->imag_)*(this->imag_))));
    auto inverso_imag = ((this->imag_) / (((this->real_)*(this->real_)) + ((this->imag_)*(this->imag_))));
    Complexo i(inverso_real, inverso_imag);
    return i;
}

Complexo Complexo::somar(Complexo y) {
    auto soma_real = ((this->real_) + (y.real_));
    auto soma_imag = ((this->imag_) + (y.imag_));
    Complexo s(soma_real, soma_imag);
    return s;
}

Complexo Complexo::subtrair(Complexo y) {
    auto subtracao_real = ((this->real_) - (y.real_));
    auto subtracao_imag = ((this->imag_) - (y.imag_));
    Complexo s(subtracao_real, subtracao_imag);
    return s;
}

Complexo Complexo::multiplicar(Complexo y) {
    auto produto_real = (((this->real_)*(y.real_)) - ((this->imag_)*(y.imag_)));
    auto produto_imag = (((this->real_)*(y.imag_)) - ((this->imag_)*(y.real_)));
    Complexo p(produto_real, produto_imag);
    return p;
}

Complexo Complexo::dividir(Complexo y) {
    Complexo inverso = y.inverso();
    auto divisao_real = (((this->real_)*(inverso.real_)) - ((this->imag_)*(inverso.imag_)));
    auto divisao_imag = (((this->real_)*(inverso.imag_)) - ((this->imag_)*(inverso.real_)));
    Complexo d(divisao_real, divisao_imag);
    return d;
}
