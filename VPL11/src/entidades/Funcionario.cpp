#include<iomanip>

#include "Funcionario.hpp"

using namespace std;

Funcionario::Funcionario(double salario, string nome, int idade) : Pessoa(nome, idade) {
    setSalario(salario);
}

void Funcionario::setSalario(double s) {
    this->salario = (s >= 1100) ? s : 1100; //O Funcion�rio recebe pelo menos o sal�rio m�nimo
}

double Funcionario::getSalario() const {
    return this->salario;
}

ostream &operator<<(ostream &out, const Funcionario &f ) {
    out << '{'<< "Pessoa=" << static_cast<Pessoa>(f)
        << ";Salario="<< fixed << f.salario << '}';
    return out;
}
