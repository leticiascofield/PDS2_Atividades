#include <iostream>
#include <vector>

int main(){
    int l1, l2, c2;
    std::cin >> l1 >> l2 >> c2;
    std::vector<int> M(l1, 0), N(l2, 0), O(c2, 0);
    std::vector<std::vector<int>> matriz1(l1, N);
    std::vector<std::vector<int>> matriz2(l2, O);
    std::vector<std::vector<int>> multMatriz(l1, O);
    
    for(int i=0; i<l1; i++){
        for(int j=0; j<l2; j++){
            std::cin >> matriz1[i][j];
        }
    }

    for(int i=0; i<l2; i++){
        for(int j=0; j<c2; j++){
            std::cin >> matriz2[i][j];
        }
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<c2; j++){
            for(int k=0; k<l2; k++){
                multMatriz[i][j] += (matriz1[i][k] * matriz2[k][j]);
            }
            std::cout << multMatriz[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}