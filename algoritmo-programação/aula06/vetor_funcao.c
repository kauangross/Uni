#include <stdio.h>

#define TAMANHO_VETOR 5

void imprimir_vetor(int vetor[])
{
    for (int i = 0; i < TAMANHO_VETOR; i++)
    {
        printf("Vetor: %d ", vetor[i]);
    }
    printf("\n");
}

int main()
{
    int vetor[TAMANHO_VETOR] = {1, 2, 3, 4, 5};

    // Chamando a função para imprimir o vetor
    imprimir_vetor(vetor);

    return 0;
}