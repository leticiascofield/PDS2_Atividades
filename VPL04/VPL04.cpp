#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int main(){
    std::map<std::string, int> map;
    std::string texto;
    while(std::getline(std::cin, texto, '$')); // usar getline() quando precisar pegar um texto com espaço
    int count = 0;
    std::string palavraAtual;
    std::vector<std::string> palavras;


    for(int i=0; i<texto.size(); i++){
        if(texto[i+1] == ' ' || i+1 == texto.size()){
            count ++;
            palavraAtual.clear();
            for(int j = i; texto[j] != ' ' && j >= 0; j--){              
                palavraAtual.push_back(texto[j]);  
            }
            std::reverse(palavraAtual.begin(), palavraAtual.end());
            palavras.push_back(palavraAtual);
        }
    }

    for(int i=0; i<palavras.size(); i++){
        map[palavras[i]]++;
    }
    

    std::string palavraMaisComum;
    int frequencia = 0;
    for(std::map<std::string, int>::iterator i= map.begin(); i != map.end(); i++){
        if((*i).second > frequencia){
            palavraMaisComum = (*i).first;
            frequencia = (*i).second;
        }
    }

    std::cout << "Palavra mais comum: " << palavraMaisComum << std::endl;

    return 0;
}

