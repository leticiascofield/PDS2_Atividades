#include "jogo_da_vida.h"
#include "jogo_da_vida.h"
#include <vector>

// Implementa o Jogo da Vida de John Conway.
// https://pt.wikipedia.org/wiki/Jogo_da_vida
    // Cria um jogo cujo torus tem l linhas e c colunas.
    // Todas as células são inicializadas como mortas.
    JogoDaVida::JogoDaVida(int l, int c){
        vivas_.resize(l, std::vector<bool>(c));
    }

    /*// Retorna o número de linhas do torus.
    int JogoDaVida::linhas() {
        return vivas_.size();
    }

    // Retorna o número de colunas do torus.
    int JogoDaVida::colunas() {
        return vivas_[0].size();
    }*/

    // Retorna o estado da célula [i, j].
    // Pré-condição: 0 <= i < #linhas e 0 <= j < #colunas
    bool JogoDaVida::viva(int i, int j){
        if((i < 0) || (j < 0) || (i >= this->linhas()) || (j >= this->colunas())){
            ExcecaoCelulaInvalida e;
            e.linha = i;
            e.coluna = j;
            throw e;
        }
        return vivas_[i][j];
    }

    // Alteram o estado célula [i, j].
    // Pré-condição: 0 <= i < #linhas e 0 <= j < #colunas
    void JogoDaVida::Matar(int i, int j){
        if((i < 0) || (j < 0) || (i >= this->linhas()) || (j >= this->colunas())){
            ExcecaoCelulaInvalida e;
            e.linha = i;
            e.coluna = j;
            throw e;
        }
        vivas_[i][j] = false;
    }

    void JogoDaVida::Reviver(int i, int j){
        if((i < 0) || (j < 0) || (i >= this->linhas()) || (j >= this->colunas())){
            ExcecaoCelulaInvalida e;
            e.linha = i;
            e.coluna = j;
            throw e;
        }
        vivas_[i][j] = true;
    }

    // Executa a próxima iteração do jogo da vida.
    // Ou seja, altera os estado da matriz,
    // de forma que ela fique igual ao da próxima iteração.
    void JogoDaVida::ExecutarProximaIteracao(){
        std::vector<std::vector<bool>> novaGeracao(vivas_);

        for (int i = 0; i < this->linhas(); i++) {
            for (int j = 0; j < this->colunas(); j++) {
                int vizinhasVivas = NumeroDeVizinhasVivas(i, j);
                
                if (vivas_[i][j]) {
                    // Célula viva com menos de 2 ou mais de 3 vizinhas vivas, morre.
                    if (vizinhasVivas < 2 || vizinhasVivas > 3) {
                        novaGeracao[i][j] = false;
                    }
                } else {
                    // Célula morta com exatamente 3 vizinhas vivas, revive.
                    if (vizinhasVivas == 3) {
                        novaGeracao[i][j] = true;
                    }
                }
            }
        }
        vivas_ = novaGeracao;
    }


    // Conta o número de vizinhas vivas da célula [x, y].
    int JogoDaVida::NumeroDeVizinhasVivas(int x, int y){
        if((x < 0) || (y < 0) || (x >= this->linhas()) || (y >= this->colunas())){
            ExcecaoCelulaInvalida e;
            e.linha = x;
            e.coluna = y;
            throw e;
        }
        int count = 0;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int vizinhoX = (x + i + this->linhas()) % this->linhas();    
                int vizinhoY = (y + j + this->colunas()) % this->colunas(); 
                if ((i != 0 || j != 0) && (vivas_[vizinhoX][vizinhoY] == true)){
                    count++;
                }
            }
        }
        return count;
    }
