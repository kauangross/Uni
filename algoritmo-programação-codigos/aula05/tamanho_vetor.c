#include <stdio.h>

int main()
{
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < 5; i++)
    {
        printf("%d", vetor[i]);
    }

    printf("\n%d", tamanho_vetor);

    return 0;
}
