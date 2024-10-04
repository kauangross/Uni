#include <iostream>

namespace Math { // namespace com a função
    int add(int vet[]){ // Função
        int soma;
        for(int i = 0; i < 3; i++) {
            soma += vet[i];
        }
        return soma;
    }
}

int main() {
    int vet[3];
    
    for(int i = 0; i < 3; i++) {
        std::cout << "Digite o p"; // "printf"
        std::cin >> vet[i]; // Adiciona o valor no vetor
    }
    
    int soma = Math::add(vet); // chama a função que está no namespace
    std::cout << soma; // Printa a soma
    return 0;
}