#include <stdio.h>

void dobrar_elementos(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] *= 2;
    }
}

int main()
{
    int vetor[5] = {1, 2, 3, 4, 5};
    int tamanho = 5;

    dobrar_elementos(vetor, tamanho);

    printf("Vetor dobrado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}