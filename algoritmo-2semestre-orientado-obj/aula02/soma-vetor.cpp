#include <iostream>

namespace soma { // namespace chamado soma
    int soma_vetor(int *vet, int tam, int *soma){ // função de soma
        for (int i = 0; i < tam; i++)
        {
            *soma += vet[i];
        }
        return *soma;
    }
}

int main()
{
    int *vet = new int[3];

    std::cout << "Digite os valores" << std::endl;
    // Lê e add na variável tudo na mesma linha
    std::cin >> vet[0] >> vet[1] >> vet[2]; 
    // Printa na tela o vetor
    std::cout << vet[0] << ", " << vet[1] << ", " << vet[2] << std::endl;

    int soma = 0;

    // Para chamar a função soma, preciso usar o namespace 'soma' e não 'std', logo antes de chamar a função 'soma_vetor'
    soma::soma_vetor(vet, 3, &soma);

    std::cout << "\nValor da soma: " << soma << std::endl;

    delete [] vet; // Excluí o vetor ( IMPORTANTE )
    return 0;
}