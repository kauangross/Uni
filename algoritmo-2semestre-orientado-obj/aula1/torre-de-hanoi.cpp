#include <iostream>

void hanoi(int n, char origem, char auxiliar, char destino) {
// É o caso base da recursão, move o disco 1 de um pino para outro, quando a recursão chegar no n == 1
    if (n == 1) { 
        std::cout << "Mover o disco 1 de " << origem << " para " << destino << std::endl;
        return; // Retorna a execução
    }

// É responsável por mover uma sequência de discos para um pino auxiliar
    hanoi(n - 1, origem, destino, auxiliar); 

// Após mover os auxiliares para o auxiliar, move um pino maior para o pino destino
    std::cout << "Mover o disco " << n << " de " << origem << " para " << destino << std::endl;
// Move os pinos de um auxiliar para o destino, repetindo todos os passos anteriores até todos os discos chegaram no pino c
    hanoi(n - 1, auxiliar, origem, destino);
}

int main() {
    int n;
    // Número de discos
    std::cout << "Insira o número de discos: ";
    std::cin >> n;

    // Chama a recursividade
    hanoi(n, 'A', 'B', 'C');
    return 0;
}