#include <iostream>
#include <vector>
#include <string>


int main () {
    std::string palavra;
    std::cin >> palavra;
    
    std::vector<char> vogais = {'a', 'e', 'i', 'o', 'u'};
    std::vector<int> count;
    count.resize(vogais.size());

    for(int i=0; i<palavra.size(); i++) {
        for(int j=0; j<vogais.size(); j++) {
            if (palavra[i] == vogais[j]) {
                count[j]++;
            }
        }
    }

    for(int j=0; j<vogais.size(); j++) {
        if (count[j] > 0) {
            std::cout << vogais[j] << ' ' << count[j] << std::endl;
        }
    }

    return 0;
}