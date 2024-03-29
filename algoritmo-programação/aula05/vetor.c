#include <stdio.h>

int main()
{
    int vetor[10];
    int maior = 0;
    for (int i = 1; i < 11; i++)
    {
        printf("Digite um numero para a posicao %d do vetor: ", i);
        scanf("%d", &vetor[i]);

        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    printf("O maior valor eh: %d", maior);

    return 0;
}
